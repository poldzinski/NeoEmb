/////////////////////////////////////
//
// Tests of TCP network server.
//
// 28-Jun-2018 Initial version.
//
/////////////////////////////////////

// System includes
#include <iostream>

// C++ includes
#include "Network/TcpNetworkServer.hpp"

// C includes
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/random.h>

// Forward references
// (none)

static const uint16_t TCP_PORT = 3000U;
static bool clientAccepted = false;
static bool dataRead = false;
static bool clientDisconnected = false;
static const uint32_t DATA_BUFFER_SIZE = 128;
static uint8_t compareBuffer[ DATA_BUFFER_SIZE ];

static void Timeout()
{
    sleep( 1 );
}

static bool AcceptClientCallback( const Network::BaseNetworkServer* const,
                                  const Network::BaseNetworkServer::IPEndPoint )
{
    clientAccepted = true;
    
    return true;
}

static void DataReadCallback( const Network::BaseNetworkServer* const,
                              const Network::BaseNetworkServer::IPEndPoint,
                              const uint8_t* const pBuffer,
                              const uint32_t bufferSize )
{
    if ( sizeof( compareBuffer ) == bufferSize )
    {
        const int comparison = memcmp( compareBuffer, pBuffer, bufferSize );
        
        if ( comparison == 0 )
        {
            dataRead = true;
        }
    }
}

static void DisconnectClientCallback( const Network::BaseNetworkServer* const,
                                      const Network::BaseNetworkServer::IPEndPoint )
{
    clientDisconnected = true;
}

/// <summary>Test of TCP connections.</summary>
static void ConnectionTest()
{
    Network::TcpNetworkServer* server = new Network::TcpNetworkServer();
    
    clientAccepted = false;
    dataRead = false;
    clientDisconnected = false;
    
    server->SetCallback( AcceptClientCallback );
    server->SetCallback( DataReadCallback );
    server->SetCallback( DisconnectClientCallback );

    server->Bind( TCP_PORT );
    
    int socketDescriptor = socket( PF_INET, SOCK_STREAM, 0 );
    struct sockaddr_in clientAddress;
    clientAddress.sin_family = AF_INET;
    clientAddress.sin_port = htons( TCP_PORT );
    clientAddress.sin_addr.s_addr = ntohl( 0x7F000001 );
    int connectionResult = connect( socketDescriptor, 
                                    reinterpret_cast< sockaddr* >( &clientAddress ), 
                                    sizeof( clientAddress ) );
    
    Timeout();
    
    if ( ( connectionResult != 0) || ( clientAccepted == false ) )
    {
        std::cout << "Error number: " << errno << std::endl;
        std::cout << "%TEST_FAILED%" \
                     "time=0 testname=ConnectionTest (TcpNetworkServerTests)" \
                     "message=Client not connected." << std::endl;
        delete server;
        return;
    }

    getrandom( compareBuffer, sizeof( compareBuffer ), 0 );
    send( socketDescriptor, compareBuffer, sizeof( compareBuffer), MSG_NOSIGNAL );
    
    Timeout();
    
    if ( dataRead == false )
    {
        std::cout << "%TEST_FAILED%" \
                     "time=0 testname=ConnectionTest (TcpNetworkServerTests)" \
                     "message=Data not read." << std::endl;
        delete  server;
        return;
    }

    close( socketDescriptor );

    Timeout();

    if ( clientDisconnected == false )
    {
        std::cout << "%TEST_FAILED%" \
                     "time=0 testname=ConnectionTest (TcpNetworkServerTests)" \
                     "message=Client not disconnected." << std::endl;
        delete  server;
        return;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% TcpNetworkServerTests" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% ConnectionTest (TcpNetworkServerTests)" << std::endl;
    ConnectionTest();
    std::cout << "%TEST_FINISHED% time=0 ConnectionTest (TcpNetworkServerTests)" << std::endl;
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

