/////////////////////////////////////
//
// Callback for reading clients' data.
//
// 07-Aug-2018 Initial version.
//
/////////////////////////////////////

// System includes
// (none)

// C++ includes
#include "Network/ClientReadCallback.hpp"

// C includes
// (none)

// Forward references
// (none)

namespace Network
{

ClientReadCallback::ClientReadCallback()
    : BaseServerCallback()
    , m_pBuffer( nullptr )
    , m_BufferSize( 0U )
{
    // Nothing to do.
}

const uint8_t* const ClientReadCallback::GetBuffer()
{
    return m_pBuffer;
}

void ClientReadCallback::SetBuffer( uint8_t* pBuffer )
{
    m_pBuffer = pBuffer;
}

const uint32_t ClientReadCallback::GetBufferSize()
{
    return m_BufferSize;
}

void ClientReadCallback::SetBufferSize( const uint32_t bufferSize )
{
    m_BufferSize = bufferSize;
}

}  // namespace Network
