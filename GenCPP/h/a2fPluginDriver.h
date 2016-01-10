#ifndef __KL2EDK_AUTOGEN_a2fPluginDriver__
#define __KL2EDK_AUTOGEN_a2fPluginDriver__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'a2fPluginDriver.h'" )
#endif

////////////////////////////////////////////////////////////////
// THIS FILE IS AUTOMATICALLY GENERATED -- DO NOT MODIFY!!
////////////////////////////////////////////////////////////////
// Generated by kl2edk version 1.15.3
////////////////////////////////////////////////////////////////

#include <FabricEDK.h>
#if FABRIC_EDK_VERSION_MAJ != 1 || FABRIC_EDK_VERSION_MIN != 15
# error "This file needs to be rebuilt for the current EDK version!"
#endif

#include "global.h"
#include "AtNode.h"
#include "AtOutputIterator.h"
#include "Box2.h"
#include "AtAOVSampleIterator.h"

namespace Fabric { namespace EDK { namespace KL {

// KL interface 'a2fPluginDriver'

class a2fPluginDriver
{
public:
  
  struct VTable
  {
    Boolean (*DriverSupportsPixelType_F107F82F9AC31031B3126131AA0F25F6)(
      ObjectCore const * const *objectCorePtr,
      Traits< AtNode >::INParam node,
      Traits< UInt8 >::INParam type
      );
    void (*DriverExtension_49E9C8F6506DEEBA796F727D31C46E26)(
      Traits< VariableArray< String > >::Result _result,
      ObjectCore const * const *objectCorePtr
      );
    void (*DriverOpen_8534A500502E740BE352B84EA1EA7FF5)(
      ObjectCore * const *objectCorePtr,
      Traits< AtNode >::IOParam node,
      Traits< AtOutputIterator >::IOParam iterator,
      Traits< Box2 >::INParam display_window,
      Traits< Box2 >::INParam data_window,
      Traits< SInt32 >::INParam bucket_size
      );
    Boolean (*DriverNeedsBucket_B0125EA272AB3DD235F09093A0A9B6B0)(
      ObjectCore const * const *objectCorePtr,
      Traits< AtNode >::IOParam node,
      Traits< SInt32 >::INParam bucket_xo,
      Traits< SInt32 >::INParam bucket_yo,
      Traits< SInt32 >::INParam bucket_size_x,
      Traits< SInt32 >::INParam bucket_size_y,
      Traits< SInt32 >::INParam tid
      );
    void (*DriverPrepareBucket_AC1A6F5269D9B2841432ABBED0800069)(
      ObjectCore * const *objectCorePtr,
      Traits< AtNode >::IOParam node,
      Traits< SInt32 >::INParam bucket_xo,
      Traits< SInt32 >::INParam bucket_yo,
      Traits< SInt32 >::INParam bucket_size_x,
      Traits< SInt32 >::INParam bucket_size_y,
      Traits< SInt32 >::INParam tid
      );
    void (*DriverProcessBucket_46C32C972B452C0BD88426D4DC154CED)(
      ObjectCore * const *objectCorePtr,
      Traits< AtNode >::IOParam node,
      Traits< AtOutputIterator >::IOParam iterator,
      Traits< AtAOVSampleIterator >::IOParam sample_iterator,
      Traits< SInt32 >::INParam bucket_xo,
      Traits< SInt32 >::INParam bucket_yo,
      Traits< SInt32 >::INParam bucket_size_x,
      Traits< SInt32 >::INParam bucket_size_y,
      Traits< SInt32 >::INParam tid
      );
    void (*DriverWriteBucket_C677E5B6B1E033561E1AC96999B49017)(
      ObjectCore * const *objectCorePtr,
      Traits< AtNode >::IOParam node,
      Traits< AtOutputIterator >::IOParam iterator,
      Traits< AtAOVSampleIterator >::IOParam sample_iterator,
      Traits< SInt32 >::INParam bucket_xo,
      Traits< SInt32 >::INParam bucket_yo,
      Traits< SInt32 >::INParam bucket_size_x,
      Traits< SInt32 >::INParam bucket_size_y
      );
    void (*DriverClose_169C657A109CC95C71C5D9047222A633)(
      ObjectCore * const *objectCorePtr,
      Traits< AtNode >::IOParam node,
      Traits< AtOutputIterator >::IOParam iterator
      );
  };
  
  struct Bits
  {
    ObjectCore *objectCorePtr;
    SwapPtr<VTable const> const *vTableSwapPtrPtr;
  } *m_bits;
  
protected:
  
  friend struct Traits< a2fPluginDriver >;
  
  static void ConstructEmpty( a2fPluginDriver *self )
  {
    self->m_bits = 0;
  }
  
  static void ConstructCopy( a2fPluginDriver *self, a2fPluginDriver const *other )
  {
    if ( (self->m_bits = other->m_bits) )
      AtomicUInt32Increment( &self->m_bits->objectCorePtr->refCount );
  }
  
  static void AssignCopy( a2fPluginDriver *self, a2fPluginDriver const *other )
  {
    if ( self->m_bits != other->m_bits )
    {
      Destruct( self );
      ConstructCopy( self, other );
    }
  }
  
  static void Destruct( a2fPluginDriver *self )
  {
    if ( self->m_bits
      && AtomicUInt32DecrementAndGetValue( &self->m_bits->objectCorePtr->refCount ) == 0 )
    {
      self->m_bits->objectCorePtr->lTableSwapPtrPtr->get()->lifecycleDestroy(
        &self->m_bits->objectCorePtr
        );
    }
  }
  
public: 
  
  typedef a2fPluginDriver &Result;
  typedef a2fPluginDriver const &INParam;
  typedef a2fPluginDriver &IOParam;
  
  a2fPluginDriver()
  {
    ConstructEmpty( this );
  }
  
  a2fPluginDriver( a2fPluginDriver const &that )
  {
    ConstructCopy( this, &that );
  }
  
  a2fPluginDriver &operator =( a2fPluginDriver const &that )
  {
    AssignCopy( this, &that );
    return *this;
  }
  
  ~a2fPluginDriver()
  {
    Destruct( this );
  }
  
  void appendDesc( String::IOParam string ) const
  {
    if ( m_bits )
      m_bits->objectCorePtr->lTableSwapPtrPtr->get()->appendDesc( &m_bits->objectCorePtr, string );
    else string.append( "null", 4 );
  }
  
  bool isValid() const
  {
    return !!m_bits;
  }
  
  operator bool() const
  {
    return isValid();
  }
  
  bool operator !() const
  {
    return !isValid();
  }
  
  bool operator ==( INParam that )
  {
    return m_bits == that.m_bits;
  }
  
  bool operator !=( INParam that )
  {
    return m_bits != that.m_bits;
  }
  
  
  Boolean DriverSupportsPixelType(
    Traits< AtNode >::INParam node,
    Traits< UInt8 >::INParam type
    ) const
  {
    Boolean _result;
    _result = m_bits->vTableSwapPtrPtr->get()->DriverSupportsPixelType_F107F82F9AC31031B3126131AA0F25F6(
      &m_bits->objectCorePtr,
      node,
      type
      );
    return _result;
  }
  
  VariableArray< String > DriverExtension(
    ) const
  {
    VariableArray< String > _result;
    m_bits->vTableSwapPtrPtr->get()->DriverExtension_49E9C8F6506DEEBA796F727D31C46E26(
      _result,
      &m_bits->objectCorePtr
      );
    return _result;
  }
  
  void DriverOpen(
    Traits< AtNode >::IOParam node,
    Traits< AtOutputIterator >::IOParam iterator,
    Traits< Box2 >::INParam display_window,
    Traits< Box2 >::INParam data_window,
    Traits< SInt32 >::INParam bucket_size
    )
  {
    m_bits->vTableSwapPtrPtr->get()->DriverOpen_8534A500502E740BE352B84EA1EA7FF5(
      &m_bits->objectCorePtr,
      node,
      iterator,
      display_window,
      data_window,
      bucket_size
      );
  }
  
  Boolean DriverNeedsBucket(
    Traits< AtNode >::IOParam node,
    Traits< SInt32 >::INParam bucket_xo,
    Traits< SInt32 >::INParam bucket_yo,
    Traits< SInt32 >::INParam bucket_size_x,
    Traits< SInt32 >::INParam bucket_size_y,
    Traits< SInt32 >::INParam tid
    ) const
  {
    Boolean _result;
    _result = m_bits->vTableSwapPtrPtr->get()->DriverNeedsBucket_B0125EA272AB3DD235F09093A0A9B6B0(
      &m_bits->objectCorePtr,
      node,
      bucket_xo,
      bucket_yo,
      bucket_size_x,
      bucket_size_y,
      tid
      );
    return _result;
  }
  
  void DriverPrepareBucket(
    Traits< AtNode >::IOParam node,
    Traits< SInt32 >::INParam bucket_xo,
    Traits< SInt32 >::INParam bucket_yo,
    Traits< SInt32 >::INParam bucket_size_x,
    Traits< SInt32 >::INParam bucket_size_y,
    Traits< SInt32 >::INParam tid
    )
  {
    m_bits->vTableSwapPtrPtr->get()->DriverPrepareBucket_AC1A6F5269D9B2841432ABBED0800069(
      &m_bits->objectCorePtr,
      node,
      bucket_xo,
      bucket_yo,
      bucket_size_x,
      bucket_size_y,
      tid
      );
  }
  
  void DriverProcessBucket(
    Traits< AtNode >::IOParam node,
    Traits< AtOutputIterator >::IOParam iterator,
    Traits< AtAOVSampleIterator >::IOParam sample_iterator,
    Traits< SInt32 >::INParam bucket_xo,
    Traits< SInt32 >::INParam bucket_yo,
    Traits< SInt32 >::INParam bucket_size_x,
    Traits< SInt32 >::INParam bucket_size_y,
    Traits< SInt32 >::INParam tid
    )
  {
    m_bits->vTableSwapPtrPtr->get()->DriverProcessBucket_46C32C972B452C0BD88426D4DC154CED(
      &m_bits->objectCorePtr,
      node,
      iterator,
      sample_iterator,
      bucket_xo,
      bucket_yo,
      bucket_size_x,
      bucket_size_y,
      tid
      );
  }
  
  void DriverWriteBucket(
    Traits< AtNode >::IOParam node,
    Traits< AtOutputIterator >::IOParam iterator,
    Traits< AtAOVSampleIterator >::IOParam sample_iterator,
    Traits< SInt32 >::INParam bucket_xo,
    Traits< SInt32 >::INParam bucket_yo,
    Traits< SInt32 >::INParam bucket_size_x,
    Traits< SInt32 >::INParam bucket_size_y
    )
  {
    m_bits->vTableSwapPtrPtr->get()->DriverWriteBucket_C677E5B6B1E033561E1AC96999B49017(
      &m_bits->objectCorePtr,
      node,
      iterator,
      sample_iterator,
      bucket_xo,
      bucket_yo,
      bucket_size_x,
      bucket_size_y
      );
  }
  
  void DriverClose(
    Traits< AtNode >::IOParam node,
    Traits< AtOutputIterator >::IOParam iterator
    )
  {
    m_bits->vTableSwapPtrPtr->get()->DriverClose_169C657A109CC95C71C5D9047222A633(
      &m_bits->objectCorePtr,
      node,
      iterator
      );
  }
};

inline void Traits<a2fPluginDriver>::ConstructEmpty( a2fPluginDriver &val )
{
  a2fPluginDriver::ConstructEmpty( &val );
}
inline void Traits<a2fPluginDriver>::ConstructCopy( a2fPluginDriver &lhs, a2fPluginDriver const &rhs )
{
  a2fPluginDriver::ConstructCopy( &lhs, &rhs );
}
inline void Traits<a2fPluginDriver>::AssignCopy( a2fPluginDriver &lhs, a2fPluginDriver const &rhs )
{
  a2fPluginDriver::AssignCopy( &lhs, &rhs );
}
inline void Traits<a2fPluginDriver>::Destruct( a2fPluginDriver &val )
{
  a2fPluginDriver::Destruct( &val );
}

}}}

#endif // __KL2EDK_AUTOGEN_a2fPluginDriver__
