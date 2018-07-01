/////////////////////////////////////
//
// Abstract network server.
//
// 20-Jun-2018 Initial version.
//
/////////////////////////////////////

// System includes
// (none)

// C++ includes
#include "BaseNetworkServer.hpp"

// C includes
// (none)

// Forward references
// (none)

namespace Network
{

BaseNetworkServer::~BaseNetworkServer()
{
    Disconnect();
}

const bool BaseNetworkServer::IsConnected()
{
    return m_Bound;
}

bool BaseNetworkServer::Bind( const uint16_t serverPort, 
                              const bool disconnect )
{
    if ( disconnect == true )
    {
        Disconnect();
    }

    if ( m_Bound == true )
    {
        return false;
    }

    if ( TryToBind( serverPort ) == true )
    {
        m_Bound = true;
        return true;
    }

    return false;
}

bool BaseNetworkServer::Disconnect()
{
    if ( m_Bound == false )
    {
        return false;
    }

    m_Bound = false;
    return TryToDisconnect();
}

const uint32_t BaseNetworkServer::SendPacket( const IPEndPoint client, 
                                              const uint8_t* const pBuffer, 
                                              const uint32_t bufferSize )
{
    if ( m_Bound == false )
    {
        return 0U;
    }

    return TryToSendPacket( client, pBuffer, bufferSize );
}

template<>
const BaseNetworkServer::AcceptClientCallback BaseNetworkServer::GetCallback()
{
    return m_pAcceptCallback;
}

template<>
const BaseNetworkServer::ClientReadCallback BaseNetworkServer::GetCallback()
{
    return m_pReadCallback;
}

template<>
const BaseNetworkServer::DisconnectClientCallback BaseNetworkServer::GetCallback()
{
    return m_pDisconnectCallback;
}

void BaseNetworkServer::SetCallback( AcceptClientCallback pAcceptCallback )
{
    m_pAcceptCallback = pAcceptCallback;
}

void BaseNetworkServer::SetCallback( ClientReadCallback pReadCallback )
{
    m_pReadCallback = pReadCallback;
}

void BaseNetworkServer::SetCallback( DisconnectClientCallback pDisconnectCallback )
{
    m_pDisconnectCallback = pDisconnectCallback;
}

}  // namespace Network
