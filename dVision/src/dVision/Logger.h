#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/fmt/bundled/core.h"
#include "spdlog/fmt/bundled/ostream.h"

namespace dVision {
	class DVISION_API Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Core log macros
#define DV_CORE_TRACE(...)	   ::dVision::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define DV_CORE_INFO(...)	   ::dVision::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define DV_CORE_WARN(...)	   ::dVision::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define DV_CORE_ERROR(...) 	   ::dVision::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define DV_CORE_FATAL(...)	   ::dVision::Logger::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define DV_TRACE(...)   	   ::dVision::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define DV_INFO(...)		   ::dVision::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define DV_WARN(...)		   ::dVision::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define DV_ERROR(...) 	       ::dVision::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define DV_FATAL(...)		   ::dVision::Logger::GetCoreLogger()->fatal(__VA_ARGS__)