#ifndef __KL2EDK_AUTOGEN_AtParamValue_functions__
#define __KL2EDK_AUTOGEN_AtParamValue_functions__

#ifdef KL2EDK_INCLUDE_MESSAGES
  #pragma message ( "Including 'AtParamValue_functions.h'" )
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
#include "Vec3.h"
#include "Mat44.h"
#include "Vec4.h"
#include "AtArray.h"


FABRIC_EXT_EXPORT Fabric::EDK::KL::UInt8 _fe_AtParamValueAsUInt8(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::AtParamValue >::INParam this_
);

FABRIC_EXT_EXPORT Fabric::EDK::KL::UInt32 _fe_AtParamValueAsUInt32(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::AtParamValue >::INParam this_
);

FABRIC_EXT_EXPORT Fabric::EDK::KL::SInt32 _fe_AtParamValueAsSInt32(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::AtParamValue >::INParam this_
);

FABRIC_EXT_EXPORT Fabric::EDK::KL::Float32 _fe_AtParamValueAsFloat32(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::AtParamValue >::INParam this_
);

FABRIC_EXT_EXPORT void _fe_AtParamValueAsVec3(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Vec3 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::AtParamValue >::INParam this_
);

FABRIC_EXT_EXPORT void _fe_AtParamValueAsMat44(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::Mat44 >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::AtParamValue >::INParam this_
);

FABRIC_EXT_EXPORT void _fe_AtParamValueAsString(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::String >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::AtParamValue >::INParam this_
);

FABRIC_EXT_EXPORT void _fe_AtParamValueAsAtArray(
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::AtArray >::Result _result,
  Fabric::EDK::KL::Traits< Fabric::EDK::KL::AtParamValue >::INParam this_
);

#endif // __KL2EDK_AUTOGEN_AtParamValue_functions__
