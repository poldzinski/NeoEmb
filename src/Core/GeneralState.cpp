/////////////////////////////////////
//
// General state of the application.
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

bool GeneralState::IsGlobalShutdown()
{
    return m_GlobalShutdown;
}

void GeneralState::SetGlobalShutdown( bool globalShutdown )
{
    m_GlobalShutdown = globalShutdown;
}

}  // namespace Core