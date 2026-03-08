require "ecc"

workspace "Kiwi"
    architecture "x64"

    configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- KIWI

project "Kiwi"
    location "Kiwi"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Kiwi/external/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++23"
        staticruntime "On"
        systemversion "latest"
        defines { "KW_PLATFORM_WINDOWS", "KW_BUILD_DLL" }

    filter "configurations:Debug"
        defines "KW_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "KW_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "KW_DIST"
        symbols "On"

-- SANDBOX

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Kiwi/external/spdlog/include",
        "Kiwi/src"
    }

    links
    {
        "Kiwi"
    }

    filter "system:windows"
        cppdialect "C++23"
        staticruntime "On"
        systemversion "latest"
        defines { "KW_PLATFORM_WINDOWS" }

    filter "configurations:Debug"
        defines "KW_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "KW_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "KW_DIST"
        symbols "On"
