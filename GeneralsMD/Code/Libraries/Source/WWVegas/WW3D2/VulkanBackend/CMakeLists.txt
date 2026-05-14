# Vulkan Backend CMakeLists.txt
# Phase 4: Modern Renderer Implementation

find_package(Vulkan QUIET)

if(Vulkan_FOUND)
    message(STATUS "Vulkan SDK found: ${Vulkan_INCLUDE_DIRS}")
    
    add_library(VulkanBackend STATIC
        VulkanRenderDevice.h
        VulkanRenderDevice.cpp
    )
    
    target_include_directories(VulkanBackend PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${Vulkan_INCLUDE_DIRS}
        ..
    )
    
    target_link_libraries(VulkanBackend PUBLIC
        Vulkan::Vulkan
        WW3D2_Core
    )
    
    target_compile_definitions(VulkanBackend PUBLIC
        VULKAN_BACKEND_ENABLED
        VK_NO_PROTOTYPES
    )
    
    # Enable Vulkan validation layers in debug builds
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_definitions(VulkanBackend PRIVATE
            VULKAN_VALIDATION_LAYERS_ENABLED
        )
    endif()
else()
    message(WARNING "Vulkan SDK not found. Vulkan backend will not be built.")
    
    # Create empty interface library as placeholder
    add_library(VulkanBackend INTERFACE)
    target_compile_definitions(VulkanBackend INTERFACE
        VULKAN_BACKEND_DISABLED
    )
endif()
