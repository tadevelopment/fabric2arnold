#ifndef __KL2EDK_AUTOGEN_Ray__
#define __KL2EDK_AUTOGEN_Ray__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'Ray.h'" )
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
#include "Vec3.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'Ray'

struct Ray
{
  typedef Ray &Result;
  typedef Ray const &INParam;
  typedef Ray &IOParam;
  typedef Ray &OUTParam;
  
  Vec3 start;
  Vec3 direction;
};

inline void Traits<Ray>::ConstructEmpty( Ray &val )
{
  Traits< Vec3 >::ConstructEmpty( val.start );
  Traits< Vec3 >::ConstructEmpty( val.direction );
}
inline void Traits<Ray>::ConstructCopy( Ray &lhs, Ray const &rhs )
{
  Traits< Vec3 >::ConstructCopy( lhs.start, rhs.start );
  Traits< Vec3 >::ConstructCopy( lhs.direction, rhs.direction );
}
inline void Traits<Ray>::AssignCopy( Ray &lhs, Ray const &rhs )
{
  Traits< Vec3 >::AssignCopy( lhs.start, rhs.start );
  Traits< Vec3 >::AssignCopy( lhs.direction, rhs.direction );
}
inline void Traits<Ray>::Destruct( Ray &val )
{
  Traits< Vec3 >::Destruct( val.direction );
  Traits< Vec3 >::Destruct( val.start );
}
}}}

#endif // __KL2EDK_AUTOGEN_Ray__
