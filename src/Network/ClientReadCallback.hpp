/////////////////////////////////////
//
// Callback for reading clients' data.
//
// 07-Aug-2018 Initial version.
//
/////////////////////////////////////

#ifndef CLIENT_READ_CALLBACK_HPP
#define CLIENT_READ_CALLBACK_HPP

// System includes
// (none)

// C++ includes
#include "Network/BaseServerCallback.hpp"

// C includes
// (none)

// Forward references
namespace Network
{
class BaseNetworkServer;
}

namespace Network
{

class ClientReadCallback: public BaseServerCallback
{
    
public:
    
    /// <summary>Constructor.</summary>
    /// <param name="pServer">Server.</param>
    /// <param name="client">Connected client.</param>
    /// <param name="pBuffer">Data buffer.</param>
    /// <param name="bufferSize">Buffer size.</param>
    ClientReadCallback();

    /// <summary>Returns the buffer.</summary>
    /// <returns>The buffer.</returns>
    const uint8_t* const GetBuffer();

    /// <summary>Sets the buffer.</summary>
    /// <param name="pBuffer">The buffer.</param>
    void SetBuffer( uint8_t* pBuffer );

    /// <summary>Returns the buffer's size.</summary>
    /// <returns>The size.</returns>
    const uint32_t GetBufferSize();

    /// <summary>Sets the buffer's size.</summary>
    /// <param name="bufferSize">The buffer's size.</param>
    void SetBufferSize( const uint32_t bufferSize );

private:
    
    /// <summary>The buffer.</summary>
    uint8_t* m_pBuffer;
    
    /// <summary>The buffer's size.</summary>
    uint32_t m_BufferSize;
    
};
        
}  // namespace Network

#endif  // #define CLIENT_READ_CALLBACK_HPP
