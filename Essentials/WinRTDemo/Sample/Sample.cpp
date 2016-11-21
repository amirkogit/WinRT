#include "Precompiled.h"
#include <windows.h>
#include <type_traits>

using Microsoft::WRL::ComPtr;

template<typename ... Interfaces>
class __declspec(novtable) Implements : public Intefaces ...
{
    long m_references = 1;

    template<int = 0> // placeholder template argument
    void * QueryInterface(GUID const &) noexcept
    {
        return nullptr;
    }

    template<typename First, typename ... Rest>
    void * QueryInteface(GUID const & id) noexcept
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
        *object = BaseQueryInteface<Interfaces ...>(id);

        if (!*object)
        {
            return E_NOINTERFACE;
        }

        static_cast<IUnknown *>(*object)->AddRef();
        return S_OK;
    }
};

struct __declspec(uuid("3a8af621-4232-40dd-9582-4379030eb576")) __declspec(novtable)
IHen : IUnknown
{
    virtual HRESULT __stdcall Cluck() = 0;
};


class Hen : public IHen
{
    long m_references = 1;

public:

    Hen()
    {
        Trace(L"Hen constructed.. Cheep\n");
    }

    ~Hen()
    {
        Trace(L"Hen desctructed.. Chicken soup\n");
    }

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
        if (id == __uuidof(IHen) ||
            id == __uuidof(IUnknown))
        {
            *object = static_cast<IHen*>(this);
        }
        else
        {
            *object = nullptr;
            return E_NOINTERFACE;
        }

        static_cast<IUnknown *>(*object)->AddRef();
        return S_OK;
    }

    HRESULT __stdcall Cluck() noexcept
    {
        Trace(L"Cluck!\n");
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
HRESULT CreateHen(IHen ** hen) noexcept
{
    ComPtr<IHen> temp = Make<Hen>();

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

    ComPtr<IHen> hen;

    HRESULT hr = CreateHen(hen.GetAddressOf());

    if (S_OK == hr)
    {
        hen->Cluck();
    }
}