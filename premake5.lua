workspace "Gngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
-- Include directories relative to root folder (Solution Directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Gngine/vendor/GLFW/include"
IncludeDir["Glad"] = "Gngine/Vendor/Glad/include"

include "Gngine/vendor/GLFW"
include "Gngine/vendor/Glad"


project "Gngine"
	location "Gngine"  
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
        
    pchheader "Gpch.h"
    pchsource "Gngine/src/Gpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{       
        "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++23"
		staticruntime "Off"
		systemversion "latest"
		buildoptions {
			"/utf-8"
		}
		
		defines
		{
			"GE_PLATFORM_WINDOWS",
			"GE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath}  ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		runtime "Debug"
        buildoptions {
			"/MDd",
			"/utf-8"
		}
		symbols "On"
     
	filter "configurations:Release"
		defines "GE_RELEASE"
		runtime "Release"
		buildoptions {
			"/MD",
			"/utf-8"
		}
		optimize "On"

	filter "configurations:Dist"
		defines "GE_DIST"
		runtime "Release"
		buildoptions {
			"/MD",
			"/utf-8"
		}
		optimize "On"

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
		"Gngine/vendor/spdlog/include",
		"Gngine/src"
	}

	links
	{
		"Gngine"
	}

	filter "system:windows"
		cppdialect "C++23"
		staticruntime "On"
		systemversion "latest"
		buildoptions{
			"/utf-8"
		}
		
		defines
		{
			"GE_PLATFORM_WINDOWS",
			
		}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		symbols "On"
     
	filter "configurations:Release"
		defines "GE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GE_DIST"
		optimize "On"
