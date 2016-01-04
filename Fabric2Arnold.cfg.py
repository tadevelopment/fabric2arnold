#
# This config file defines the various options
# and overrides for converting a C++ API to KL
# The output files are intended to be consumed
# by kl2edk utility
#


# Name of this project
project_name = 'Fabric2Arnold'
# Specify the root of the doxygen output directory.  This dir is relative to this file
xml_dir = 'DoxygenXML/xml/'

cppToKLTypeMapping.update( {
    'AtByte' : 'UInt8',
    'AtBBox': 'Box3',
    'AtRGB': 'Color',
    'AtEnum': 'String[]',
    'AtUInt16' : 'UInt16',
    'AtUInt32' : 'UInt32',
    'AtUInt64' : 'UInt64',
    'AtPoint' : 'Vec3',
    'AtVector' : 'Vec3',
    'AtPoint2' : 'Vec2',
    'AtMatrix' : 'Mat44',
} )

#
# When multiple C++ types map to a single KL
# type, it becomes impossible to correctly remap
# the conversion functions for the KL type back
# to the correct C++ type.  To resolve these 
# issues, we can create a KL 'alias' for the type
# which allows us to specify a unique KL type in the
# generated fn signatures, and this type lets us know
# the correct C++ type to convert to in the 
# kl2edk phase
# NOTE: The alias must be named the same as the C++ type
#
kl_type_aliases.update( {
    'AtString' : 'String',
    'AtColor' : 'Color',
    'AtRGBA' : 'Color'
} )

# AtMatrix is defined as float[4][4],
# so should always be treated as a pointer
force_io_types += [
    'AtMatrix'
]

#
# If an SDK exposes opaque types (eg, handles) then
# the only interaction KL can have with these objects
# is to pass them around as Data pointers.  To maintain
# some type-safety, we can generate structs to wrap
# these pointers that simply contain a Data ptr. 
# Note - the opaque_file_name should not conflict
# with any filesToProcess, or it may be overwritten
#
opaque_file_name = '_opaque_types'
opaque_type_wrappers += [
    'AtBucket',
    'AtList',
    'AtNode',
    'AtNodeEntry',
    'AtNodeMethods',
    'AtParamIterator',
    'AtMetaDataIterator',
    'AtUserParamIterator',
    'AtTextureHandle',
    'AtScrSample',
    'AtNodeIterator',
    'AtNodeEntryIterator',
    'AtAOVIterator',
    'AtParamEntry',
    'AtUserParamEntry',
    'AtMetaDataStore',
    'AtOutputIterator',
    'AtAOVSampleIterator'
]


filesToProcess = [
    'ai_params.h',
    'ai_array.h',
    "ai_cameras.h",
    'ai_dotass.h',
    "ai_enum.h",
    "ai_license.h",
    'ai_metadata.h',
    'ai_msg.h',
    'ai_node_entry.h',
    'ai_nodes.h',
    'ai_render.h',
    'ai_plugins.h',
    'ai_ray.h',
    'ai_texture.h',
    'ai_universe.h',
    'ai_shader_parameval.h',
    'ai_drivers.h',
    'ai_filters.h'
]

# If you need to manually set any ordering, specify the files
# in this list and they will be added to the FPM last, in ther
# order specified here.
fpm_enforced_order = [
    "ai_shaderglobals.kl",
    "ai_ray.kl",
    "a2fPlugins.kl",
    "a2fPluginMgr.kl"
]
# Any elements named in this list will not be exported
elementsToIgnore = [
    'AtCameraNodeMethods',
    'AiMsgSetCallback',
    'AtCommonMethods',
    'AtNodeMethods',
    'AtDriverNodeMethods',
    'AtFilterNodeMethods',
    'AiArrayGetMtxFunc',
    'AiNodeGetMatrixAtString',
    'AiRawDriverInitialize',
    'AiDriverExtension',
    'AiOutputIteratorGetNext'
]

# Add extensions to be required.  Should
# this be per-file?  Or common for the whole project?
extns_required = [
    'Math'
]

# Add custom code to be added to the head of a file.
# It is possible to override built in translations by
# ignoring an element, and defining it explicitly here.
custom_add_to_file = {

    'ai_params.h' :     'struct AtParamValue {\n'
                        '  Data param_handle;\n'
                        '};\n'
                        '\n'
                        'UInt8 AtParamValue.asUInt8() = "_fe_AtParamValueAsUInt8";\n'
                        'UInt32 AtParamValue.asUInt32() = "_fe_AtParamValueAsUInt32";\n'
                        'SInt32 AtParamValue.asSInt32() = "_fe_AtParamValueAsSInt32";\n'
                        'Boolean AtParamValue.asBoolean() = "_fe_AtParamValueAsBoolean";\n'
                        'Float32 AtParamValue.asFloat32() = "_fe_AtParamValueAsFloat32";\n'
                        'Color AtParamValue.asRGB() = "_fe_AtParamValueAsRGB";\n'
                        'Color AtParamValue.asRGBA() = "_fe_AtParamValueAsRGBA";\n'
                        'Vec3 AtParamValue.asVec3() = "_fe_AtParamValueAsVec3";\n'
                        'Vec2 AtParamValue.asVec2() = "_fe_AtParamValueAsVec2";\n'
                        'Data AtParamValue.asData() = "_fe_AtParamValueAsData";\n'
                        'Mat44 AtParamValue.asMat44() = "_fe_AtParamValueAsMat44";\n'
                        'String AtParamValue.asString() = "_fe_AtParamValueAsString";\n'
                        'AtArray AtParamValue.asAtArray() = "_fe_AtParamValueAsAtArray";\n'
                        '\n'
                        'AtParamValue.setUInt8(UInt8 val) = "_fe_AtParamValueSetUInt8";\n'
                        'AtParamValue.setUInt32(UInt32 val) = "_fe_AtParamValueSetUInt32";\n'
                        'AtParamValue.setSInt32(SInt32 val) = "_fe_AtParamValueSetSInt32";\n'
                        'AtParamValue.setFloat32(Float32 val) = "_fe_AtParamValueSetFloat32";\n'
                        'AtParamValue.setRGB(Color val) = "_fe_AtParamValueSetRGB";\n'
                        'AtParamValue.setRGBA(Color val) = "_fe_AtParamValueSetRGBA";\n'
                        'AtParamValue.setVec3(Vec3 val) = "_fe_AtParamValueSetVec3";\n'
                        'AtParamValue.setVec2(Vec2 val) = "_fe_AtParamValueSetVec2";\n'
                        'AtParamValue.setData(Data val) = "_fe_AtParamValueSetData";\n'
                        'AtParamValue.setMat44(Mat44 val) = "_fe_AtParamValueSetMat44";\n'
                        'AtParamValue.setString(String val) = "_fe_AtParamValueSetString";\n'
                        'AtParamValue.setAtArray(AtArray val) = "_fe_AtParamValueSetAtArray";\n',

    'ai_array.h' :      'Mat44 AiArrayGetMtxFunc(AtArray a, UInt32 i) = "_fe_AiArrayGetMtxFunc";\n\n'
                        'function Boolean AiArraySetBool(io AtArray a, Boolean val[]) = "_fe_AiArraySetBoolArr";\n'
                        'function Boolean AiArraySetByte(io AtArray a, UInt8 val[]) = "_fe_AiArraySetByteArr";\n'
                        'function Boolean AiArraySetInt(io AtArray a, SInt32 val[]) = "_fe_AiArraySetIntArr";\n'
                        'function Boolean AiArraySetUInt(io AtArray a, UInt32 val[]) = "_fe_AiArraySetUIntArr";\n'
                        'function Boolean AiArraySetFlt(io AtArray a, Float32 val[]) = "_fe_AiArraySetFltArr";\n'
                        #'function Boolean AiArraySetRGB(io AtArray a, RGB val[]) = "_fe_AiArraySetRGBArr";\n'
                        'function Boolean AiArraySetRGBA(io AtArray a, Color val[]) = "_fe_AiArraySetRGBAArr";\n'
                        'function Boolean AiArraySetPnt(io AtArray a, Vec3 val[]) = "_fe_AiArraySetPntArr";\n'
                        'function Boolean AiArraySetPnt2(io AtArray a, Vec2 val[]) = "_fe_AiArraySetPnt2Arr";\n'
                        'function Boolean AiArraySetVec(io AtArray a, Vec3 val[]) = "_fe_AiArraySetVecArr";\n\n'
                        #'function Boolean AiArraySetMtx(io AtArray a, Mat44 val[]) = "_fe_AiArraySetMtxArr";\n'
                        #'function Boolean AiArraySetStr(io AtArray a, String val[]) = "_fe_AiArraySetStrArr";\n'
                        #'function Boolean AiArraySetPtr(io AtArray a, Data val[]) = "_fe_AiArraySetPtrArr";\n'
                        'function Boolean AiArrayGetBool(io AtArray a, io Boolean val<>) = "_fe_AiArrayGetBoolArr";\n'
                        'function Boolean AiArrayGetByte(io AtArray a, io UInt8 val<>) = "_fe_AiArrayGetByteArr";\n'
                        'function Boolean AiArrayGetInt(io AtArray a, io SInt32 val<>) = "_fe_AiArrayGetIntArr";\n'
                        'function Boolean AiArrayGetUInt(io AtArray a, io UInt32 val<>) = "_fe_AiArrayGetUIntArr";\n'
                        'function Boolean AiArrayGetFlt(io AtArray a, io Float32 val<>) = "_fe_AiArrayGetFltArr";\n'
                        #'function Boolean AiArrayGetRGB(io AtArray a, io RGB val<>) = "_fe_AiArrayGetRGBArr";\n'
                        'function Boolean AiArrayGetRGBA(io AtArray a, io Color val<>) = "_fe_AiArrayGetRGBAArr";\n'
                        'function Boolean AiArrayGetPnt(io AtArray a, io Vec3 val<>) = "_fe_AiArrayGetPntArr";\n'
                        'function Boolean AiArrayGetPnt2(io AtArray a, io Vec2 val<>) = "_fe_AiArrayGetPnt2Arr";\n'
                        'function Boolean AiArrayGetVec(io AtArray a, io Vec3 val<>) = "_fe_AiArrayGetVecArr";\n\n',

                        #'function Boolean AiArrayGetMtx(io AtArray a, io Mat44 val<>) = "_fe_AiArrayGetMtxArr";\n'
                        #'function Boolean AiArrayGetStr(io AtArray a, io String val<>) = "_fe_AiArrayGetStrArr";\n'
                        #'function Boolean AiArrayGetPtr(io AtArray a, io Data val<>) = "_fe_AiArrayGetPtrArr";\n'

    'ai_nodes.h' :      'Mat44 AiNodeGetMatrix(AtNode node, String param) = "_fe_AiNodeGetMatrix";\n\n',

    'ai_drivers.h' :    'function AiRawDriverInitialize(io AtNode node, String required_aovs[], Boolean requires_depth, io Data data) = "_fe_AiRawDriverInitialize";\n'
                        'function String[] AiDriverExtension(AtNodeEntry node_entry) = "_fe_AiDriverExtension";\n'
                        'function Boolean AiOutputIteratorGetNext(io AtOutputIterator iter, io String output_name, io SInt32 pixel_type, io Data bucket_data) = "_fe_AiOutputIteratorGetNext";'
}

#####
# The following parameters deal with creating a codegen file

# Specify a file to be merged with the auto-generated codegen file
# Items in this file will override the auto-generated items
# This file should be specified relative to this file
merge_codegen_file = project_name + ".codegen.json"

# The parameter prefix is used to fill in the auto-generated
# codegen.json file.  It is required to auto-generate function bodies
parameter_prefix = 'f2a'

