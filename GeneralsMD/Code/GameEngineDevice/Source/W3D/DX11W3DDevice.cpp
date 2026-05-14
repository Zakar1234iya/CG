#include <d3d11.h>
#include <d3d11_1.h>
#include <dxgi1_2.h>
#include <DirectXMath.h>
#include <wrl.h>

using namespace Microsoft::WRL;
using namespace DirectX;

class DX11W3DDevice {
    ComPtr<ID3D11Device> m_device;
    ComPtr<ID3D11DeviceContext> m_context;
    ComPtr<IDXGISwapChain1> m_swapChain;
    ComPtr<ID3D11RenderTargetView> m_rtv;
    ComPtr<ID3D11DepthStencilView> m_dsv;

    DXGI_SWAP_CHAIN_DESC1 m_sd = {};

public:
    bool Initialize(HWND hwnd, int width, int height) {
        m_sd.Width = width;
        m_sd.Height = height;
        m_sd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        m_sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        m_sd.BufferCount = 2;
        m_sd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        m_sd.SampleDesc = { 1, 0 };

        UINT flags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#if defined(_DEBUG)
        flags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

        D3D_FEATURE_LEVEL levels[] = { D3D_FEATURE_LEVEL_11_1 };

        HRESULT hr = D3D11CreateDevice(
            nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, flags,
            levels, 1, D3D11_SDK_VERSION,
            &m_device, nullptr, &m_context
        );
        if (FAILED(hr)) return false;

        ComPtr<IDXGIDevice1> dxgiDevice;
        ComPtr<IDXGIAdapter> dxgiAdapter;
        ComPtr<IDXGIFactory2> dxgiFactory;
        m_device.As(&dxgiDevice);
        dxgiDevice->GetAdapter(&dxgiAdapter);
        DXGIGetDebugInterface1(0, IID_PPV_ARGS(&dxgiFactory));
        dxgiFactory->CreateSwapChainForHwnd(m_device.Get(), hwnd, &m_sd, nullptr, nullptr, &m_swapChain);

        CreateRenderTargets();
        return true;
    }

    void CreateRenderTargets() {
        ComPtr<ID3D11Texture2D> backBuffer;
        m_swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));
        m_device->CreateRenderTargetView(backBuffer.Get(), nullptr, &m_rtv);

        D3D11_TEXTURE2D_DESC depthDesc = {};
        depthDesc.Width = m_sd.Width;
        depthDesc.Height = m_sd.Height;
        depthDesc.MipLevels = 1;
        depthDesc.ArraySize = 1;
        depthDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
        depthDesc.SampleDesc = { 1, 0 };
        depthDesc.Usage = D3D11_USAGE_DEFAULT;
        depthDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;

        ComPtr<ID3D11Texture2D> depthBuffer;
        m_device->CreateTexture2D(&depthDesc, nullptr, &depthBuffer);
        m_device->CreateDepthStencilView(depthBuffer.Get(), nullptr, &m_dsv);

        m_context->OMSetRenderTargets(1, m_rtv.GetAddressOf(), m_dsv.Get());
    }

    void BeginFrame() {
        float clearColor[] = { 0.0f, 0.0f, 0.0f, 1.0f };
        m_context->ClearRenderTargetView(m_rtv.Get(), clearColor);
        m_context->ClearDepthStencilView(m_dsv.Get(), D3D11_CLEAR_DEPTH, 1.0f, 0);
    }

    void EndFrame() {
        m_swapChain->Present(1, 0);
    }

    void Resize(int width, int height) {
        m_context->OMSetRenderTargets(0, nullptr, nullptr);
        m_rtv.Reset();
        m_dsv.Reset();
        m_swapChain->ResizeBuffers(0, width, height, DXGI_FORMAT_UNKNOWN, 0);
        m_sd.Width = width;
        m_sd.Height = height;
        CreateRenderTargets();
    }
};
