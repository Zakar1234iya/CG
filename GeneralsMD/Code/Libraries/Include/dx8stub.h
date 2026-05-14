#pragma once
// Stub header for DX8 types - replaced by DX11
// This allows WW3D2/wwshade to compile until the DX11 renderer is complete.

#include <d3d11.h>
#include <DirectXMath.h>

typedef ID3D11Device* LPDIRECT3DDEVICE8;
typedef ID3D11DeviceContext* LPDIRECT3DDEVICE8_CTX;

struct D3DXVECTOR3 { float x, y, z; };
struct D3DXVECTOR4 { float x, y, z, w; };
struct D3DXMATRIX { float m[4][4]; };

inline D3DXMATRIX* D3DXMatrixMultiply(D3DXMATRIX* out, const D3DXMATRIX* a, const D3DXMATRIX* b) {
    DirectX::XMMATRIX ma = DirectX::XMLoadFloat4x4((const DirectX::XMFLOAT4X4*)a);
    DirectX::XMMATRIX mb = DirectX::XMLoadFloat4x4((const DirectX::XMFLOAT4X4*)b);
    DirectX::XMStoreFloat4x4((DirectX::XMFLOAT4X4*)out, DirectX::XMMatrixMultiply(ma, mb));
    return out;
}

#define D3DFVF_XYZ 0x002
#define D3DFVF_NORMAL 0x010
#define D3DFVF_TEX1 0x100
#define D3DFVF_DIFFUSE 0x040

typedef uint32_t D3DCOLOR;
typedef uint32_t D3DFORMAT;

enum D3DPRIMITIVETYPE {
    D3DPT_TRIANGLELIST = 4,
    D3DPT_TRIANGLESTRIP = 5,
};
