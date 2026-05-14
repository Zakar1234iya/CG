file(GLOB MAIN_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

add_executable(ZeroHour WIN32 ${MAIN_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/RTS.RC)

target_link_libraries(ZeroHour
  GameEngine
  GameEngineDevice
  WW3D2
  WWLib
  WWMath
  WWDebug
  WWUtil
  WWSaveLoad
  WWShade
  WWAudio
  WWDownload
  Compression
  debug
  profile
)

target_include_directories(ZeroHour PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(ZeroHour PROPERTIES
  OUTPUT_NAME "ZeroHour"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Run"
)
