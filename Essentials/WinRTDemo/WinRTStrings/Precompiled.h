#pragma once

#include <windows.h>
#include <stdio.h>
#include <winstring.h>
#include <algorithm>

#pragma comment(lib, "runtimeobject")

#ifdef _DEBUG

    #include <crtdbg.h>
    #include <stdio.h>

    #define ASSERT _ASSERTE
    #define VERIFY ASSERT
    #define VERIFY_(result, expression) ASSERT(result == expression)

    template<typename ... Args>
    void TRACE(wchar_t const * format, Args ... args)
    {
        wchar_t buffer[200];
        swprintf_s(buffer, format, args ...);

        OutputDebugStringW(buffer);
    }
#else
    #define ASSERT __noop
    #define VERIFY(expression) (expression)
    #define VERIFY_(result, expression) (expression)
    #define TRACE __noop
#endif
