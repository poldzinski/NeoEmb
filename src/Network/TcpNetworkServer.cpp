/////////////////////////////////////
//
// TCP network server.
//
// 21-Jun-2018 Initial version.
//
/////////////////////////////////////

// System includes
// (none)

// C++ includes
#include "Network/TcpNetworkServer.hpp"

// C includes
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <assert.h>

// Forward references
// (none)

namespace Network
{

// Public methods.
    
void TcpNetworkServer::DisconnectClient( const ClientSocket client )
{
    for ( auto clientSocket = m_Clients.begin(); clientSocket != m_Clients.end(); ++clientSocket )
    {
        if ( ( *clientSocket ).socketDescriptor == client.socketDescriptor )
        {
            close( client.socketDescriptor );
            m_Clients.erase( clientSocket );

            if ( m_pDisconnectCallback != nullptr )
            {
                m_pDisconnectCallback( this, client.endPoint );
            }
            
            return;
        }
    }
            
    assert( false );
}
    
void TcpNetworkServer::DisconnectClient( const uint32_t clientIndex )
{
    assert( clientIndex < m_Clients.size() );
    DisconnectClient( m_Clients[ clientIndex ] );
}

// Private methods.
    
/// <summary>Accepts new client.</summary>
bool TcpNetworkServer::AddNewClient( ServerSocket serverSocket, 
                                     struct pollfd* pPollSetting )
{
    struct sockaddr_in clientAddress;
    socklen_t addressSize = sizeof( clientAddress );

    int clientDescriptor = accept( serverSocket.socketDescriptor, 
                                   reinterpret_cast< sockaddr* >( &clientAddress ), 
                                   &addressSize );
    pPollSetting->fd = clientDescriptor;
    pPollSetting->events = POLLIN;

    ClientSocket client = { clientDescriptor,
                            { clientAddress.sin_addr.s_addr },
                            serverSocket.pServer };

    bool clientAccepted = true;

    if ( serverSocket.pAcceptCallback != nullptr )
    {
        clientAccepted = serverSocket.pAcceptCallback( serverSocket.pServer, 
                                                       client.endPoint );
    }

    if ( clientAccepted == true )
    {
        serverSocket.pClients->push_back( client );
    }
    else
    {
        close( clientDescriptor );
    }
    
    return clientAccepted;
}

void TcpNetworkServer::RemoveClient( ServerSocket serverSocket,
                                     struct pollfd* pPollSettings,
                                     const uint32_t settingIndex,
                                     const uint32_t clientsConnected )
{
    std::vector< ClientSocket > clients = *serverSocket.pClients;
    
    clients.erase( clients.begin() + settingIndex - 1 );

    if ( serverSocket.pDisconnectCallback != nullptr )
    {
        serverSocket.pDisconnectCallback( serverSocket.pServer, 
                                          clients[ settingIndex - 1 ].endPoint );
    }
    memcpy( &pPollSettings[ settingIndex ],
            &pPollSettings[ settingIndex + 1U ],
            ( clientsConnected - settingIndex ) * sizeof( pPollSettings[ 0U ] ) );
}
    
void TcpNetworkServer::ReadDataFromSocket( ServerSocket serverSocket,
                                           struct pollfd* pPollSettings,
                                           const uint32_t clientIndex )
{
    struct pollfd rSetting = pPollSettings[ clientIndex + 1U ];
    uint8_t buffer[ READ_BUFFER_SIZE ];
    size_t dataRead = read( rSetting.fd, buffer, sizeof( buffer ) );
    if ( serverSocket.pReadCallback != nullptr )
    {
        std::vector< ClientSocket > clients = *serverSocket.pClients;
        serverSocket.pReadCallback( serverSocket.pServer,
                                    clients[ clientIndex ].endPoint,
                                    buffer,
                                    dataRead );
    }
}
    
bool TcpNetworkServer::ReadDataFromClient( const ServerSocket serverSocket,
                                           struct pollfd* pPollSettings,
                                           const uint32_t settingIndex,
                                           const uint32_t clientsConnected )
{
    struct pollfd& rSetting = pPollSettings[ settingIndex ];
    bool clientRemoved = false;
    uint8_t buffer[ READ_BUFFER_SIZE ];
    size_t dataRead = read( rSetting.fd, buffer, sizeof( buffer ) );
    
    if ( dataRead == 0 )
    {
        RemoveClient( serverSocket, pPollSettings, settingIndex, clientsConnected );
        clientRemoved = true;
    }
    else if ( dataRead <= sizeof( buffer ) )
    {
        if ( serverSocket.pReadCallback != nullptr )
        {
            std::vector< ClientSocket > clients = *serverSocket.pClients;
            serverSocket.pReadCallback( serverSocket.pServer,
                                        clients[ settingIndex - 1 ].endPoint,
                                        buffer,
                                        dataRead );
        }
    }

    return clientRemoved;
}
    
bool TcpNetworkServer::ProcessEvent( const ServerSocket serverSocket,
                                     struct pollfd* pPollSettings,
                                     const uint32_t settingIndex,
                                     uint32_t& rClientsConnected )
{
    bool proceed = false;
    struct pollfd& rSetting = pPollSettings[ settingIndex ];
    std::vector< ClientSocket > clients = *serverSocket.pClients;

    if ( ( rSetting.revents & POLLIN ) == POLLIN )
    {
        if ( rSetting.fd == serverSocket.socketDescriptor )
        {
            const bool accepted = AddNewClient( serverSocket, &pPollSettings[ rClientsConnected + 1U ] );
            if ( accepted == true )
            {
                rClientsConnected++;
            }
        }
        else if ( rSetting.fd == clients[ settingIndex - 1].socketDescriptor )
        {
            proceed = ReadDataFromClient( serverSocket, 
                                          pPollSettings, 
                                          settingIndex, 
                                          rClientsConnected );
        }
    }

    return proceed;
}
    
void TcpNetworkServer::ListeningThread( const ServerSocket serverSocket )
{
    uint32_t clientsConnected = 0U;

    struct pollfd poll_settings[ MAX_CLIENTS_COUNT ];
    memset( poll_settings, 0, sizeof( poll_settings ) );
    poll_settings[ 0 ].fd = serverSocket.socketDescriptor;
    poll_settings[ 0 ].events = POLLIN;

    while ( *serverSocket.pServerDown == false )
    {
        // Waiting for an event from clients connected or a new one.
        const int ONE_SECOND = 1000;
        int results = poll( poll_settings, clientsConnected + 1U, ONE_SECOND );

        for ( uint32_t settingIndex = 0; 
              ( results > 0 ) && ( settingIndex <= clientsConnected ); 
              ++settingIndex )
        {
            bool proceed = true;

            do
            {
                proceed = ProcessEvent( serverSocket,
                                        poll_settings,
                                        settingIndex,
                                        clientsConnected );
            }
            while ( ( proceed == true ) && ( settingIndex <= clientsConnected ) );
        }
    }
}
    
bool TcpNetworkServer::TryToBind( const uint16_t serverPort )
{
    try
    {
        struct sockaddr_in serverAddress;

        m_SocketDescriptor = socket( AF_INET, SOCK_STREAM, 0 );

        int options = fcntl( m_SocketDescriptor, F_GETFL ) | O_NONBLOCK;
        fcntl( m_SocketDescriptor, F_SETFL, options );

        int socketOptions;
        setsockopt( m_SocketDescriptor, 
                    SOL_SOCKET, 
                    SO_REUSEADDR, 
                    &socketOptions, 
                    sizeof( socketOptions ) );

        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = INADDR_ANY;
        serverAddress.sin_port = htons( serverPort );
        ( void )bind( m_SocketDescriptor,
                      reinterpret_cast< sockaddr* >( &serverAddress ), 
                      sizeof( serverAddress ) );

        listen( m_SocketDescriptor, static_cast< int >( MAX_CLIENTS_COUNT ) );

        m_ServerDown = false;

        const ServerSocket serverSocket = { this,
                                            m_pAcceptCallback,
                                            m_pReadCallback,
                                            m_pDisconnectCallback,
                                            &m_Clients,
                                            m_SocketDescriptor, 
                                            &m_ServerDown };
        m_ListeningThread = std::thread( ListeningThread, serverSocket );
    }
    catch ( ... )
    {
        return false;
    }

    return true;
}

bool TcpNetworkServer::TryToDisconnect()
{
    try
    {
        m_ServerDown = true;
        m_ListeningThread.join();
        
        while ( m_Clients.size() > 0 )
        {
            DisconnectClient( 0U );
        }
        
        close( m_SocketDescriptor );
    }
    catch ( ... )
    {
        return false;
    }

    return true;
}

const uint32_t TcpNetworkServer::TryToSendPacket( const IPEndPoint endPoint, 
                                                  const uint8_t* const buffer, 
                                                  const uint32_t size )
{
    for ( ClientSocket& client: m_Clients )
    {
        if ( client.endPoint.ipAddress == endPoint.ipAddress )
        {
            try
            {
                write( client.socketDescriptor, buffer, size );
                return size;
            }
            catch ( ... )
            {
                return 0;
            }
        }
    }
    return 0;
}

} // namespace Network
