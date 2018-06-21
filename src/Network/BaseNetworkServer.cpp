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

BaseNetworkServer::BaseNetworkServer()
    : m_pReadCallback( nullptr )
    , m_Bound( false )
{
}

BaseNetworkServer::~BaseNetworkServer()
{
    Disconnect();
}

bool BaseNetworkServer::IsConnected()
{
    return m_Bound;
}

bool BaseNetworkServer::Bind( uint16_t serverPort, 
                              ServerReadCallback* pReadCallback,
                              bool disconnect )
{
    m_pReadCallback = nullptr;

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
        m_pReadCallback = pReadCallback;
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

uint32_t BaseNetworkServer::SendPacket( IPEndPoint client, 
                                        uint8_t* pBuffer, 
                                        uint32_t bufferSize )
{
    if ( m_Bound == false )
    {
        return 0;
    }

    return TryToSendPacket( client, pBuffer, bufferSize );
}

BaseNetworkServer::ServerReadCallback* BaseNetworkServer::GetReadCallback()
{
    return m_pReadCallback;
}

void BaseNetworkServer::SetReadCallback( ServerReadCallback* pReadCallback )
{
    m_pReadCallback = pReadCallback;
}

}  // namespace Network
