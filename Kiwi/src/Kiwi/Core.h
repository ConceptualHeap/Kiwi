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

#ifdef KW_ENABLE_ASSERTS
    #define KW_ASSERT(x, ...) { if(!(x)) { KW_ERROR("Assertion Failed: {}", __VA_ARGS__); } }
    #define KW_CORE_ASSERT(x, ...) { if(!(x)) { KW_CORE_ERROR("Assertion Failed: {}", __VA_ARGS__); } }
#else
    #define KW_ASSERT(x, ...)
    #define KW_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
