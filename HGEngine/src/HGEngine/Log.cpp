#include "Log.h"

namespace HGEngine 
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{

		// spdlog wiki contains patter info. 
		// start-color [ 12-hour-clock , log-level ] logger-name text-to-log end-color 
		spdlog::set_pattern("== %^[%r , %l] %n %v%$ ==");

		// Create color multithreaded logger.
		s_CoreLogger = spdlog::stdout_color_mt("HGEngine");
		s_CoreLogger->set_level(spdlog::level::trace);

		// Create color multithreaded logger.
		s_ClientLogger = spdlog::stdout_color_mt("Application");
		s_ClientLogger->set_level(spdlog::level::trace);

		// testing to force bat file to remake project. 
		int test = 2;
	}
}

