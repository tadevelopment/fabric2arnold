#ifndef __KL2EDK_AUTOGEN_AtArray__
#define __KL2EDK_AUTOGEN_AtArray__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtArray.h'" )
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

// KL struct 'AtArray'
// Defined at GenKL//ai_array.kl:10:1

struct AtArray
{
  typedef AtArray &Result;
  typedef AtArray const &INParam;
  typedef AtArray &IOParam;
  typedef AtArray &OUTParam;
  
  Data data;
  UInt32 nelements;
  UInt8 nkeys;
  UInt8 type;
};

inline void Traits<AtArray>::ConstructEmpty( AtArray &val )
{
  Traits< Data >::ConstructEmpty( val.data );
  Traits< UInt32 >::ConstructEmpty( val.nelements );
  Traits< UInt8 >::ConstructEmpty( val.nkeys );
  Traits< UInt8 >::ConstructEmpty( val.type );
}
inline void Traits<AtArray>::ConstructCopy( AtArray &lhs, AtArray const &rhs )
{
  Traits< Data >::ConstructCopy( lhs.data, rhs.data );
  Traits< UInt32 >::ConstructCopy( lhs.nelements, rhs.nelements );
  Traits< UInt8 >::ConstructCopy( lhs.nkeys, rhs.nkeys );
  Traits< UInt8 >::ConstructCopy( lhs.type, rhs.type );
}
inline void Traits<AtArray>::AssignCopy( AtArray &lhs, AtArray const &rhs )
{
  Traits< Data >::AssignCopy( lhs.data, rhs.data );
  Traits< UInt32 >::AssignCopy( lhs.nelements, rhs.nelements );
  Traits< UInt8 >::AssignCopy( lhs.nkeys, rhs.nkeys );
  Traits< UInt8 >::AssignCopy( lhs.type, rhs.type );
}
inline void Traits<AtArray>::Destruct( AtArray &val )
{
  Traits< UInt8 >::Destruct( val.type );
  Traits< UInt8 >::Destruct( val.nkeys );
  Traits< UInt32 >::Destruct( val.nelements );
  Traits< Data >::Destruct( val.data );
}
}}}

#endif // __KL2EDK_AUTOGEN_AtArray__
