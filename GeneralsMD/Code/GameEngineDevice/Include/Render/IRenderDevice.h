#pragma once
#ifndef __IRENDERDEVICE_H__
#define __IRENDERDEVICE_H__

#include <cstdint>
#include <cstddef>

/**
 * Forward declaration for Matrix4 (defined in Math/Matrix4.h)
 */
struct Matrix4;

/**
 * Render Device Capabilities
 */
struct RenderDeviceCaps
{
    uint32_t maxTextureSize;
    uint32_t maxVertexAttributes;
    uint32_t maxUniformBufferBindings;
    uint32_t maxShaderStorageBufferBindings;
    bool supportsInstancing;
    bool supportsTessellation;
    bool supportsGeometryShaders;
    bool supportsComputeShaders;
    float maxAnisotropy;
};

/**
 * Texture handle type
 */
struct TextureHandle
{
    uint64_t handle;
    bool IsValid() const { return handle != 0; }
    static TextureHandle Invalid() { return { 0 }; }
};

/**
 * Vertex buffer handle type
 */
struct VertexBufferHandle
{
    uint64_t handle;
    bool IsValid() const { return handle != 0; }
    static VertexBufferHandle Invalid() { return { 0 }; }
};

/**
 * Index buffer handle type
 */
struct IndexBufferHandle
{
    uint64_t handle;
    bool IsValid() const { return handle != 0; }
    static IndexBufferHandle Invalid() { return { 0 }; }
};

/**
 * Shader handle type
 */
struct ShaderHandle
{
    uint64_t handle;
    bool IsValid() const { return handle != 0; }
    static ShaderHandle Invalid() { return { 0 }; }
};

/**
 * Buffer usage hints
 */
enum class UsageHint : uint8_t
{
    Static,     // Rarely updated
    Dynamic,    // Updated frequently
    Stream      // Updated every frame
};

/**
 * Map types for buffer mapping
 */
enum class MapType : uint8_t
{
    Read,
    Write,
    ReadWrite
};

/**
 * Primitive types for drawing
 */
enum class PrimitiveType : uint8_t
{
    PointList,
    LineList,
    LineStrip,
    TriangleList,
    TriangleStrip,
    TriangleFan
};

/**
 * Transform types
 */
enum class TransformType : uint8_t
{
    World,
    View,
    Projection,
    Texture
};

/**
 * Texture formats
 */
enum class TextureFormat : uint8_t
{
    R8,
    R8G8,
    R8G8B8,
    R8G8B8A8,
    B8G8R8A8,
    R16Float,
    R16G16Float,
    R32Float,
    R32G32B32A32Float,
    D16,
    D24S8,
    D32Float
};

/**
 * Index formats
 */
enum class IndexFormat : uint8_t
{
    UInt16,
    UInt32
};

/**
 * Render states
 */
enum class RenderState : uint8_t
{
    FillMode,           // Wireframe, Solid
    CullMode,           // None, Front, Back
    DepthTestEnable,    // Boolean
    DepthWriteEnable,   // Boolean
    DepthFunc,          // Less, Equal, LessEqual, etc.
    StencilTestEnable,  // Boolean
    BlendEnable,        // Boolean
    BlendSrcFactor,     // Source blend factor
    BlendDstFactor,     // Destination blend factor
    BlendOp,            // Blend operation
    AlphaTestEnable,    // Boolean
    AlphaFunc,          // Alpha comparison function
    ScissorTestEnable,  // Boolean
    ColorWriteEnable    // Which color channels to write
};

/**
 * Texture stage states
 */
enum class TextureStageState : uint8_t
{
    MinFilter,
    MagFilter,
    MipFilter,
    AddressU,
    AddressV,
    AddressW,
    BorderColor,
    MaxAnisotropy,
    TextureTransform
};

/**
 * Viewport structure
 */
struct Viewport
{
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    float minDepth;
    float maxDepth;
};

/**
 * Clear flags
 */
enum class ClearFlags : uint8_t
{
    None = 0,
    Color = 1 << 0,
    Depth = 1 << 1,
    Stencil = 1 << 2,
    All = Color | Depth | Stencil
};

/**
 * Shader types
 */
enum class ShaderType : uint8_t
{
    Vertex,
    Pixel,
    Geometry,
    Compute,
    Hull,
    Domain
};

/**
 * IRenderDevice - Abstract Render Device Interface (Phase 1)
 * 
 * This is the core abstraction layer for rendering backends.
 * Implementations include:
 * - DX8RenderDevice (legacy DirectX 8)
 * - DX11RenderDevice (DirectX 11)
 * - VulkanRenderDevice (Vulkan)
 */
class IRenderDevice
{
public:
    virtual ~IRenderDevice() = default;

    // Initialization
    virtual bool Initialize(void* windowHandle, int width, int height, bool fullscreen) = 0;
    virtual void Shutdown() = 0;

    // Frame management
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void Present() = 0;

    // Device capabilities
    virtual const RenderDeviceCaps& GetCaps() const = 0;

    // State management
    virtual void SetRenderState(RenderState state, uint32_t value) = 0;
    virtual void SetTextureStageState(uint32_t stage, TextureStageState state, uint32_t value) = 0;
    virtual void SetTransform(TransformType type, const Matrix4& matrix) = 0;

    // Texture management
    virtual bool CreateTexture(TextureHandle* handle, uint32_t width, uint32_t height,
                               TextureFormat format, const void* data) = 0;
    virtual void DestroyTexture(TextureHandle handle) = 0;
    virtual void SetTexture(uint32_t stage, TextureHandle handle) = 0;

    // Buffer management
    virtual bool CreateVertexBuffer(VertexBufferHandle* handle, uint32_t size,
                                    const void* data, UsageHint usage) = 0;
    virtual bool CreateIndexBuffer(IndexBufferHandle* handle, uint32_t size,
                                   const void* data, IndexFormat format, UsageHint usage) = 0;
    virtual void DestroyVertexBuffer(VertexBufferHandle handle) = 0;
    virtual void DestroyIndexBuffer(IndexBufferHandle handle) = 0;
    virtual void* MapVertexBuffer(VertexBufferHandle handle, MapType mapType) = 0;
    virtual void UnmapVertexBuffer(VertexBufferHandle handle) = 0;
    virtual void* MapIndexBuffer(IndexBufferHandle handle, MapType mapType) = 0;
    virtual void UnmapIndexBuffer(IndexBufferHandle handle) = 0;

    // Drawing
    virtual void DrawPrimitive(PrimitiveType type, uint32_t startVertex, uint32_t vertexCount) = 0;
    virtual void DrawIndexedPrimitive(PrimitiveType type, uint32_t startIndex,
                                      uint32_t indexCount, uint32_t vertexOffset) = 0;

    // Viewport
    virtual void SetViewport(const Viewport& viewport) = 0;
    virtual const Viewport& GetViewport() const = 0;

    // Clear
    virtual void Clear(ClearFlags flags, uint32_t color, float depth, uint8_t stencil) = 0;

    // Shader support
    virtual bool CreateShader(ShaderHandle* handle, const char* source, ShaderType type) = 0;
    virtual void DestroyShader(ShaderHandle handle) = 0;
    virtual void SetShader(ShaderHandle handle) = 0;
    virtual void SetShaderConstant(const char* name, const void* data, uint32_t size) = 0;
};

#endif // __IRENDERDEVICE_H__