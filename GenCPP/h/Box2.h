#ifndef __KL2EDK_AUTOGEN_Box2__
#define __KL2EDK_AUTOGEN_Box2__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'Box2.h'" )
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
#include "Vec2.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'Box2'

struct Box2
{
  typedef Box2 &Result;
  typedef Box2 const &INParam;
  typedef Box2 &IOParam;
  
  Vec2 min;
  Vec2 max;
};

inline void Traits<Box2>::ConstructEmpty( Box2 &val )
{
  Traits< Vec2 >::ConstructEmpty( val.min );
  Traits< Vec2 >::ConstructEmpty( val.max );
}
inline void Traits<Box2>::ConstructCopy( Box2 &lhs, Box2 const &rhs )
{
  Traits< Vec2 >::ConstructCopy( lhs.min, rhs.min );
  Traits< Vec2 >::ConstructCopy( lhs.max, rhs.max );
}
inline void Traits<Box2>::AssignCopy( Box2 &lhs, Box2 const &rhs )
{
  Traits< Vec2 >::AssignCopy( lhs.min, rhs.min );
  Traits< Vec2 >::AssignCopy( lhs.max, rhs.max );
}
inline void Traits<Box2>::Destruct( Box2 &val )
{
  Traits< Vec2 >::Destruct( val.max );
  Traits< Vec2 >::Destruct( val.min );
}
}}}

#endif // __KL2EDK_AUTOGEN_Box2__
