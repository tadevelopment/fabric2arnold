#ifndef __KL2EDK_AUTOGEN_ArnoldKLPluginMgr_impl__
#define __KL2EDK_AUTOGEN_ArnoldKLPluginMgr_impl__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'ArnoldKLPluginMgr_impl.h'" )
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

#include "ArnoldKLPluginIMgr.h"
#include "global.h"

#include "ArnoldKLPluginMgr.h"

namespace Fabric { namespace EDK { namespace KL {

  struct ArnoldKLPluginMgr::Bits
  {
    ObjectCore __objectCore;
    Dict< String, Type > registeredPlugins;
    Object::Bits __interfaceObjectBits;
    ArnoldKLPluginIMgr::Bits __interfaceArnoldKLPluginIMgrBits;
  };
  
  inline void ArnoldKLPluginMgr::ConstructEmpty( ArnoldKLPluginMgr *self )
  {
    self->m_bits = 0;
  }
  
  inline void ArnoldKLPluginMgr::ConstructCopy( ArnoldKLPluginMgr *self, ArnoldKLPluginMgr const *other )
  {
    if ( (self->m_bits = other->m_bits) )
      AtomicUInt32Increment( &self->m_bits->__objectCore.refCount );
  }
  
  inline void ArnoldKLPluginMgr::AssignCopy( ArnoldKLPluginMgr *self, ArnoldKLPluginMgr const *other )
  {
    if ( self->m_bits != other->m_bits )
    {
      Destruct( self );
      ConstructCopy( self, other );
    }
  }
  
  inline void ArnoldKLPluginMgr::Destruct( ArnoldKLPluginMgr *self )
  {
    if ( self->m_bits
      && AtomicUInt32DecrementAndGetValue( &self->m_bits->__objectCore.refCount ) == 0 )
    {
      ObjectCore *objectCorePtr = &self->m_bits->__objectCore;
      self->m_bits->__objectCore.lTableSwapPtrPtr->get()->lifecycleDestroy(
        &objectCorePtr
        );
    }
  }
  
  inline ArnoldKLPluginMgr::ArnoldKLPluginMgr()
  {
    ConstructEmpty( this );
  }
  
  inline ArnoldKLPluginMgr ArnoldKLPluginMgr::Create()
  {
    static KL::SwapPtr<void> const *sp = 0;
    if ( !sp )
    {
      sp = static_cast<KL::SwapPtr<void> const *>(
        s_callbacks.m_lookupGlobalSymbol(
          "sp.function.kl.OO_ArnoldKLPluginMgr.createEmpty.io_AS0.OO_ArnoldKLPluginMgr",
          75
          )
        );
      if ( !sp )
        throwException(
          "EDK internal error: failed to look up '%s'",
          "sp.function.kl.OO_ArnoldKLPluginMgr.createEmpty.io_AS0.OO_ArnoldKLPluginMgr"
          );
    }
    void (*createFuncPtr)(void *) = ((void (*)(void *))sp->get());
    if ( !createFuncPtr )
      throwException(
        "EDK internal error: target of '%s' is NULL",
        "sp.function.kl.OO_ArnoldKLPluginMgr.createEmpty.io_AS0.OO_ArnoldKLPluginMgr"
        );
    ArnoldKLPluginMgr result;
    createFuncPtr( &result );
    return result;
  }
  
  inline ArnoldKLPluginMgr::ArnoldKLPluginMgr( ArnoldKLPluginMgr const &that )
  {
    ConstructCopy( this, &that );
  }
  
  inline ArnoldKLPluginMgr &ArnoldKLPluginMgr::operator =( ArnoldKLPluginMgr const &that )
  {
    AssignCopy( this, &that );
    return *this;
  }
  
  inline ArnoldKLPluginMgr::~ArnoldKLPluginMgr()
  {
    Destruct( this );
  }
  
  inline void ArnoldKLPluginMgr::appendDesc( String::IOParam string ) const
  {
    if ( m_bits )
    {
      ObjectCore *objectCorePtr = &m_bits->__objectCore;
      objectCorePtr->lTableSwapPtrPtr->get()->appendDesc(
        &objectCorePtr, string
        );
    }
    else string.append( "null", 4 );
  }
  inline uint32_t ArnoldKLPluginMgr::getRefCount() const
  {
    if ( m_bits )
    {
      ObjectCore *objectCorePtr = &m_bits->__objectCore;
      return objectCorePtr->refCount;
    }
    else return 0;
  }
  inline Type ArnoldKLPluginMgr::getType() const
  {
    if ( m_bits )
    {
      return Type( m_bits->__objectCore.typeInfoSwapPtrPtr->get() );
    }
    else return Type();
  }
  
  inline bool ArnoldKLPluginMgr::isValid() const
  {
    return !!m_bits;
  }
  
  inline ArnoldKLPluginMgr::operator bool() const
  {
    return isValid();
  }
  
  inline bool ArnoldKLPluginMgr::operator !() const
  {
    return !isValid();
  }
  
  inline ArnoldKLPluginMgr::Bits *ArnoldKLPluginMgr::operator ->()
  {
    return static_cast<ArnoldKLPluginMgr::Bits *>( m_bits );
  }
  
  inline ArnoldKLPluginMgr::Bits const *ArnoldKLPluginMgr::operator ->() const
  {
    return static_cast<ArnoldKLPluginMgr::Bits const *>( m_bits );
  }
  
  inline bool ArnoldKLPluginMgr::operator ==( INParam that )
  {
    return m_bits == that.m_bits;
  }
  
  inline bool ArnoldKLPluginMgr::operator !=( INParam that )
  {
    return m_bits != that.m_bits;
  }
  
  // Methods for 'Object'
  // Methods for 'ArnoldKLPluginIMgr'
  
  inline void ArnoldKLPluginMgr::RegisterKLPlugin(
    Traits< Type >::INParam kltype,
    Traits< SInt32 >::INParam type,
    Traits< UInt8 >::INParam output_type,
    Traits< String >::INParam name,
    Traits< String >::INParam filename
    )
  {
    ObjectCore *objectCorePtr = &static_cast<ArnoldKLPluginMgr::Bits *>( m_bits )->__objectCore;
    static_cast<ArnoldKLPluginMgr::Bits *>( m_bits )->__interfaceArnoldKLPluginIMgrBits.vTableSwapPtrPtr->get()->RegisterKLPlugin_90A2D737E448DE49F8A0B7116473A700(
      &objectCorePtr,
      kltype,
      type,
      output_type,
      name,
      filename
      );
  }
  
  inline a2fPluginBase ArnoldKLPluginMgr::CreateInstance(
    Traits< String >::INParam name
    ) const
  {
    a2fPluginBase _result;
    ObjectCore const *objectCorePtr = &static_cast<ArnoldKLPluginMgr::Bits *>( m_bits )->__objectCore;
    static_cast<ArnoldKLPluginMgr::Bits *>( m_bits )->__interfaceArnoldKLPluginIMgrBits.vTableSwapPtrPtr->get()->CreateInstance_773E5E5E62015AD2910DFDAB2A02C783(
      _result,
      &objectCorePtr,
      name
      );
    return _result;
  }
  
  inline a2fPluginShader ArnoldKLPluginMgr::CastToShader(
    Traits< a2fPluginBase >::INParam instance
    ) const
  {
    a2fPluginShader _result;
    ObjectCore const *objectCorePtr = &static_cast<ArnoldKLPluginMgr::Bits *>( m_bits )->__objectCore;
    static_cast<ArnoldKLPluginMgr::Bits *>( m_bits )->__interfaceArnoldKLPluginIMgrBits.vTableSwapPtrPtr->get()->CastToShader_06C73D3783B3F9939383B0F5BA0C3FC4(
      _result,
      &objectCorePtr,
      instance
      );
    return _result;
  }

}}}

#endif // __KL2EDK_AUTOGEN_ArnoldKLPluginMgr_impl__
