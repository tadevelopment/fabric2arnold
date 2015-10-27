#ifndef __KL2EDK_AUTOGEN_AtDisplayCallback_impl__
#define __KL2EDK_AUTOGEN_AtDisplayCallback_impl__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtDisplayCallback_impl.h'" )
#endif

////////////////////////////////////////////////////////////////
// THIS FILE IS AUTOMATICALLY GENERATED -- DO NOT MODIFY!!
////////////////////////////////////////////////////////////////
// Generated by kl2edk version 2.1.0-alpha3
////////////////////////////////////////////////////////////////

#include <FabricEDK.h>
#if FABRIC_EDK_VERSION_MAJ != 2 || FABRIC_EDK_VERSION_MIN != 1
# error "This file needs to be rebuilt for the current EDK version!"
#endif

#include "RGBA.h"
#include "Color.h"
#include "global.h"

#include "AtDisplayCallback.h"

namespace Fabric { namespace EDK { namespace KL {

  inline void AtDisplayCallback::ConstructEmpty( AtDisplayCallback *self )
  {
    self->m_bits = 0;
  }
  
  inline void AtDisplayCallback::ConstructCopy( AtDisplayCallback *self, AtDisplayCallback const *other )
  {
    if ( (self->m_bits = other->m_bits) )
      AtomicUInt32Increment( &self->m_bits->objectCorePtr->refCount );
  }
  
  inline void AtDisplayCallback::AssignCopy( AtDisplayCallback *self, AtDisplayCallback const *other )
  {
    if ( self->m_bits != other->m_bits )
    {
      Destruct( self );
      ConstructCopy( self, other );
    }
  }
  
  inline void AtDisplayCallback::Destruct( AtDisplayCallback *self )
  {
    if ( self->m_bits
      && AtomicUInt32DecrementAndGetValue( &self->m_bits->objectCorePtr->refCount ) == 0 )
    {
      self->m_bits->objectCorePtr->lTableSwapPtrPtr->get()->lifecycleDestroy(
        &self->m_bits->objectCorePtr
        );
    }
  }
  
  inline AtDisplayCallback::AtDisplayCallback()
  {
    ConstructEmpty( this );
  }
  
  inline AtDisplayCallback::AtDisplayCallback( AtDisplayCallback const &that )
  {
    ConstructCopy( this, &that );
  }
  
  inline AtDisplayCallback &AtDisplayCallback::operator =( AtDisplayCallback const &that )
  {
    AssignCopy( this, &that );
    return *this;
  }
  
  inline AtDisplayCallback::~AtDisplayCallback()
  {
    Destruct( this );
  }
  
  inline void AtDisplayCallback::appendDesc( String::IOParam string ) const
  {
    if ( m_bits )
      m_bits->objectCorePtr->lTableSwapPtrPtr->get()->appendDesc( &m_bits->objectCorePtr, string );
    else string.append( "null", 4 );
  }
  
  inline bool AtDisplayCallback::klInterfaceIsValid() const
  {
    return !!m_bits;
  }
  
  inline AtDisplayCallback::operator bool() const
  {
    return klInterfaceIsValid();
  }
  
  inline bool AtDisplayCallback::operator !() const
  {
    return !klInterfaceIsValid();
  }
  
  inline bool AtDisplayCallback::operator ==( INParam that )
  {
    return m_bits == that.m_bits;
  }
  
  inline bool AtDisplayCallback::operator !=( INParam that )
  {
    return m_bits != that.m_bits;
  }
  
  
  inline void AtDisplayCallback::Callback(
    Traits< UInt32 >::INParam arg0,
    Traits< UInt32 >::INParam arg1,
    Traits< UInt32 >::INParam arg2,
    Traits< UInt32 >::INParam arg3,
    Traits< ExternalArray< RGBA > >::INParam arg4,
    Traits< ExternalArray< Color > >::INParam arg5,
    Traits< Data >::INParam arg6
    )
  {
    m_bits->vTableSwapPtrPtr->get()->Callback_E253B18F7761677298CCF3C32F927BFD(
      &m_bits->objectCorePtr,
      arg0,
      arg1,
      arg2,
      arg3,
      arg4,
      arg5,
      arg6
      );
  }
}}}

#endif // __KL2EDK_AUTOGEN_AtDisplayCallback_impl__
