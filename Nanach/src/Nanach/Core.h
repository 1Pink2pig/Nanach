#pragma once

#ifdef CH_PLATFORM_WINDOWS
	#ifdef CH_BUILD_DLL
		#define NANACH_API __declspec(dllexport)
	#else
		#define NANACH_API __declspec(dllimport)
	#endif
#endif

#define BIT(x) (1 << x)