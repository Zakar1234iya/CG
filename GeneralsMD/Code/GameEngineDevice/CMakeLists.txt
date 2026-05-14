file(GLOB_RECURSE GAMEENGINEDEVICE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/W3DDevice/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/W3DDevice/**/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/Win32Device/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/Win32Device/**/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/Audio/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/Video/*.cpp
)

add_library(GameEngineDevice STATIC ${GAMEENGINEDEVICE_SOURCES})

target_include_directories(GameEngineDevice PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/Include
)

target_link_libraries(GameEngineDevice PUBLIC
  GameEngine
  WW3D2
)
