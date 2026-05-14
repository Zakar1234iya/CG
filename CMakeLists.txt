cmake_minimum_required(VERSION 3.28)
project(CommandConquerGeneralsZeroHour VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
  message(FATAL_ERROR "Only x64 builds are supported. Use -A x64 or set CMAKE_GENERATOR_PLATFORM=x64.")
endif()

option(BUILD_TOOLS "Build developer tools" OFF)
option(ENABLE_UPSCALER "Enable DLSS/XeSS/FSR upscaler support" OFF)

add_subdirectory(GeneralsMD)
