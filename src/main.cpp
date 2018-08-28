/////////////////////////////////////
//
// Main project file.
//
// 20-Jun-2018 Initial version.
// 21-Jun-2018 Excessive namespace removed.
//
/////////////////////////////////////

// System includes
#include <iostream>
#include <thread>

// C++ includes
#include "Core/GeneralState.hpp"
#include "Core/Threads/NetworkThread.hpp"
#include "Core/Threads/MotionThread.hpp"

// C includes
#include <assert.h>

// Forward references
// (none)

/// <summary>Main entry point.</summary>
/// <param name="argumentsCount">Number of input arguments.</param>
/// <param name="ppArguments">Input arguments.</param>
/// <returns>Exit result of the application.</returns>
int main( int, char** )
{
    std::cout << "Starting..." << std::endl;

    Core::GeneralState* pGeneralState = new Core::GeneralState();
    assert( pGeneralState != nullptr );

    std::cout << "Creating threads..." << std::endl;

    const Core::Threads::NetworkThread& rNetworkThread = Core::Threads::NetworkThread::GetInstance();
    std::thread networkThreadHandle( rNetworkThread.GetThread(), rNetworkThread, pGeneralState );
    
    const Core::Threads::MotionThread& rMotionThread = Core::Threads::MotionThread::GetInstance();
    std::thread motionThreadHandle( rMotionThread.GetThread(), rMotionThread, pGeneralState );
    
    std::cout << "Core processing..." << std::endl;
    
    while ( pGeneralState->IsGlobalShutdown() == false )
    {
    }
    
    std::cout << "Closing threads..." << std::endl;
    
    motionThreadHandle.join();
    networkThreadHandle.join();

    std::cout << "Shutting down" << std::endl;
    
    delete pGeneralState;
    
    return 0;
}
