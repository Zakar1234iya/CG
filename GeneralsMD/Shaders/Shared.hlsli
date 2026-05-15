cbuffer PerFrame : register(b0) {
    float4x4 ViewProj;
    float3   CameraPos;
    float    Time;
    float3   SunDirection;
    float    _Padding0; // Alignment padding
};

cbuffer PerObject : register(b1) {
    float4x4 World;
    float4x4 WorldInverseTranspose;
    float4   TintColor;
};

Texture2D DiffuseTexture : register(t0);
SamplerState LinearSampler : register(s0);

struct VSInput {
    float3 Position : POSITION;
    float3 Normal : NORMAL;
    float2 TexCoord : TEXCOORD;
};

struct PSInput {
    float4 Position : SV_POSITION;
    float3 Normal : NORMAL;
    float2 TexCoord : TEXCOORD;
    float3 WorldPos : POSITION1;
};
