#include "Precompiled.h"
#include "Component.h"
#include "Implements.h"
#include <activation.h>

static long s_serverLock;

struct Hen : Implements<ABI::Component::IHen>
{
    Hen() noexcept
    {
        InterlockedIncrement(&s_serverLock);
    }

    ~Hen() noexcept
    {
        InterlockedDecrement(&s_serverLock);
    }

    HRESULT __stdcall Cluck() noexcept
    {
        return S_OK;
    }
};

// Exported DLL functions implementation
HRESULT __stdcall DllCanUnloadNow() noexcept
{
    return s_serverLock ? S_FALSE : S_OK;
}

HRESULT __stdcall DllGetActivationFactory(HSTRING classId,
                                          IActivationFactory ** factory) noexcept
{
    return E_NOTIMPL;
}