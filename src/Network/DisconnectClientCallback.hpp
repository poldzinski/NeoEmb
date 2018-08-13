/////////////////////////////////////
//
// Callback for disconnecting a client.
//
// 07-Aug-2018 Initial version.
//
/////////////////////////////////////

#ifndef DISCONNECT_CLIENT_CALLBACK_HPP
#define DISCONNECT_CLIENT_CALLBACK_HPP

// System includes
// (none)

// C++ includes
// (none)

// C includes
// (none)

// Forward references
namespace Network
{
class BaseServerCallback;
}

namespace Network
{

class DisconnectClientCallback: public BaseServerCallback
{
};
        
}  // namespace Network

#endif  // #define DISCONNECT_CLIENT_CALLBACK_HPP
