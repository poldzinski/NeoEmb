/////////////////////////////////////
//
// Motion driver thread.
//
// 25-Aug-2018 Initial version.
//
/////////////////////////////////////

// System includes
// (none)

// C++ includes
#include "Core/GeneralState.hpp"
#include "Core/Threads/MotionThread.hpp"

// C includes
#include <wiringPi.h>

// Forward references
// (none)

namespace Core
{
namespace Threads
{

    
MotionThread::MotionThread()
{
    wiringPiSetup();
    pinMode( 7, OUTPUT );
    pinMode( 11, INPUT );
    pullUpDnControl( 11, PUD_UP );
}

void MotionThread::ProcessingThread( GeneralState* pGeneralState )
{
    while ( ( pGeneralState->IsGlobalShutdown() == false ) &&
            ( m_ShutDown == false ) )
    {
        if ( LOW == digitalRead( 11 ) )
        {
            digitalWrite( 7, HIGH );
            digitalWrite( 7, LOW );
            delay( 5 );
        }
    }
}

}  // namespace Threads
}  // namespace Core
