#include "Precompiled.h"
#include "Handle.h"

struct Exception
{
    HRESULT m_result;

    explicit Exception(HRESULT const result) noexcept:
    m_result(result)
    {

    }
};

void Check(HRESULT const result)
{
    if (S_OK != result)
    {
        throw Exception(result);
    }
}


struct StringTraits
{
    using Pointer = HSTRING;

    static Pointer Invalid() noexcept
    {
        return nullptr;
    }

    static void Close(Pointer value) noexcept
    {
        VERIFY_(S_OK, WindowsDeleteString(value));
    }
};

using String = Handle<StringTraits>;

// helper function to create a String that wraps windows API function WindowsCreateString
String CreateString(wchar_t const * const string,
                    unsigned const length)
{
    String result;

    Check(WindowsCreateString(string,
                              length,
                              result.GetAddressOf()));

    return result;
}

// another overload of CreateString function
template <unsigned Count>
String CreateString(wchar_t const (&string)[Count])
{
    return CreateString(string, Count -1);
}

wchar_t const * Buffer(String const & string) noexcept
{
    return WindowsGetStringRawBuffer(string.Get(), nullptr);
}

wchar_t const * Buffer(String const & string,
                       unsigned & length) noexcept
{
    return WindowsGetStringRawBuffer(string.Get(), & length);
}

unsigned Length(String const & string) noexcept
{
    return WindowsGetStringLen(string.Get());
}

bool Empty(String const & string) noexcept
{
    return 0 != WindowsIsStringEmpty(string.Get());
}

void CreateStringTest()
{
    TRACE(L"Windows runtime strings demo\n");

    String s = CreateString(L"Runtime strings");

    unsigned length = 0;
    wchar_t const * const buffer = Buffer(s, length);

    printf("\"%ls\" length=%d empty=%s\n",
        buffer,
        length,
        0 == length ? "Yes" : "No");
}

int main()
{
    CreateStringTest();
}