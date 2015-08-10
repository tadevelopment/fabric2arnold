#ifndef __KL2EDK_AUTOGEN_AtShaderGlobals__
#define __KL2EDK_AUTOGEN_AtShaderGlobals__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtShaderGlobals.h'" )
#endif

////////////////////////////////////////////////////////////////
// THIS FILE IS AUTOMATICALLY GENERATED -- DO NOT MODIFY!!
////////////////////////////////////////////////////////////////
// Generated by kl2edk version 2.1.0-alpha2
////////////////////////////////////////////////////////////////

#include <FabricEDK.h>
#if FABRIC_EDK_VERSION_MAJ != 2 || FABRIC_EDK_VERSION_MIN != 1
# error "This file needs to be rebuilt for the current EDK version!"
#endif

#include "global.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'AtShaderGlobals'
// Defined at R:\src\HordeSoftware\demoarnoldapp\fabric2arnold\GenKL/\_opaque_types.kl:56:1

struct AtShaderGlobals
{
  typedef AtShaderGlobals &Result;
  typedef AtShaderGlobals const &INParam;
  typedef AtShaderGlobals &IOParam;
  typedef AtShaderGlobals &OUTParam;
  
  Data _handle;
};

inline void Traits<AtShaderGlobals>::ConstructEmpty( AtShaderGlobals &val )
{
  Traits< Data >::ConstructEmpty( val._handle );
}
inline void Traits<AtShaderGlobals>::ConstructCopy( AtShaderGlobals &lhs, AtShaderGlobals const &rhs )
{
  Traits< Data >::ConstructCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtShaderGlobals>::AssignCopy( AtShaderGlobals &lhs, AtShaderGlobals const &rhs )
{
  Traits< Data >::AssignCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtShaderGlobals>::Destruct( AtShaderGlobals &val )
{
  Traits< Data >::Destruct( val._handle );
}
}}}

#endif // __KL2EDK_AUTOGEN_AtShaderGlobals__
