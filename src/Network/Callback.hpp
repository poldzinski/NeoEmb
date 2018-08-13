/////////////////////////////////////
//
// Callback interface.
//
// 07-Aug-2018 Initial version.
//
/////////////////////////////////////

#ifndef CALLBACK_HPP
#define CALLBACK_HPP

// System includes
// (none)

// C++ includes
#include "Core/Thread.hpp"

// C includes
// (none)

// Forward references
// (none)

namespace Network
{

class Callback
{
    
public:
    
    typedef
        /// <summary>General callback method.</summary>
        void ( CallbackMethod )( void );
    
    /// <summary>Setting the callback.</summary>
    virtual void Set( CallbackMethod* pCallback )
    {
        m_pCallback = pCallback;
    }
    
    /// <summary>Returns the callback method.</summary>
    CallbackMethod* GetCallback() const
    {
        return m_pCallback;
    }
    
private:

    /// <summary>Callback method.</summary>
    CallbackMethod* m_pCallback = nullptr;

};
        
}  // namespace Network

#endif  // #define CALLBACK_HPP
