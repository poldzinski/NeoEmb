/////////////////////////////////////
//
// Abstract network server.
//
// 20-Jun-2018 Initial version.
// 01-Jul-2018 Methods for callbacks added.
// 17-Jul-2018 Method for getting amount of clients added.
// 19-Jul-2018 Disconneting clients fixed.
//
/////////////////////////////////////

#ifndef BASE_NETWORK_SERVER_HPP
#define BASE_NETWORK_SERVER_HPP

// System includes
#include <cstdint>

// C++ includes
// (none)

// C includes
// (none)

// Forward references
namespace Network
{
class AcceptClientCallback;
class ClientReadCallback;
class DisconnectClientCallback;
}

namespace Network
{

/// <summary>Base TCP server class.</summary>
class BaseNetworkServer
{

public:
    
    /// <summary>Size of buffers for read operations.</summary>
    static const uint32_t READ_BUFFER_SIZE = 256U;
    
    /// <summary>Description of an IP endpoint.</summary>
    struct IPEndPoint
    {
        /// <summary>IP address.</summary>
        uint32_t ipAddress;
    };
    
    /// <summary>Destructor.</summary>
    virtual ~BaseNetworkServer();

    /// <summary>Returns the state of the connection.</summary>
    /// <returns>True if connected, otherwise false.</returns>
    const bool IsConnected();

    /// <summary>Binds to a port.</summary>
    /// <param name="serverPort">Server's port.</param>
    /// <param name="disconnect">Whether to disconnect if already connected.</param>
    /// <returns>True if the operation was successful, False otherwise.</returns>
    bool Bind( const uint16_t serverPort, 
               const bool disconnect = true );

    /// <summary>Disconnects.</summary>
    /// <returns>True if the operation was successful, False otherwise.</returns>
    bool Disconnect();

    /// <summary>Sends a packet to the server.</summary>
    /// <param name="client">Destination client.</param>
    /// <param name="buffer">Data to be sent.</param>
    /// <param name="size">Data size to be sent.</param>
    /// <returns>Amount of sent bytes.</returns>
    const uint32_t SendPacket( const IPEndPoint client, 
                               const uint8_t* const pBuffer, 
                               const uint32_t size );

    /// <summary>Returns current read operations callback.</summary>
    /// <returns>Callback.</returns>
    template< typename CALLBACK >
    const CALLBACK* GetCallback();

    /// <summary>Sets read operations callback.</summary>
    /// <param name="pCallback">Callback for accept operations.</param>
    void SetCallback( AcceptClientCallback* pCallback );

    /// <summary>Sets read operations callback.</summary>
    /// <param name="pCallback">Callback for accept operations.</param>
    void SetCallback( ClientReadCallback* pCallback );

    /// <summary>Sets read operations callback.</summary>
    /// <param name="pCallback">Callback for accept operations.</param>
    void SetCallback( DisconnectClientCallback* pCallback );

    /// <summary>Gets the amount of clients.</summary>
    /// <returns>The amount of clients.</returns>
    virtual uint32_t GetClientsCount() const = 0;

protected:
    
    /// <summary>Tries to connect to a server.</summary>
    /// <param name="serverPort">Server's port.</param>
    /// <returns>True if the operation was successful, False otherwise.</returns>
    virtual bool TryToBind( const uint16_t serverPort ) = 0;

    /// <summary>Tries to disconnect.</summary>
    /// <returns>True if the operation was successful, False otherwise.</returns>
    virtual bool TryToDisconnect() = 0;

    /// <summary>Tries to send a packet to the server.</summary>
    /// <param name="client">Destination client.</param>
    /// <param name="buffer">Data to be sent.</param>
    /// <param name="size">Data size to be sent.</param>
    /// <returns>Amount of sent bytes.</returns>
    virtual const uint32_t TryToSendPacket( const IPEndPoint client, 
                                            const uint8_t* const pBuffer, 
                                            const uint32_t size ) = 0;
    
    /// <summary>Callback to accept clients.</summary>
    AcceptClientCallback* m_pAcceptCallback = nullptr;
    /// <summary>Callback to handle read operations.</summary>
    ClientReadCallback* m_pReadCallback = nullptr;
    /// <summary>Callback to handle read operations.</summary>
    DisconnectClientCallback* m_pDisconnectCallback = nullptr;
    /// <summary>Keeps current connection state.</summary>
    bool m_Bound = false;

};

}  // namespace Network

#endif // BASE_NETWORK_SERVER_HPP
