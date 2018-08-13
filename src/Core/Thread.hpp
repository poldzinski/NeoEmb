/////////////////////////////////////
//
// Interface of a thread.
//
//  2-Aug-2018 Initial version.
//
/////////////////////////////////////

#ifndef THREAD_HPP
#define THREAD_HPP

// System includes
// (none)

// C++ includes
#include "Core/GeneralState.hpp"

// C includes
// (none)

// Forward references
// (none)

namespace Core
{

class Thread
{

public:
    
    typedef
        /// <summary>Handle of a thread.</summary>
        /// <param name="pGeneralState">General state of the application.</param>
        void ( Thread::*ThreadHandle )( GeneralState* pGeneralState );
    
    /// <summary>Gets the processing thread.</summary>
    /// <returns>A pointer to the thread.</returns>
    ThreadHandle GetThread() const
    {
        return &Core::Thread::ProcessingThread;
    }
    
protected:

    /// <summary>Body of the processing thread.</summary>
    /// <param name="pGeneralState">General state of the application.</param>
    virtual void ProcessingThread( GeneralState* pGeneralState ) = 0;

    /// <summary>Shutting down flag.</summary>
    bool m_ShutDown = false;
};

}  // namespace Core

#endif // THREAD_HPP
