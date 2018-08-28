/////////////////////////////////////
//
// Motion driver thread.
//
// 25-Aug-2018 Initial version.
//
/////////////////////////////////////

#ifndef MOTION_THREAD_HPP
#define MOTION_THREAD_HPP

// System includes
// (none)

// C++ includes
#include "Core/Thread.hpp"

// C includes
// (none)

// Forward references
namespace Core
{
class GeneralState;
}

namespace Core
{
namespace Threads
{

class MotionThread: public Thread
{

public:
    
    /// <summary>Gets the single instance of the class.</summary>
    /// <returns>The instance.</returns>
    static MotionThread& GetInstance()
    {
        static MotionThread instance;
        return instance;
    }
    
private:
    
    /// <summary>Constructor.</summary>
    MotionThread();
    
    /// <summary>Body of the processing thread.</summary>
    /// <param name="pGeneralState">General state of the application.</param>
    virtual void ProcessingThread( GeneralState* pGeneralState );

};

}  // namespace Threads
}  // namespace Core

#endif // MOTION_THREAD_HPP
