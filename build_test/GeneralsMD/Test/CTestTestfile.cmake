# CMake generated Testfile for 
# Source directory: D:/generalzh/GeneralsMD/Test
# Build directory: D:/generalzh/build_test/GeneralsMD/Test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test([=[SmokeTest]=] "C:/Program Files/Python312/python.exe" "D:/generalzh/GeneralsMD/Test/Smoke/smoke_test.py")
  set_tests_properties([=[SmokeTest]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/generalzh/GeneralsMD/Test/CMakeLists.txt;23;add_test;D:/generalzh/GeneralsMD/Test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test([=[SmokeTest]=] "C:/Program Files/Python312/python.exe" "D:/generalzh/GeneralsMD/Test/Smoke/smoke_test.py")
  set_tests_properties([=[SmokeTest]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/generalzh/GeneralsMD/Test/CMakeLists.txt;23;add_test;D:/generalzh/GeneralsMD/Test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test([=[SmokeTest]=] "C:/Program Files/Python312/python.exe" "D:/generalzh/GeneralsMD/Test/Smoke/smoke_test.py")
  set_tests_properties([=[SmokeTest]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/generalzh/GeneralsMD/Test/CMakeLists.txt;23;add_test;D:/generalzh/GeneralsMD/Test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test([=[SmokeTest]=] "C:/Program Files/Python312/python.exe" "D:/generalzh/GeneralsMD/Test/Smoke/smoke_test.py")
  set_tests_properties([=[SmokeTest]=] PROPERTIES  _BACKTRACE_TRIPLES "D:/generalzh/GeneralsMD/Test/CMakeLists.txt;23;add_test;D:/generalzh/GeneralsMD/Test/CMakeLists.txt;0;")
else()
  add_test([=[SmokeTest]=] NOT_AVAILABLE)
endif()
