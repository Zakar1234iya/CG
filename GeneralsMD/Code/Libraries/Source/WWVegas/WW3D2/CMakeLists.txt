file(GLOB WW3D2_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(WW3D2 STATIC ${WW3D2_SOURCES})
target_include_directories(WW3D2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(WW3D2 PUBLIC WWLib WWMath)
