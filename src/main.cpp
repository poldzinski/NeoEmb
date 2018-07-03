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

// C includes
#include <assert.h>

// Forward references
namespace Core
{
void NetworkThread( GeneralState* pGeneralState );
}

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

    std::thread networkThread = std::thread( Core::NetworkThread, pGeneralState );
    
    std::cout << "Core processing..." << std::endl;
    
    while ( pGeneralState->IsGlobalShutdown() == false )
    {
        pGeneralState->SetGlobalShutdown( true );
    }
    
    std::cout << "Closing threads..." << std::endl;
    
    networkThread.join();

    std::cout << "Shutting down" << std::endl;
    
    delete pGeneralState;
    
    return 0;
}
