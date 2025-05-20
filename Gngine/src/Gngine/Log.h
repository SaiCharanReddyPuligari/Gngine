#pragma once
#include "Core.h"
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
namespace Gngine {
	class GE_API Log
	{
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}
	private:
		static  std::shared_ptr<spdlog::logger> s_CoreLogger;
		static  std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//CORE Log Macros
#define GE_CORE_TRACE(...)		::Gngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)		::Gngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)		::Gngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...)		::Gngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...)		::Gngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//CLIENT Log Macros
#define GE_CLIENT_TRACE(...)	::Gngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_CLIENT_INFO(...)		::Gngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_CLIENT_WARN(...)		::Gngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_CLIENT_ERROR(...)	::Gngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_CLIENT_FATAL(...)	::Gngine::Log::GetClientLogger()->fatal(__VA_ARGS__)


