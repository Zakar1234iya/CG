# CMake generated Testfile for 
# Source directory: /workspace/GeneralsMD/Test
# Build directory: /workspace/build_test/GeneralsMD/Test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[SmokeTest]=] "/usr/local/bin/python3.12" "/workspace/GeneralsMD/Test/Smoke/smoke_test.py")
set_tests_properties([=[SmokeTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/workspace/GeneralsMD/Test/CMakeLists.txt;23;add_test;/workspace/GeneralsMD/Test/CMakeLists.txt;0;")
