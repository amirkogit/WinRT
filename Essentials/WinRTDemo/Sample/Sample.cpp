#include "Precompiled.h"
#include <windows.h>

struct __declspec(uuid("3a8af621-4232-40dd-9582-4379030eb576")) __declspec(novtable)
IHen : IUnknown
{
    virtual HRESULT __stdcall Cluck() = 0;
};


class Hen : public IHen
{
    long m_references = 1;

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

int main()
{
    Trace(L"Windows Runtime demo\n");
}