#include "Precompiled.h"
#include "Component.h"
#include "Implements.h"
#include <activation.h>
#include <winstring.h>
#pragma comment(lib, "runtimeobject")

static long s_serverLock;

struct Hen : Implements<ABI::Component::IHen,
                        ABI::Component::ILayer>
{
    int m_eggs = 0;

    explicit Hen(int const eggs = 0) noexcept :
    m_eggs(eggs)
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

    HRESULT __stdcall get_Eggs(int * value) noexcept
    {
        *value = m_eggs;
        return S_OK;
    }
};

// Factory class for creating Hen objects
struct HenFactory : Implements<IActivationFactory, 
                               ABI::Component::IHenFactory,
                               ABI::Component::IHenStatics>
{
    HenFactory() noexcept
    {
        InterlockedIncrement(&s_serverLock);
    }

    ~HenFactory() noexcept
    {
        InterlockedDecrement(&s_serverLock);
    }

    HRESULT __stdcall ActivateInstance(IInspectable ** instance) noexcept
    {
        *instance = 
            static_cast<ABI::Component::IHen *>(new (std::nothrow) Hen);

        return *instance ? S_OK : E_OUTOFMEMORY;
    }

    HRESULT __stdcall CreateHen(int eggs, 
                                ABI::Component::IHen ** instance) noexcept
    {
        *instance = new (std::nothrow) Hen(eggs);
        return *instance ? S_OK : E_OUTOFMEMORY;
    }

    HRESULT __stdcall get_Layers(int * value) noexcept
    {
        *value = 123;
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
    if (0 == wcscmp(RuntimeClass_Component_Hen,
        WindowsGetStringRawBuffer(classId, nullptr)))
    {
        *factory = new (std::nothrow) HenFactory;

        return *factory ? S_OK : E_OUTOFMEMORY;
    }

    *factory = nullptr;

    return CLASS_E_CLASSNOTAVAILABLE;
}