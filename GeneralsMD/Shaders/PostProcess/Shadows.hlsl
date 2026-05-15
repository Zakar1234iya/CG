#ifndef SHADOWS_HLSL
#define SHADOWS_HLSL

#include "../Shared.hlsli"

Texture2D DepthTexture : register(t0);
Texture2D ShadowMap : register(t1);
SamplerComparisonState ShadowSampler : register(s0);

cbuffer ShadowCascade : register(b2) {
    float4x4 LightViewProj;
    float SplitDepth;
};

float SampleShadow(float4 shadowPos) {
    shadowPos.xyz /= shadowPos.w;
    float2 uv = shadowPos.xy * 0.5f + 0.5f;
    uv.y = 1.0f - uv.y;
    float bias = 0.001f;
    return ShadowMap.SampleCmpLevelZero(ShadowSampler, uv, shadowPos.z - bias);
}

#endif // SHADOWS_HLSL
