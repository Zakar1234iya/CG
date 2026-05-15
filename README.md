# C&C Generals: Zero Hour — Ultimate Engine Modernization Plan

> **Scope:** Debug build hardening → DX8 stabilization → DX8→DX12 migration → multi-core CPU architecture → GPU-driven rendering → 1000-unit crash fix → multiplayer stability.
> **Repository:** [electronicarts/CnC_Generals_Zero_Hour](https://github.com/electronicarts/CnC_Generals_Zero_Hour)
> **Build target:** MSVC 2022, C++20, CMake, Windows 10 22H2+
> **Architecture:** `GeneralsMD/` is the immutable baseline. All changes live in `ModernizedSrc/`.

---

## Table of Contents

1. [Phase 0 — Immediate Fixes & Build Stabilization](#phase-0)
2. [Phase 1 — Audit & Graphics Abstraction Layer](#phase-1)
3. [Phase 2 — DX8 Runtime Stabilization (DX9 Bridge)](#phase-2)
4. [Phase 3 — DirectX 12 Backend](#phase-3)
5. [Phase 4 — 64-bit Port & Memory Model](#phase-4)
6. [Phase 5 — 1000-Unit Crash Fix & Object Pool Overhaul](#phase-5)
7. [Phase 6 — Multi-core CPU Architecture](#phase-6)
8. [Phase 7 — GPU & CPU Performance Optimization](#phase-7)
9. [Multiplayer Stability](#multiplayer)
10. [Testing Strategy](#testing)
11. [Milestones & Timeline](#milestones)
12. [Dependencies & Toolchain](#dependencies)
13. [Risk Register](#risks)

---

<a name="phase-0"></a>
## Phase 0 — Immediate Fixes & Build Stabilization

**Estimate:** 1–2 weeks | **Team:** 1 engineer | **Priority:** CRITICAL — blocks all other work

> These are bugs present right now that prevent the game from booting reliably or building cleanly. Fix these first before any architectural work begins.

### 0.1 — Debug Build Startup Time ✅ FIXED

**Root cause:** `Win32BIGFileSystem::openArchiveFile()` had two `LOG_TRACE` calls inside the per-file-entry `for` loop. With 50,000+ files across 17 `.big` archives, this generated 100,000+ synchronous disk writes during startup — causing 45–60 minute init times in Debug builds.

**File:** `ModernizedSrc/GameEngineDevice/Source/Win32Device/Common/Win32BIGFileSystem.cpp`

**Fix applied:**
- Removed both per-entry `LOG_TRACE` calls from the hot loop
- Replaced with `LOG_DEBUG` every 5,000 entries
- Demoted per-archive header traces from `LOG_TRACE` → `LOG_DEBUG`

**Result:** Debug startup time expected to drop to < 2 minutes.

---

### 0.2 — D3DERR_INVALIDCALL on GetAdapterIdentifier ✅ FIXED (verify)

**File:** `ModernizedSrc/Libraries/Source/WWVegas/WW3D2/dx8wrapper.cpp`

**Root cause:** `GetAdapterIdentifier(0, D3DENUM_NO_WHQL_LEVEL, ...)` returns `D3DERR_INVALIDCALL` on modern drivers — `D3DENUM_NO_WHQL_LEVEL` is a DX9 flag that is not valid through the DX8 ABI even when using a compatibility wrapper.

```cpp
// BEFORE (broken on Win10/11 modern drivers)
hr = d3d->GetAdapterIdentifier(0, D3DENUM_NO_WHQL_LEVEL, &adapterInfo);

// AFTER (correct — flags must be 0 for DX8 compatibility path)
hr = d3d->GetAdapterIdentifier(0, 0, &adapterInfo);
```

**Action:** Verify this is committed in `dx8wrapper.cpp`. Add an `ASSERT(hr == D3D_OK)` with a descriptive message after the call so future regressions are caught immediately.

---

### 0.3 — DX8 Stub Struct Layout Issues ❌ OUTSTANDING

**File:** `ModernizedSrc/Stubs/DX8Stubs/d3d8.h`

Three struct layout mismatches between our stubs and the real DX8 SDK. Any mismatch causes silent memory corruption when the DX8 wrapper DLL writes into our structs.

| Struct | Problem | Real DX8 Size | Fix |
|--------|---------|---------------|-----|
| `D3DCAPS8` | Missing `DeviceType` + `AdapterOrdinal` fields at offset 0 | 208 bytes | Add both fields at struct start ✅ (verify) |
| `D3DADAPTER_IDENTIFIER8` | Had extra `WHQLLevel` field (DX9-only, not in DX8) | 552 bytes | Remove `WHQLLevel` ✅ (verify) |
| `MAX_DEVICE_IDENTIFIER_STRING` | Was 512 (DX9 constant) — should be 256 for DX8 | 256 | Change `#define` to 256 ✅ (verify) |

**Validation method:**
```cpp
// Add to a test .cpp that compiles against the stubs:
static_assert(sizeof(D3DCAPS8) == 208,
    "D3DCAPS8 layout mismatch — will cause memory corruption");
static_assert(sizeof(D3DADAPTER_IDENTIFIER8) == 552,
    "D3DADAPTER_IDENTIFIER8 layout mismatch — GetAdapterIdentifier will corrupt stack");
static_assert(MAX_DEVICE_IDENTIFIER_STRING == 256,
    "MAX_DEVICE_IDENTIFIER_STRING must be 256 for DX8 ABI compatibility");
```

Add these `static_assert`s permanently in `d3d8.h` — they are free at compile time and catch regressions immediately.

---

### 0.4 — Missing Build Symbols ❌ OUTSTANDING

**Files:** `ModernizedSrc/Stubs/DX8Stubs/`, `ModernizedSrc/Libraries/`

| Symbol | Location needed | Fix |
|--------|----------------|-----|
| `d3dx8.h` not found | Any file using D3DX math | Add D3DX8 math stubs or replace with `DirectXMath` headers now (see §1.4) |
| `D3DDP_MAXTEXCOORD` undefined | Shader/texture coord code | Add `#define D3DDP_MAXTEXCOORD 8` to stubs |
| `D3DXVECTOR4` → `void*` implicit conversion | `wwshade/` | Add explicit cast operator or replace with `XMFLOAT4` (already patched in `dx8wrapper.h`) — ensure `wwshade` gets the same fix |

---

### 0.5 — Forward Declaration / Include Ordering in d3d8.h ❌ OUTSTANDING

**File:** `ModernizedSrc/Stubs/DX8Stubs/d3d8.h`

Types are used before they are defined due to declaration ordering. This causes compiler errors in translation units that include the stub before the full type is complete.

**Fix:** Audit `d3d8.h` top-to-bottom and ensure every type is fully defined before first use. Apply the same ordering as the real DX8 SDK:
1. Enums and `#define` constants
2. Forward declarations
3. `typedef struct` definitions (leaf types first, composite types after)
4. Interface declarations (`IDirect3D8`, `IDirect3DDevice8`, etc.)

---

### 0.6 — CreateDevice Failure on Windows 11 + RTX ❌ OUTSTANDING (critical)

**Status:** `CreateDevice` fails with all tested DX8 compatibility wrappers on Windows 11 + RTX 3060.

This is the primary blocker for running the game today. The failure occurs at:
```
WW3D::Set_Render_Device(0, ...)
  └── DX8Wrapper::Set_Render_Device()
      └── D3DInterface->CreateDevice()   ← FAILS here
```

**Root cause investigation checklist:**
- [ ] Confirm which wrapper DLL is loaded (`build/Main/Debug/d3d8.dll` from GenTool?)
- [ ] Try `D3DDEVTYPE_HAL` → `D3DDEVTYPE_WARP` fallback for debugging
- [ ] Log the full `D3DPRESENT_PARAMETERS` struct before `CreateDevice` — check for invalid values (zero width/height, unsupported format)
- [ ] Try creating a `D3DSWAPEFFECT_COPY` swapchain instead of `D3DSWAPEFFECT_DISCARD`
- [ ] Test with WineD3D8 wrapper as an alternative to GenTool
- [ ] Check if DXVK's d3d8 layer resolves the issue (DXVK 2.x has DX8 support)

**Recommended immediate path:** Switch to DXVK's d3d8.dll for the development bootstrap. It translates DX8 → Vulkan and is actively maintained. If the game runs under DXVK, the `CreateDevice` failure is confirmed as a wrapper bug, not our code.

**Implementation Status:**
- ✅ Debug build startup time fixed by throttling LOG_TRACE calls in Win32BIGFileSystem.cpp
- ✅ GetAdapterIdentifier crash fixed by changing D3DENUM_NO_WHQL_LEVEL to 0 in dx8wrapper.cpp
- ❌ DX8 stub struct layouts (D3DCAPS8, D3DADAPTER_IDENTIFIER8) still need verification with static_asserts
- ❌ Missing build symbols (d3dx8.h, D3DDP_MAXTEXCOORD) need resolution
- ❌ Forward declaration ordering in d3d8.h needs audit
- ❌ CreateDevice failure on Windows 11 + RTX requires DXVK wrapper testing

---

<a name="phase-1"></a>
## Phase 1 — Audit & Graphics Abstraction Layer

**Estimate:** 6–8 weeks | **Team:** 2 graphics engineers | **Priority:** Foundation (must complete first)

> **Gate:** Phase 0 must be fully resolved before Phase 1 begins. The game must boot and render.

### Goal

Wrap every DX8 call behind an `IRenderDevice` abstraction interface before any DX12 work begins. The DX8 and DX12 backends co-exist during development. The game can ship at any intermediate stage.

### 1.1 — DX8 Call-site Audit

Enumerate every usage of the following across `GameEngine/`, `W3DDisplay`, `W3DScene`, `W3DShadow`, `W3DParticleSystem`, `W3DGameClient`, and all `Libraries/Source/WWVegas/WW3D2/` files:

- `IDirect3D8` / `IDirect3DDevice8` — device and swap chain management
- `IDirect3DSurface8`, `IDirect3DTexture8`, `IDirect3DVertexBuffer8`, `IDirect3DIndexBuffer8` — resource types
- `D3DXMatrix*`, `D3DXVec3*`, `D3DXQuaternion*` — math utilities
- Fixed-function state: `SetTextureStageState`, `SetRenderState`, `SetTransform`, `SetMaterial`, `SetLight`
- `DrawPrimitive`, `DrawIndexedPrimitive`

**Deliverable:** A spreadsheet (or `docs/dx8_callsites.csv`) listing file, line number, call type, and subsystem grouping.

**Known hotspots from current codebase:**
| File | DX8 exposure | Notes |
|------|-------------|-------|
| `WW3D2/dx8wrapper.cpp` | High — owns `IDirect3DDevice8` | Already patched for scope/DX9 fallback |
| `W3DDevice/GameClient/W3DDisplay.cpp` | Medium — calls `WW3D::Init` + `Set_Render_Device` | Logging added |
| `WW3D2/dx8wrapper.h` | Declarations | `D3DXVECTOR4` overloads added for MSVC 2022 |
| `wwshade/` | Medium — fixed-function shader library | `D3DXVECTOR4→void*` cast issue |

### 1.2 — IRenderDevice Interface Design

```cpp
// ModernizedSrc/NewSystems/Renderer/IRenderDevice.h

class IRenderDevice {
public:
    virtual ~IRenderDevice() = default;

    // Lifecycle
    virtual bool Initialize(HWND hwnd, int width, int height, bool fullscreen) = 0;
    virtual void Shutdown() = 0;
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void Present() = 0;
    virtual void OnResize(int width, int height) = 0;

    // Resource creation
    virtual RenderBufferHandle  CreateVertexBuffer(const void* data, size_t bytes, bool dynamic) = 0;
    virtual RenderBufferHandle  CreateIndexBuffer(const void* data, size_t count, bool is32bit) = 0;
    virtual RenderTextureHandle CreateTexture(const TextureDesc& desc) = 0;
    virtual RenderShaderHandle  CreateShader(const ShaderDesc& desc) = 0;
    virtual void                DestroyBuffer(RenderBufferHandle h) = 0;
    virtual void                DestroyTexture(RenderTextureHandle h) = 0;
    virtual void                DestroyShader(RenderShaderHandle h) = 0;

    // Render state
    virtual void SetShader(RenderShaderHandle shader) = 0;
    virtual void SetVertexBuffer(RenderBufferHandle vb, uint32_t stride, uint32_t offset) = 0;
    virtual void SetIndexBuffer(RenderBufferHandle ib, bool is32bit) = 0;
    virtual void SetRenderTarget(RenderTextureHandle target, RenderTextureHandle depthStencil) = 0;
    virtual void SetViewport(int x, int y, int w, int h, float minZ, float maxZ) = 0;
    virtual void SetScissor(int x, int y, int w, int h) = 0;
    virtual void SetConstantBuffer(uint32_t slot, const void* data, size_t bytes) = 0;

    // Draw calls
    virtual void Draw(uint32_t vertexCount, uint32_t startVertex) = 0;
    virtual void DrawIndexed(uint32_t indexCount, uint32_t startIndex, int32_t baseVertex) = 0;
    virtual void DrawInstanced(uint32_t indexCount, uint32_t instanceCount,
                               uint32_t startIndex, int32_t baseVertex) = 0;
    virtual void DrawIndirect(RenderBufferHandle argsBuffer, size_t argsOffset) = 0;

    // Queries
    virtual RenderQueryHandle CreateQuery(QueryType type) = 0;
    virtual void              BeginQuery(RenderQueryHandle q) = 0;
    virtual bool              GetQueryResult(RenderQueryHandle q, uint64_t& outResult) = 0;

    // Debug
    virtual void PushDebugLabel(const char* label) = 0;
    virtual void PopDebugLabel() = 0;
    virtual void SetObjectName(RenderBufferHandle h, const char* name) = 0;
    virtual void SetObjectName(RenderTextureHandle h, const char* name) = 0;

    // Backend identification
    virtual const char* GetBackendName() const = 0;
    virtual bool        SupportsFeature(RenderFeature feature) const = 0;
};

// Global accessor — replaces all direct d3dDevice usage
extern IRenderDevice* TheRenderDevice;
```

**Note:** `DX8Wrapper` is not replaced immediately — `DX8RenderDevice` wraps it. `TheRenderDevice` points to `DX8RenderDevice` during Phase 1. No behavior changes.

### 1.3 — DX8RenderDevice Shim

Implement `DX8RenderDevice : public IRenderDevice` as a thin pass-through. Every method maps 1:1 to the corresponding existing `DX8Wrapper` call. This is a pure refactor — zero behavior changes.

**File:** `ModernizedSrc/NewSystems/Renderer/DX8RenderDevice.cpp`

**Validation gate:** The game must run identically through the shim. Run the full Phase 0 regression suite (boot test, skirmish, multiplayer smoke) before marking this phase complete.

### 1.4 — Remove D3DX Dependency

Replace all `D3DX*` math with `DirectXMath` (Windows SDK, header-only, no DLL). Required because D3DX is not available in DX12 and is not shipping in the stub layer.

| D3DX call | DirectXMath replacement |
|-----------|------------------------|
| `D3DXMatrixPerspectiveFovLH` | `XMMatrixPerspectiveFovLH` |
| `D3DXVec3Transform` | `XMVector3Transform` |
| `D3DXQuaternionSlerp` | `XMQuaternionSlerp` |
| `D3DXMatrixLookAtLH` | `XMMatrixLookAtLH` |
| `D3DXComputeBoundingBox` | `DirectX::BoundingBox::CreateFromPoints` |
| `D3DXMatrixDecompose` | `XMMatrixDecompose` |
| `D3DXVec3Normalize` | `XMVector3Normalize` |
| `D3DXVECTOR4` | `XMFLOAT4` / `XMVECTOR` |
| `D3DXMATRIX` | `XMFLOAT4X4` / `XMMATRIX` |

Add a compatibility header `ModernizedSrc/Common/D3DXCompat.h` with `typedef` aliases so call-sites can be migrated incrementally without breaking the build.

### 1.5 — Console Variable for Backend Selection

Add `r_backend` console variable early — before DX12 work begins:

```cpp
// r_backend dx8   → DX8RenderDevice (default during Phase 1-2)
// r_backend dx12  → DX12RenderDevice (available in Phase 3+)
// r_backend null  → NullRenderDevice (headless/test mode)
```

This lets engineers switch renderers at runtime (requires restart) and is essential for automated visual regression testing.

**Implementation Status:**
- ❌ IRenderDevice.h interface not created — blocks all backend development
- ❌ DX8RenderDevice shim not implemented
- ❌ VulkanRenderDevice.h exists but cannot compile without IRenderDevice.h base class
- ❌ DX11W3DDevice.cpp exists as standalone class, not wired into IRenderDevice interface
- ⚠️ Dependency order violation: Phase 3/7 backends written before Phase 1 abstraction layer defined

---

<a name="phase-2"></a>
## Phase 2 — DX8 Runtime Stabilization (DX9 Bridge)

**Estimate:** 3–4 weeks | **Team:** 1–2 engineers | **Priority:** High — prerequisite for Phase 3

> This phase closes the gap between "game boots in a wrapper" and "game runs reliably on modern hardware." It is intentionally scoped to stabilization — no new features, no DX12.

### 2.1 — Wrapper Strategy Decision

Evaluate and commit to one DX8 compatibility layer:

| Wrapper | Translation | Status | Recommended for |
|---------|------------|--------|----------------|
| **DXVK d3d8** | DX8 → Vulkan | Active development, open source | Primary recommendation |
| **GenTool d3d8.dll** | DX8 → DX9 | Game-specific, closed source | Already in `build/Main/Debug/` |
| **WineD3D8** | DX8 → OpenGL | Linux-compatible | Cross-platform fallback |

**Recommendation:** Target DXVK as the primary runtime wrapper. GenTool's `d3d8.dll` is useful as a reference but is not open-source and cannot be modified. DXVK resolves the `CreateDevice` failure on RTX hardware (§0.6).

Ship `dxvk-d3d8.dll` renamed to `d3d8.dll` alongside `generals_zh.exe` for the development bootstrap.

### 2.2 — Device Creation Hardening

In `DX8Wrapper::Set_Render_Device()` (`dx8wrapper.cpp`), add a multi-strategy `CreateDevice` fallback:

```cpp
// Strategy 1: Hardware HAL, multithreaded
hr = d3d->CreateDevice(adapter, D3DDEVTYPE_HAL, hwnd,
    D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &pp, &device);

// Strategy 2: Hardware HAL, software VP (fallback for drivers with HW VP issues)
if (FAILED(hr)) {
    LOG_WARN(LogCategory::Renderer, "HW VP failed (hr=0x%08X), trying SW VP", hr);
    hr = d3d->CreateDevice(adapter, D3DDEVTYPE_HAL, hwnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED, &pp, &device);
}

// Strategy 3: WARP (software renderer, for debugging only — not for shipping)
#if defined(_DEBUG)
if (FAILED(hr)) {
    LOG_WARN(LogCategory::Renderer, "HAL failed (hr=0x%08X), falling back to WARP", hr);
    hr = d3d->CreateDevice(adapter, D3DDEVTYPE_SW, hwnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &device);
}
#endif

if (FAILED(hr)) {
    LOG_ERROR(LogCategory::Renderer, "All CreateDevice strategies failed. "
        "PresentParameters: %dx%d fmt=%d refresh=%d swapeffect=%d flags=0x%08X",
        pp.BackBufferWidth, pp.BackBufferHeight, pp.BackBufferFormat,
        pp.FullScreen_RefreshRateInHz, pp.SwapEffect, pp.Flags);
    DEBUG_CRASH(("CreateDevice failed with hr=0x%08X", hr));
}
```

### 2.3 — Device Lost / Reset Handling

Modern drivers are more aggressive about triggering `D3DERR_DEVICELOST` (especially on Alt+Tab, monitor sleep, resolution changes). Add explicit device lost/reset handling:

```cpp
// In the main render loop (W3DDisplay::draw or equivalent):
hr = DX8Wrapper::Get_D3D_Device8()->TestCooperativeLevel();
if (hr == D3DERR_DEVICELOST) {
    // Device lost — stop rendering, release DEFAULT-pool resources
    OnDeviceLost();
    return;
}
if (hr == D3DERR_DEVICENOTRESET) {
    // Device ready to reset
    ReleaseDefaultPoolResources();
    hr = device->Reset(&presentParams);
    if (SUCCEEDED(hr)) {
        RecreateDefaultPoolResources();
        OnDeviceRestored();
    }
}
```

### 2.4 — Presentation Parameter Validation

Before calling `CreateDevice`, validate all `D3DPRESENT_PARAMETERS` fields and log them in full. Add a `ValidatePresentParameters()` helper:

- `BackBufferWidth` / `BackBufferHeight` must be > 0
- `BackBufferFormat` must be supported by the adapter (query `CheckDeviceFormat`)
- `FullScreen_RefreshRateInHz` must be 0 for windowed mode
- `MultiSampleType` must be validated via `CheckDeviceMultiSampleType`

**Implementation Status:**
- ❌ CreateDevice multi-strategy fallback not implemented (HAL→SW VP→WARP)
- ❌ Device lost/reset handler not implemented — Alt+Tab crash unfixed
- ❌ DXVK wrapper integration not tested

---

<a name="phase-3"></a>
## Phase 3 — DirectX 12 Backend

**Estimate:** 12–16 weeks | **Team:** 3 graphics engineers | **Priority:** High

> **Gate:** Phase 1 abstraction layer complete and verified. Game runs cleanly through `DX8RenderDevice` shim.

### Goal

Implement `DX12RenderDevice : public IRenderDevice`. The DX8 backend stays live (selectable via `r_backend dx8`) throughout. DX12 backend must reach full visual parity before DX8 is removed (Phase 3 end → M8).

### 3.1 — DX12 Device Initialization

```cpp
// ModernizedSrc/NewSystems/Renderer/DX12RenderDevice.cpp
// Initialization order:

// 1. Enable debug layer (Debug builds only)
#if defined(_DEBUG)
ComPtr<ID3D12Debug1> debugController;
D3D12GetDebugInterface(IID_PPV_ARGS(&debugController));
debugController->EnableDebugLayer();
debugController->SetEnableGPUBasedValidation(true);
#endif

// 2. Create IDXGIFactory7 — enumerate adapters
ComPtr<IDXGIFactory7> factory;
CreateDXGIFactory2(dxgiFlags, IID_PPV_ARGS(&factory));

// 3. Select hardware adapter with FEATURE_LEVEL_11_0 minimum (12_0 preferred)
//    Skip adapters without DX12 native support (fall back to DX8 path)
SelectHardwareAdapter(factory.Get(), &adapter, D3D_FEATURE_LEVEL_11_0);

// 4. Create ID3D12Device2
D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));

// 5. Create command queues
//    - Direct queue:  D3D12_COMMAND_LIST_TYPE_DIRECT  (render + copy)
//    - Compute queue: D3D12_COMMAND_LIST_TYPE_COMPUTE (GPU culling, particle sim)
//    - Copy queue:    D3D12_COMMAND_LIST_TYPE_COPY    (upload ring buffer)

// 6. Create IDXGISwapChain4
//    - 3 back buffers, DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
//    - DXGI_SWAP_EFFECT_FLIP_DISCARD
//    - Allow tearing if supported (DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING)

// 7. Create descriptor heaps
//    - RTV:         512 descriptors  (back buffers + render targets)
//    - DSV:         64  descriptors  (shadow maps + depth buffers)
//    - CBV/SRV/UAV: 65536 descriptors, shader-visible (all textures + buffers)
//    - Sampler:     128 descriptors, shader-visible

// 8. Create per-frame resources (FRAMES_IN_FLIGHT = 3)
//    - Command allocator per frame per queue type
//    - Fence per frame

// 9. D3D12MA: initialize GPU memory allocator (D3D12MemAlloc)
D3D12MA::ALLOCATOR_DESC allocDesc = {};
allocDesc.pDevice = device.Get();
allocDesc.pAdapter = adapter.Get();
D3D12MA::CreateAllocator(&allocDesc, &gpuAllocator);
```

### 3.2 — Upload Ring Buffer

All CPU→GPU data transfers (vertices, constants, instance data) go through a dedicated upload ring buffer. Never allocate an `UPLOAD`-heap resource per draw call.

```cpp
// ModernizedSrc/NewSystems/Renderer/UploadRingBuffer.h
class UploadRingBuffer {
    static constexpr size_t CAPACITY = 32 * 1024 * 1024; // 32 MB
    ComPtr<ID3D12Resource> m_buffer;
    uint8_t*               m_mapped = nullptr;
    size_t                 m_head   = 0;
    size_t                 m_tail   = 0;
public:
    // Returns GPU address + mapped CPU pointer. Aligned to 256 bytes (CB requirement).
    UploadAlloc Allocate(size_t bytes, size_t align = 256);
    // Called at frame start after GPU signals fence for this frame slot.
    void Reclaim(size_t frameHead);
};
```

### 3.3 — Root Signature Design

Define root signatures per render pass. Minimize signature churn per draw.

```
// Terrain pass root signature
[0] CBV b0             — per-frame constants (view, proj, time, fog, camera pos)
[1] CBV b1             — per-draw (world, tile UVs, blend weight offset)
[2] Descriptor table   — SRV t0-t15 (terrain tile texture array)
[3] Descriptor table   — SRV t16    (blend weight map)
[4] Descriptor table   — SRV t17    (shadow map)
[5] Descriptor table   — Samplers s0-s2

// Unit pass root signature (instanced)
[0] CBV b0             — per-frame constants
[1] SRV t0             — per-instance structured buffer (world matrix, team color, damage)
[2] Descriptor table   — SRV t1-t4  (albedo, normal, roughness, AO per model)
[3] 32-bit constant    — instance offset into structured buffer
[4] Descriptor table   — Samplers s0

// UI/HUD root signature
[0] CBV b0             — orthographic projection + clip rect
[1] Descriptor table   — SRV t0 (atlas texture)
[2] Descriptor table   — Sampler s0
```

### 3.4 — Shader Rewrite (HLSL SM6)

All fixed-function pipeline states become explicit HLSL shaders compiled with DXC (`dxcompiler.dll`, target `-T ps_6_0 / vs_6_0 / cs_6_0`).

| Original (DX8 FFP) | DX12 HLSL shader | Notes |
|--------------------|-----------------|-------|
| Terrain tile blend | `terrain.hlsl` (VS+PS) | 16-texture array, per-pixel weight map |
| Unit diffuse + team color | `unit_lit.hlsl` (VS+PS) | Instanced; Lambert + Blinn-Phong + team tint |
| Water surface | `water.hlsl` (VS+PS) | Planar reflection tex + animated normal map |
| Particle / FX | `particle.hlsl` (VS+PS) | Additive blend + soft-particle depth fade |
| Shadow map | `shadow.hlsl` (VS only) | Depth-only, no PS; PCF filter in unit_lit |
| UI / HUD | `ui.hlsl` (VS+PS) | Textured quad, alpha blend, clip rect in CB |
| Sky / backdrop | `sky.hlsl` (VS+PS) | Fullscreen reverse-Z clear replacement |

**Compile pipeline:**
```cmake
# CMakeLists.txt — compile all shaders at build time
find_program(DXC_EXECUTABLE dxc REQUIRED)
foreach(HLSL_FILE ${SHADER_SOURCES})
    add_custom_command(
        OUTPUT  ${SHADER_OUTPUT_DIR}/${HLSL_FILE}.cso
        COMMAND ${DXC_EXECUTABLE} -T vs_6_0 -E VSMain -Fo ... ${HLSL_FILE}
        COMMAND ${DXC_EXECUTABLE} -T ps_6_0 -E PSMain -Fo ... ${HLSL_FILE}
        DEPENDS ${HLSL_FILE}
    )
endforeach()
```

Compile all PSOs offline at build time. Cache all permutations in `PSOCache.bin` loaded at startup — eliminates in-game PSO compilation stutter.

### 3.5 — Resource Barrier Management

Use a `BarrierBatcher` helper to batch and deduplicate `D3D12_RESOURCE_BARRIER` transitions. Avoid per-draw barriers on non-transitioning resources.

```
Per-frame barrier sequence:
  Frame start:   Back buffer PRESENT → RENDER_TARGET
  Shadow pass:   Shadow map SHADER_RESOURCE → DEPTH_WRITE
  Opaque pass:   Shadow map DEPTH_WRITE → SHADER_RESOURCE
  Post-process:  Back buffer RENDER_TARGET → UNORDERED_ACCESS  (if using CS post-process)
  Frame end:     Back buffer (RENDER_TARGET or UAV) → PRESENT
```

### 3.6 — Visual Parity Checklist

Before marking Phase 3 complete, verify these are pixel-accurate (PIX frame diff < 1%):

- [ ] Terrain tile blending (China, USA, GLA maps)
- [ ] Unit diffuse + team color tint
- [ ] Water with reflection (Warlord's Chan map)
- [ ] Particle effects (explosions, dust, smoke)
- [ ] Shadow map quality + PCF soft edges
- [ ] UI elements, minimap, HUD overlays
- [ ] Night/day lighting transitions
- [ ] Fog of war boundary rendering

**Implementation Status:**
- ⚠️ DX11W3DDevice.cpp skeleton exists (~80 lines) with Initialize(), CreateRenderTargets(), BeginFrame(), Present()
- ⚠️ Shaders/ directory has stub HLSL files (Terrain.hlsl, Unit.hlsl, UI.hlsl, Shared.hlsli) — 19–31 lines each, no wired entry points
- ⚠️ VulkanRenderDevice.h/cpp and VulkanBasic.vert/.frag exist but unverified
- ❌ RenderStateCache not implemented
- ❌ Constant buffer layout not defined
- ❌ Texture migration path (24-bit→32-bit) not implemented
- ❌ D3DX replacement wrappers missing

---

<a name="phase-4"></a>
## Phase 4 — 64-bit Port & Memory Model

**Estimate:** 3–4 weeks | **Team:** 1–2 engineers | **Priority:** High — required before Phase 5+

> The game is currently a 32-bit process. At 4 GB virtual address space, large skirmish games with 1000 units risk exhausting the address space before any crash fixes take effect. This phase is a prerequisite for meaningful memory pool work in Phase 5.

### 4.1 — CMake 64-bit Target

```cmake
# Top-level CMakeLists.txt
if (CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(FATAL_ERROR "32-bit builds are no longer supported. "
            "Use -A x64 or set CMAKE_GENERATOR_PLATFORM=x64.")
endif()

# Ensure MSVC targets x64
set(CMAKE_GENERATOR_PLATFORM "x64" CACHE STRING "" FORCE)
```

### 4.2 — Pointer Width Audit

Search for code patterns that break at 64-bit:

```bash
# Cast from pointer to int (truncates on 64-bit)
grep -rn "(int)" --include="*.cpp" --include="*.h" ModernizedSrc/ | grep "this\|ptr\|Ptr\|handle\|Handle"

# Explicit DWORD used where size_t is correct
grep -rn "DWORD.*size\|DWORD.*count\|DWORD.*len" ModernizedSrc/
```

Key patterns to fix:
- `(int)ptr` → `(intptr_t)ptr` or `reinterpret_cast<intptr_t>(ptr)`
- `DWORD` for memory sizes → `size_t`
- `int` for array indices over 2 billion → `int64_t` / `ptrdiff_t`
- `memcpy` size arguments: must be `size_t`, not `int`

### 4.3 — Memory Usage Baseline

Instrument memory usage at startup with `GetProcessMemoryInfo` and log to `crashes/memory_baseline.txt`:

```
[MEMORY] Committed at game boot:     X MB
[MEMORY] Committed after BIG load:   X MB
[MEMORY] Committed after INI parse:  X MB
[MEMORY] Committed at main menu:     X MB
[MEMORY] Peak committed (1000-unit): X MB
```

This baseline drives the pool sizing decisions in Phase 5.

**Implementation Status:**
- ✅ CMakeLists.txt enforces x64-only build with FATAL_ERROR check
- ❌ Pointer type audit (DWORD→UINT_PTR, etc.) not started — no clang-tidy pass evidence
- ❌ SetWindowLongPtr migration not applied
- ❌ Static_assert guards on serialized structs missing

---

<a name="phase-5"></a>
## Phase 5 — 1000-Unit Crash Fix & Object Pool Overhaul

**Estimate:** 4–6 weeks | **Team:** 2 engineers | **Priority:** High-impact, self-contained

> This is the highest-visibility user-facing fix. Can be parallelized with Phase 3 after Phase 4 completes.

### 5.1 — Root Cause Investigation

The 1000-unit crash is almost certainly one of these three causes (in order of likelihood):

1. **32-bit address space exhaustion** — heap fragmentation + >4 GB virtual allocation → `new` returns null or throws, game crashes. Fixed by Phase 4.
2. **Object list / slot array overflow** — fixed-size arrays that assume unit count < some constant. Look for `MAX_UNITS`, `MAX_OBJECTS`, `MAX_THINGS` defines.
3. **Pathfinding / spatial hash overflow** — the pathfinding system may have a fixed-capacity grid that corrupts memory when overflowed.

**Diagnostic step:** Add crash handler annotation to the minidump (already integrated at `ModernizedSrc/NewSystems/CrashHandler/`):

```cpp
// In crash handler, log unit counts:
WriteMiniDumpAnnotation("AliveUnitCount", TheGameLogic->GetObjectCount());
WriteMiniDumpAnnotation("TotalAllocated", GetHeapBytesAllocated());
WriteMiniDumpAnnotation("FreeVirtualMB", GetFreeVirtualAddressSpaceMB());
```

### 5.2 — SlotMap Object Pool

Replace the current `Object*` linked list with a `SlotMap<T>` — O(1) alloc/free, contiguous storage, stable handles, no fragmentation:

```cpp
// ModernizedSrc/NewSystems/Memory/SlotMap.h
template<typename T, size_t CAPACITY>
class SlotMap {
    struct Slot {
        T        value;
        uint32_t generation;  // bumped on free — detects dangling handles
        uint32_t nextFree;
    };
    std::array<Slot, CAPACITY> m_slots;
    uint32_t m_freeHead = 0;
    uint32_t m_count    = 0;

public:
    struct Handle { uint32_t index; uint32_t generation; };

    Handle       Alloc();
    void         Free(Handle h);
    T*           Get(Handle h);    // returns nullptr if stale
    const T*     Get(Handle h) const;
    uint32_t     Count() const { return m_count; }
    void         ForEach(auto&& fn);   // iterates only live slots
};
```

Define maximum capacities with `static_assert` guards:

```cpp
static constexpr size_t MAX_UNITS   = 2048;  // was implicitly 1000 or less
static constexpr size_t MAX_OBJECTS = 8192;  // all game objects (units + buildings + projectiles)
static constexpr size_t MAX_WEAPONS = 16384; // weapon instances

static_assert(MAX_UNITS   <= MAX_OBJECTS, "Unit pool can't exceed object pool");
```

### 5.3 — Pool Allocator for Modules

Each game object carries a `ModuleList` of behavioral components (AI, physics, weapons, etc.). These are currently heap-allocated individually, causing severe fragmentation.

```cpp
// ModernizedSrc/NewSystems/Memory/PoolAllocator.h
template<typename T, size_t POOL_SIZE>
class PoolAllocator {
    alignas(T) uint8_t m_storage[sizeof(T) * POOL_SIZE];
    std::bitset<POOL_SIZE> m_used;
public:
    T*   Allocate();
    void Deallocate(T* ptr);
    bool IsFromPool(const T* ptr) const;
};

// Register per-module-type pools:
static PoolAllocator<AIUpdateModule,      MAX_OBJECTS> g_aiPool;
static PoolAllocator<PhysicsUpdateModule, MAX_OBJECTS> g_physicsPool;
static PoolAllocator<WeaponModule,        MAX_OBJECTS> g_weaponPool;
```

### 5.4 — Weapon & ThingTemplate Validation (Already Patched)

Both `Weapon.cpp` and `ThingTemplate.cpp` have been updated to replace `ASSERT` crashes on missing audio with `LOG_WARN` — preventing crashes during asset validation at startup. Verify these patches are stable under the full 1000-unit stress test.

### 5.5 — Spatial Hash for Pathfinding

Implement a fixed-bucket spatial hash for the pathfinding threat map. Sized to handle `MAX_OBJECTS` without overflow:

```cpp
// ModernizedSrc/NewSystems/World/SpatialHash.h
class SpatialHash {
    static constexpr int CELL_SIZE   = 64;   // world units per cell
    static constexpr int GRID_WIDTH  = 512;  // cells
    static constexpr int GRID_HEIGHT = 512;
    static constexpr int MAX_PER_CELL = 32;
    // ...
};
```

**Implementation Status:**
- ✅ PoolAllocator.h implemented with thread-safe bitset tracking and multi-block expansion
- ❌ SlotMap.h missing — no stable handles or generation system to prevent dangling pointers
- ❌ SpatialHash.h not in repo
- ❌ Pool integration into game object creation not done — PoolAllocator defined but not hooked into Unit/Object factory

---

<a name="phase-6"></a>
## Phase 6 — Multi-core CPU Architecture

**Estimate:** 8–10 weeks | **Team:** 2–3 engineers | **Priority:** High

> **Gate:** Phase 4 (64-bit) and Phase 5 (pool overhaul) must be complete. Multi-threaded access to object pools without stable handles is dangerous.

### 6.1 — Job System

```cpp
// ModernizedSrc/NewSystems/Threading/JobSystem.h
class JobSystem {
public:
    static void Init(int workerCount = std::thread::hardware_concurrency() - 1);
    static void Shutdown();

    // Submit work. Returns a handle to wait on.
    static JobHandle Submit(std::function<void()> fn, JobHandle dependency = {});
    static JobHandle SubmitBatch(std::span<std::function<void()>> fns);

    // Wait for completion before proceeding.
    static void Wait(JobHandle h);
    static void WaitAll();

    // Called from main thread once per game tick
    static void Flush();
};
```

Uses `moodycamel::ConcurrentQueue` for the work-stealing deque. N-1 worker threads (leave 1 core for the main/sim thread). Workers spin-wait briefly before sleeping to minimize latency on burst workloads.

### 6.2 — Simulation Thread Separation

Separate the game simulation from the render thread:

```
Main thread:      Window messages, input pump, swap present
Sim thread:       Game logic, AI, physics, weapon fire (locked to 1/15 s turn boundary)
Render thread:    Build + submit DX12 command lists, read PREV frame's sim snapshot
Worker pool:      Pathfinding, audio decode, async BIG file I/O
```

**Critical:** The sim thread writes the frame snapshot; the render thread reads it. Use double-buffering (two complete snapshots, ping-pong). The render thread always reads the completed previous frame — never the in-progress current one.

```cpp
struct FrameSnapshot {
    std::vector<UnitRenderData>     units;      // position, orientation, anim state
    std::vector<ParticleRenderData> particles;
    std::vector<DecalRenderData>    decals;
    TerrainRenderData               terrain;
    FogOfWarSnapshot                fogOfWar;
    uint64_t                        frameIndex;
};

FrameSnapshot g_snapshots[2];          // [0] = render reads, [1] = sim writes
std::atomic<int> g_renderReadSlot = 0; // render thread reads this slot
```

### 6.3 — AI Thread Budget

AI is the most expensive simulation component. Time-slice it across worker threads:

```cpp
// Per game tick:
// 1. Collect all AI units with pending decisions
// 2. Batch into groups of ~32
// 3. Submit each group as a job
// 4. Wait for all jobs (must complete within turn budget: 40 ms for 8 players)
// 5. Apply results to game state (main sim thread only — no concurrent writes)

static constexpr int AI_BATCH_SIZE     = 32;
static constexpr int AI_TURN_BUDGET_MS = 40;
```

Hard-cap AI time per tick. If budget exceeded: defer remaining AI decisions to next tick, issue a `LOG_WARN`. Never stall the turn boundary.

### 6.4 — Async Pathfinding

Pathfinding requests are submitted as jobs. Results are applied at the next available tick boundary:

```cpp
// Unit requests a path:
JobHandle h = JobSystem::Submit([unit, dest]() {
    Path path = ThePathfinder->FindPath(unit->GetPosition(), dest);
    unit->GetAI()->SetPendingPath(std::move(path));  // thread-safe: write to pending slot
});
// Main sim thread polls pending paths each tick and applies them.
```

**Implementation Status:**
- ⚠️ JobSystem.h/JobSystem.cpp exists with Initialize, Submit, WaitFor, Shutdown — but contains critical deadlock bug
- 🔧 **BUG FIX APPLIED:** JobSystem::Submit() was creating new JobHandle but fn() never called m_done->store(true), causing WaitFor() to spin forever. Fixed by marking done after fn() executes in WorkerLoop.
- ✅ FlowField.h/FlowField.cpp fully implemented with BFS, 8-directional movement, diagonal cost 1.414
- ❌ ShardedList not implemented
- ❌ Frame snapshot / double-buffer sim not implemented
- ❌ AI job dispatch not wired into game loop

---

<a name="phase-7"></a>
## Phase 7 — GPU & CPU Performance Optimization

**Estimate:** 6–8 weeks | **Team:** 2 graphics + 1 CPU engineer | **Priority:** Medium

> **Gate:** Phase 3 (DX12 backend) and Phase 6 (multi-core) complete.

### 7.1 — GPU-Driven Rendering (ExecuteIndirect)

Replace per-unit CPU draw calls with GPU-driven indirect rendering.

**Unit Instance Buffer (GPU):**
```hlsl
struct UnitInstance {
    float4x4 worldMatrix;
    float4   teamColor;
    float    damageFraction;  // 0=full health, 1=destroyed
    uint     modelVariant;
    uint     animFrameIndex;
    float    _pad;
};
StructuredBuffer<UnitInstance> g_instances : register(t1);
```

**GPU Frustum Culling (compute shader):**
```hlsl
// cull.hlsl — dispatched once per frame, 64 threads per group
[numthreads(64, 1, 1)]
void CSCullUnits(uint3 id : SV_DispatchThreadID) {
    if (id.x >= g_totalUnits) return;
    float3 center = g_unitAABBs[id.x].center;
    float  radius = g_unitAABBs[id.x].radius;
    bool   visible = FrustumTest(g_frustumPlanes, center, radius);
    if (visible) {
        uint slot;
        InterlockedAdd(g_visibleCount[0], 1, slot);
        g_visibleIndices[slot] = id.x;
    }
}
// g_visibleIndices feeds directly into ExecuteIndirect — zero CPU readback.
```

**ExecuteIndirect call:**
```cpp
commandList->ExecuteIndirect(
    commandSignature,       // stride = sizeof(IndirectDrawIndexedArguments)
    maxDrawCount,
    argsBuffer.Get(),  0,
    countBuffer.Get(), 0    // GPU-written draw count (output of cull compute)
);
```

**Expected gain:** CPU draw call time drops from ~2–4 ms (1000 units × DX12 per-draw) → ~0.05 ms.

### 7.2 — Async Compute Timeline

Overlap GPU workloads using the async compute queue:

| Frame phase | Direct queue | Compute queue |
|-------------|-------------|---------------|
| Shadow pass | Shadow depth render | — |
| Opaque pass | Opaque geometry | Unit frustum culling |
| Lighting | Deferred lighting + shadows | Particle simulation |
| Transparent | Particles, water | — |
| Post-process | TAA, tone map | — |

Synchronize with `ID3D12Fence`: compute signals after culling; direct queue waits before `ExecuteIndirect`.

### 7.3 — Data-Oriented Unit Update (SoA)

Restructure hot unit data into Structure-of-Arrays for SIMD batch processing:

```cpp
// ModernizedSrc/NewSystems/World/UnitArrays.h
struct UnitArrays {
    // Hot data — processed every tick
    float*    posX;          // [MAX_UNITS]
    float*    posY;          // [MAX_UNITS]
    float*    posZ;          // [MAX_UNITS]
    float*    velX;          // [MAX_UNITS]
    float*    velY;          // [MAX_UNITS]
    float*    health;        // [MAX_UNITS]
    float*    healthRegen;   // [MAX_UNITS]
    int32_t*  teamId;        // [MAX_UNITS]
    uint32_t* statusFlags;   // [MAX_UNITS]

    // Cold data — accessed only on events (damage, death, ability use)
    UnitAIState*   aiState;  // [MAX_UNITS]  pointer into AI pool
    WeaponState*   weapons;  // [MAX_UNITS]  pointer into weapon pool
    ModuleList*    modules;  // [MAX_UNITS]  pointer into module pool
};
```

Health regen, cooldown ticks, and status updates run as AVX2 loops — ~8× throughput vs scalar per-object.

### 7.4 — BIG File I/O Async Loading

Move `.big` archive I/O to the async copy queue. Use `ReadFileEx` with IOCP on Windows. INI parsing and W3D model loading run as jobs on the worker pool — the main thread pumps the message queue and updates a progress bar while waiting.

**Expected gain:** Startup time (already improved by Phase 0 trace fix) reduced further — async I/O overlaps parsing with subsequent archive reads.

---

<a name="multiplayer"></a>
## Multiplayer Stability

### Lockstep Turn Hardening

- **Turn time:** 1/15 s (66 ms) — sufficient for 8 players on typical connections.
- **Input latency:** Configurable turn delay (default 2 turns = 133 ms) accommodates high-ping players without slowing simulation.
- **Desync detection:** CRC32 of full simulation state broadcast at every turn boundary. On first desync: log full state diff to `crashes/desync_TIMESTAMP.log`, continue game. Desync log includes: unit positions, health, weapon states, random seed.

### Packet Loss & Reconnection

- Sequence-numbered turn packets with ACK. Re-request missing turns from peers before stalling simulation.
- On disconnect: pause up to 10 s awaiting reconnection. After timeout, replace disconnected player with their last AI state.
- Add a `net_packetloss_sim N` debug variable to simulate N% packet loss in local games — essential for testing reconnection paths.

### Network Thread

Move all socket I/O to the worker pool (async recv/send via IOCP on Windows). Network callbacks post jobs to the sim thread's inbox queue. No locking on the hot path — use `moodycamel::ConcurrentQueue<TurnPacket>`.

### Bandwidth Optimization

- **Delta compression** — send only units that moved or changed state since last turn.
- **Command deduplication** — if the same command is issued to the same unit twice in one turn, send once.
- **Spectator stream** — spectators receive every 4th turn update to reduce broadcast load.

---

<a name="testing"></a>
## Testing Strategy

### Automated Tests

| Test type | Tool | Coverage target |
|-----------|------|----------------|
| Unit tests | Google Test | SlotMap, JobSystem, SpatialHash, PoolAllocator, UploadRingBuffer |
| Render regression | PIX frame capture diff | Visual parity DX8 vs DX12 (< 1% diff) |
| Desync detection | Headless replay comparison | All multiplayer maps × all faction combos |
| Performance regression | Custom frame timer + CI gate | No frame > 33 ms on reference target hardware |
| Crash reproduction | Automated 1000-unit stress test | 10-minute match, no crash, no desync |
| Build verification | CI on every PR | Clean build, zero new warnings, all static_asserts pass |
| Struct layout | Compile-time static_assert | D3DCAPS8, D3DADAPTER_IDENTIFIER8, all DX8 stub structs |
| Memory leak | AddressSanitizer (ASAN) + LeakSanitizer | Zero leaks after 10-minute skirmish |

### Headless / CI Mode

Add a `--headless` launch flag that:
- Creates a `NullRenderDevice` (no window, no GPU)
- Runs a scripted game session (e.g., `test_1000units.replay`)
- Outputs a `test_result.json` with frame times, unit counts, desync CRCs
- Returns exit code 0 (pass) / 1 (fail)

This enables fully automated CI on servers without GPUs.

### Reference Hardware

| Tier | CPU | GPU | RAM | Target frame time |
|------|-----|-----|-----|------------------|
| Minimum | Intel Core i5-8400 | GTX 1060 6 GB | 8 GB | ≤ 33 ms (30 fps) |
| Target | Ryzen 5 5600X | RTX 3070 | 16 GB | ≤ 16 ms (60 fps) |
| High-end | Ryzen 9 7950X | RTX 4090 | 32 GB | ≤ 8 ms (120 fps) |

---

<a name="milestones"></a>
## Milestones & Timeline

| # | Milestone | Phase(s) | Week | Gate criteria |
|---|-----------|----------|------|--------------|
| **M0** | Game boots and renders on Win11 + RTX | 0 | 2 | `CreateDevice` succeeds; skirmish map visible |
| **M1** | Build clean — zero warnings, all stubs correct | 0 | 2 | CI green; all `static_assert`s pass |
| **M2** | Abstraction layer complete | 1 | 10 | Game runs identically through `DX8RenderDevice` shim |
| **M3** | DX8 runtime stable | 2 | 14 | Device lost/reset handled; no crash on Alt+Tab or resolution change |
| **M4** | 64-bit build | 4 | 16 | `x64` target builds clean; no pointer truncation warnings |
| **M5** | 1000-unit crash eliminated | 5 | 22 | 10-min 1000-unit stress match completes without crash |
| **M6** | DX12 backend boots | 3 | 26 | Skirmish map renders at 60 fps on target GPU via DX12 |
| **M7** | DX12 visual parity | 3 | 32 | PIX frame diff < 1% vs DX8 on all stock maps |
| **M8** | Multi-core sim live | 6 | 38 | Frame time < 16 ms with 8 AI players, 1000 units |
| **M9** | GPU-driven rendering | 7 | 42 | CPU draw call time < 0.5 ms at 1000 visible units |
| **M10** | Multiplayer stable | 6, 7 | 46 | 8-player 60-min match: no desync, no crash, no stall |
| **M11** | DX8 backend removed | 1, 2, 3 | 48 | Compiles without DX8 SDK; CI green; no `DX8RenderDevice` references |

---

<a name="dependencies"></a>
## Dependencies & Toolchain

| Dependency | Version | Purpose |
|------------|---------|---------|
| Windows SDK | 10.0.22621+ | DX12 headers, DXGI, DirectXMath, IOCP |
| Visual Studio 2022 | 17.8+ | C++20, ASAN, `/W4`, `/WX` |
| CMake | 3.25+ | Build system; `x64` generator |
| DXC (DirectX Shader Compiler) | Latest | HLSL SM6 offline compilation |
| D3D12MA | 2.x | GPU heap sub-allocation |
| DXVK (d3d8 branch) | Latest | DX8→Vulkan bootstrap wrapper |
| PIX for Windows | Latest | GPU frame capture, timing, PSO analysis |
| WinPixEventRuntime | Latest | GPU marker/label support in DX12 |
| moodycamel::ConcurrentQueue | 1.0.4 | Lock-free job + network queues |
| Google Test | 1.14 | Unit + integration tests |
| DirectXTex | Latest | Texture loading/conversion (replaces D3DX texture utilities) |
| DirectXMesh | Latest | Mesh processing (replaces D3DX geometry utilities) |

---

<a name="risks"></a>
## Risk Register

| Risk | Likelihood | Impact | Mitigation |
|------|-----------|--------|-----------|
| `CreateDevice` fails on Win11 + RTX with all wrappers | High | **Critical** | Adopt DXVK d3d8 as primary bootstrap; resolve in Phase 0 before anything else |
| DX8 stub struct layout mismatch causes silent corruption | High | **Critical** | Add compile-time `static_assert` for every stub struct size; validate against SDK docs |
| Fixed-function pipeline effects with no obvious HLSL equivalent | High | High | Audit all FFP effects in Phase 1; prototype shaders early in Phase 3 |
| Multiplayer desync introduced by multi-threading | High | **Critical** | Double-buffer sim snapshot; determinism watchdog + CRC32 check from Phase 6 day 1 |
| 32-bit address space exhaustion before Phase 4 | Medium | High | Phase 4 (64-bit) is explicitly scheduled before Phase 5 (pool work) |
| PSO compilation stutter during Phase 3 development | Medium | Medium | Precompile + cache all PSOs at build time; `PSOCache.bin` loaded at startup |
| AI time budget overrun causing turn stalls | Medium | Medium | Hard-cap AI budget at 40 ms per tick; defer overflow with `LOG_WARN` |
| Regression in skirmish AI quality from time-slicing | Medium | Medium | Tune budget per AI difficulty level; add AI-quality automated regression test |
| DX12 validation layer false positives blocking development | Low | Low | Suppress known-safe warnings via info-queue filter; document suppression list |
| Desync introduced by async pathfinding scheduling | Medium | High | Pathfinding results applied only at deterministic tick boundaries; include path state in CRC32 |
| GenTool DLL incompatibility after 64-bit port | Medium | Medium | Migrate off GenTool to DXVK before Phase 4; GenTool is 32-bit only |

---

## Appendix A — File Status Reference

| File | Purpose | Status |
|------|---------|--------|
| `Win32Device/Common/Win32BIGFileSystem.cpp` | BIG archive loading | ✅ Per-5000 trace (was per-file — 45 min startup fixed) |
| `WW3D2/dx8wrapper.cpp` | DX8 wrapper — device creation | ✅ Scope fixes; DX9 fallback; GetAdapterIdentifier flags=0 |
| `WW3D2/dx8wrapper.h` | DX8 interface declarations | ✅ D3DXVECTOR4 overloads for MSVC 2022 |
| `Stubs/DX8Stubs/d3d8.h` | Compile-time DX8 stubs | ❌ Ordering issues; missing D3DDP_MAXTEXCOORD; d3dx8.h missing |
| `W3DDevice/GameClient/W3DDisplay.cpp` | Display creation + WW3D init | ✅ Logging added |
| `GameEngine/Source/Common/GameEngine.cpp` | Engine init, BIG load, INI | ✅ |
| `GameEngine/Source/GameClient/GameClient.cpp` | Subsystem init order | ✅ |
| `GameEngine/Source/GameLogic/Object/Weapon.cpp` | Weapon sound validation | ✅ Assert → warning |
| `GameEngine/Source/Common/Thing/ThingTemplate.cpp` | Object audio validation | ✅ Assert → warning |
| `Main/WinMain.cpp` | Entry point, copy protection | ✅ |
| `NewSystems/Logger/Logger.h` | Modern logging system | ✅ Active |
| `NewSystems/CrashHandler/` | Minidump crash handler | ✅ Active |
| `JobSystem.h / JobSystem.cpp` | Multi-core job dispatch | 🔧 Fixed deadlock: Submit() now marks m_done=true after fn() executes |
| `PoolAllocator.h` | Thread-safe object pools | ✅ Implemented with bitset tracking and multi-block expansion |
| `FlowField.h / FlowField.cpp` | BFS pathfinding | ✅ Full implementation with 8-directional movement |
| `DX11W3DDevice.cpp` | DX11 renderer skeleton | ⚠️ Device init + swap chain correct; no shaders or draw calls wired |
| `VulkanRenderDevice.h/cpp` | Vulkan backend | ⚠️ Header complete; cpp unverified; blocked by missing IRenderDevice.h |
| `IAudioDevice.h` | Audio interface | ✅ Well-designed interface header |
| `XAudio2Device.cpp` | XAudio2 backend | ⚠️ Initialize/Shutdown correct; PlaySFX/PlayMusic/etc. are empty stubs |

**Critical Missing Files:**
- ❌ `IRenderDevice.h` — Base interface for all render backends (Phase 1.2)
- ❌ `IInputDevice.h` — Base interface needed by SDL2InputDevice
- ❌ `SlotMap.h` — Stable handles with generation counters for object pools
- ❌ `SpatialHash.h` — Spatial partitioning for collision/query optimization
- ❌ `RenderStateCache.h` — PSO and state caching for DX12/Vulkan
- ❌ `.github/workflows/build.yml` — CI pipeline for automated builds

**Dependency Order Warning:**
⚠️ Phase 3/7 backends (VulkanRenderDevice, DX11W3DDevice, SDL2InputDevice) were written before Phase 1 base interfaces (IRenderDevice, IInputDevice) were defined. This causes compilation failures and must be resolved before merging.

## Appendix B — DX8 Wrapper Initialization Pipeline (Reference)

```
generals_zh.exe
  WinMain()                              ModernizedSrc/Main/WinMain.cpp
  TheGameEngine->init()                  Loads .big archives, INI, objects
  TheGameClient->init()
    createGameDisplay()                  W3DDisplay constructor
    TheDisplay->init()
      WWMath::Init()
      WW3D::Init(hwnd)                   ← DX8 initialization starts here
        DX8Wrapper::Init()
          LoadLibrary("d3d8.dll")        GenTool / DXVK / WineD3D8
          Direct3DCreate8()
          Enumerate_Devices()
            GetAdapterCount()
            GetAdapterIdentifier(0, 0)   ← flags MUST be 0, not D3DENUM_NO_WHQL_LEVEL
            GetDeviceCaps()
            GetAdapterModeCount()
  WW3D::Set_Render_Device(0, ...)       ← Device creation
    DX8Wrapper::Set_Render_Device()
      D3DInterface->CreateDevice()       ← Currently fails on Win11 + RTX
```
