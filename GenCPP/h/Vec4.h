#ifndef __KL2EDK_AUTOGEN_Vec4__
#define __KL2EDK_AUTOGEN_Vec4__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'Vec4.h'" )
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

// KL struct 'Vec4'

struct Vec4
{
  typedef Vec4 &Result;
  typedef Vec4 const &INParam;
  typedef Vec4 &IOParam;
  typedef Vec4 &OUTParam;
  
  Float32 x;
  Float32 y;
  Float32 z;
  Float32 t;
};

inline void Traits<Vec4>::ConstructEmpty( Vec4 &val )
{
  Traits< Float32 >::ConstructEmpty( val.x );
  Traits< Float32 >::ConstructEmpty( val.y );
  Traits< Float32 >::ConstructEmpty( val.z );
  Traits< Float32 >::ConstructEmpty( val.t );
}
inline void Traits<Vec4>::ConstructCopy( Vec4 &lhs, Vec4 const &rhs )
{
  Traits< Float32 >::ConstructCopy( lhs.x, rhs.x );
  Traits< Float32 >::ConstructCopy( lhs.y, rhs.y );
  Traits< Float32 >::ConstructCopy( lhs.z, rhs.z );
  Traits< Float32 >::ConstructCopy( lhs.t, rhs.t );
}
inline void Traits<Vec4>::AssignCopy( Vec4 &lhs, Vec4 const &rhs )
{
  Traits< Float32 >::AssignCopy( lhs.x, rhs.x );
  Traits< Float32 >::AssignCopy( lhs.y, rhs.y );
  Traits< Float32 >::AssignCopy( lhs.z, rhs.z );
  Traits< Float32 >::AssignCopy( lhs.t, rhs.t );
}
inline void Traits<Vec4>::Destruct( Vec4 &val )
{
  Traits< Float32 >::Destruct( val.t );
  Traits< Float32 >::Destruct( val.z );
  Traits< Float32 >::Destruct( val.y );
  Traits< Float32 >::Destruct( val.x );
}
}}}

#endif // __KL2EDK_AUTOGEN_Vec4__
