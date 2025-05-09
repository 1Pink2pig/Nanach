workspace "Nanach"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir ="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

project "Nanach"
	location "Nanach"
	kind "SharedLib"
	language "C++"
	buildoptions { "/utf-8" }
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"CH_PLATFORM_WINDOWS",
			"CH_BUILD_DLL",
			"_WINDLL",
			"NANACH_EXPORTS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CH_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language"C++"
	buildoptions { "/utf-8" }
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Nanach/vendor/spdlog/include",
		"Nanach/src"
	}

	links
	{
		"Nanach"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines
		{
			"CH_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines "CH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CH_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CH_DIST"
		optimize "On"