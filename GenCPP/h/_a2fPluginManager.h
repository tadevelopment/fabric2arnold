#pragma once

#include <map>
#include <string>

class _a2fPluginManager
{
    std::map<std::string, Fabric::EDK::KL::Type> m_plugin_types;
public:

  // Call this function to register a new KL plugin type
  bool RegisterPlugin(Fabric::EDK::KL::Type kltype, int type, AtByte output_type, const char* name, const char* filename);

  static _a2fPluginManager* GetInstance() {
    static _a2fPluginManager instance;
    return &instance;
  }  
};

// Call this function to register a new KL plugin type
extern void RegisterPlugin(Fabric::EDK::KL::ArnoldKLPluginIMgr& mgr, int type, AtByte output_type, const char* name, const char* filename);
