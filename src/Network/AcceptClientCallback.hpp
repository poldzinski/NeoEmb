/////////////////////////////////////
//
// Callback for accepting client.
//
// 07-Aug-2018 Initial version.
//
/////////////////////////////////////

#ifndef ACCEPT_CLIENT_CALLBACK_HPP
#define ACCEPT_CLIENT_CALLBACK_HPP

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

class AcceptClientCallback: public BaseServerCallback
{
    
public:
    
    /// <summary>Informs whether the client has been accepted.</summary>
    /// <returns>True if the client accepted, false otherwise.</returns>
    bool IsClientAccepted();
    
    /// <summary>Accepts the client.</summary>
    void Accept();
    
    /// <summary>Rejects the client.</summary>
    void Reject();
    
private:
    
    /// <summary>Acceptance flag.</summary>
    bool m_Acceptance = false;
    
};
        
}  // namespace Network

#endif  // #define ACCEPT_CLIENT_CALLBACK_HPP
