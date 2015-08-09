#include "_IncludeAll.h"


static Fabric::EDK::KL::AtDisplayCallback _klCallack;
static AtNode* _shaderNode = nullptr;

void AtDisplayCallback_Imp(AtUInt32 x, AtUInt32 y, AtUInt32 width, AtUInt32 height, void* buffer, void* data)
{
    // We need to convert the parameters to this function from C++ type to KL.
    // Luckily, all these types here convert without any extra effort on our part.
    Fabric::EDK::report("You are here");
    if (_klCallack.isValid())
    {
        bool rgbaPacking = AiNodeGetBool(_shaderNode, "rgba_packing");

        Fabric::EDK::KL::ExternalArray<Fabric::EDK::KL::RGBA> rgbaBuffer;
        Fabric::EDK::KL::ExternalArray<Fabric::EDK::KL::Color> colorBuffer;

        if (buffer != nullptr)
        {        
            int size = width * height;
            if (rgbaPacking)
                rgbaBuffer = Fabric::EDK::KL::ExternalArray<Fabric::EDK::KL::RGBA>(reinterpret_cast<Fabric::EDK::KL::RGBA*>(buffer), size);
            else
                colorBuffer = Fabric::EDK::KL::ExternalArray<Fabric::EDK::KL::Color>(reinterpret_cast<Fabric::EDK::KL::Color*>(buffer), size);
        }

        _klCallack.Callback(x, y, width, height, rgbaBuffer, colorBuffer, data);
    }
}

bool KlAtDisplayCallback_to_AtDisplayCallback(const Fabric::EDK::KL::AtDisplayCallback & from, AtDisplayCallback & to) 
{
    _klCallack = from;
    to = &AtDisplayCallback_Imp;
    return true;
}

void SetDisplayDriverNode(AtNode* node)
{
    _shaderNode = node;
}
