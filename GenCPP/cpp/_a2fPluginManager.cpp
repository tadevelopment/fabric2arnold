#include "_IncludeAll.h"

#include "_a2fPluginManager.h"

AI_INSTANCE_COMMON_METHODS

static Fabric::EDK::KL::ArnoldKLPluginIMgr s_mgr;
static Fabric::EDK::KL::a2fPluginShaderInterface s_instance;
static const char* s_currentlyRegisteringItem = nullptr;
node_parameters
//void Parameters(AtList* params, AtMetaDataStore* mds)
{
    Fabric::EDK::KL::a2fPluginShaderInterface temp_instance = s_mgr.CreateInstance(s_currentlyRegisteringItem);
    if (temp_instance.isValid())
    {
        Fabric::EDK::KL::AtList klparams;
        CPAtList_to_KLAtList(params, klparams);
        Fabric::EDK::KL::AtMetaDataStore klmds;
        CPAtMetaDataStore_to_KLAtMetaDataStore(mds, klmds);
        temp_instance.parameters(klparams, klmds);
        // Explicitly clear, as it appears the copy construct manages lifetime,
        // but the destructor does not
        temp_instance = Fabric::EDK::KL::a2fPluginShaderInterface();
    }
}

node_initialize
//void Initialize(AtNode* node, AtParamValue* params)
{
    const AtNodeEntry* nodeEntry = AiNodeGetNodeEntry(node);
    const char* entryname = AiNodeEntryGetName(nodeEntry);

    s_instance = s_mgr.CreateInstance(entryname);
    if (s_instance.isValid())
    {
        Fabric::EDK::KL::AtNode klnode;
        CPAtNode_to_KLAtNode(node, klnode);
        Fabric::EDK::KL::AtParamValue klparams;
        AtParamValue_to_KLParamValue(params, klparams);
        s_instance.initialize(klnode, klparams);
    }
}

//node_update
void Update(AtNode* node, AtParamValue* params)
{
    if (s_instance.isValid())
    {
        Fabric::EDK::KL::AtNode klnode;
        CPAtNode_to_KLAtNode(node, klnode);
        Fabric::EDK::KL::AtParamValue klparams;
        AtParamValue_to_KLParamValue(params, klparams);
        s_instance.update(klnode, klparams);
    }
}

node_finish
//void Finish(AtNode* node)
{
    if (s_instance.isValid())
    {
        Fabric::EDK::KL::AtNode klnode;
        CPAtNode_to_KLAtNode(node, klnode);
        s_instance.finish(klnode);
        s_instance = Fabric::EDK::KL::a2fPluginShaderInterface();
    }
}

//////////////////////////////////////////////////////////////
// Shader nodes
//shader_evaluate
void Evaluate(AtNode* node, AtShaderGlobals* globals)
{
    if (s_instance.isValid())
    {
        Fabric::EDK::KL::AtNode klnode;
        CPAtNode_to_KLAtNode(node, klnode);
        Fabric::EDK::KL::AtShaderGlobals klglobals;
        CPAtShaderGlobals_to_KLAtShaderGlobals(globals, klglobals);
        
        s_instance.evaluate(klnode, klglobals);
        KLAtShaderGlobals_to_CPAtShaderGlobals(klglobals, globals);
    }
}


void RegisterPlugin(Fabric::EDK::KL::ArnoldKLPluginIMgr& mgr, int type, AtByte output_type, const char* name, const char* filename)
{
    static AtShaderNodeMethods ai_shader_mtds = {
        Evaluate
    };
    static AtNodeMethods methods {
        &ai_common_mtds,
        &ai_shader_mtds
    };
    s_mgr = mgr;
    s_currentlyRegisteringItem = name;
    AiNodeEntryInstall(type, output_type, name, filename, &methods, AI_VERSION);
    s_currentlyRegisteringItem = nullptr;
}
