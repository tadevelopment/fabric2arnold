#ifndef __KL2EDK_AUTOGEN_AtOutputIterator__
#define __KL2EDK_AUTOGEN_AtOutputIterator__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtOutputIterator.h'" )
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

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'AtOutputIterator'

struct AtOutputIterator
{
  typedef AtOutputIterator &Result;
  typedef AtOutputIterator const &INParam;
  typedef AtOutputIterator &IOParam;
  
  Data _handle;
};

inline void Traits<AtOutputIterator>::ConstructEmpty( AtOutputIterator &val )
{
  Traits< Data >::ConstructEmpty( val._handle );
}
inline void Traits<AtOutputIterator>::ConstructCopy( AtOutputIterator &lhs, AtOutputIterator const &rhs )
{
  Traits< Data >::ConstructCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtOutputIterator>::AssignCopy( AtOutputIterator &lhs, AtOutputIterator const &rhs )
{
  Traits< Data >::AssignCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtOutputIterator>::Destruct( AtOutputIterator &val )
{
  Traits< Data >::Destruct( val._handle );
}
}}}

#endif // __KL2EDK_AUTOGEN_AtOutputIterator__