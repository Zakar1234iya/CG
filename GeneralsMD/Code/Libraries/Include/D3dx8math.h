#pragma once
// DX8 math stub for WWMath -- provides minimal types needed for compilation
// Full DX11 migration will replace these with DirectXMath

#include <DirectXMath.h>
#include <cstdint>

typedef DirectX::XMFLOAT2 D3DXVECTOR2;
typedef DirectX::XMFLOAT3 D3DXVECTOR3;
typedef DirectX::XMFLOAT4 D3DXVECTOR4;

struct D3DXMATRIX {
    DirectX::XMFLOAT4X4 m;
    float operator()(int i, int j) const { return m.m[i][j]; }
    float& operator()(int i, int j) { return m.m[i][j]; }
};

inline D3DXMATRIX* D3DXMatrixMultiply(D3DXMATRIX* out, const D3DXMATRIX* a, const D3DXMATRIX* b) {
    DirectX::XMMATRIX ma = DirectX::XMLoadFloat4x4(&a->m);
    DirectX::XMMATRIX mb = DirectX::XMLoadFloat4x4(&b->m);
    DirectX::XMStoreFloat4x4(&out->m, DirectX::XMMatrixMultiply(ma, mb));
    return out;
}

inline D3DXVECTOR3* D3DXVec3TransformCoord(D3DXVECTOR3* out, const D3DXVECTOR3* v, const D3DXMATRIX* m) {
    DirectX::XMVECTOR vv = DirectX::XMLoadFloat3(v);
    DirectX::XMMATRIX mm = DirectX::XMLoadFloat4x4(&m->m);
    DirectX::XMStoreFloat3(out, DirectX::XMVector3TransformCoord(vv, mm));
    return out;
}
