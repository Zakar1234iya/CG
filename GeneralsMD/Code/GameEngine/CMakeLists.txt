file(GLOB_RECURSE GAMEENGINE_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/GameClient/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/GameClient/**/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/GameLogic/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/GameLogic/**/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/GameNetwork/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/GameNetwork/**/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Source/System/*.cpp
)

add_library(GameEngine STATIC ${GAMEENGINE_SOURCES})

target_include_directories(GameEngine PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/Include
  ${CMAKE_CURRENT_SOURCE_DIR}/Include/Common
  ${CMAKE_CURRENT_SOURCE_DIR}/Include/Precompiled
)

target_link_libraries(GameEngine PUBLIC
  WWLib
  WWMath
  Compression
)
