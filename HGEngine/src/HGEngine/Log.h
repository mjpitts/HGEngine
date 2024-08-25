#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace HGEngine
{
	class HGE_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }


	};
}

// Core log Macros
#define HGE_CORE_TRACE(...) ::HGEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HGE_CORE_INFO(...)	::HGEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HGE_CORE_WARN(...)	::HGEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HGE_CORE_ERROR(...) ::HGEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HGE_CORE_FATAL(...) ::HGEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log Macros
#define HGE_TRACE(...)	::HGEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HGE_INFO(...)	::HGEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define HGE_WARN(...)	::HGEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HGE_ERROR(...)	::HGEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define HGE_FATAL(...)	::HGEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)



