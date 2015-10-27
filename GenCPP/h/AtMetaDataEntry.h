#ifndef __KL2EDK_AUTOGEN_AtMetaDataEntry__
#define __KL2EDK_AUTOGEN_AtMetaDataEntry__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtMetaDataEntry.h'" )
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
#include "AtParamValue.h"

namespace Fabric { namespace EDK { namespace KL {

// KL struct 'AtMetaDataEntry'
// Defined at R:\src\HordeSoftware\Fabric2Arnold\GenKL/\ai_node_entry.kl:24:1

struct AtMetaDataEntry
{
  typedef AtMetaDataEntry &Result;
  typedef AtMetaDataEntry const &INParam;
  typedef AtMetaDataEntry &IOParam;
  typedef AtMetaDataEntry &OUTParam;
  
  String name;
  String param;
  UInt8 type;
  AtParamValue value;
};

inline void Traits<AtMetaDataEntry>::ConstructEmpty( AtMetaDataEntry &val )
{
  Traits< String >::ConstructEmpty( val.name );
  Traits< String >::ConstructEmpty( val.param );
  Traits< UInt8 >::ConstructEmpty( val.type );
  Traits< AtParamValue >::ConstructEmpty( val.value );
}
inline void Traits<AtMetaDataEntry>::ConstructCopy( AtMetaDataEntry &lhs, AtMetaDataEntry const &rhs )
{
  Traits< String >::ConstructCopy( lhs.name, rhs.name );
  Traits< String >::ConstructCopy( lhs.param, rhs.param );
  Traits< UInt8 >::ConstructCopy( lhs.type, rhs.type );
  Traits< AtParamValue >::ConstructCopy( lhs.value, rhs.value );
}
inline void Traits<AtMetaDataEntry>::AssignCopy( AtMetaDataEntry &lhs, AtMetaDataEntry const &rhs )
{
  Traits< String >::AssignCopy( lhs.name, rhs.name );
  Traits< String >::AssignCopy( lhs.param, rhs.param );
  Traits< UInt8 >::AssignCopy( lhs.type, rhs.type );
  Traits< AtParamValue >::AssignCopy( lhs.value, rhs.value );
}
inline void Traits<AtMetaDataEntry>::Destruct( AtMetaDataEntry &val )
{
  Traits< AtParamValue >::Destruct( val.value );
  Traits< UInt8 >::Destruct( val.type );
  Traits< String >::Destruct( val.param );
  Traits< String >::Destruct( val.name );
}
}}}

#endif // __KL2EDK_AUTOGEN_AtMetaDataEntry__
