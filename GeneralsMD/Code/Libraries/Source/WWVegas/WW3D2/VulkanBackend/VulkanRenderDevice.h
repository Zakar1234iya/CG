#pragma once

#include "IRenderDevice.h"
#include <vulkan/vulkan.h>
#include <vector>
#include <string>
#include <memory>

/**
 * Vulkan Render Device - Phase 4 Implementation
 * Modern, cross-platform Vulkan backend implementing IRenderDevice
 */
class VulkanRenderDevice : public IRenderDevice
{
public:
    VulkanRenderDevice();
    ~VulkanRenderDevice() override;

    // IRenderDevice Interface
    bool Initialize(void* windowHandle, int width, int height, bool fullscreen) override;
    void Shutdown() override;
    void BeginFrame() override;
    void EndFrame() override;
    void Present() override;
    
    // Device Caps
    const RenderDeviceCaps& GetCaps() const override { return m_caps; }
    
    // State Management
    void SetRenderState(RenderState state, uint32_t value) override;
    void SetTextureStageState(uint32_t stage, TextureStageState state, uint32_t value) override;
    void SetTransform(TransformType type, const Matrix4& matrix) override;
    
    // Texture Management
    bool CreateTexture(TextureHandle* handle, uint32_t width, uint32_t height, 
                       TextureFormat format, const void* data) override;
    void DestroyTexture(TextureHandle handle) override;
    void SetTexture(uint32_t stage, TextureHandle handle) override;
    
    // Buffer Management
    bool CreateVertexBuffer(VertexBufferHandle* handle, uint32_t size, 
                           const void* data, UsageHint usage) override;
    bool CreateIndexBuffer(IndexBufferHandle* handle, uint32_t size,
                          const void* data, IndexFormat format, UsageHint usage) override;
    void DestroyVertexBuffer(VertexBufferHandle handle) override;
    void DestroyIndexBuffer(IndexBufferHandle handle) override;
    void* MapVertexBuffer(VertexBufferHandle handle, MapType mapType) override;
    void UnmapVertexBuffer(VertexBufferHandle handle) override;
    void* MapIndexBuffer(IndexBufferHandle handle, MapType mapType) override;
    void UnmapIndexBuffer(IndexBufferHandle handle) override;
    
    // Drawing
    void DrawPrimitive(PrimitiveType type, uint32_t startVertex, uint32_t vertexCount) override;
    void DrawIndexedPrimitive(PrimitiveType type, uint32_t startIndex, 
                             uint32_t indexCount, uint32_t vertexOffset) override;
    
    // Viewport
    void SetViewport(const Viewport& viewport) override;
    const Viewport& GetViewport() const override { return m_viewport; }
    
    // Clear
    void Clear(ClearFlags flags, uint32_t color, float depth, uint8_t stencil) override;
    
    // Shader Support (Phase 4 Advanced)
    bool CreateShader(ShaderHandle* handle, const char* source, 
                     ShaderType type) override;
    void DestroyShader(ShaderHandle handle) override;
    void SetShader(ShaderHandle handle) override;
    void SetShaderConstant(const char* name, const void* data, uint32_t size) override;

    // Vulkan Specific
    VkInstance GetInstance() const { return m_instance; }
    VkPhysicalDevice GetPhysicalDevice() const { return m_physicalDevice; }
    VkDevice GetDevice() const { return m_device; }
    VkQueue GetGraphicsQueue() const { return m_graphicsQueue; }
    VkRenderPass GetRenderPass() const { return m_renderPass; }
    VkCommandPool GetCommandPool() const { return m_commandPool; }

private:
    struct SwapChainSupport {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    struct QueueFamilyIndices {
        int32_t graphicsFamily = -1;
        int32_t presentFamily = -1;
        
        bool IsComplete() const {
            return graphicsFamily >= 0 && presentFamily >= 0;
        }
    };

    // Initialization helpers
    bool CreateInstance();
    bool CreateSurface(void* windowHandle);
    bool SelectPhysicalDevice();
    bool CreateLogicalDevice();
    bool CreateSwapChain(int width, int height);
    bool CreateImageViews();
    bool CreateRenderPass();
    bool CreateFramebuffers();
    bool CreateCommandPool();
    bool CreateCommandBuffers();
    bool CreateSyncObjects();
    
    void CleanupSwapChain();
    void RecreateSwapChain(int width, int height);
    
    QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
    SwapChainSupport QuerySwapChainSupport(VkPhysicalDevice device);
    bool IsDeviceSuitable(VkPhysicalDevice device);
    bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
    
    VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& formats);
    VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& modes);
    VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, 
                                int width, int height);
    
    uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    
    void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, 
                     VkMemoryPropertyFlags properties, VkBuffer& buffer, 
                     VkDeviceMemory& bufferMemory);
    
    // State tracking
    RenderDeviceCaps m_caps;
    Viewport m_viewport;
    
    // Vulkan objects
    VkInstance m_instance = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT m_debugMessenger = VK_NULL_HANDLE;
    VkSurfaceKHR m_surface = VK_NULL_HANDLE;
    VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
    VkDevice m_device = VK_NULL_HANDLE;
    
    VkQueue m_graphicsQueue = VK_NULL_HANDLE;
    VkQueue m_presentQueue = VK_NULL_HANDLE;
    
    VkSwapchainKHR m_swapChain = VK_NULL_HANDLE;
    std::vector<VkImage> m_swapChainImages;
    VkFormat m_swapChainImageFormat;
    VkExtent2D m_swapChainExtent;
    std::vector<VkImageView> m_swapChainImageViews;
    std::vector<VkFramebuffer> m_swapChainFramebuffers;
    
    VkRenderPass m_renderPass = VK_NULL_HANDLE;
    VkPipelineLayout m_pipelineLayout = VK_NULL_HANDLE;
    VkPipeline m_graphicsPipeline = VK_NULL_HANDLE;
    
    VkCommandPool m_commandPool = VK_NULL_HANDLE;
    std::vector<VkCommandBuffer> m_commandBuffers;
    
    std::vector<VkSemaphore> m_imageAvailableSemaphores;
    std::vector<VkSemaphore> m_renderFinishedSemaphores;
    std::vector<VkFence> m_inFlightFences;
    
    uint32_t m_currentFrame = 0;
    uint32_t m_imageIndex = 0;
    
    bool m_framebufferResized = false;
    int m_windowWidth;
    int m_windowHeight;
    
    // Validation layers (debug builds)
    std::vector<const char*> m_validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };
    
    // Device extensions
    std::vector<const char*> m_deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };
    
#ifdef NDEBUG
    const bool m_enableValidationLayers = false;
#else
    const bool m_enableValidationLayers = true;
#endif
};
