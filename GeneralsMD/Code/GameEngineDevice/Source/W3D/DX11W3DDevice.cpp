#include "DX11W3DDevice.h"
#include <d3d11.h>
#include <dxgi1_2.h>
#include <wrl/client.h>

using Microsoft::WRL::ComPtr;

class DX11W3DDevice {
private:
    ComPtr<ID3D11Device> m_device;
    ComPtr<ID3D11DeviceContext> m_context;
    ComPtr<IDXGISwapChain1> m_swapChain;
    ComPtr<ID3D11RenderTargetView> m_rtv;
    DXGI_SWAP_CHAIN_DESC1 m_sd;

public:
    bool Initialize(HWND hwnd, int width, int height, bool fullscreen) {
        // Create device
        D3D_FEATURE_LEVEL levels[] = { D3D_FEATURE_LEVEL_11_0 };
        D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
                          levels, 1, D3D11_SDK_VERSION, &m_device, nullptr, &m_context);

        // Create swap chain
        ComPtr<IDXGIDevice> dxgiDevice;
        ComPtr<IDXGIAdapter> dxgiAdapter;
        ComPtr<IDXGIFactory2> dxgiFactory;
        m_device.As(&dxgiDevice);
        dxgiDevice->GetAdapter(&dxgiAdapter);
        CreateDXGIFactory2(0, IID_PPV_ARGS(&dxgiFactory));
        
        m_sd.Width = width;
        m_sd.Height = height;
        m_sd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        m_sd.Stereo = FALSE;
        m_sd.SampleDesc.Count = 1;
        m_sd.SampleDesc.Quality = 0;
        m_sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        m_sd.BufferCount = 2;
        m_sd.Scaling = DXGI_SCALING_STRETCH;
        m_sd.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
        m_sd.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
        m_sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING;
        
        dxgiFactory->CreateSwapChainForHwnd(m_device.Get(), hwnd, &m_sd, nullptr, nullptr, &m_swapChain);
        CreateRenderTargets();
        return true;
    }

    void CreateRenderTargets() {
        ComPtr<ID3D11Texture2D> backBuffer;
        m_swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));
        m_device->CreateRenderTargetView(backBuffer.Get(), nullptr, &m_rtv);
    }

    void BeginFrame() {
        float clearColor[] = { 0.0f, 0.0f, 0.0f, 1.0f };
        m_context->ClearRenderTargetView(m_rtv.Get(), clearColor);
        m_context->OMSetRenderTargets(1, m_rtv.GetAddressOf(), nullptr);
    }

    void Present() {
        m_swapChain->Present(1, 0);
    }
};