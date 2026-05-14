#include "Shared.hlsli"

PSInput VSMain(VSInput input) {
    PSInput output;
    float4 worldPos = mul(float4(input.Position, 1.0f), World);
    output.Position = mul(worldPos, ViewProj);
    output.Normal = mul(input.Normal, (float3x3)World);
    output.TexCoord = input.TexCoord;
    output.WorldPos = worldPos.xyz;
    return output;
}

float4 PSMain(PSInput input) : SV_TARGET {
    float4 albedo = DiffuseTexture.Sample(LinearSampler, input.TexCoord);
    float3 N = normalize(input.Normal);
    float NdotL = saturate(dot(N, SunDirection));
    float3 color = albedo.rgb * (NdotL * 0.8f + 0.3f);
    return float4(color, albedo.a);
}
