#pragma once

#include <map>
#include <string>

// These functions match the a2fPluginMgr to allow registering plugins within Arnold
extern void RegisterPlugin(int type, AtByte output_type, const char* name, const char* filename);
extern void RegisterKLMgr(Fabric::EDK::KL::ArnoldKLPluginIMgr& mgr);
extern void ReleaseKLMgr();
