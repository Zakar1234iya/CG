#include "VulkanRenderDevice.h"
#include "CrossPlatform.h"
#include <cstring>
#include <algorithm>
#include <set>

// Vulkan function pointers (loaded dynamically)
PFN_vkCreateInstance vkCreateInstance = nullptr;
PFN_vkDestroyInstance vkDestroyInstance = nullptr;
PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices = nullptr;
PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties = nullptr;
PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties = nullptr;
PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR = nullptr;
PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR = nullptr;
PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR = nullptr;
PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR = nullptr;
PFN_vkCreateDevice vkCreateDevice = nullptr;
PFN_vkDestroyDevice vkDestroyDevice = nullptr;
PFN_vkGetDeviceQueue vkGetDeviceQueue = nullptr;
PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR = nullptr;
PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR = nullptr;
PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR = nullptr;
PFN_vkCreateImageView vkCreateImageView = nullptr;
PFN_vkDestroyImageView vkDestroyImageView = nullptr;
PFN_vkCreateRenderPass vkCreateRenderPass = nullptr;
PFN_vkDestroyRenderPass vkDestroyRenderPass = nullptr;
PFN_vkCreateFramebuffer vkCreateFramebuffer = nullptr;
PFN_vkDestroyFramebuffer vkDestroyFramebuffer = nullptr;
PFN_vkCreateCommandPool vkCreateCommandPool = nullptr;
PFN_vkDestroyCommandPool vkDestroyCommandPool = nullptr;
PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers = nullptr;
PFN_vkBeginCommandBuffer vkBeginCommandBuffer = nullptr;
PFN_vkEndCommandBuffer vkEndCommandBuffer = nullptr;
PFN_vkQueueSubmit vkQueueSubmit = nullptr;
PFN_vkQueueWaitIdle vkQueueWaitIdle = nullptr;
PFN_vkCreateSemaphore vkCreateSemaphore = nullptr;
PFN_vkDestroySemaphore vkDestroySemaphore = nullptr;
PFN_vkCreateFence vkCreateFence = nullptr;
PFN_vkDestroyFence vkDestroyFence = nullptr;
PFN_vkWaitForFences vkWaitForFences = nullptr;
PFN_vkResetFences vkResetFences = nullptr;
PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR = nullptr;
PFN_vkQueuePresentKHR vkQueuePresentKHR = nullptr;
PFN_vkCmdBindPipeline vkCmdBindPipeline = nullptr;
PFN_vkCmdSetViewport vkCmdSetViewport = nullptr;
PFN_vkCmdSetScissor vkCmdSetScissor = nullptr;
PFN_vkCmdDraw vkCmdDraw = nullptr;
PFN_vkCmdDrawIndexed vkCmdDrawIndexed = nullptr;
PFN_vkCmdClearAttachments vkCmdClearAttachments = nullptr;
PFN_vkMapMemory vkMapMemory = nullptr;
PFN_vkUnmapMemory vkUnmapMemory = nullptr;
PFN_vkCreateBuffer vkCreateBuffer = nullptr;
PFN_vkAllocateMemory vkAllocateMemory = nullptr;
PFN_vkBindBufferMemory vkBindBufferMemory = nullptr;
PFN_vkDestroyBuffer vkDestroyBuffer = nullptr;
PFN_vkFreeMemory vkFreeMemory = nullptr;
PFN_vkCreateImage vkCreateImage = nullptr;
PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements = nullptr;
PFN_vkBindImageMemory vkBindImageMemory = nullptr;
PFN_vkCreateSampler vkCreateSampler = nullptr;
PFN_vkDestroySampler vkDestroySampler = nullptr;
PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets = nullptr;

#ifdef VK_USE_PLATFORM_WIN32_KHR
PFN_vkCreateWin32SurfaceKHR vkCreateWin32SurfaceKHR = nullptr;
#endif

#ifdef VK_USE_PLATFORM_XLIB_KHR
PFN_vkCreateXlibSurfaceKHR vkCreateXlibSurfaceKHR = nullptr;
#endif

VulkanRenderDevice::VulkanRenderDevice() 
    : m_windowWidth(0), m_windowHeight(0)
{
    memset(&m_caps, 0, sizeof(m_caps));
    memset(&m_viewport, 0, sizeof(m_viewport));
}

VulkanRenderDevice::~VulkanRenderDevice()
{
    Shutdown();
}

bool VulkanRenderDevice::Initialize(void* windowHandle, int width, int height, bool fullscreen)
{
    m_windowWidth = width;
    m_windowHeight = height;

    // Load Vulkan library and get function pointers
    // (In production, use volk or similar loader)
    
    if (!CreateInstance()) {
        return false;
    }

    if (!CreateSurface(windowHandle)) {
        vkDestroyInstance(m_instance, nullptr);
        return false;
    }

    if (!SelectPhysicalDevice()) {
        CleanupSwapChain();
        vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        vkDestroyInstance(m_instance, nullptr);
        return false;
    }

    if (!CreateLogicalDevice()) {
        CleanupSwapChain();
        vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        vkDestroyInstance(m_instance, nullptr);
        return false;
    }

    if (!CreateSwapChain(width, height)) {
        vkDestroyDevice(m_device, nullptr);
        CleanupSwapChain();
        vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        vkDestroyInstance(m_instance, nullptr);
        return false;
    }

    if (!CreateImageViews()) {
        CleanupSwapChain();
        vkDestroyDevice(m_device, nullptr);
        vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        vkDestroyInstance(m_instance, nullptr);
        return false;
    }

    if (!CreateRenderPass()) {
        CleanupSwapChain();
        vkDestroyDevice(m_device, nullptr);
        vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        vkDestroyInstance(m_instance, nullptr);
        return false;
    }

    if (!CreateFramebuffers()) {
        CleanupSwapChain();
        vkDestroyDevice(m_device, nullptr);
        vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        vkDestroyInstance(m_instance, nullptr);
        return false;
    }

    if (!CreateCommandPool()) {
        CleanupSwapChain();
        vkDestroyDevice(m_device, nullptr);
        vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        vkDestroyInstance(m_instance, nullptr);
        return false;
    }

    if (!CreateCommandBuffers()) {
        CleanupSwapChain();
        vkDestroyDevice(m_device, nullptr);
        vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        vkDestroyInstance(m_instance, nullptr);
        return false;
    }

    if (!CreateSyncObjects()) {
        CleanupSwapChain();
        vkDestroyDevice(m_device, nullptr);
        vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
        vkDestroyInstance(m_instance, nullptr);
        return false;
    }

    // Set device capabilities
    VkPhysicalDeviceProperties props;
    vkGetPhysicalDeviceProperties(m_physicalDevice, &props);
    
    m_caps.max_texture_width = props.limits.maxImageDimension2D;
    m_caps.max_texture_height = props.limits.maxImageDimension2D;
    m_caps.max_texture_stages = 8; // Vulkan supports many stages
    m_caps.max_vertex_buffers = VK_MAX_DESCRIPTION_SETS;
    m_caps.supports_hw_transform_and_light = true;
    m_caps.supports_pixel_shader_1_1 = true;
    m_caps.supports_pixel_shader_2_0 = true;
    m_caps.supports_vertex_shader_1_1 = true;
    m_caps.supports_vertex_shader_2_0 = true;
    
    strncpy(m_caps.device_name, props.deviceName, sizeof(m_caps.device_name) - 1);
    
    // Set default viewport
    m_viewport.x = 0;
    m_viewport.y = 0;
    m_viewport.width = static_cast<float>(width);
    m_viewport.height = static_cast<float>(height);
    m_viewport.minZ = 0.0f;
    m_viewport.maxZ = 1.0f;

    return true;
}

void VulkanRenderDevice::Shutdown()
{
    if (m_device == VK_NULL_HANDLE) return;  // Already shut down or never initialized

    vkDeviceWaitIdle(m_device);

    // Cleanup sync objects
    for (size_t i = 0; i < m_inFlightFences.size(); i++) {
        vkDestroySemaphore(m_device, m_imageAvailableSemaphores[i], nullptr);
        vkDestroySemaphore(m_device, m_renderFinishedSemaphores[i], nullptr);
        vkDestroyFence(m_device, m_inFlightFences[i], nullptr);
    }
    m_imageAvailableSemaphores.clear();
    m_renderFinishedSemaphores.clear();
    m_inFlightFences.clear();

    // Cleanup command buffers and pool
    vkDestroyCommandPool(m_device, m_commandPool, nullptr);

    // Cleanup framebuffers
    for (auto framebuffer : m_swapChainFramebuffers) {
        vkDestroyFramebuffer(m_device, framebuffer, nullptr);
    }
    m_swapChainFramebuffers.clear();

    // Cleanup render pass
    vkDestroyRenderPass(m_device, m_renderPass, nullptr);

    // Cleanup pipeline
    if (m_graphicsPipeline != VK_NULL_HANDLE) {
        vkDestroyPipeline(m_device, m_graphicsPipeline, nullptr);
    }
    if (m_pipelineLayout != VK_NULL_HANDLE) {
        vkDestroyPipelineLayout(m_device, m_pipelineLayout, nullptr);
    }

    // Cleanup image views
    for (auto imageView : m_swapChainImageViews) {
        vkDestroyImageView(m_device, imageView, nullptr);
    }
    m_swapChainImageViews.clear();

    // Cleanup swap chain
    vkDestroySwapchainKHR(m_device, m_swapChain, nullptr);

    // Cleanup device and instance
    vkDestroyDevice(m_device, nullptr);
    vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
    
#ifdef VK_EXT_DEBUG_UTILS_EXTENSION_NAME
    if (m_debugMessenger != VK_NULL_HANDLE) {
        // Destroy debug messenger (function loaded dynamically)
    }
#endif
    
    vkDestroyInstance(m_instance, nullptr);

    m_instance = VK_NULL_HANDLE;
    m_physicalDevice = VK_NULL_HANDLE;
    m_device = VK_NULL_HANDLE;
    m_surface = VK_NULL_HANDLE;
}

void VulkanRenderDevice::BeginFrame()
{
    // Wait for previous frame
    vkWaitForFences(m_device, 1, &m_inFlightFences[m_currentFrame], VK_TRUE, UINT64_MAX);
    vkResetFences(m_device, 1, &m_inFlightFences[m_currentFrame]);

    // Acquire next image
    VkResult result = vkAcquireNextImageKHR(m_device, m_swapChain, UINT64_MAX,
                                            m_imageAvailableSemaphores[m_currentFrame],
                                            VK_NULL_HANDLE, &m_imageIndex);

    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || m_framebufferResized) {
        m_framebufferResized = false;
        RecreateSwapChain(m_windowWidth, m_windowHeight);
        return;
    } else if (result != VK_SUCCESS) {
        // Log error instead of throwing in game engine frame loop
        WWDEBUG_SAY(("Failed to acquire swap chain image! Result: %d\n", result));
        return;
    }

    // Begin command buffer
    VkCommandBufferBeginInfo beginInfo{};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = 0;
    beginInfo.pInheritanceInfo = nullptr;

    if (vkBeginCommandBuffer(m_commandBuffers[m_imageIndex], &beginInfo) != VK_SUCCESS) {
        throw std::runtime_error("Failed to begin recording command buffer!");
    }
}

void VulkanRenderDevice::EndFrame()
{
    if (vkEndCommandBuffer(m_commandBuffers[m_imageIndex]) != VK_SUCCESS) {
        throw std::runtime_error("Failed to record command buffer!");
    }

    // Submit command buffer
    VkSubmitInfo submitInfo{};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore waitSemaphores[] = {m_imageAvailableSemaphores[m_currentFrame]};
    VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = waitSemaphores;
    submitInfo.pWaitDstStageMask = waitStages;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &m_commandBuffers[m_imageIndex];

    VkSemaphore signalSemaphores[] = {m_renderFinishedSemaphores[m_currentFrame]};
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signalSemaphores;

    if (vkQueueSubmit(m_graphicsQueue, 1, &submitInfo, m_inFlightFences[m_currentFrame]) != VK_SUCCESS) {
        throw std::runtime_error("Failed to submit draw command buffer!");
    }
}

void VulkanRenderDevice::Present()
{
    VkPresentInfoKHR presentInfo{};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    VkSemaphore waitSemaphores[] = {m_renderFinishedSemaphores[m_currentFrame]};
    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = waitSemaphores;

    VkSwapchainKHR swapChains[] = {m_swapChain};
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapChains;
    presentInfo.pImageIndices = &m_imageIndex;

    VkResult result = vkQueuePresentKHR(m_presentQueue, &presentInfo);

    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || m_framebufferResized) {
        m_framebufferResized = false;
        RecreateSwapChain(m_windowWidth, m_windowHeight);
    } else if (result != VK_SUCCESS) {
        throw std::runtime_error("Failed to present swap chain image!");
    }

    m_currentFrame = (m_currentFrame + 1) % 3; // Triple buffering
}

void VulkanRenderDevice::SetRenderState(RenderState state, uint32_t value)
{
    // Vulkan uses pipeline state objects, so render states are set during pipeline creation
    // For dynamic states, we would use vkCmdSet* functions
    // This is a simplified implementation
}

void VulkanRenderDevice::SetTextureStageState(uint32_t stage, TextureStageState state, uint32_t value)
{
    // Similar to render states, texture states are part of pipeline/descriptor sets
}

void VulkanRenderDevice::SetTransform(TransformType type, const Matrix4& matrix)
{
    // Transforms are handled via uniform buffers in Vulkan
    // Would update the appropriate uniform buffer here
}

bool VulkanRenderDevice::CreateTexture(TextureHandle* handle, uint32_t width, uint32_t height,
                                       TextureFormat format, const void* data)
{
    // TODO: Implement texture creation
    // Create VkImage, allocate memory, copy data, create VkImageView and VkSampler
    return false;
}

void VulkanRenderDevice::DestroyTexture(TextureHandle handle)
{
    // TODO: Implement texture destruction
}

void VulkanRenderDevice::SetTexture(uint32_t stage, TextureHandle handle)
{
    // TODO: Bind texture to descriptor set
}

bool VulkanRenderDevice::CreateVertexBuffer(VertexBufferHandle* handle, uint32_t size,
                                           const void* data, UsageHint usage)
{
    // TODO: Implement vertex buffer creation
    return false;
}

bool VulkanRenderDevice::CreateIndexBuffer(IndexBufferHandle* handle, uint32_t size,
                                          const void* data, IndexFormat format, UsageHint usage)
{
    // TODO: Implement index buffer creation
    return false;
}

void VulkanRenderDevice::DestroyVertexBuffer(VertexBufferHandle handle)
{
    // TODO: Implement vertex buffer destruction
}

void VulkanRenderDevice::DestroyIndexBuffer(IndexBufferHandle handle)
{
    // TODO: Implement index buffer destruction
}

void* VulkanRenderDevice::MapVertexBuffer(VertexBufferHandle handle, MapType mapType)
{
    // TODO: Implement vertex buffer mapping
    return nullptr;
}

void VulkanRenderDevice::UnmapVertexBuffer(VertexBufferHandle handle)
{
    // TODO: Implement vertex buffer unmapping
}

void* VulkanRenderDevice::MapIndexBuffer(IndexBufferHandle handle, MapType mapType)
{
    // TODO: Implement index buffer mapping
    return nullptr;
}

void VulkanRenderDevice::UnmapIndexBuffer(IndexBufferHandle handle)
{
    // TODO: Implement index buffer unmapping
}

void VulkanRenderDevice::DrawPrimitive(PrimitiveType type, uint32_t startVertex, uint32_t vertexCount)
{
    VkPrimitiveTopology topology;
    switch (type) {
        case PT_POINT_LIST: topology = VK_PRIMITIVE_TOPOLOGY_POINT_LIST; break;
        case PT_LINE_LIST: topology = VK_PRIMITIVE_TOPOLOGY_LINE_LIST; break;
        case PT_LINE_STRIP: topology = VK_PRIMITIVE_TOPOLOGY_LINE_STRIP; break;
        case PT_TRIANGLE_LIST: topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST; break;
        case PT_TRIANGLE_STRIP: topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP; break;
        default: return;
    }

    // Pipeline should already be bound with correct topology
    vkCmdDraw(m_commandBuffers[m_imageIndex], vertexCount, 1, startVertex, 0);
}

void VulkanRenderDevice::DrawIndexedPrimitive(PrimitiveType type, uint32_t startIndex,
                                             uint32_t indexCount, uint32_t vertexOffset)
{
    VkPrimitiveTopology topology;
    switch (type) {
        case PT_POINT_LIST: topology = VK_PRIMITIVE_TOPOLOGY_POINT_LIST; break;
        case PT_LINE_LIST: topology = VK_PRIMITIVE_TOPOLOGY_LINE_LIST; break;
        case PT_LINE_STRIP: topology = VK_PRIMITIVE_TOPOLOGY_LINE_STRIP; break;
        case PT_TRIANGLE_LIST: topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST; break;
        case PT_TRIANGLE_STRIP: topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP; break;
        default: return;
    }

    vkCmdDrawIndexed(m_commandBuffers[m_imageIndex], indexCount, 1, startIndex, vertexOffset, 0);
}

void VulkanRenderDevice::SetViewport(const Viewport& viewport)
{
    m_viewport = viewport;

    VkViewport vkViewport{};
    vkViewport.x = viewport.x;
    vkViewport.y = viewport.y;
    vkViewport.width = viewport.width;
    vkViewport.height = viewport.height;
    vkViewport.minDepth = viewport.minZ;
    vkViewport.maxDepth = viewport.maxZ;

    vkCmdSetViewport(m_commandBuffers[m_imageIndex], 0, 1, &vkViewport);

    VkRect2D scissor{};
    scissor.offset = {static_cast<int32_t>(viewport.x), static_cast<int32_t>(viewport.y)};
    scissor.extent = {static_cast<uint32_t>(viewport.width), static_cast<uint32_t>(viewport.height)};
    vkCmdSetScissor(m_commandBuffers[m_imageIndex], 0, 1, &scissor);
}

void VulkanRenderDevice::Clear(ClearFlags flags, uint32_t color, float depth, uint8_t stencil)
{
    std::vector<VkClearAttachment> clearAttachments;
    std::vector<VkClearRect> clearRects;

    VkClearRect clearRect{};
    clearRect.rect.offset = {0, 0};
    clearRect.rect.extent = {m_swapChainExtent.width, m_swapChainExtent.height};
    clearRect.baseArrayLayer = 0;
    clearRect.layerCount = 1;

    if (flags & CLEAR_COLOR) {
        VkClearAttachment colorClear{};
        colorClear.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        colorClear.colorAttachment = 0;
        colorClear.clearValue.color.float32[0] = ((color >> 16) & 0xFF) / 255.0f;
        colorClear.clearValue.color.float32[1] = ((color >> 8) & 0xFF) / 255.0f;
        colorClear.clearValue.color.float32[2] = (color & 0xFF) / 255.0f;
        colorClear.clearValue.color.float32[3] = ((color >> 24) & 0xFF) / 255.0f;
        clearAttachments.push_back(colorClear);
    }

    if (flags & CLEAR_DEPTH) {
        VkClearAttachment depthClear{};
        depthClear.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
        depthClear.clearValue.depthStencil.depth = depth;
        clearAttachments.push_back(depthClear);
    }

    if (flags & CLEAR_STENCIL) {
        if (clearAttachments.empty() || clearAttachments.back().aspectMask != VK_IMAGE_ASPECT_DEPTH_BIT) {
            VkClearAttachment stencilClear{};
            stencilClear.aspectMask = VK_IMAGE_ASPECT_STENCIL_BIT;
            stencilClear.clearValue.depthStencil.stencil = stencil;
            clearAttachments.push_back(stencilClear);
        } else {
            clearAttachments.back().clearValue.depthStencil.stencil = stencil;
        }
    }

    if (!clearAttachments.empty()) {
        vkCmdClearAttachments(m_commandBuffers[m_imageIndex], 
                             static_cast<uint32_t>(clearAttachments.size()),
                             clearAttachments.data(), 1, &clearRect);
    }
}

bool VulkanRenderDevice::CreateShader(ShaderHandle* handle, const char* source, ShaderType type)
{
    // TODO: Compile SPIR-V shader and create VkShaderModule
    return false;
}

void VulkanRenderDevice::DestroyShader(ShaderHandle handle)
{
    // TODO: Destroy shader module
}

void VulkanRenderDevice::SetShader(ShaderHandle handle)
{
    // TODO: Bind shader pipeline
}

void VulkanRenderDevice::SetShaderConstant(const char* name, const void* data, uint32_t size)
{
    // TODO: Update uniform buffer
}

// ============================================================================
// Private Helper Methods
// ============================================================================

bool VulkanRenderDevice::CreateInstance()
{
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Generals Vulkan";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "WW3D2";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_2;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // Get required extensions
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = nullptr; // Would get from window system
    
    std::vector<const char*> extensions;
    // Add platform-specific surface extension
#ifdef VK_USE_PLATFORM_WIN32_KHR
    extensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
#endif
#ifdef VK_USE_PLATFORM_XLIB_KHR
    extensions.push_back(VK_KHR_XLIB_SURFACE_EXTENSION_NAME);
#endif
    extensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);

    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

    if (m_enableValidationLayers) {
        createInfo.enabledLayerCount = static_cast<uint32_t>(m_validationLayers.size());
        createInfo.ppEnabledLayerNames = m_validationLayers.data();

        // Add debug messenger
        // (Implementation omitted for brevity)
    } else {
        createInfo.enabledLayerCount = 0;
    }

    if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS) {
        return false;
    }

    return true;
}

bool VulkanRenderDevice::CreateSurface(void* windowHandle)
{
#ifdef VK_USE_PLATFORM_WIN32_KHR
    // Windows implementation
    VkWin32SurfaceCreateInfoKHR createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    createInfo.hwnd = windowHandle;
    createInfo.hinstance = GetModuleHandle(nullptr);
    
    if (vkCreateWin32SurfaceKHR(m_instance, &createInfo, nullptr, &m_surface) != VK_SUCCESS) {
        return false;
    }
#elif defined(VK_USE_PLATFORM_XLIB_KHR)
    // X11 implementation
    // (Implementation omitted)
#endif
    
    return m_surface != VK_NULL_HANDLE;
}

bool VulkanRenderDevice::SelectPhysicalDevice()
{
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(m_instance, &deviceCount, nullptr);

    if (deviceCount == 0) {
        return false;
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(m_instance, &deviceCount, devices.data());

    for (const auto& device : devices) {
        if (IsDeviceSuitable(device)) {
            m_physicalDevice = device;
            return true;
        }
    }

    return false;
}

bool VulkanRenderDevice::CreateLogicalDevice()
{
    QueueFamilyIndices indices = FindQueueFamilies(m_physicalDevice);

    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    std::set<uint32_t> uniqueQueueFamilies = {
        static_cast<uint32_t>(indices.graphicsFamily),
        static_cast<uint32_t>(indices.presentFamily)
    };

    float queuePriority = 1.0f;
    for (uint32_t queueFamily : uniqueQueueFamilies) {
        VkDeviceQueueCreateInfo queueCreateInfo{};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = queueFamily;
        queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = &queuePriority;
        queueCreateInfos.push_back(queueCreateInfo);
    }

    VkPhysicalDeviceFeatures deviceFeatures{};

    VkDeviceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
    createInfo.pQueueCreateInfos = queueCreateInfos.data();
    createInfo.pEnabledFeatures = &deviceFeatures;
    createInfo.enabledExtensionCount = static_cast<uint32_t>(m_deviceExtensions.size());
    createInfo.ppEnabledExtensionNames = m_deviceExtensions.data();

    if (m_enableValidationLayers) {
        createInfo.enabledLayerCount = static_cast<uint32_t>(m_validationLayers.size());
        createInfo.ppEnabledLayerNames = m_validationLayers.data();
    } else {
        createInfo.enabledLayerCount = 0;
    }

    if (vkCreateDevice(m_physicalDevice, &createInfo, nullptr, &m_device) != VK_SUCCESS) {
        return false;
    }

    vkGetDeviceQueue(m_device, indices.graphicsFamily, 0, &m_graphicsQueue);
    vkGetDeviceQueue(m_device, indices.presentFamily, 0, &m_presentQueue);

    return true;
}

bool VulkanRenderDevice::CreateSwapChain(int width, int height)
{
    SwapChainSupport support = QuerySwapChainSupport(m_physicalDevice);

    VkSurfaceFormatKHR surfaceFormat = ChooseSwapSurfaceFormat(support.formats);
    VkPresentModeKHR presentMode = ChooseSwapPresentMode(support.presentModes);
    VkExtent2D extent = ChooseSwapExtent(support.capabilities, width, height);

    uint32_t imageCount = support.capabilities.minImageCount + 1;
    if (support.capabilities.maxImageCount > 0 && imageCount > support.capabilities.maxImageCount) {
        imageCount = support.capabilities.maxImageCount;
    }

    VkSwapchainCreateInfoKHR createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    createInfo.surface = m_surface;
    createInfo.minImageCount = imageCount;
    createInfo.imageFormat = surfaceFormat.format;
    createInfo.imageColorSpace = surfaceFormat.colorSpace;
    createInfo.imageExtent = extent;
    createInfo.imageArrayLayers = 1;
    createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

    QueueFamilyIndices indices = FindQueueFamilies(m_physicalDevice);
    uint32_t queueFamilyIndices[] = {
        static_cast<uint32_t>(indices.graphicsFamily),
        static_cast<uint32_t>(indices.presentFamily)
    };

    if (indices.graphicsFamily != indices.presentFamily) {
        createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
        createInfo.queueFamilyIndexCount = 2;
        createInfo.pQueueFamilyIndices = queueFamilyIndices;
    } else {
        createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    }

    createInfo.preTransform = support.capabilities.currentTransform;
    createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    createInfo.presentMode = presentMode;
    createInfo.clipped = VK_TRUE;
    createInfo.oldSwapchain = VK_NULL_HANDLE;

    if (vkCreateSwapchainKHR(m_device, &createInfo, nullptr, &m_swapChain) != VK_SUCCESS) {
        return false;
    }

    vkGetSwapchainImagesKHR(m_device, m_swapChain, &imageCount, nullptr);
    m_swapChainImages.resize(imageCount);
    vkGetSwapchainImagesKHR(m_device, m_swapChain, &imageCount, m_swapChainImages.data());

    m_swapChainImageFormat = surfaceFormat.format;
    m_swapChainExtent = extent;

    return true;
}

bool VulkanRenderDevice::CreateImageViews()
{
    m_swapChainImageViews.resize(m_swapChainImages.size());

    for (size_t i = 0; i < m_swapChainImages.size(); i++) {
        VkImageViewCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        createInfo.image = m_swapChainImages[i];
        createInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        createInfo.format = m_swapChainImageFormat;
        createInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
        createInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        createInfo.subresourceRange.baseMipLevel = 0;
        createInfo.subresourceRange.levelCount = 1;
        createInfo.subresourceRange.baseArrayLayer = 0;
        createInfo.subresourceRange.layerCount = 1;

        if (vkCreateImageView(m_device, &createInfo, nullptr, &m_swapChainImageViews[i]) != VK_SUCCESS) {
            return false;
        }
    }

    return true;
}

bool VulkanRenderDevice::CreateRenderPass()
{
    VkAttachmentDescription colorAttachment{};
    colorAttachment.format = m_swapChainImageFormat;
    colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
    colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    colorAttachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    VkAttachmentReference colorAttachmentRef{};
    colorAttachmentRef.attachment = 0;
    colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass{};
    subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments = &colorAttachmentRef;

    VkSubpassDependency dependency{};
    dependency.srcSubpass = VK_SUBPASS_EXTERNAL;
    dependency.dstSubpass = 0;
    dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.srcAccessMask = 0;
    dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;

    VkRenderPassCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    createInfo.attachmentCount = 1;
    createInfo.pAttachments = &colorAttachment;
    createInfo.subpassCount = 1;
    createInfo.pSubpasses = &subpass;
    createInfo.dependencyCount = 1;
    createInfo.pDependencies = &dependency;

    if (vkCreateRenderPass(m_device, &createInfo, nullptr, &m_renderPass) != VK_SUCCESS) {
        return false;
    }

    return true;
}

bool VulkanRenderDevice::CreateFramebuffers()
{
    m_swapChainFramebuffers.resize(m_swapChainImageViews.size());

    for (size_t i = 0; i < m_swapChainImageViews.size(); i++) {
        VkImageView attachments[] = {
            m_swapChainImageViews[i]
        };

        VkFramebufferCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        createInfo.renderPass = m_renderPass;
        createInfo.attachmentCount = 1;
        createInfo.pAttachments = attachments;
        createInfo.width = m_swapChainExtent.width;
        createInfo.height = m_swapChainExtent.height;
        createInfo.layers = 1;

        if (vkCreateFramebuffer(m_device, &createInfo, nullptr, &m_swapChainFramebuffers[i]) != VK_SUCCESS) {
            return false;
        }
    }

    return true;
}

bool VulkanRenderDevice::CreateCommandPool()
{
    QueueFamilyIndices queueFamilyIndices = FindQueueFamilies(m_physicalDevice);

    VkCommandPoolCreateInfo poolInfo{};
    poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily;
    poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

    if (vkCreateCommandPool(m_device, &poolInfo, nullptr, &m_commandPool) != VK_SUCCESS) {
        return false;
    }

    return true;
}

bool VulkanRenderDevice::CreateCommandBuffers()
{
    m_commandBuffers.resize(m_swapChainFramebuffers.size());

    VkCommandBufferAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.commandPool = m_commandPool;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandBufferCount = static_cast<uint32_t>(m_commandBuffers.size());

    if (vkAllocateCommandBuffers(m_device, &allocInfo, m_commandBuffers.data()) != VK_SUCCESS) {
        return false;
    }

    return true;
}

bool VulkanRenderDevice::CreateSyncObjects()
{
    m_imageAvailableSemaphores.resize(3);
    m_renderFinishedSemaphores.resize(3);
    m_inFlightFences.resize(3);

    VkSemaphoreCreateInfo semaphoreInfo{};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkFenceCreateInfo fenceInfo{};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    for (size_t i = 0; i < 3; i++) {
        if (vkCreateSemaphore(m_device, &semaphoreInfo, nullptr, &m_imageAvailableSemaphores[i]) != VK_SUCCESS ||
            vkCreateSemaphore(m_device, &semaphoreInfo, nullptr, &m_renderFinishedSemaphores[i]) != VK_SUCCESS ||
            vkCreateFence(m_device, &fenceInfo, nullptr, &m_inFlightFences[i]) != VK_SUCCESS) {
            return false;
        }
    }

    return true;
}

void VulkanRenderDevice::CleanupSwapChain()
{
    for (auto framebuffer : m_swapChainFramebuffers) {
        vkDestroyFramebuffer(m_device, framebuffer, nullptr);
    }
    m_swapChainFramebuffers.clear();

    for (auto imageView : m_swapChainImageViews) {
        vkDestroyImageView(m_device, imageView, nullptr);
    }
    m_swapChainImageViews.clear();

    if (m_swapChain != VK_NULL_HANDLE) {
        vkDestroySwapchainKHR(m_device, m_swapChain, nullptr);
        m_swapChain = VK_NULL_HANDLE;
    }
}

void VulkanRenderDevice::RecreateSwapChain(int width, int height)
{
    vkDeviceWaitIdle(m_device);

    CleanupSwapChain();
    CreateSwapChain(width, height);
    CreateImageViews();
    CreateFramebuffers();
}

VulkanRenderDevice::QueueFamilyIndices VulkanRenderDevice::FindQueueFamilies(VkPhysicalDevice device)
{
    QueueFamilyIndices indices;

    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    int i = 0;
    for (const auto& queueFamily : queueFamilies) {
        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.graphicsFamily = i;
        }

        VkBool32 presentSupport = false;
        vkGetPhysicalDeviceSurfaceSupportKHR(device, i, m_surface, &presentSupport);

        if (presentSupport) {
            indices.presentFamily = i;
        }

        if (indices.IsComplete()) {
            break;
        }

        i++;
    }

    return indices;
}

VulkanRenderDevice::SwapChainSupport VulkanRenderDevice::QuerySwapChainSupport(VkPhysicalDevice device)
{
    SwapChainSupport support;

    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, m_surface, &support.capabilities);

    uint32_t formatCount;
    vkGetPhysicalDeviceSurfaceFormatsKHR(device, m_surface, &formatCount, nullptr);

    if (formatCount != 0) {
        support.formats.resize(formatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(device, m_surface, &formatCount, support.formats.data());
    }

    uint32_t presentModeCount;
    vkGetPhysicalDeviceSurfacePresentModesKHR(device, m_surface, &presentModeCount, nullptr);

    if (presentModeCount != 0) {
        support.presentModes.resize(presentModeCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(device, m_surface, &presentModeCount, support.presentModes.data());
    }

    return support;
}

bool VulkanRenderDevice::IsDeviceSuitable(VkPhysicalDevice device)
{
    QueueFamilyIndices indices = FindQueueFamilies(device);

    bool extensionsSupported = CheckDeviceExtensionSupport(device);

    bool swapChainAdequate = false;
    if (extensionsSupported) {
        SwapChainSupport support = QuerySwapChainSupport(device);
        swapChainAdequate = !support.formats.empty() && !support.presentModes.empty();
    }

    return indices.IsComplete() && extensionsSupported && swapChainAdequate;
}

bool VulkanRenderDevice::CheckDeviceExtensionSupport(VkPhysicalDevice device)
{
    uint32_t extensionCount;
    vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> availableExtensions(extensionCount);
    vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, availableExtensions.data());

    std::set<std::string> requiredExtensions(m_deviceExtensions.begin(), m_deviceExtensions.end());

    for (const auto& extension : availableExtensions) {
        requiredExtensions.erase(extension.extensionName);
    }

    return requiredExtensions.empty();
}

VkSurfaceFormatKHR VulkanRenderDevice::ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& formats)
{
    if (formats.empty()) {
        return {VK_FORMAT_B8G8R8A8_SRGB, VK_COLOR_SPACE_SRGB_NONLINEAR_KHR};
    }

    for (const auto& availableFormat : formats) {
        if (availableFormat.format == VK_FORMAT_B8G8R8A8_SRGB && 
            availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
            return availableFormat;
        }
    }

    return formats[0];
}

VkPresentModeKHR VulkanRenderDevice::ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& modes)
{
    for (const auto& mode : modes) {
        if (mode == VK_PRESENT_MODE_MAILBOX_KHR) {
            return mode;
        }
    }

    for (const auto& mode : modes) {
        if (mode == VK_PRESENT_MODE_IMMEDIATE_KHR) {
            return mode;
        }
    }

    return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D VulkanRenderDevice::ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities,
                                                int width, int height)
{
    if (capabilities.currentExtent.width != UINT32_MAX) {
        return capabilities.currentExtent;
    }

    VkExtent2D actualExtent = {static_cast<uint32_t>(width), static_cast<uint32_t>(height)};

    actualExtent.width = std::max(capabilities.minImageExtent.width,
                                  std::min(capabilities.maxImageExtent.width, actualExtent.width));
    actualExtent.height = std::max(capabilities.minImageExtent.height,
                                   std::min(capabilities.maxImageExtent.height, actualExtent.height));

    return actualExtent;
}

uint32_t VulkanRenderDevice::FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties)
{
    VkPhysicalDeviceMemoryProperties memProperties;
    vkGetPhysicalDeviceMemoryProperties(m_physicalDevice, &memProperties);

    for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
        if ((typeFilter & (1 << i)) && 
            (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
            return i;
        }
    }

    throw std::runtime_error("Failed to find suitable memory type!");
}

void VulkanRenderDevice::CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
                                     VkMemoryPropertyFlags properties, VkBuffer& buffer,
                                     VkDeviceMemory& bufferMemory)
{
    VkBufferCreateInfo bufferInfo{};
    bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferInfo.size = size;
    bufferInfo.usage = usage;
    bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    if (vkCreateBuffer(m_device, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create buffer!");
    }

    VkMemoryRequirements memRequirements;
    vkGetBufferMemoryRequirements(m_device, buffer, &memRequirements);

    VkMemoryAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memRequirements.size;
    allocInfo.memoryTypeIndex = FindMemoryType(memRequirements.memoryTypeBits, properties);

    if (vkAllocateMemory(m_device, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS) {
        throw std::runtime_error("Failed to allocate buffer memory!");
    }

    vkBindBufferMemory(m_device, buffer, bufferMemory, 0);
}
