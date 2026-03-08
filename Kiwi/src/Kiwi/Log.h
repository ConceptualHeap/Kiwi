#pragma once

#include "kwpch.h"
#include "Core.h"

namespace Kiwi {

    class KIWI_API Logger {
    public:
        static void Init();

        enum class LogType {
            Trace, Info, Warn, Error, Fatal
        };
        enum class LogLevel {
            Core, Client
        };

        template <typename... Args>
        static void CoreTrace(std::format_string<Args...> fmt, Args&&... args) {
            Log(LogType::Trace, LogLevel::Core, std::format(fmt, std::forward<Args>(args)...).c_str());
        }
        template <typename... Args>
        static void CoreInfo(std::format_string<Args...> fmt, Args&&... args) {
            Log(LogType::Info, LogLevel::Core, std::format(fmt, std::forward<Args>(args)...).c_str());
        }
        template <typename... Args>
        static void CoreWarn(std::format_string<Args...> fmt, Args&&... args) {
            Log(LogType::Warn, LogLevel::Core, std::format(fmt, std::forward<Args>(args)...).c_str());
        }
        template <typename... Args>
        static void CoreError(std::format_string<Args...> fmt, Args&&... args) {
            Log(LogType::Error, LogLevel::Core, std::format(fmt, std::forward<Args>(args)...).c_str());
        }
        template <typename... Args>
        static void CoreFatal(std::format_string<Args...> fmt, Args&&... args) {
            Log(LogType::Fatal, LogLevel::Core, std::format(fmt, std::forward<Args>(args)...).c_str());
        }

        template <typename... Args>
        static void Trace(std::format_string<Args...> fmt, Args&&... args) {
            Log(LogType::Trace, LogLevel::Client, std::format(fmt, std::forward<Args>(args)...).c_str());
        }
        template <typename... Args>
        static void Info(std::format_string<Args...> fmt, Args&&... args) {
            Log(LogType::Info, LogLevel::Client, std::format(fmt, std::forward<Args>(args)...).c_str());
        }
        template <typename... Args>
        static void Warn(std::format_string<Args...> fmt, Args&&... args) {
            Log(LogType::Warn, LogLevel::Client, std::format(fmt, std::forward<Args>(args)...).c_str());
        }
        template <typename... Args>
        static void Error(std::format_string<Args...> fmt, Args&&... args) {
            Log(LogType::Error, LogLevel::Client, std::format(fmt, std::forward<Args>(args)...).c_str());
        }
        template <typename... Args>
        static void Fatal(std::format_string<Args...> fmt, Args&&... args) {
            Log(LogType::Fatal, LogLevel::Client, std::format(fmt, std::forward<Args>(args)...).c_str());
        }
    private:
        static void Log(LogType type, LogLevel level, const std::string& message);
    };

}

#define KW_CORE_TRACE(...)  ::Kiwi::Logger::CoreTrace(__VA_ARGS__);
#define KW_CORE_INFO(...)   ::Kiwi::Logger::CoreInfo(__VA_ARGS__);
#define KW_CORE_WARN(...)   ::Kiwi::Logger::CoreWarn(__VA_ARGS__);
#define KW_CORE_ERROR(...)  ::Kiwi::Logger::CoreError(__VA_ARGS__);
#define KW_CORE_FATAL(...)  ::Kiwi::Logger::CoreFatal(__VA_ARGS__);

#define KW_TRACE(...)       ::Kiwi::Logger::Trace(__VA_ARGS__);
#define KW_INFO(...)        ::Kiwi::Logger::Info(__VA_ARGS__);
#define KW_WARN(...)        ::Kiwi::Logger::Warn(__VA_ARGS__);
#define KW_ERROR(...)       ::Kiwi::Logger::Error(__VA_ARGS__);
#define KW_FATAL(...)       ::Kiwi::Logger::Fatal(__VA_ARGS__);
