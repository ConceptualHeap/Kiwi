project "spdlog"
    location "spdlog"
    kind "StaticLib"
    language "C++"
    cppdialect "C++23"
    staticruntime "on"

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

project "imgui"
    location "imgui"
    kind "StaticLib"
    language "C++"
    cppdialect "C++23"
    staticruntime "on"

    targetdir ("bin/" .. OutputDir .. "/%{prj.name}")
    objdir("bin-int/" .. OutputDir .. "/%{prj.name}")

    files
    {
        "imgui/imconfig.h",
        "imgui/imgui.h",
        "imgui/imgui.cpp",
        "imgui/imgui_demo.cpp",
        "imgui/imgui_draw.cpp",
        "imgui/imgui_internal.h",
        "imgui/imgui_tables.cpp",
        "imgui/imgui_widgets.cpp",
        "imgui/imstb_rectpack.h",
        "imgui/imstb_textedit.h",
        "imgui/imstb_truetype.h",

        "imgui/backends/imgui_impl_sdl3.h",
        "imgui/backends/imgui_impl_sdl3.cpp"
    }

    includedirs
    {
        "imgui",
        "sdl/include"
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
