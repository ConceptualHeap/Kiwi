project "spdlog"
    location "spdlog"
    kind "StaticLib"
    language "C++"
    cppdialect "C++23"

    targetdir ("bin/" .. OutputDir .. "/%{prj.name}")
    objdir("bin-int/" .. OutputDir .. "/%{prj.name}")

    defines {
        "SPDLOG_COMPILED_LIB"
    }

    files
    {
        "spdlog/src/spdlog.cpp"
    }

    includedirs
    {
        "spdlog/include"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        runtime "Release"
        optimize "on"
