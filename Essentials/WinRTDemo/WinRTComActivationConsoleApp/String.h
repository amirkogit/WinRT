#pragma once

#include "Handle.h"

struct Exception
{
    HRESULT Result;

    explicit Exception(HRESULT const result) noexcept :
        Result(result)
    {
    }
};

inline void Check(HRESULT const result)
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

inline String CreateString(wchar_t const * const string,
                           unsigned const length)
{
    String result;

    Check(WindowsCreateString(string,
                              length,
                              result.GetAddressOf()));

    return result;
}

template <unsigned Count>
String CreateString(wchar_t const (&string)[Count])
{
    return CreateString(string, Count - 1);
}

inline wchar_t const * Buffer(String const & string) noexcept
{
    return WindowsGetStringRawBuffer(string.Get(), nullptr);
}

inline wchar_t const * Buffer(String const & string,
                              unsigned & length) noexcept
{
    return WindowsGetStringRawBuffer(string.Get(), &length);
}

inline unsigned Length(String const & string) noexcept
{
    return WindowsGetStringLen(string.Get());
}

inline bool Empty(String const & string) noexcept
{
    return 0 != WindowsIsStringEmpty(string.Get());
}

inline String Duplicate(String const & string)
{
    String result;

    Check(WindowsDuplicateString(string.Get(),
                                 result.GetAddressOf()));

    return result;
}

inline String Substring(String const & string,
                        unsigned const start)
{
    String result;

    Check(WindowsSubstring(string.Get(),
                           start,
                           result.GetAddressOf()));

    return result;
}

struct StringBufferTraits
{
    using Pointer = HSTRING_BUFFER;

    static Pointer Invalid() noexcept
    {
        return nullptr;
    }

    static void Close(Pointer value) noexcept
    {
        VERIFY_(S_OK, WindowsDeleteStringBuffer(value));
    }
};

using StringBuffer = Handle<StringBufferTraits>;

template <typename ... Args>
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

    swprintf(target, size + 1, format, args ...);

    String result;

    Check(WindowsPromoteStringBuffer(buffer.Get(),
                                     result.GetAddressOf()));

    buffer.Detach();

    return result;
}

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
    void operator delete[](void *) =delete;

    StringReference(wchar_t const * const value,
                    unsigned length)
    {
        Check(WindowsCreateStringReference(value,
                                           length,
                                           &m_header,
                                           &m_string));
    }

    template <unsigned Count>
    StringReference(wchar_t const (&value)[Count]) :
        StringReference(value, Count - 1)
    {
    }

    HSTRING Get() const noexcept
    {
        return m_string;
    }
};
