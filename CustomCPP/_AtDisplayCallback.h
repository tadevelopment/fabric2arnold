
#include <ai.h>

typedef void (*AtDisplayCallback)(AtUInt32 x, AtUInt32 y, AtUInt32 width, AtUInt32 height, void* buffer, void* data);

extern bool KlAtDisplayCallback_to_AtDisplayCallback(const Fabric::EDK::KL::AtDisplayCallback & from, AtDisplayCallback & to);

// We need an additional piece of info to run this callback - each eval,
// we will check whether or not our values are packed.  To do this, we
// need to reference the source AtNode parameters
extern void SetDisplayDriverNode(AtNode* node);
