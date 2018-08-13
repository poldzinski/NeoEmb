/////////////////////////////////////
//
// Base callback for a server.
//
// 07-Aug-2018 Initial version.
//
/////////////////////////////////////

// System includes
// (none)

// C++ includes
#include "Network/BaseServerCallback.hpp"

// C includes
// (none)

// Forward references
// (none)

namespace Network
{

BaseServerCallback::BaseServerCallback()
    : m_pServer( nullptr )
    , m_Client( { 0U } )
{
    // Nothing to do.
}

const BaseNetworkServer* BaseServerCallback::GetServer()
{
    return m_pServer;
}

void BaseServerCallback::SetServer( BaseNetworkServer* pServer )
{
    m_pServer = pServer;
}

const BaseNetworkServer::IPEndPoint BaseServerCallback::GetClient()
{
    return m_Client;
}

void BaseServerCallback::SetClient( const BaseNetworkServer::IPEndPoint client )
{
    m_Client = client;
}

}  // namespace Network
