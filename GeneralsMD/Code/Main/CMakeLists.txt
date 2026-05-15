file(GLOB MAIN_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

if(MSVC)
  set(RC_FILE ${CMAKE_CURRENT_SOURCE_DIR}/RTS.RC)
else()
  set(RC_FILE "")
endif()
add_executable(ZeroHour WIN32 ${MAIN_SOURCES} ${RC_FILE})

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
  Threads::Threads
)

target_include_directories(ZeroHour PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(ZeroHour PROPERTIES
  OUTPUT_NAME "ZeroHour"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Run"
)
