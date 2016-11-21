/*
* IUnknown based COM interfaces
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

#if 0 // set to 1 to run main function in this file

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
IHen : IUnknown
{
    virtual HRESULT __stdcall Cluck() = 0;
};


// Interface: ILayer
struct __declspec(uuid("fb550cc1-a0b7-4769-b0c1-52cce29c52dc")) __declspec(novtable)
ILayer : IUnknown
{
    virtual HRESULT __stdcall ComputeLayer() = 0;
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
// note that there is no COM plumbing requirements in Hen2 class now! This class simply has to implement interfaces
// that are defined in its Interface lists...
class Hen2 : public Implements<IHen, ILayer>
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

    // IHen
    HRESULT __stdcall Cluck() noexcept
    {
        Trace(L"Cluck from Hen2!\n");
        return S_OK;
    }

    // ILayer
    HRESULT __stdcall ComputeLayer() noexcept
    {
        Trace(L"Computing layer...\n");
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

    // query for newly added interface: ILayer
    ComPtr<ILayer> layer;
    ASSERT(S_OK == hen2.As(&layer));
    layer->ComputeLayer();

    // query for interface that doesn't exist
    ComPtr<IStream> invalid;
    ASSERT(E_NOINTERFACE == hen2.As(&invalid));
}

#endif // 0 
