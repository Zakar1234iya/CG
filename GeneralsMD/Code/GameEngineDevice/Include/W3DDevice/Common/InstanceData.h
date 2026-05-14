#pragma once
#include <DirectXMath.h>

struct InstanceData {
    DirectX::XMFLOAT4X4 world;
    DirectX::XMFLOAT4   tint;
    uint32_t            textureIndex;
    uint32_t            healthRatio;
    float               padding[2];
};

static_assert(sizeof(InstanceData) % 16 == 0, "InstanceData must be 16-byte aligned");
