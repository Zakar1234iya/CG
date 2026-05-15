cmake_minimum_required(VERSION 3.28)
project(CommandConquerGeneralsZeroHour VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
  message(FATAL_ERROR "Only x64 builds are supported. Use -A x64 or set CMAKE_GENERATOR_PLATFORM=x64.")
endif()

# Safe Floating Point Defaults (Critical for Lockstep Simulation)
# Do NOT use /fp:fast or -ffast-math globally.
# Renderer can override locally if needed, but GameEngine must be precise.
if(MSVC)
    add_compile_options(/fp:precise)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-fast-math")
endif()

option(BUILD_TOOLS "Build developer tools" OFF)
option(ENABLE_UPSCALER "Enable DLSS/XeSS/FSR upscaler support" OFF)

# Platform Detection
if(WIN32)
    add_compile_definitions(_WIN32)
elseif(APPLE)
    add_definitions(-DAPPLE)
elseif(UNIX)
    add_definitions(-DUNIX -DLINUX)
endif()

# Global Compile Definitions
add_compile_definitions(UNICODE _UNICODE)
add_compile_definitions(_CRT_SECURE_NO_WARNINGS) # Handled by CrossPlatform.h

# Compiler Specific Flags
if(MSVC)
    # MSVC Specific Flags
    add_compile_options(/W4 /WX- /permissive-)
    # Legacy compatibility flags - track removal in separate issues
    add_compile_options(/Zc:twoPhase- /Zc:forScope- /Zc:strictStrings-)
    
    # AVX2 is optional, default to SSE2 for broader compatibility
    if(NOT DEFINED ENABLE_AVX2)
        add_compile_options(/arch:SSE2)
    else()
        add_compile_options(/arch:AVX2)
    endif()
else()
    # GCC/Clang Flags
    add_compile_options(-Wall -Wextra -Wno-unused-parameter -Wno-missing-braces)
    
    # Strict aliasing is enabled by default
    add_compile_options(-fstrict-aliasing)
    
    # Architecture: Default to x86-64-v2 for modern compatibility without AVX2 requirement
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64")
        if(NOT DEFINED ENABLE_AVX2)
            add_compile_options(-march=x86-64-v2)
        else()
            add_compile_options(-march=native)
        endif()
    endif()
endif()

# Find Packages
find_package(Threads REQUIRED)

add_subdirectory(GeneralsMD)
