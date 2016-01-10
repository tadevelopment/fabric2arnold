#include "_IncludeAll.h"

#include "_a2fPluginManager.h"
#include <assert.h>
#include <map>


AI_INSTANCE_COMMON_METHODS

// Doing the Very Bad Thing of holding on to some static
// vars, we need to hold on to a pointer to the KL
// plugin manager to callback into it to create instances of
// our plugins during render time.
static Fabric::EDK::KL::ArnoldKLPluginIMgr s_mgr;
static const char* s_currentlyRegisteringItem = nullptr;
const char* s_klptr = "__klptr";

node_parameters
//void Parameters(AtList* params, AtMetaDataStore* mds)
{
  Fabric::EDK::KL::a2fPluginBase temp_instance = s_mgr.CreateInstance( s_currentlyRegisteringItem );
  if (temp_instance.isValid())
  {
    Fabric::EDK::KL::AtList klparams;
    CPAtList_to_KLAtList( params, klparams );
    Fabric::EDK::KL::AtMetaDataStore klmds;
    CPAtMetaDataStore_to_KLAtMetaDataStore( mds, klmds );
    temp_instance.parameters( klparams, klmds );
  }
}

//static Fabric::EDK::KL::a2fPluginBase* pInstance = NULL;
node_initialize
//void Initialize(AtNode* node, AtParamValue* params)
{
  const AtNodeEntry* nodeEntry = AiNodeGetNodeEntry( node );
  const char* entryname = AiNodeEntryGetName( nodeEntry );

  Fabric::EDK::KL::a2fPluginBase instance = s_mgr.CreateInstance( entryname );
  if (instance.isValid())
  {
    // Save the pointer to the AtNode for later reference
    // Because the C++ classes are just handles to the KL classes
    // we need to do a full copy (not just save a pointer)
    Fabric::EDK::KL::a2fPluginBase* pInstance = new Fabric::EDK::KL::a2fPluginBase( instance );

    // We cache our pointer on a user-parameter.
    // We cannot use LocalData, as Arnold seems to
    // use local data already for some plugin types (drivers)
    bool res = AiNodeDeclare( node, s_klptr, "constant POINTER" );
    assert( res );
    AiNodeSetPtr( node, s_klptr, pInstance );
    
    Fabric::EDK::KL::AtNode klnode;
    CPAtNode_to_KLAtNode( node, klnode );
    Fabric::EDK::KL::AtParamValue klparams;
    AtParamValue_to_KLParamValue( params, klparams );
    instance.initialize( klnode, klparams );
  }
}

//node_update
void Update( AtNode* node, AtParamValue* params )
{
  Fabric::EDK::KL::a2fPluginBase* pInstance = reinterpret_cast<Fabric::EDK::KL::a2fPluginBase*>(AiNodeGetPtr( node, s_klptr ));
  if (pInstance != nullptr && pInstance->isValid())
  {
    Fabric::EDK::KL::AtNode klnode;
    CPAtNode_to_KLAtNode( node, klnode );
    Fabric::EDK::KL::AtParamValue klparams;
    AtParamValue_to_KLParamValue( params, klparams );
    pInstance->update( klnode, klparams );
  }
}

node_finish
//void Finish(AtNode* node)
{
  Fabric::EDK::KL::a2fPluginBase* pInstance = reinterpret_cast<Fabric::EDK::KL::a2fPluginBase*>(AiNodeGetPtr( node, s_klptr ));
  if (pInstance != nullptr && pInstance->isValid())
  {
    Fabric::EDK::KL::AtNode klnode;
    CPAtNode_to_KLAtNode( node, klnode );
    pInstance->finish( klnode );
    delete pInstance;
    AiNodeSetLocalData( node, nullptr );
  }
}

//////////////////////////////////////////////////////////////
// Shader nodes
//shader_evaluate
void Evaluate( AtNode* node, AtShaderGlobals* globals )
{
  Fabric::EDK::KL::a2fPluginBase* pInstance = reinterpret_cast<Fabric::EDK::KL::a2fPluginBase*>(AiNodeGetPtr( node, s_klptr ));
  if (pInstance != nullptr && pInstance->isValid())
  {
    Fabric::EDK::KL::a2fPluginShader asShader = s_mgr.CastToShader( *pInstance );
    if (asShader.isValid())
    {
      Fabric::EDK::KL::AtNode klnode;
      CPAtNode_to_KLAtNode( node, klnode );
      Fabric::EDK::KL::AtShaderGlobals klglobals;
      AtShaderGlobals_to_KLAtShaderGlobals( globals, klglobals );

      asShader.evaluate( klnode, klglobals );
      KlAtShaderGlobals_to_AtShaderGlobals( klglobals, globals );
    }
  }
}

//////////////////////////////////////////////////////////////
// Driver nodes

inline Fabric::EDK::KL::a2fPluginDriver GetKLDriver( const AtNode* node )
{
  Fabric::EDK::KL::a2fPluginBase* pInstance = reinterpret_cast<Fabric::EDK::KL::a2fPluginBase*>(AiNodeGetPtr( node, s_klptr ));
  return (pInstance != nullptr && pInstance->isValid()) ? s_mgr.CastToDriver( *pInstance ) : Fabric::EDK::KL::a2fPluginDriver();
}

// TODO: We have no safe way of knowing which
// plugin is calling DriverExtension.  It appears 
// that the function is called after SupportsPixelType.
// Validate (somehow) that the following hack-job
// is safe for arbitrary driver types.
std::map<AtNode*, const char**> s_driver_extns;
static const AtNode* s_LastQueriedDriver = NULL;
static bool DriverSupportsPixelType( const AtNode* node, AtByte pixel_type )
{
  Fabric::EDK::KL::a2fPluginDriver asDriver = GetKLDriver( node );
  if (asDriver.isValid())
  {
    s_LastQueriedDriver = node; // Cache this pointer for DriverExtension below
    Fabric::EDK::KL::AtNode klnode;
    CPAtNode_to_KLAtNode( node, klnode );
    return asDriver.DriverSupportsPixelType( klnode, pixel_type );
  }
  return false;
}

static const char** DriverExtension()
{
  // In a flagrant disregard for threading safety, we use a 
  // static variable to cache the return value
  // from KL.
  static const char** s_storage = NULL;
  if (s_LastQueriedDriver == NULL)
    return s_storage;

  Fabric::EDK::KL::a2fPluginDriver asDriver = GetKLDriver( s_LastQueriedDriver );
  if (asDriver.isValid())
  {
    Fabric::EDK::KL::VariableArray< Fabric::EDK::KL::String > extns = asDriver.DriverExtension();

    // Convert strings to static-const-char variation.
    // Release any existing returned types.  These values
    // are stored in a NULL-terminated list
    if (s_storage != NULL)
    {
      const char** itr = s_storage;
      while (*itr != NULL)
        delete *itr++;
      delete s_storage;
    }
    // Allocate enough new pointers for the new strings + 1 for NULL-terminated
    int n_strings = extns.size();
    s_storage = new const char*[n_strings + 1]();
    for (int i = 0; i < n_strings; i++)
    {
      const char* str = extns[i].data();
      size_t len = extns[i].length() + 1;
      char* newstr = new char[len];
      memcpy( newstr, str, len );
      s_storage[i] = newstr;
    }
    s_LastQueriedDriver = NULL;
  }
  return s_storage;
}

static void DriverOpen( AtNode* node, AtOutputIterator* iterator, AtBBox2 display_window, AtBBox2 data_window, int bucket_size )
{
  Fabric::EDK::KL::a2fPluginDriver asDriver = GetKLDriver( node );
  if (asDriver.isValid())
  {
    Fabric::EDK::KL::AtNode klnode;
    CPAtNode_to_KLAtNode( node, klnode );
    Fabric::EDK::KL::AtOutputIterator kliter;
    CPAtOutputIterator_to_KLAtOutputIterator( iterator, kliter );
    Fabric::EDK::KL::Box2 kldisplay;
    AtBBox2_to_Box2( display_window, kldisplay );
    Fabric::EDK::KL::Box2 kldata;
    AtBBox2_to_Box2( data_window, kldata );

    asDriver.DriverOpen( klnode, kliter, kldisplay, kldata, bucket_size );
  }
}

static bool DriverNeedsBucket( AtNode* node, int bucket_xo, int bucket_yo, int bucket_size_x, int bucket_size_y, int tid )
{
  Fabric::EDK::KL::a2fPluginDriver asDriver = GetKLDriver( node );
  if (asDriver.isValid())
  {
    Fabric::EDK::KL::AtNode klnode;
    CPAtNode_to_KLAtNode( node, klnode );
    return asDriver.DriverNeedsBucket( klnode, bucket_xo, bucket_yo, bucket_size_x, bucket_size_y, tid );
  }
  return false;
}
static void DriverPrepareBucket( AtNode* node, int bucket_xo, int bucket_yo, int bucket_size_x, int bucket_size_y, int tid )
{
  Fabric::EDK::KL::a2fPluginDriver asDriver = GetKLDriver( node );
  if (asDriver.isValid())
  {
    Fabric::EDK::KL::AtNode klnode;
    CPAtNode_to_KLAtNode( node, klnode );
    asDriver.DriverPrepareBucket( klnode, bucket_xo, bucket_yo, bucket_size_x, bucket_size_y, tid );
  }
}
static void DriverProcessBucket( AtNode* node, AtOutputIterator* iterator, AtAOVSampleIterator* sample_iterator, int bucket_xo, int bucket_yo, int bucket_size_x, int bucket_size_y, int tid )
{
  Fabric::EDK::KL::a2fPluginDriver asDriver = GetKLDriver( node );
  if (asDriver.isValid())
  {
    Fabric::EDK::KL::AtNode klnode;
    CPAtNode_to_KLAtNode( node, klnode );
    Fabric::EDK::KL::AtOutputIterator kliter;
    CPAtOutputIterator_to_KLAtOutputIterator( iterator, kliter );
    Fabric::EDK::KL::AtAOVSampleIterator klsampleiter;
    CPAtAOVSampleIterator_to_KLAtAOVSampleIterator( sample_iterator, klsampleiter );
    asDriver.DriverProcessBucket( klnode, kliter, klsampleiter, bucket_xo, bucket_yo, bucket_size_x, bucket_size_y, tid );
  }
}
static void DriverWriteBucket( AtNode* node, AtOutputIterator* iterator, AtAOVSampleIterator* sample_iterator, int bucket_xo, int bucket_yo, int bucket_size_x, int bucket_size_y )
{
  Fabric::EDK::KL::a2fPluginDriver asDriver = GetKLDriver( node );
  if (asDriver.isValid())
  {
    Fabric::EDK::KL::AtNode klnode;
    CPAtNode_to_KLAtNode( node, klnode );
    Fabric::EDK::KL::AtOutputIterator kliter;
    CPAtOutputIterator_to_KLAtOutputIterator( iterator, kliter );
    Fabric::EDK::KL::AtAOVSampleIterator klsampleiter;
    CPAtAOVSampleIterator_to_KLAtAOVSampleIterator( sample_iterator, klsampleiter );
    asDriver.DriverWriteBucket( klnode, kliter, klsampleiter, bucket_xo, bucket_yo, bucket_size_x, bucket_size_y );
  }
}
static void DriverClose( AtNode* node, AtOutputIterator* iterator )
{
  Fabric::EDK::KL::a2fPluginDriver asDriver = GetKLDriver( node );
  if (asDriver.isValid())
  {
    Fabric::EDK::KL::AtNode klnode;
    CPAtNode_to_KLAtNode( node, klnode );
    Fabric::EDK::KL::AtOutputIterator kliter;
    CPAtOutputIterator_to_KLAtOutputIterator( iterator, kliter );
    asDriver.DriverClose( klnode, kliter );
  }
}

//////////////////////////////////////////////////////////////////////////

void RegisterPlugin( int type, AtByte output_type, const char* name, const char* filename )
{
  if (!s_mgr.isValid())
    throw; // Irrevocably gone wrong.

  void* plugin_methods;
  switch (type)
  {
    case AI_NODE_SHADER:
    {
      static AtShaderNodeMethods ai_shader_mtds = {
        Evaluate
      };
      plugin_methods = &ai_shader_mtds;
      break;
    }
    case AI_NODE_DRIVER:
    {
      static AtDriverNodeMethods ai_driver_mtds = {
        DriverSupportsPixelType,
        DriverExtension,
        DriverOpen,
        DriverNeedsBucket,
        DriverPrepareBucket,
        DriverProcessBucket,
        DriverWriteBucket,
        DriverClose
      };
      plugin_methods = &ai_driver_mtds;
      break;
    }
    default:
    {
      assert( 0 && "Unknown Type passed to RegisterPlugin" );
      return; // WE cannot register an unknown type
    }
  }

  // Register plugin as combo of base and extended methods.
  static AtNodeMethods methods{
      &ai_common_mtds,
      plugin_methods
  };

  s_currentlyRegisteringItem = name;
  AiNodeEntryInstall( type, output_type, name, filename, &methods, AI_VERSION );
  s_currentlyRegisteringItem = nullptr;
}

void RegisterKLMgr( Fabric::EDK::KL::ArnoldKLPluginIMgr& mgr )
{
  s_mgr = mgr;
}

void ReleaseKLMgr()
{
  s_mgr = Fabric::EDK::KL::ArnoldKLPluginIMgr();
}
