/////////////////////////////////////
//
// TCP network server.
//
// 21-Jun-2018 Initial version.
// 17-Jul-2018 Method for getting amount of clients added.
// 19-Jul-2018 Disconneting clients fixed.
//
/////////////////////////////////////

#ifndef TCP_NETWORK_SERVER_HPP
#define TCP_NETWORK_SERVER_HPP

// System includes
#include <vector>
#include <thread>

// C++ includes
#include "Network/BaseNetworkServer.hpp"

// C includes
#include <sys/poll.h>

// Forward references
// (none)

namespace Network
{

/// <summary>TCP server class.</summary>
class TcpNetworkServer: public BaseNetworkServer
{

public:
    
    /// <summary>Description of a client socket.</summary>
    struct ClientSocket
    {
        /// <summary>Client's socket descriptor.</summary>
        int socketDescriptor;
        /// <summary>End point.</summary>
        IPEndPoint endPoint;
        /// <summary>Parent server.</summary>
        TcpNetworkServer* pParentServer;
    };
    
    /// <summary>Description of a server socket.</summary>
    struct ServerSocket
    {
        /// <summary>Parent server.</summary>
        TcpNetworkServer* pServer;
        /// <summary>Callback for accepting incoming connections.</summary>
        AcceptClientCallback* pAcceptCallback;
        /// <summary>Callback for reading data from clients.</summary>
        ClientReadCallback* pReadCallback;
        /// <summary>Callback for disconnecting clients.</summary>
        DisconnectClientCallback* pDisconnectCallback;
        /// <summary>List of clients.</summary>
        std::vector< ClientSocket >* pClients;
        /// <summary>Server's socket descriptor.</summary>
        int socketDescriptor;
        /// <summary>State of the server.</summary>
        bool* pServerDown;
    };
    
    /// <summary>Gets the amount of clients.</summary>
    /// <returns>The amount of clients.</returns>
    virtual uint32_t GetClientsCount() const;
    
    /// <summary>Disconnects a client.</summary>
    /// <param name="client">Client.</param>
    void DisconnectClient( const ClientSocket client );
    
    /// <summary>Disconnects a client.</summary>
    /// <param name="client">Index of a client.</param>
    void DisconnectClient( const uint32_t clientIndex );

private:
    
    /// <summary>Accepts new client.</summary>
    /// <param name="serverSocket">Server.</param>
    /// <param name="pPollSetting">Settings of the client's socket.</param>
    static bool AddNewClient( ServerSocket serverSocket, struct pollfd* pPollSetting );
    
    /// <summary>Removes a client.</summary>
    /// <param name="serverSocket">Server.</param>
    /// <param name="pPollSettings">Settings of the client's socket.</param>
    /// <param name="settingIndex">Index of the client's settings.</param>
    /// <param name="clientsConnected">Number of connected clients.</param>
    static void RemoveClient( ServerSocket serverSocket,
                              struct pollfd* pPollSettings,
                              const uint32_t settingIndex,
                              const uint32_t clientsConnected );
    
    /// <summary>Reads data from a socket.</summary>
    /// <param name="serverSocket">Server.</param>
    /// <param name="pPollSettings">Settings of the client's socket.</param>
    /// <param name="clientIndex">Index of the client.</param>
    static void ReadDataFromSocket( ServerSocket serverSocket,
                                    struct pollfd* pPollSettings,
                                    const uint32_t clientIndex );
    
    /// <summary>Reads data from a client.</summary>
    /// <param name="serverSocket">Server.</param>
    /// <param name="pPollSettings">Settings of the client's socket.</param>
    /// <param name="settingIndex">Index of the client's settings.</param>
    /// <param name="clientsConnected">Number of connected clients.</param>
    /// <returns>True if client has been disconnected, false otherwise.</returns>
    static bool ReadDataFromClient( const ServerSocket serverSocket,
                                    struct pollfd* pPollSettings,
                                    const uint32_t settingIndex,
                                    uint32_t& clientsConnected );
    
    /// <summary>Processes an event.</summary>
    /// <param name="serverSocket">Server.</param>
    /// <param name="pPollSettings">Settings of the client's socket.</param>
    /// <param name="settingIndex">Index of the client's settings.</param>
    /// <param name="rClientsConnected">Number of connected clients.</param>
    /// <returns>True if client has been disconnected, false otherwise.</returns>
    static bool ProcessEvent( const ServerSocket serverSocket,
                              struct pollfd* pPollSettings,
                              const uint32_t settingIndex,
                              uint32_t& rClientsConnected );
    
    /// <summary>Thread listening for attempts to connect.</summary>
    /// <param name="serverSocket">Server.</param>
    static void ListeningThread( const ServerSocket serverSocket );
    
    /// <summary>Tries to connect to a server.</summary>
    /// <param name="serverPort">Server's port.</param>
    /// <returns>True if the operation was successful, false otherwise.</returns>
    virtual bool TryToBind( const uint16_t serverPort );

    /// <summary>Tries to disconnect.</summary>
    /// <returns>True if the operation was successful, False otherwise.</returns>
    virtual bool TryToDisconnect();

    /// <summary>Tries to send a packet to the server.</summary>
    /// <param name="ipAddress">Destination client's IP address.</param>
    /// <param name="buffer">Data to be sent.</param>
    /// <param name="size">Data size to be sent.</param>
    /// <returns>Amount of sent bytes.</returns>
    virtual const uint32_t TryToSendPacket( const IPEndPoint endPoint, 
                                            const uint8_t* const buffer, 
                                            const uint32_t size );

    /// <summary>Maximum number of clients.</summary>
    static const uint32_t MAX_CLIENTS_COUNT = 8U;
    /// <summary>Connected clients.</summary>
    std::vector< ClientSocket > m_Clients;
    /// <summary>Server's state.</summary>
    bool m_ServerDown = true;
    /// <summary>Socket descriptor.</summary>
    int m_SocketDescriptor = 0;
    /// <summary>Listening thread.</summary>
    std::thread m_ListeningThread;

};

} // namespace Network

#endif  // TCP_NETWORK_SERVER_HPP
