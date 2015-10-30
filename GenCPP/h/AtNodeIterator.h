#ifndef __KL2EDK_AUTOGEN_AtNodeIterator__
#define __KL2EDK_AUTOGEN_AtNodeIterator__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtNodeIterator.h'" )
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

// KL struct 'AtNodeIterator'

struct AtNodeIterator
{
  typedef AtNodeIterator &Result;
  typedef AtNodeIterator const &INParam;
  typedef AtNodeIterator &IOParam;
  
  Data _handle;
};

inline void Traits<AtNodeIterator>::ConstructEmpty( AtNodeIterator &val )
{
  Traits< Data >::ConstructEmpty( val._handle );
}
inline void Traits<AtNodeIterator>::ConstructCopy( AtNodeIterator &lhs, AtNodeIterator const &rhs )
{
  Traits< Data >::ConstructCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtNodeIterator>::AssignCopy( AtNodeIterator &lhs, AtNodeIterator const &rhs )
{
  Traits< Data >::AssignCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtNodeIterator>::Destruct( AtNodeIterator &val )
{
  Traits< Data >::Destruct( val._handle );
}
}}}

#endif // __KL2EDK_AUTOGEN_AtNodeIterator__
