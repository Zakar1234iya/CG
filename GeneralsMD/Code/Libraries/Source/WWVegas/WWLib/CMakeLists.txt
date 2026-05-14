file(GLOB WWLIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(WWLib STATIC ${WWLIB_SOURCES})
target_include_directories(WWLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# MSVC-specific settings
if(MSVC)
    target_link_libraries(WWLib PRIVATE dbghelp.lib)
    target_compile_options(WWLib PRIVATE /wd4267 /wd4244 /wd4996)
endif()
