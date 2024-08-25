workspace "HGEngine"
	architecture "x64"
	startproject "SandBox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "HGEngine"
	location "HGEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name/src/**.h",
		"%{prj.name/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HGE_PLATFORM_WINDOWS", 
			"HGE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines"HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines"HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines"HZ_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name/src/**.h",
		"%{prj.name/src/**.cpp",
	}

	includedirs
	{
		"HGEngine/vendor/spdlog/include",
		"HGEngine/src"
	}

	links
	{
		"HGEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HGE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines"HZ_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines"HZ_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines"HZ_DIST"
		optimize "On"
