workspace "dVision"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{}cfg.buildcfg-%{cfg.system}-%{cfg.architecture}"

project "dVision"
	location "dVision"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dvpch.h"
	pchsource "dVision/src/dvpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"DV_PLATFORM_WINDOWS",
		"DV_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "DV_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DV_DIST"
		optimize "On"

	filter "action:vs2022"
        buildoptions { "/source-charset:utf-8", "/execution-charset:utf-8" }

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"dVision/vendor/spdlog/include",
		"dVision/src"
	}

	links
	{
		"dVision"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"DV_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "DV_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DV_DIST"
		optimize "On"

	filter "action:vs2022"
        buildoptions { "/source-charset:utf-8", "/execution-charset:utf-8" }