/////////////////////////////////////
//
// General state of the application.
//
// 03-Jul-2018 Initial version.
//
/////////////////////////////////////

#ifndef GENERALSTATE_HPP
#define GENERALSTATE_HPP

// System includes
// (none)

// C++ includes
// (none)

// C includes
// (none)

// Forward references
// (none)

namespace Core
{

class GeneralState
{

public:
    
    /// <summary>Gets the status of the global shutdown.</summary>
    /// <returns>Status of the global shutdown.</returns>
    bool IsGlobalShutdown();
    
    /// <summary>Sets the status of the global shutdown.</summary>
    /// <param name="globalShutdown">New status of the global shutdown.</param>
    void SetGlobalShutdown( bool globalShutdown );

private:    

    bool m_GlobalShutdown = false;
    
};

}  // namespace Core

#endif /* GENERALSTATE_HPP */
