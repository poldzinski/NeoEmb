/////////////////////////////////////
//
// Abstract network server.
//
// 20-Jun-2018 Initial version.
//
/////////////////////////////////////

// System includes
#include <cstdint>
#include <vector>

// C++ includes
// (none)

// C includes
// (none)

// Forward references
// (none)

namespace Network
{

class BaseNetworkServer
{

public:
    
    /// <summary>Size of buffers for read operations.</summary>
    const uint32_t READ_BUFFER_SIZE = 256U;
    
    /// <summary>Description of an IP endpoint.</summary>
    struct IPEndPoint
    {
        /// <summary>IP address.</summary>
        uint32_t ipAddress;
    };
    
    typedef
        /// <summary>Callback for server's reading operations.</summary>
        /// <param name="pServer">Server.</param>
        /// <param name="client">Connected client.</param>
        /// <param name="pBuffer">Data buffer.</param>
        /// <param name="bufferSize">Buffer size.</param>
        void* ServerReadCallback( BaseNetworkServer* pServer,
                                  IPEndPoint client,
                                  uint8_t* pBuffer,
                                  uint32_t bufferSize );
    
    /// <summary>Constructor.</summary>
    BaseNetworkServer();

    /// <summary>Destructor.</summary>
    virtual ~BaseNetworkServer();

    /// <summary>Returns the state of the connection.</summary>
    /// <returns>True if connected, otherwise false.</returns>
    bool IsConnected();

    /// <summary>Binds to a port.</summary>
    /// <param name="serverPort">Server's port.</param>
    /// <param name="readCallback">Callback for read operations.</param>
    /// <param name="disconnect">Whether to disconnect if already connected.</param>
    /// <returns>True if the operation was successful, False otherwise.</returns>
    bool Bind( uint16_t serverPort, 
               ServerReadCallback* pReadCallback = nullptr,
               bool disconnect = true );

    /// <summary>Disconnects.</summary>
    /// <returns>True if the operation was successful, False otherwise.</returns>
    bool Disconnect();

    /// <summary>Sends a packet to the server.</summary>
    /// <param name="client">Destination client.</param>
    /// <param name="buffer">Data to be sent.</param>
    /// <param name="size">Data size to be sent.</param>
    /// <returns>Amount of sent bytes.</returns>
    uint32_t SendPacket( IPEndPoint client, uint8_t* pBuffer, uint32_t size );

    /// <summary>Returns current read operations callback.</summary>
    /// <returns>Callback.</returns>
    ServerReadCallback* GetReadCallback();

    /// <summary>Sets read operations callback.</summary>
    /// <param name="readCallback">Callback for read operations.</param>
    void SetReadCallback( ServerReadCallback* pReadCallback );

protected:
    
    /// <summary>Tries to connect to a server.</summary>
    /// <param name="serverPort">Server's port.</param>
    /// <returns>True if the operation was successful, False otherwise.</returns>
    virtual bool TryToBind( uint16_t serverPort ) = 0;

    /// <summary>Tries to disconnect.</summary>
    /// <returns>True if the operation was successful, False otherwise.</returns>
    virtual bool TryToDisconnect() = 0;

    /// <summary>Tries to send a packet to the server.</summary>
    /// <param name="client">Destination client.</param>
    /// <param name="buffer">Data to be sent.</param>
    /// <param name="size">Data size to be sent.</param>
    /// <returns>Amount of sent bytes.</returns>
    virtual uint32_t TryToSendPacket( IPEndPoint client, 
                                      uint8_t* pBuffer, 
                                      uint32_t size ) = 0;

private:
    
    /// <summary>Callback to handle read operations.</summary>
    ServerReadCallback* m_pReadCallback;
    /// <summary>Keeps current connection state.</summary>
    bool m_Bound;

};

}  // namespace Network
