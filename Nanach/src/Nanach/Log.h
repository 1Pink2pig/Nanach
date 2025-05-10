#pragma once

#include "chpch.h"
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Nanach
{
	class NANACH_API Log
	{
	public:
		static void init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};


}

// Core log macros
#define CH_CORE_TRACE(...)        ::Nanach::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CH_CORE_INFO(...)         ::Nanach::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CH_CORE_WARN(...)         ::Nanach::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CH_CORE_ERROR(...)        ::Nanach::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CH_CORE_FATAL(...)        ::Nanach::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define CH_TRACE(...)        ::Nanach::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CH_INFO(...)         ::Nanach::Log::GetClientLogger()->info(__VA_ARGS__)
#define CH_WARN(...)         ::Nanach::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CH_ERROR(...)        ::Nanach::Log::GetClientLogger()->error(__VA_ARGS__)
#define CH_FATAL(...)        ::Nanach::Log::GetClientLogger()->fatal(__VA_ARGS__)