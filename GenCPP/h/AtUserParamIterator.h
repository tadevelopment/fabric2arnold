#ifndef __KL2EDK_AUTOGEN_AtUserParamIterator__
#define __KL2EDK_AUTOGEN_AtUserParamIterator__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtUserParamIterator.h'" )
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

#include "global.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'AtUserParamIterator'
// Defined at R:\src\HordeSoftware\Fabric2Arnold\GenKL/\_opaque_types.kl:46:1

struct AtUserParamIterator
{
  typedef AtUserParamIterator &Result;
  typedef AtUserParamIterator const &INParam;
  typedef AtUserParamIterator &IOParam;
  typedef AtUserParamIterator &OUTParam;
  
  Data _handle;
};

inline void Traits<AtUserParamIterator>::ConstructEmpty( AtUserParamIterator &val )
{
  Traits< Data >::ConstructEmpty( val._handle );
}
inline void Traits<AtUserParamIterator>::ConstructCopy( AtUserParamIterator &lhs, AtUserParamIterator const &rhs )
{
  Traits< Data >::ConstructCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtUserParamIterator>::AssignCopy( AtUserParamIterator &lhs, AtUserParamIterator const &rhs )
{
  Traits< Data >::AssignCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtUserParamIterator>::Destruct( AtUserParamIterator &val )
{
  Traits< Data >::Destruct( val._handle );
}
}}}

#endif // __KL2EDK_AUTOGEN_AtUserParamIterator__
