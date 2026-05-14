#pragma once
#include <d3d11.h>
#include <wrl.h>
#include <unordered_map>

class RenderStateCache {
    std::unordered_map<uint32_t, Microsoft::WRL::ComPtr<ID3D11BlendState>> m_blendStates;
    std::unordered_map<uint32_t, Microsoft::WRL::ComPtr<ID3D11DepthStencilState>> m_depthStates;
    std::unordered_map<uint32_t, Microsoft::WRL::ComPtr<ID3D11RasterizerState>> m_rasterStates;

    static uint32_t HashBlend(const D3D11_BLEND_DESC& desc) {
        uint32_t h = 0;
        for (int i = 0; i < 8; ++i) {
            h ^= (desc.RenderTarget[i].BlendEnable << i);
            h ^= (desc.RenderTarget[i].SrcBlend << (i + 8));
            h ^= (desc.RenderTarget[i].DestBlend << (i + 16));
        }
        return h;
    }

    static uint32_t HashDepth(const D3D11_DEPTH_STENCIL_DESC& desc) {
        return desc.DepthEnable ^ (desc.DepthWriteMask << 1) ^ (desc.DepthFunc << 2);
    }

    static uint32_t HashRaster(const D3D11_RASTERIZER_DESC& desc) {
        return desc.FillMode ^ (desc.CullMode << 2) ^ (desc.DepthClipEnable << 4);
    }

public:
    ID3D11BlendState* GetBlend(ID3D11Device* device, const D3D11_BLEND_DESC& desc);
    ID3D11DepthStencilState* GetDepth(ID3D11Device* device, const D3D11_DEPTH_STENCIL_DESC& desc);
    ID3D11RasterizerState* GetRaster(ID3D11Device* device, const D3D11_RASTERIZER_DESC& desc);
};
