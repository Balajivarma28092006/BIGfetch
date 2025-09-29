cmake_minimum_required(VERSION 3.10)

project(BIGfetch CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find nlohmann_json (header-only)
find_package(nlohmann_json CONFIG REQUIRED)

# Collect source files
file(GLOB_RECURSE SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/external/*.cpp
)

# Create executable
add_executable(BIGfetch
    src/main.cpp
    src/configreader.cpp
    src/colors/colors.cpp
    src/sysinfo/systeminfo.cpp
    src/display/display.cpp
    external/helper.cpp
    src/ascii/ascii.cpp
)

# Include directories
target_include_directories(BIGfetch PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external
)

# Link nlohmann_json (header-only, so this is just include paths)
target_link_libraries(BIGfetch PRIVATE nlohmann_json::nlohmann_json)

# Optional: make sure no MSVC-specific scripts (like applocal.ps1) are run
set(CMAKE_VCPKG_TARGET_TRIPLET "x64-mingw-static")
