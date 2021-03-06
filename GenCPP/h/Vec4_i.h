#ifndef __KL2EDK_AUTOGEN_Vec4_i__
#define __KL2EDK_AUTOGEN_Vec4_i__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'Vec4_i.h'" )
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

// KL struct 'Vec4_i'

struct Vec4_i
{
  typedef Vec4_i &Result;
  typedef Vec4_i const &INParam;
  typedef Vec4_i &IOParam;
  typedef Vec4_i &OUTParam;
  
  SInt32 x;
  SInt32 y;
  SInt32 z;
  SInt32 t;
};

inline void Traits<Vec4_i>::ConstructEmpty( Vec4_i &val )
{
  Traits< SInt32 >::ConstructEmpty( val.x );
  Traits< SInt32 >::ConstructEmpty( val.y );
  Traits< SInt32 >::ConstructEmpty( val.z );
  Traits< SInt32 >::ConstructEmpty( val.t );
}
inline void Traits<Vec4_i>::ConstructCopy( Vec4_i &lhs, Vec4_i const &rhs )
{
  Traits< SInt32 >::ConstructCopy( lhs.x, rhs.x );
  Traits< SInt32 >::ConstructCopy( lhs.y, rhs.y );
  Traits< SInt32 >::ConstructCopy( lhs.z, rhs.z );
  Traits< SInt32 >::ConstructCopy( lhs.t, rhs.t );
}
inline void Traits<Vec4_i>::AssignCopy( Vec4_i &lhs, Vec4_i const &rhs )
{
  Traits< SInt32 >::AssignCopy( lhs.x, rhs.x );
  Traits< SInt32 >::AssignCopy( lhs.y, rhs.y );
  Traits< SInt32 >::AssignCopy( lhs.z, rhs.z );
  Traits< SInt32 >::AssignCopy( lhs.t, rhs.t );
}
inline void Traits<Vec4_i>::Destruct( Vec4_i &val )
{
  Traits< SInt32 >::Destruct( val.t );
  Traits< SInt32 >::Destruct( val.z );
  Traits< SInt32 >::Destruct( val.y );
  Traits< SInt32 >::Destruct( val.x );
}
}}}

#endif // __KL2EDK_AUTOGEN_Vec4_i__
