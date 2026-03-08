require "ecc"

workspace "Kiwi"
    architecture "x64"

    configurations { "Debug", "Release", "Dist" }

VULKAN_SDK = os.getenv("VULKAN_SDK") or os.getenv("VK_SDK_PATH")
if not VULKAN_SDK then
    error("Vulkan SDK not found!!")
else
    print("Vulkan SDK found at " .. VULKAN_SDK)
end

IncludeDirs           = {}
IncludeDirs["spdlog"] = "Kiwi/external/spdlog/include"
IncludeDirs["Vulkan"] = "%{VULKAN_SDK}/Include"
IncludeDirs["SDL3"]   = "%{VULKAN_SDK}/Include/SDL3"

LibDirs               = {}
LibDirs["Vulkan"]     = "%{VULKAN_SDK}/Lib"
LibDirs["SDL3"]       = "%{VULKAN_SDK}/Lib"

OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Kiwi/external"

-- KIWI

project "Kiwi"
    location "Kiwi"
    kind "StaticLib"
    language "C++"
    cppdialect "C++23"
    staticruntime "on"

    targetdir ("bin/" .. OutputDir .. "/%{prj.name}")
    objdir("bin-int/" .. OutputDir .. "/%{prj.name}")

    pchheader "kwpch.h"
    pchsource "Kiwi/src/kwpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDirs.spdlog}",
        "%{IncludeDirs.Vulkan}",
        "%{IncludeDirs.SDL3}",
    }

    libdirs {
        "%{LibDirs.Vulkan}",
        "%{LibDirs.SDL3}",
    }

    links {
        "spdlog",
    }

    filter "system:windows"
        systemversion "latest"
        defines { "KW_PLATFORM_WINDOWS", "KW_BUILD_DLL" }
        links { "vulkan-1", "SDL3" }

    filter "configurations:Debug"
        defines "KW_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "KW_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "KW_DIST"
        runtime "Release"
        optimize "on"

-- SANDBOX

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++23"
    staticruntime "on"

    targetdir ("bin/" .. OutputDir .. "/%{prj.name}")
    objdir("bin-int/" .. OutputDir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "Kiwi/src"
    }

    libdirs {
        "%{LibDirs.Vulkan}",
        "%{LibDirs.SDL3}",
    }

    links {
        "Kiwi",
        "spdlog",
    }

    filter "system:windows"
        systemversion "latest"
        defines { "KW_PLATFORM_WINDOWS" }
        links { "vulkan-1", "SDL3" }

    filter "configurations:Debug"
        defines "KW_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "KW_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "KW_DIST"
        runtime "Release"
        optimize "on"
