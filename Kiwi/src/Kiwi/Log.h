#pragma once

#include "spdlog/spdlog.h"
#include "Core.h"
#include <memory>

namespace Kiwi {

    class KIWI_API Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };

}

#define KW_CORE_TRACE(...)  ::Kiwi::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define KW_CORE_INFO(...)   ::Kiwi::Log::GetCoreLogger()->info(__VA_ARGS__);
#define KW_CORE_WARN(...)   ::Kiwi::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define KW_CORE_ERROR(...)  ::Kiwi::Log::GetCoreLogger()->error(__VA_ARGS__);
#define KW_CORE_FATAL(...)  ::Kiwi::Log::GetCoreLogger()->fatal(__VA_ARGS__);

#define KW_TRACE(...)       ::Kiwi::Log::GetClientLogger()->trace(__VA_ARGS__);
#define KW_INFO(...)        ::Kiwi::Log::GetClientLogger()->info(__VA_ARGS__);
#define KW_WARN(...)        ::Kiwi::Log::GetClientLogger()->warn(__VA_ARGS__);
#define KW_ERROR(...)       ::Kiwi::Log::GetClientLogger()->error(__VA_ARGS__);
#define KW_FATAL(...)       ::Kiwi::Log::GetClientLogger()->fatal(__VA_ARGS__);
