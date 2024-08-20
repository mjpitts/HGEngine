#pragma once

#ifdef HGE_PLATFORM_WINDOWS
	#ifdef HGE_BUILD_DLL
		#define HGE_API __declspec(dllexport)
	#else
		#define HGE_API __declspec(dllimport)
	#endif
#else
	#error HGE only supports windows!
#endif 