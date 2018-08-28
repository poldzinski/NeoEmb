/////////////////////////////////////
//
// Main network thread.
//
// 19-Jul-2018 Initial version.
//
/////////////////////////////////////

#ifndef NETWORK_THREAD_HPP
#define NETWORK_THREAD_HPP

// System includes
// (none)

// C++ includes
#include "Core/Thread.hpp"
#include "Network/AcceptClientCallback.hpp"
#include "Network/ClientReadCallback.hpp"
#include "Network/DisconnectClientCallback.hpp"

// C includes
// (none)

// Forward references
namespace Core
{
class GeneralState;
}
namespace Network
{
class BaseNetworkServer;
}

namespace Core
{
namespace Threads
{

class NetworkThread: public Thread
{

public:
    
    /// <summary>Gets the single instance of the class.</summary>
    /// <returns>The instance.</returns>
    static NetworkThread& GetInstance()
    {
        static NetworkThread instance;
        return instance;
    }
    
private:
    
    /// <summary>Constructor.</summary>
    NetworkThread();
    
    /// <summary>Body of the processing thread.</summary>
    /// <param name="pGeneralState">General state of the application.</param>
    virtual void ProcessingThread( GeneralState* pGeneralState );
    
    /// <summary>Callback for server's reading operations.</summary>
    static void AcceptClient();

    /// <summary>Callback for server's reading operations.</summary>
    virtual void AcceptThisClient();

    /// <summary>Callback for server's reading operations.</summary>
    static void ClientRead();

    /// <summary>Callback for server's reading operations.</summary>
    virtual void ThisClientRead();

    /// <summary>Callback for disconnecting a client.</summary>
    static void DisconnectClient();

    /// <summary>Callback for disconnecting a client.</summary>
    virtual void DisconnectThisClient();

    static Network::AcceptClientCallback m_AcceptClientCallback;
    static Network::ClientReadCallback m_ClientReadCallback;
    static Network::DisconnectClientCallback m_DisconnectClientCallback;

};

}  // namespace Threads
}  // namespace Core

#endif // NETWORK_THREAD_HPP
