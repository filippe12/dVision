#pragma once

#ifdef DV_PLATFORM_WINDOWS
	#ifdef DV_BUILD_DLL
		#define DVISION_API __declspec(dllexport)
	#else
		#define DVISION_API __declspec(dllimport)
	#endif
#else
	#error dVision only supports windows!
#endif