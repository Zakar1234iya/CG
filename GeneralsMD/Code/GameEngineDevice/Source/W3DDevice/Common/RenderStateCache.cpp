#include "W3DDevice/Common/RenderStateCache.h"

ID3D11BlendState* RenderStateCache::GetBlend(ID3D11Device* device, const D3D11_BLEND_DESC& desc) {
    uint32_t hash = HashBlend(desc);
    auto it = m_blendStates.find(hash);
    if (it != m_blendStates.end()) return it->second.Get();
    Microsoft::WRL::ComPtr<ID3D11BlendState> state;
    device->CreateBlendState(&desc, &state);
    m_blendStates[hash] = state;
    return state.Get();
}

ID3D11DepthStencilState* RenderStateCache::GetDepth(ID3D11Device* device, const D3D11_DEPTH_STENCIL_DESC& desc) {
    uint32_t hash = HashDepth(desc);
    auto it = m_depthStates.find(hash);
    if (it != m_depthStates.end()) return it->second.Get();
    Microsoft::WRL::ComPtr<ID3D11DepthStencilState> state;
    device->CreateDepthStencilState(&desc, &state);
    m_depthStates[hash] = state;
    return state.Get();
}

ID3D11RasterizerState* RenderStateCache::GetRaster(ID3D11Device* device, const D3D11_RASTERIZER_DESC& desc) {
    uint32_t hash = HashRaster(desc);
    auto it = m_rasterStates.find(hash);
    if (it != m_rasterStates.end()) return it->second.Get();
    Microsoft::WRL::ComPtr<ID3D11RasterizerState> state;
    device->CreateRasterizerState(&desc, &state);
    m_rasterStates[hash] = state;
    return state.Get();
}
