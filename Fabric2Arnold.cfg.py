#
# This config file defines the various options
# and overrides for converting a C++ API to KL
# The output files are intended to be consumed
# by kl2edk utility
#

cppToKLTypeMapping = {
    'unsigned int': 'UInt32',
    'int': 'SInt32',
    'float': 'Float32',
    'double': 'Float64',
    'long long': 'SInt64',
    'bool': 'Boolean',
    'UINT': 'UInt32',
    'void*': 'Data',
    'void': '',
    'char*': 'String',

    'AtByte' : 'UInt8',
    'AtBBox': 'Box3',
    'AtRGB': 'RGB',
    'AtColor': 'RGB',
    'AtRGBA': 'Color',
    'AtEnum': 'String[]',
    'AtUInt16' : 'UInt16',
    'AtUInt32' : 'UInt32',
    'AtUInt64' : 'UInt64',
    'AtPoint' : 'Vec3',
    'AtVector' : 'Vec3',
    'AtPoint2' : 'Vec2',
    'AtVector2' : 'Vec2',
    'AtMatrix' : 'Mat44',
}

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
kl_type_aliases = {
    'AtString' : 'String'
}

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
opaque_type_wrappers = [
    'AtBucket',
    'AtList',
    'AtNode',
    'AtNodeEntry',
    'AtNodeMethods',
    'AtParamIterator',
    'AtMetaDataIterator',
    'AtUserParamIterator',
    'AtTextureHandle',
    'AtShaderGlobals',
    'AtScrSample',
    'AtNodeIterator',
    'AtNodeEntryIterator',
    'AtAOVIterator',
    'AtParamEntry',
    'AtUserParamEntry',
    'AtMetaDataStore',
]

#
# We need to define a list of KL POD types
# When generating the fn definition in kl2edk,
# complex (non-POD) types will be passed an IO
# parameter to set as a return value, while
# POD types will return their value directly.
# We need to know which is which in order to
# correctly generate the function implementations
#
kl_pod_types = [
    'UInt8',
    'UInt16',
    'UInt32',
    'UInt64',
    'SInt8',
    'SInt16',
    'SInt32',
    'SInt64',
    'Float32',
    'Float64',
    'Boolean',
    'Data'
]

# Name of this project
project_name = 'Fabric2Arnold'
# Specify the root of the doxygen output directory.  This dir is relative to this file
xml_dir = 'DoxygenXML/xml/'
# Specify where the output files are written.  This dir is relative to this file
output_dir = 'GenKL'
output_h_dir = 'GenCPP/h'
output_cpp_dir = 'GenCPP/cpp'

# specify where custom CPP files (if any) are located
custom_cpp_dir = 'CustomCPP'

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
]

# Any elements named in this list will not be exported
elementsToIgnore = [
    'AtCameraNodeMethods',
    'AiMsgSetCallback',
    'AtCommonMethods',
    'AtNodeMethods',
    'AiArrayGetMtxFunc'
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
                        'Float32 AtParamValue.asFloat32() = "_fe_AtParamValueAsFloat32";\n'
                        'Vec3 AtParamValue.asVec3() = "_fe_AtParamValueAsVec3";\n'
                        'Mat44 AtParamValue.asMat44() = "_fe_AtParamValueAsMat44";\n'
                        'String AtParamValue.asString() = "_fe_AtParamValueAsString";\n'
                        'AtArray AtParamValue.asAtArray() = "_fe_AtParamValueAsAtArray";\n',

    'ai_array.h' :      'Mat44 AiArrayGetMtxFunc(AtArray a, UInt32 i) = "_fe_AiArrayGetMtxFunc";'
}
# Define this value to true to not expose inline functions
skipInlineFunctions = True

#####
# The following parameters deal with creating a codegen file

# Specify a file to be merged with the auto-generated codegen file
# Items in this file will override the auto-generated items
# This file should be specified relative to this file
merge_codegen_file = "Fabric2Arnold.codegen.json"

# The parameter prefix is used to fill in the auto-generated
# codegen.json file.  It is required to auto-generate function bodies
parameter_prefix = 'f2a'
