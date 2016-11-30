#include "Precompiled.h"
#include "Component.h"
#include "Implements.h"

struct Hen : Implements<ABI::Component::IHen>
{
    HRESULT __stdcall Cluck() noexcept
    {
        return S_OK;
    }
};