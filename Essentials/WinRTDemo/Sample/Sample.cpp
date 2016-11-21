#include "Precompiled.h"
#include <windows.h>
#include <type_traits>

using Microsoft::WRL::ComPtr;

template<typename ... Interfaces>
class __declspec(novtable) Implements : public Interfaces ...
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
        *object = BaseQueryInterface<Interfaces ...>(id);

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


// old style: creating Hen class derived directly fron IHen
// Here all code related to COM plumbing has to be written for eg: AddRef, Release... etc
class Hen : public IHen
{
    long m_references = 1;

public:

    Hen()
    {
        Trace(L"Hen constructed ...\n");
    }

    ~Hen()
    {
        Trace(L"Hen destructed ...\n");
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
        Trace(L"Cluck from Hen!\n");
        return S_OK;
    }
};

// New style:
// In the old style Hen class was directly derived from IHen interface which was derived from IUnknown interface
// So, all inteface implementations of IUnknown goes into Hen class.
// Here, we create a new class named Hen2 which will make use of Implements<> template class that implements
// variadic template to get the list of all interfaces that Hen2 class will implement
class Hen2 : public Implements<IHen>
{
public:

    Hen2()
    {
        Trace(L"Hen2 constructed ...\n");
    }

    ~Hen2()
    {
        Trace(L"Hen2 destructed ...\n");
    }

    HRESULT __stdcall Cluck() noexcept
    {
        Trace(L"Cluck from Hen2!\n");
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

// helper function that creates Hen2 objects
// new style Hen2
HRESULT CreateHen2(IHen ** hen) noexcept
{
    ComPtr<IHen> temp = Make<Hen2>();

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

    // old style Hen object creation
    ComPtr<IHen> hen;

    HRESULT hr = CreateHen(hen.GetAddressOf());

    if (S_OK == hr)
    {
        hen->Cluck();
    }

    // new style Hen2 object creation
    ComPtr<IHen> hen2;
    ASSERT(S_OK == CreateHen2(hen2.GetAddressOf()));

    hen2->Cluck();
}