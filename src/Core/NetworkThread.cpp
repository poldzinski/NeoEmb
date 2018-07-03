/////////////////////////////////////
//
// Main network thread.
//
// 03-Jul-2018 Initial version.
//
/////////////////////////////////////

// System includes
// (none)

// C++ includes
#include "GeneralState.hpp"

// C includes
// (none)

// Forward references
// (none)

namespace Core
{

/// <summary>Thread for network processing.</summary>
/// <param name="globalShutdown">Global signal for shutting down.</param>
void NetworkThread( GeneralState* pGeneralState )
{
    while ( pGeneralState->IsGlobalShutdown() == false )
    {
        
    }
}

}  // namespace Core
