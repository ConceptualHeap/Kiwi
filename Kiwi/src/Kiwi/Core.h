#pragma once

#ifdef KW_PLATFORM_WINDOWS
    #ifdef KW_DYNAMIC_LINK
        #ifdef KW_BUILD_DLL
            #define KIWI_API __declspec(dllexport)
        #else
            #define KIWI_API __declspec(dllimport)
        #endif
    #else
        #define KIWI_API
    #endif
#else
    #error KIWI ONLY SUPPORTS WINDOWS
#endif

#define BIT(x) (1 << x)
