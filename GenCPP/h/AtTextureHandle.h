#ifndef __KL2EDK_AUTOGEN_AtTextureHandle__
#define __KL2EDK_AUTOGEN_AtTextureHandle__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtTextureHandle.h'" )
#endif

////////////////////////////////////////////////////////////////
// THIS FILE IS AUTOMATICALLY GENERATED -- DO NOT MODIFY!!
////////////////////////////////////////////////////////////////
// Generated by kl2edk version 2.0.0
////////////////////////////////////////////////////////////////

#include <FabricEDK.h>
#if FABRIC_EDK_VERSION_MAJ != 2 || FABRIC_EDK_VERSION_MIN != 0
# error "This file needs to be rebuilt for the current EDK version!"
#endif

#include "global.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'AtTextureHandle'

struct AtTextureHandle
{
  typedef AtTextureHandle &Result;
  typedef AtTextureHandle const &INParam;
  typedef AtTextureHandle &IOParam;
  typedef AtTextureHandle &OUTParam;
  
  Data _handle;
};

inline void Traits<AtTextureHandle>::ConstructEmpty( AtTextureHandle &val )
{
  Traits< Data >::ConstructEmpty( val._handle );
}
inline void Traits<AtTextureHandle>::ConstructCopy( AtTextureHandle &lhs, AtTextureHandle const &rhs )
{
  Traits< Data >::ConstructCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtTextureHandle>::AssignCopy( AtTextureHandle &lhs, AtTextureHandle const &rhs )
{
  Traits< Data >::AssignCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtTextureHandle>::Destruct( AtTextureHandle &val )
{
  Traits< Data >::Destruct( val._handle );
}
}}}

#endif // __KL2EDK_AUTOGEN_AtTextureHandle__
