#include "Shared.hlsli"

Texture2D TerrainAlbedo : register(t0);
Texture2D TerrainNormal : register(t1);
Texture2D TerrainRoughness : register(t2);

float3 UnpackNormal(float2 encoded) {
    float3 n;
    n.xy = encoded * 2.0f - 1.0f;
    n.z = sqrt(1.0f - saturate(dot(n.xy, n.xy)));
    return n;
}

PSInput VSMain(VSInput input) {
    PSInput output;
    float4 worldPos = mul(float4(input.Position, 1.0f), World);
    output.Position = mul(worldPos, ViewProj);
    output.Normal = normalize(mul(input.Normal, (float3x3)WorldInverseTranspose));
    output.TexCoord = input.TexCoord;
    output.WorldPos = worldPos.xyz;
    return output;
}

float4 PSMain(PSInput input) : SV_TARGET {
    float3 albedo = TerrainAlbedo.Sample(LinearSampler, input.TexCoord).rgb;
    float roughness = TerrainRoughness.Sample(LinearSampler, input.TexCoord).r;
    float3 normal = UnpackNormal(TerrainNormal.Sample(LinearSampler, input.TexCoord).xy);
    float NdotL = saturate(dot(normal, SunDirection));
    float3 color = albedo * (NdotL * 0.8f + 0.3f);
    return float4(color, 1.0f);
}
