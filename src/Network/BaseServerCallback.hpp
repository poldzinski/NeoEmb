/////////////////////////////////////
//
// Base callback for a server.
//
// 07-Aug-2018 Initial version.
//
/////////////////////////////////////

#ifndef BASE_SERVER_CALLBACK_HPP
#define BASE_SERVER_CALLBACK_HPP

// System includes
// (none)

// C++ includes
#include "Network/Callback.hpp"
#include "Network/BaseNetworkServer.hpp"

// C includes
// (none)

// Forward references
// (none)

namespace Network
{

class BaseServerCallback: public Callback
{
    
public:
    
    /// <summary>Constructor.</summary>
    /// <param name="pServer">Server.</param>
    /// <param name="client">Connected client.</param>
    BaseServerCallback();
    
    /// <summary>Returns the server.</summary>
    /// <returns>The server.</returns>
    const Network::BaseNetworkServer* GetServer();
    
    /// <summary>Sets the server.</summary>
    /// <param name="pServer">The server.</param>
    void SetServer( BaseNetworkServer* pServer );
    
    /// <summary>Returns the client.</summary>
    /// <returns>The client.</returns>
    const BaseNetworkServer::IPEndPoint GetClient();

    /// <summary>Sets the client.</summary>
    /// <param name="client">The client.</param>
    void SetClient( const BaseNetworkServer::IPEndPoint client );

private:
    
    /// <summary>The server.</summary>
    BaseNetworkServer* m_pServer;
    
    /// <summary>The client.</summary>
    BaseNetworkServer::IPEndPoint m_Client;
};
        
}  // namespace Network

#endif  // #define BASE_SERVER_CALLBACK_HPP
