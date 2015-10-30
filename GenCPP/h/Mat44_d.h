#ifndef __KL2EDK_AUTOGEN_Mat44_d__
#define __KL2EDK_AUTOGEN_Mat44_d__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'Mat44_d.h'" )
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
#include "Vec4_d.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'Mat44_d'

struct Mat44_d
{
  typedef Mat44_d &Result;
  typedef Mat44_d const &INParam;
  typedef Mat44_d &IOParam;
  typedef Mat44_d &OUTParam;
  
  Vec4_d row0;
  Vec4_d row1;
  Vec4_d row2;
  Vec4_d row3;
};

inline void Traits<Mat44_d>::ConstructEmpty( Mat44_d &val )
{
  Traits< Vec4_d >::ConstructEmpty( val.row0 );
  Traits< Vec4_d >::ConstructEmpty( val.row1 );
  Traits< Vec4_d >::ConstructEmpty( val.row2 );
  Traits< Vec4_d >::ConstructEmpty( val.row3 );
}
inline void Traits<Mat44_d>::ConstructCopy( Mat44_d &lhs, Mat44_d const &rhs )
{
  Traits< Vec4_d >::ConstructCopy( lhs.row0, rhs.row0 );
  Traits< Vec4_d >::ConstructCopy( lhs.row1, rhs.row1 );
  Traits< Vec4_d >::ConstructCopy( lhs.row2, rhs.row2 );
  Traits< Vec4_d >::ConstructCopy( lhs.row3, rhs.row3 );
}
inline void Traits<Mat44_d>::AssignCopy( Mat44_d &lhs, Mat44_d const &rhs )
{
  Traits< Vec4_d >::AssignCopy( lhs.row0, rhs.row0 );
  Traits< Vec4_d >::AssignCopy( lhs.row1, rhs.row1 );
  Traits< Vec4_d >::AssignCopy( lhs.row2, rhs.row2 );
  Traits< Vec4_d >::AssignCopy( lhs.row3, rhs.row3 );
}
inline void Traits<Mat44_d>::Destruct( Mat44_d &val )
{
  Traits< Vec4_d >::Destruct( val.row3 );
  Traits< Vec4_d >::Destruct( val.row2 );
  Traits< Vec4_d >::Destruct( val.row1 );
  Traits< Vec4_d >::Destruct( val.row0 );
}
}}}

#endif // __KL2EDK_AUTOGEN_Mat44_d__
