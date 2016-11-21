/*
* IInspectable based COM interfaces
* References: MSDN, Pluralsight course
*
* Copyright (C) 2016  Amir Shrestha
* amirkomail@gmail.com
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#if 1 // set to 1 to run main function in this file

#include "Precompiled.h"
#include <windows.h>
#include <type_traits>

using Microsoft::WRL::ComPtr;

template<typename T>
struct Cloaked : T {};

template<typename ... Interfaces>
class __declspec(novtable) Implements : public Interfaces ...
{
    long m_references = 1;

    template<typename T>
    struct IsCloaked : std::false_type {};

    // template specialization for Cloaked type = true
    template<typename T>
    struct IsCloaked<Cloaked<T>> : std::true_type {};

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

    template<int = 0>
    void CopyInterfaces(GUID * const) noexcept
    {

    }

    template<typename First, typename ... Rest>
    void CopyInterfaces(GUID * ids) noexcept
    {
        if (!IsCloaked<First>::value)
        {
            *ids++ = __uuidof(First);
        }

        CopyInterfaces<Rest ...>(ids);
    }

    template<int = 0>
    unsigned CountInterfaces() noexcept
    {
        return 0;
    }

    template<typename First, typename ... Rest>
    unsigned CountInterfaces() noexcept
    {
        return !IsCloaked<First>::value + CountInterfaces<Rest ...>();
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

    HRESULT __stdcall GetIids(unsigned long * pCount,
                              GUID ** pIds) noexcept
    {
        *pCount = 0;
        *pIds = nullptr;

        //unsigned const count = sizeof ... (Interfaces);
        // use the recursive version
        unsigned const count =
            CountInterfaces<Interfaces ...>();

        if (0 == count)
        {
            return S_OK;
        }

        GUID * ids = static_cast<GUID *>(CoTaskMemAlloc(sizeof(GUID) * count));

        if (!ids)
        {
            return E_OUTOFMEMORY;
        }

        CopyInterfaces<Interfaces ...>(ids);

        *pCount = count;
        *pIds = ids;
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


// Interface: IHenInterop
struct __declspec(uuid("f4d49537-8955-4aa3-acfb-eccb22fde776")) __declspec(novtable)
IHenInterop : IUnknown
{

};

class HenInspectable : public Implements<IHenInspectable,Cloaked<IHenInterop>,ILayer>
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

void TestInterfacePointers()
{
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

void TestDynamicallyGetIids()
{
    ComPtr<IHenInspectable> henInspectable;

    ASSERT(S_OK == CreateHen(henInspectable.GetAddressOf()));

    ULONG count = 0;
    GUID * guids = nullptr;

    ASSERT(S_OK == henInspectable->GetIids(&count, &guids));

    ASSERT(2 == count);
    ASSERT(guids[0] == __uuidof(IHenInspectable));
    ASSERT(guids[1] == __uuidof(ILayer));

    CoTaskMemFree(guids);
}

int main()
{
    Trace(L"Windows Runtime demo\n");

    TestInterfacePointers();

    TestDynamicallyGetIids();
}

#endif // 0 
