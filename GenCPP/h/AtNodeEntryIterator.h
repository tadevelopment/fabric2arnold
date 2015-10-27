#ifndef __KL2EDK_AUTOGEN_AtNodeEntryIterator__
#define __KL2EDK_AUTOGEN_AtNodeEntryIterator__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtNodeEntryIterator.h'" )
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

// KL struct 'AtNodeEntryIterator'
// Defined at R:\src\HordeSoftware\Fabric2Arnold\GenKL/\_opaque_types.kl:72:1

struct AtNodeEntryIterator
{
  typedef AtNodeEntryIterator &Result;
  typedef AtNodeEntryIterator const &INParam;
  typedef AtNodeEntryIterator &IOParam;
  typedef AtNodeEntryIterator &OUTParam;
  
  Data _handle;
};

inline void Traits<AtNodeEntryIterator>::ConstructEmpty( AtNodeEntryIterator &val )
{
  Traits< Data >::ConstructEmpty( val._handle );
}
inline void Traits<AtNodeEntryIterator>::ConstructCopy( AtNodeEntryIterator &lhs, AtNodeEntryIterator const &rhs )
{
  Traits< Data >::ConstructCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtNodeEntryIterator>::AssignCopy( AtNodeEntryIterator &lhs, AtNodeEntryIterator const &rhs )
{
  Traits< Data >::AssignCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtNodeEntryIterator>::Destruct( AtNodeEntryIterator &val )
{
  Traits< Data >::Destruct( val._handle );
}
}}}

#endif // __KL2EDK_AUTOGEN_AtNodeEntryIterator__
