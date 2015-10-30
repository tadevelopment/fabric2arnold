#ifndef __KL2EDK_AUTOGEN_Vec2__
#define __KL2EDK_AUTOGEN_Vec2__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'Vec2.h'" )
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

// KL struct 'Vec2'

struct Vec2
{
  typedef Vec2 &Result;
  typedef Vec2 const &INParam;
  typedef Vec2 &IOParam;
  typedef Vec2 &OUTParam;
  
  Float32 x;
  Float32 y;
};

inline void Traits<Vec2>::ConstructEmpty( Vec2 &val )
{
  Traits< Float32 >::ConstructEmpty( val.x );
  Traits< Float32 >::ConstructEmpty( val.y );
}
inline void Traits<Vec2>::ConstructCopy( Vec2 &lhs, Vec2 const &rhs )
{
  Traits< Float32 >::ConstructCopy( lhs.x, rhs.x );
  Traits< Float32 >::ConstructCopy( lhs.y, rhs.y );
}
inline void Traits<Vec2>::AssignCopy( Vec2 &lhs, Vec2 const &rhs )
{
  Traits< Float32 >::AssignCopy( lhs.x, rhs.x );
  Traits< Float32 >::AssignCopy( lhs.y, rhs.y );
}
inline void Traits<Vec2>::Destruct( Vec2 &val )
{
  Traits< Float32 >::Destruct( val.y );
  Traits< Float32 >::Destruct( val.x );
}
}}}

#endif // __KL2EDK_AUTOGEN_Vec2__
