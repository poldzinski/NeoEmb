
#include "AcceptClientCallback.hpp"

/////////////////////////////////////
//
// Callback for accepting a client.
//
// 07-Aug-2018 Initial version.
//
/////////////////////////////////////

// System includes
// (none)

// C++ includes
// (none)

// C includes
// (none)

// Forward references
// (none)

namespace Network
{
    
bool AcceptClientCallback::IsClientAccepted()
{
    return m_Acceptance;
}
    
void AcceptClientCallback::Accept()
{
    m_Acceptance = true;
}

void AcceptClientCallback::Reject()
{
    m_Acceptance = false;
}
    
}  // namespace Network
