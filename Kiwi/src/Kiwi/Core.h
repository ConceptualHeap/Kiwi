#pragma once

#ifdef KW_PLATFORM_WINDOWS
    #ifdef KW_BUILD_DLL
        #define KIWI_API __declspec(dllexport)
    #else
        #define KIWI_API __declspec(dllimport)
    #endif
#else
    #error KIWI ONLY SUPPORTS WINDOWS
#endif
