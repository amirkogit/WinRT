// testing IInspectable derived interface

#if 1 // set to 1 to run main function in this file

#include "Precompiled.h"
#include <windows.h>
#include <type_traits>

using Microsoft::WRL::ComPtr;

template<typename ... Interfaces>
class __declspec(novtable) Implements : public Interfaces ...
{
    long m_references = 1;

    template<int = 0> // placeholder template argument to make compiler not complain
    void * QueryInterface(GUID const &) noexcept
    {
        return nullptr;
    }

    // recursive implementation
    template<typename First, typename ... Rest>
    void * QueryInterface(GUID const & id) noexcept
    {
        if (id == __uuidof(First))
        {
            return static_cast<First *>(this);
        }

        return QueryInterface<Rest ...>(id);
    }

    template<typename First, typename ... Rest>
    void * BaseQueryInterface(GUID const & id) noexcept
    {
        if (id == __uuidof(First) ||
            id == __uuidof(IUnknown) ||
            (std::is_base_of<IInspectable, First>::value && id == __uuidof(IInspectable)))
        {
            return static_cast<First *>(this);
        }

        return QueryInterface<Rest ...>(id);
    }

protected:
    virtual ~Implements() noexcept {}

public:
    unsigned long __stdcall AddRef() noexcept
    {
        return InterlockedIncrement(&m_references);
    }

    unsigned long __stdcall Release() noexcept
    {
        unsigned long const count = InterlockedDecrement(&m_references);

        if (0 == count)
        {
            delete this;
        }

        return count;
    }

    HRESULT __stdcall QueryInterface(GUID const & id,
                                     void ** object) noexcept
    {
        *object = BaseQueryInterface<Interfaces ...>(id);

        if (!*object)
        {
            return E_NOINTERFACE;
        }

        static_cast<IUnknown *>(*object)->AddRef();
        return S_OK;
    }
};

// Interface: IHen
struct __declspec(uuid("3a8af621-4232-40dd-9582-4379030eb576")) __declspec(novtable)
    IHenInspectable : IInspectable
{
    virtual HRESULT __stdcall Cluck() = 0;
};


// Interface: ILayer
struct __declspec(uuid("fb550cc1-a0b7-4769-b0c1-52cce29c52dc")) __declspec(novtable)
    ILayer : IUnknown
{
};


class HenInspectable : public Implements<IHenInspectable, ILayer>
{
public:

    HenInspectable()
    {
        Trace(L"[HenInspectable] constructed ...\n");
    }

    ~HenInspectable()
    {
        Trace(L"[HenInspectable] destructed ...\n");
    }


    HRESULT __stdcall GetIids(unsigned long * count,
        GUID ** ids) noexcept
    {
        *count = 0;

        *ids = static_cast<GUID *>(CoTaskMemAlloc(sizeof(GUID) * 2));

        if (!*ids)
        {
            return E_OUTOFMEMORY;
        }

        *count = 2;
        (*ids)[0] = __uuidof(IHenInspectable);
        (*ids)[1] = __uuidof(ILayer);

        return S_OK;
    }

    HRESULT __stdcall GetRuntimeClassName(HSTRING *) noexcept
    {
        return E_NOTIMPL;
    }

    HRESULT __stdcall GetTrustLevel(TrustLevel * level) noexcept
    {
        *level = BaseTrust;
        return S_OK;
    }

    HRESULT __stdcall Cluck() noexcept
    {
        Trace(L"Cluck from [HenInspectable]!\n");
        return S_OK;
    }

};

// helper function to get a COM pointer wrapped in ComPtr
template <typename T>
ComPtr<T> Make() noexcept
{
    ComPtr<T> result;

    result.Attach(new (std::nothrow) T);

    return result;
}

// helper function that creates Hen objects
// old style Hen
HRESULT CreateHen(IHenInspectable ** hen) noexcept
{
    ComPtr<IHenInspectable> temp = Make<HenInspectable>();

    if (!temp)
    {
        *hen = nullptr;
        return E_OUTOFMEMORY;
    }

    *hen = temp.Detach();
    return S_OK;
}

int main()
{
    Trace(L"Windows Runtime demo\n");

    ComPtr<IHenInspectable> henInspectable;
    ASSERT(S_OK == CreateHen(henInspectable.GetAddressOf()));

    henInspectable->Cluck();

    ComPtr<IHenInspectable> another;
    ASSERT(S_OK == henInspectable.As(&another));

    ComPtr<IUnknown> unknown;
    ASSERT(S_OK == henInspectable.As(&unknown));

    ComPtr<IStream> invalid;
    ASSERT(E_NOINTERFACE == henInspectable.As(&invalid));

    ComPtr<ILayer> layer;
    ASSERT(S_OK == henInspectable.As(&layer));
}

#endif // 0 
