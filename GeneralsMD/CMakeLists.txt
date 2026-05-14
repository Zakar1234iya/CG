cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
  add_compile_options(
    /W3
    /MP
    /arch:AVX2
    /fp:fast
    /Zc:preprocessor
    /Zc:__cplusplus
    /Zc:twoPhase-
    /Zc:forScope-
    /Zc:strictStrings-
    /utf-8
  )

  add_compile_definitions(
    WIN32_LEAN_AND_MEAN
    NOMINMAX
    _CRT_SECURE_NO_WARNINGS
    _CRT_NONSTDC_NO_DEPRECATE
    _SILENCE_CXX17_OLD_ALLOCATOR_FUNCTIONS_DEFINED
    _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING
    _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING
    _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
    _SILENCED_PLACEMENT_NEW_CONFLICT=1
  )
endif()

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Include
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/GameEngine/Include
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/GameEngineDevice/Include
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/GameNetwork/Include
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/WWVegas
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/WWVegas/WWMath
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/WWVegas/WWLib
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/WWVegas/WWDebug
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/WWVegas/WWSaveLoad
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/WWVegas/WW3D2
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/WWVegas/wwshade
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/WWVegas/Wwutil
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/WWVegas/WWAudio
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/WWVegas/WWDownload
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/Compression
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Libraries/Source/GameSpy
  ${CMAKE_CURRENT_SOURCE_DIR}/Code/Main
)

# Build libraries
add_subdirectory(Code/Libraries/Source/WWVegas/WWLib)
add_subdirectory(Code/Libraries/Source/WWVegas/WWMath)
add_subdirectory(Code/Libraries/Source/WWVegas/WWDebug)
add_subdirectory(Code/Libraries/Source/WWVegas/WWSaveLoad)
add_subdirectory(Code/Libraries/Source/WWVegas/wwshade)
add_subdirectory(Code/Libraries/Source/WWVegas/Wwutil)
add_subdirectory(Code/Libraries/Source/WWVegas/WW3D2)
add_subdirectory(Code/Libraries/Source/WWVegas/WWAudio)
add_subdirectory(Code/Libraries/Source/WWVegas/WWDownload)
add_subdirectory(Code/Libraries/Source/Compression)
add_subdirectory(Code/Libraries/Source/GameSpy)
add_subdirectory(Code/GameEngine)
add_subdirectory(Code/GameEngineDevice)
add_subdirectory(Code/Main)

if(BUILD_TOOLS)
  add_subdirectory(Code/Tools/WorldBuilder)
endif()

enable_testing()
add_subdirectory(Test)
