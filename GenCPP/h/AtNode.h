#ifndef __KL2EDK_AUTOGEN_AtNode__
#define __KL2EDK_AUTOGEN_AtNode__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtNode.h'" )
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

// KL struct 'AtNode'

struct AtNode
{
  typedef AtNode &Result;
  typedef AtNode const &INParam;
  typedef AtNode &IOParam;
  typedef AtNode &OUTParam;
  
  Data _handle;
};

inline void Traits<AtNode>::ConstructEmpty( AtNode &val )
{
  Traits< Data >::ConstructEmpty( val._handle );
}
inline void Traits<AtNode>::ConstructCopy( AtNode &lhs, AtNode const &rhs )
{
  Traits< Data >::ConstructCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtNode>::AssignCopy( AtNode &lhs, AtNode const &rhs )
{
  Traits< Data >::AssignCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtNode>::Destruct( AtNode &val )
{
  Traits< Data >::Destruct( val._handle );
}
}}}

#endif // __KL2EDK_AUTOGEN_AtNode__
