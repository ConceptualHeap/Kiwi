#include "kwpch.h"

#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Kiwi {
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;

    void Logger::Init() {
        spdlog::set_pattern("%^[%T] %n: %v%$");

        s_CoreLogger = spdlog::stdout_color_mt("KIWI");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_CoreLogger->set_level(spdlog::level::trace);
    }
    void Logger::Log(LogType type, LogLevel level, const std::string& message) {
        std::shared_ptr<spdlog::logger>& logger = level == LogLevel::Core ? s_CoreLogger : s_ClientLogger;

        switch (type) {
            case LogType::Trace :
                logger->trace(message);
                break;
            case LogType::Info :
                logger->info(message);
                break;
            case LogType::Warn :
                logger->warn(message);
                break;
            case LogType::Error :
                logger->error(message);
                break;
            case LogType::Fatal :
                logger->critical(message);
                break;
            default:
                break;
        }
    }
}
