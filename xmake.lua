-- Set minimum xmake version
set_xmakever("2.7.0")

-- Project name and version
set_project("quantcore")
set_version("0.1.0")

-- Set C++ standard and static library target
add_rules("mode.debug", "mode.release")
set_languages("cxx17")

-- Dependencies (moved to root scope)
add_requires("armadillo")
add_requires("fmt")
add_requires("spdlog")
add_requires("nlohmann_json")
add_requires("gtest")

-- Define the static library target
target("quantcore")
    set_kind("static")
    
    -- Add source files (adjust path as needed)
    add_files("quantcore/**.cc")
    add_headerfiles("quantcore/**.h")
    add_includedirs("quantcore")
    
    -- Package references only (not requires)
    add_packages("armadillo")
    add_packages("fmt")
    add_packages("spdlog")
    add_packages("nlohmann_json")

    -- Compiler flags
    if is_mode("debug") then
        add_defines("DEBUG")
        set_symbols("debug")
        set_optimize("none")
    else
        set_optimize("faster")
        add_defines("NDEBUG")
    end
    
    -- Platform-specific settings
    if is_plat("windows") then
        add_defines("WINDOWS")
    elseif is_plat("linux") then
        add_defines("LINUX")
    elseif is_plat("macosx") then
        add_defines("MACOS")
    end

-- Optional: Add test target
target("tests")
    set_kind("binary")
    add_files("tests/**.cc")
    add_deps("quantcore")
    add_includedirs("quantcore")
    -- Add test framework
    add_packages("gtest")
    add_includedirs(".")
