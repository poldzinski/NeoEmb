/////////////////////////////////////
//
// Main project file.
//
// 20-Jun-2018 Initial version.
// 21-Jun-2018 Excessive namespace removed.
//
/////////////////////////////////////

// System includes
#include <wiringPi.h>
#include <iostream>
#include <thread>

// C++ includes
#include "Core/GeneralState.hpp"
#include "Core/NetworkThread.hpp"

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
    wiringPiSetup();
    pinMode( 7, OUTPUT );
    digitalWrite( 7, HIGH );
    
    std::cout << "Starting..." << std::endl;

    Core::GeneralState* pGeneralState = new Core::GeneralState();
    assert( pGeneralState != nullptr );

    std::cout << "Creating threads..." << std::endl;

    Core::NetworkThread& rNetworkThread = Core::NetworkThread::GetInstance();
    auto threadHandle = rNetworkThread.GetThread();
    std::thread networkThreadHandle( threadHandle, rNetworkThread, pGeneralState );
    
    std::cout << "Core processing..." << std::endl;
    
    while ( pGeneralState->IsGlobalShutdown() == false )
    {
    }
    
    std::cout << "Closing threads..." << std::endl;
    
    networkThreadHandle.join();

    std::cout << "Shutting down" << std::endl;
    
    delete pGeneralState;
    
    return 0;
}
