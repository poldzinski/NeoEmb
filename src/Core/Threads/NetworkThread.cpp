/////////////////////////////////////
//
// Main network thread.
//
// 03-Jul-2018 Initial version.
//
/////////////////////////////////////

// System includes
#include <cstring>

// C++ includes
#include "Core/GeneralState.hpp"
#include "Core/Threads/NetworkThread.hpp"
#include "Network/TcpNetworkServer.hpp"
#include "Network/AcceptClientCallback.hpp"
#include "Network/ClientReadCallback.hpp"
#include "Network/DisconnectClientCallback.hpp"

// C includes
#include <assert.h>

// Forward references
// (none)

namespace Core
{
namespace Threads
{

Network::AcceptClientCallback NetworkThread::m_AcceptClientCallback = Network::AcceptClientCallback();
Network::ClientReadCallback NetworkThread::m_ClientReadCallback = Network::ClientReadCallback();
Network::DisconnectClientCallback NetworkThread::m_DisconnectClientCallback = Network::DisconnectClientCallback();
    
NetworkThread::NetworkThread()
{
    m_AcceptClientCallback.Set( &AcceptClient );
    m_ClientReadCallback.Set( &ClientRead );
    m_DisconnectClientCallback.Set( &DisconnectClient );
}

void NetworkThread::ProcessingThread( GeneralState* pGeneralState )
{
    Network::TcpNetworkServer* const pServer = new Network::TcpNetworkServer();
    assert( pServer != nullptr );
    
    pServer->SetCallback( &m_AcceptClientCallback );
    pServer->SetCallback( &m_ClientReadCallback );
    pServer->SetCallback( &m_DisconnectClientCallback );
    pServer->Bind( GeneralState::TCP_SERVER_PORT );
    while ( ( pGeneralState->IsGlobalShutdown() == false ) &&
            ( m_ShutDown == false ) )
    {
        
    }
    pServer->Disconnect();
    
    delete pServer;
}

void NetworkThread::AcceptClient()
{
    GetInstance().AcceptThisClient();
}

void NetworkThread::AcceptThisClient()
{
    m_AcceptClientCallback.Accept();
}

void NetworkThread::ClientRead()
{
    GetInstance().ThisClientRead();
}

void NetworkThread::ThisClientRead()
{
    const char* pQuitCommand = "QUIT";
    
    if ( ( m_ClientReadCallback.GetBufferSize() == strlen( pQuitCommand ) ) &&
         ( memcmp( m_ClientReadCallback.GetBuffer(), pQuitCommand, m_ClientReadCallback.GetBufferSize() ) == 0 ) )
    {
        m_ShutDown = true;
    }
}

void NetworkThread::DisconnectClient()
{
    GetInstance().DisconnectThisClient();
}

void NetworkThread::DisconnectThisClient()
{
}

}  // namespace Threads
}  // namespace Core
