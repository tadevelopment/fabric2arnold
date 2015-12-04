#include "_IncludeAll.h"

#include "_a2fPluginManager.h"


AI_INSTANCE_COMMON_METHODS

// Doing the Very Bad Thing of holding on to some static
// vars, we need to hold on to a pointer to the KL
// plugin manager to callback into it to create instances of
// our plugins during render time.
static Fabric::EDK::KL::ArnoldKLPluginIMgr s_mgr;
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
    }
}

node_initialize
//void Initialize(AtNode* node, AtParamValue* params)
{
    const AtNodeEntry* nodeEntry = AiNodeGetNodeEntry(node);
    const char* entryname = AiNodeEntryGetName(nodeEntry);

    Fabric::EDK::KL::a2fPluginShaderInterface instance = s_mgr.CreateInstance(entryname);
    if (instance.isValid())
    {
        // Save the pointer to the AtNode for later reference
        // Because the C++ classes are just handles to the KL classes
        // we need to do a full copy (not just save a pointer)
        Fabric::EDK::KL::a2fPluginShaderInterface* pInstance = new Fabric::EDK::KL::a2fPluginShaderInterface(instance);
        AiNodeSetLocalData(node, pInstance);

        Fabric::EDK::KL::AtNode klnode;
        CPAtNode_to_KLAtNode(node, klnode);
        Fabric::EDK::KL::AtParamValue klparams;
        AtParamValue_to_KLParamValue(params, klparams);
        instance.initialize(klnode, klparams);
    }
}

//node_update
void Update(AtNode* node, AtParamValue* params)
{
    Fabric::EDK::KL::a2fPluginShaderInterface* pInstance = reinterpret_cast<Fabric::EDK::KL::a2fPluginShaderInterface*>(AiNodeGetLocalData(node));
    if (pInstance != nullptr && pInstance->isValid())
    {
        Fabric::EDK::KL::AtNode klnode;
        CPAtNode_to_KLAtNode(node, klnode);
        Fabric::EDK::KL::AtParamValue klparams;
        AtParamValue_to_KLParamValue(params, klparams);
        pInstance->update(klnode, klparams);
    }
}

node_finish
//void Finish(AtNode* node)
{
    Fabric::EDK::KL::a2fPluginShaderInterface* pInstance = reinterpret_cast<Fabric::EDK::KL::a2fPluginShaderInterface*>(AiNodeGetLocalData(node));
    if (pInstance != nullptr && pInstance->isValid())
    {
        Fabric::EDK::KL::AtNode klnode;
        CPAtNode_to_KLAtNode(node, klnode);
        pInstance->finish(klnode);
        delete pInstance;
        AiNodeSetLocalData(node, nullptr);
    }
}

//////////////////////////////////////////////////////////////
// Shader nodes
//shader_evaluate
void Evaluate(AtNode* node, AtShaderGlobals* globals)
{
    Fabric::EDK::KL::a2fPluginShaderInterface* pInstance = reinterpret_cast<Fabric::EDK::KL::a2fPluginShaderInterface*>(AiNodeGetLocalData(node));
    if (pInstance != nullptr && pInstance->isValid())
    {
        Fabric::EDK::KL::AtNode klnode;
        CPAtNode_to_KLAtNode(node, klnode);
        Fabric::EDK::KL::AtShaderGlobals klglobals;
        AtShaderGlobals_to_KLAtShaderGlobals(globals, klglobals);
        
        pInstance->evaluate(klnode, klglobals);
        KlAtShaderGlobals_to_AtShaderGlobals(klglobals, globals);
    }
}


void RegisterPlugin(int type, AtByte output_type, const char* name, const char* filename)
{
    if (!s_mgr.isValid())
        throw; // Irrevocably gone wrong.

    static AtShaderNodeMethods ai_shader_mtds = {
        Evaluate
    };
    static AtNodeMethods methods {
        &ai_common_mtds,
        &ai_shader_mtds
    };
    s_currentlyRegisteringItem = name;
    AiNodeEntryInstall(type, output_type, name, filename, &methods, AI_VERSION);
    s_currentlyRegisteringItem = nullptr;
}

void RegisterKLMgr(Fabric::EDK::KL::ArnoldKLPluginIMgr& mgr)
{
    s_mgr = mgr;
}

void ReleaseKLMgr()
{
    s_mgr = Fabric::EDK::KL::ArnoldKLPluginIMgr();
}
