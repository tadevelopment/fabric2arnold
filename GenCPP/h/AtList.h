#ifndef __KL2EDK_AUTOGEN_AtList__
#define __KL2EDK_AUTOGEN_AtList__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtList.h'" )
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

// KL struct 'AtList'

struct AtList
{
  typedef AtList &Result;
  typedef AtList const &INParam;
  typedef AtList &IOParam;
  typedef AtList &OUTParam;
  
  Data _handle;
};

inline void Traits<AtList>::ConstructEmpty( AtList &val )
{
  Traits< Data >::ConstructEmpty( val._handle );
}
inline void Traits<AtList>::ConstructCopy( AtList &lhs, AtList const &rhs )
{
  Traits< Data >::ConstructCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtList>::AssignCopy( AtList &lhs, AtList const &rhs )
{
  Traits< Data >::AssignCopy( lhs._handle, rhs._handle );
}
inline void Traits<AtList>::Destruct( AtList &val )
{
  Traits< Data >::Destruct( val._handle );
}
}}}

#endif // __KL2EDK_AUTOGEN_AtList__
