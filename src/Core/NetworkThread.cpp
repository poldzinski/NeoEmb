/////////////////////////////////////
//
// Main network thread.
//
// 03-Jul-2018 Initial version.
//
/////////////////////////////////////

// System includes
#include <cstdint>

// C++ includes
#include "Core/GeneralState.hpp"
#include "Network/TcpNetworkServer.hpp"

// C includes
#include <assert.h>

// Forward references
// (none)

namespace Core
{
    
static bool shutDown = false;

bool AcceptClientCallback( const Network::BaseNetworkServer* const pServer,
                           const Network::BaseNetworkServer::IPEndPoint client )
{
    return true;
}

void ClientReadCallback( const Network::BaseNetworkServer* const pServer,
                         const Network::BaseNetworkServer::IPEndPoint client,
                         const uint8_t* const pBuffer,
                         const uint32_t bufferSize )
{
    const char* pQuitCommand = "QUIT";
    
    std::cout << static_cast< char* >( pBuffer ) << std::endl;
    if ( ( bufferSize == strlen( pQuitCommand ) ) &&
         ( strcmp( pBuffer, pQuitCommand ) == 0 ) )
    {
        shutDown = true;
    }
}

void DisconnectClientCallback( const Network::BaseNetworkServer* const pServer,
                               const Network::BaseNetworkServer::IPEndPoint client )
{
    
}
    
/// <summary>Thread for network processing.</summary>
/// <param name="globalShutdown">Global signal for shutting down.</param>
void NetworkThread( GeneralState* pGeneralState )
{
    Network::TcpNetworkServer* pServer = new Network::TcpNetworkServer();
    assert( pServer != nullptr );
    
    pServer->SetCallback( AcceptClientCallback );
    pServer->SetCallback( ClientReadCallback );
    pServer->SetCallback( DisconnectClientCallback );
    pServer->Bind( GeneralState::TCP_SERVER_PORT );
    while ( ( pGeneralState->IsGlobalShutdown() == false ) &&
            ( shutDown == false ) )
    {
        
    }
    pServer->Disconnect();
    
    delete pServer;
}

}  // namespace Core
