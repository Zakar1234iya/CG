find_package(GTest QUIET)
if(GTEST_FOUND)
  enable_testing()

  add_executable(ZeroHourUnitTests
    Unit/test_ini_parser.cpp
    Unit/test_pathfinding.cpp
  )

  target_link_libraries(ZeroHourUnitTests
    GameEngine
    GameEngineDevice
    GTest::GTest
    GTest::Main
  )

  add_test(NAME ZeroHourUnitTests COMMAND ZeroHourUnitTests)
endif()

# Smoke test (Python)
find_package(Python3 QUIET)
if(Python3_FOUND)
  add_test(
    NAME SmokeTest
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Smoke/smoke_test.py
  )
endif()
