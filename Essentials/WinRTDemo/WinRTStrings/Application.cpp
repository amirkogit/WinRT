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

String Duplicate(String const & string)
{
    String result;

    Check(WindowsDuplicateString(string.Get(),
                           result.GetAddressOf()));

    return result;
}

String Substring(String const & string,
                 unsigned const start)
{
    String result;

    Check(WindowsSubstring(string.Get(),
                           start,
                           result.GetAddressOf()));

    return result;
}

//! Wrapper class for handling immutable strings 
struct StringBufferTraits
{
    using Pointer = HSTRING_BUFFER;

    static Pointer Invalid() noexcept
    {
        return nullptr;
    }

    static void Close(Pointer value) noexcept
    {
        VERIFY_(S_OK,WindowsDeleteStringBuffer(value));
    }
};


using StringBuffer = Handle<StringBufferTraits>;

template<typename ... Args>
String Format(wchar_t const * format, Args ... args)
{
    int const size = swprintf(nullptr, 0, format, args ...);

    if (-1 == size)
    {
        throw Exception(E_INVALIDARG);
    }

    if (0 == size)
    {
        return String();
    }

    StringBuffer buffer;
    wchar_t * target = nullptr;

    Check(WindowsPreallocateStringBuffer(size,
                                        &target,
                                        buffer.GetAddressOf()));

    swprintf(target, size + 1, format , args ...);

    String result;

    Check(WindowsPromoteStringBuffer(buffer.Get(), 
                                     result.GetAddressOf()));

    buffer.Detach();

    return result;
}

// Optimized String object without reference counting
class StringReference
{
    HSTRING m_string;
    HSTRING_HEADER m_header;

public:
    StringReference(StringReference const &) = delete;
    StringReference & operator=(StringReference const &) = delete;
    void * operator new(std::size_t) = delete;
    void * operator new[](std::size_t) = delete;
    void operator delete(void *) = delete;
    void operator delete[](void *) = delete;

    StringReference(wchar_t const * const value,
        unsigned length)
    {
        Check(WindowsCreateStringReference(value,
                                           length,
                                           &m_header,
                                           &m_string));
    }

    template<unsigned Count>
    StringReference(wchar_t const (&value)[Count]) :
        StringReference(value, Count - 1)
    {

    }

    HSTRING Get() const noexcept
    {
        return m_string;
    }
};

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

void DuplicateTest()
{
    String s = CreateString(L"Runtime strings");

    String d = Duplicate(s);

    ASSERT(s.Get() == d.Get());
}

void SubstringTest()
{
    String s = CreateString(L"Runtime strings");

    String c = Substring(s,0);

    ASSERT(s.Get() != c.Get());

    ASSERT(Length(s) == Length(s));

    ASSERT(0 == wcscmp(Buffer(s), Buffer(c)));
}

void FormatTest()
{
    String s = Format(L"Format strings %d", 1234);

    printf("%ls (%d)\n", Buffer(s), Length(s));
}

// helper function for testing StringReferenceTest()
void Call(HSTRING string)
{
    String copy;

    Check(WindowsDuplicateString(string, 
                                 copy.GetAddressOf()));

    ASSERT(string != copy.Get());
}

void StringReferenceTest()
{
    StringReference s(L"String reference test");

    Call(s.Get());
}

int main()
{
    CreateStringTest();

    DuplicateTest();

    SubstringTest();

    FormatTest();

    StringReferenceTest();
}