#pragma once

#ifdef CH_PLATFORM_WINDOWS
	#ifdef CH_BUILD_DLL
		#define NANACH_API __declspec(dllexport)
	#else
		#define NANACH_API __declspec(dllimport)
	#endif
#endif

#ifdef  CH_ENABLE_ASSERTS
	#define CH_ASSERT(x,...){if(!(x)){CH_ERROR("Assertion Failed:{0}",__VA_ARGS__);__debugbreak();}}
	#define CH_CORE_ASSERT(x,...){if(!(x)){CH_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__),__debugbreak();}}
#else
	#define CH_ASSERT(x,...)
	#define CH_CORE_ASSERT(x,...)
#endif //  CH_ENABLE_ASSERTS


#define BIT(x) (1 << x)

#define CH_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)