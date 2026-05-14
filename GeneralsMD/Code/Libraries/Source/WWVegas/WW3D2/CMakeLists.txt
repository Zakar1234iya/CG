# WW3D2 Core Library (Phase 1-4 Refactored)
file(GLOB WW3D2_CORE_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VulkanBackend/*.cpp
)

# Exclude DX8-specific files from core if needed
list(REMOVE_ITEM WW3D2_CORE_SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/dx8wrapper.cpp
)

add_library(WW3D2_Core STATIC ${WW3D2_CORE_SOURCES})
target_include_directories(WW3D2_Core PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/VulkanBackend
)
target_link_libraries(WW3D2_Core PUBLIC WWLib WWMath)

# Add backend subdirectories
add_subdirectory(VulkanBackend)

# Platform-specific renderer backends
if(WIN32)
    # DX8 Wrapper (legacy, Windows only)
    add_library(WW3D2_DX8 STATIC ${CMAKE_CURRENT_SOURCE_DIR}/dx8wrapper.cpp)
    target_include_directories(WW3D2_DX8 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(WW3D2_DX8 PUBLIC WW3D2_Core)
    target_compile_definitions(WW3D2_DX8 PRIVATE DX8_BACKEND_ENABLED)
endif()

# Meta-library that includes all available backends
add_library(WW3D2 INTERFACE)
target_link_libraries(WW3D2 INTERFACE 
    WW3D2_Core
    $<TARGET_NAME_IF_EXISTS:VulkanBackend>
    $<TARGET_NAME_IF_EXISTS:WW3D2_DX8>
)
