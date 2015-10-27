#ifndef __KL2EDK_AUTOGEN_Mat44_i__
#define __KL2EDK_AUTOGEN_Mat44_i__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'Mat44_i.h'" )
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
#include "Vec4_i.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'Mat44_i'
// Defined at Mat44_i.kl:50:1

struct Mat44_i
{
  typedef Mat44_i &Result;
  typedef Mat44_i const &INParam;
  typedef Mat44_i &IOParam;
  typedef Mat44_i &OUTParam;
  
  Vec4_i row0;
  Vec4_i row1;
  Vec4_i row2;
  Vec4_i row3;
};

inline void Traits<Mat44_i>::ConstructEmpty( Mat44_i &val )
{
  Traits< Vec4_i >::ConstructEmpty( val.row0 );
  Traits< Vec4_i >::ConstructEmpty( val.row1 );
  Traits< Vec4_i >::ConstructEmpty( val.row2 );
  Traits< Vec4_i >::ConstructEmpty( val.row3 );
}
inline void Traits<Mat44_i>::ConstructCopy( Mat44_i &lhs, Mat44_i const &rhs )
{
  Traits< Vec4_i >::ConstructCopy( lhs.row0, rhs.row0 );
  Traits< Vec4_i >::ConstructCopy( lhs.row1, rhs.row1 );
  Traits< Vec4_i >::ConstructCopy( lhs.row2, rhs.row2 );
  Traits< Vec4_i >::ConstructCopy( lhs.row3, rhs.row3 );
}
inline void Traits<Mat44_i>::AssignCopy( Mat44_i &lhs, Mat44_i const &rhs )
{
  Traits< Vec4_i >::AssignCopy( lhs.row0, rhs.row0 );
  Traits< Vec4_i >::AssignCopy( lhs.row1, rhs.row1 );
  Traits< Vec4_i >::AssignCopy( lhs.row2, rhs.row2 );
  Traits< Vec4_i >::AssignCopy( lhs.row3, rhs.row3 );
}
inline void Traits<Mat44_i>::Destruct( Mat44_i &val )
{
  Traits< Vec4_i >::Destruct( val.row3 );
  Traits< Vec4_i >::Destruct( val.row2 );
  Traits< Vec4_i >::Destruct( val.row1 );
  Traits< Vec4_i >::Destruct( val.row0 );
}
}}}

#endif // __KL2EDK_AUTOGEN_Mat44_i__
