#ifndef __KL2EDK_AUTOGEN_Quat_i__
#define __KL2EDK_AUTOGEN_Quat_i__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'Quat_i.h'" )
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
#include "Vec3_i.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'Quat_i'

struct Quat_i
{
  typedef Quat_i &Result;
  typedef Quat_i const &INParam;
  typedef Quat_i &IOParam;
  typedef Quat_i &OUTParam;
  
  Vec3_i v;
  SInt32 w;
};

inline void Traits<Quat_i>::ConstructEmpty( Quat_i &val )
{
  Traits< Vec3_i >::ConstructEmpty( val.v );
  Traits< SInt32 >::ConstructEmpty( val.w );
}
inline void Traits<Quat_i>::ConstructCopy( Quat_i &lhs, Quat_i const &rhs )
{
  Traits< Vec3_i >::ConstructCopy( lhs.v, rhs.v );
  Traits< SInt32 >::ConstructCopy( lhs.w, rhs.w );
}
inline void Traits<Quat_i>::AssignCopy( Quat_i &lhs, Quat_i const &rhs )
{
  Traits< Vec3_i >::AssignCopy( lhs.v, rhs.v );
  Traits< SInt32 >::AssignCopy( lhs.w, rhs.w );
}
inline void Traits<Quat_i>::Destruct( Quat_i &val )
{
  Traits< SInt32 >::Destruct( val.w );
  Traits< Vec3_i >::Destruct( val.v );
}
}}}

#endif // __KL2EDK_AUTOGEN_Quat_i__
