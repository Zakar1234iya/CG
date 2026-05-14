Texture2D UITexture : register(t0);
SamplerState UI Sampler : register(s0);

struct VSInputUI {
    float2 Position : POSITION;
    float2 TexCoord : TEXCOORD;
    float4 Color : COLOR;
};

struct PSInputUI {
    float4 Position : SV_POSITION;
    float2 TexCoord : TEXCOORD;
    float4 Color : COLOR;
};

PSInputUI VSMain(VSInputUI input) {
    PSInputUI output;
    output.Position = float4(input.Position, 0.0f, 1.0f);
    output.TexCoord = input.TexCoord;
    output.Color = input.Color;
    return output;
}

float4 PSMain(PSInputUI input) : SV_TARGET {
    return UITexture.Sample(UISampler, input.TexCoord) * input.Color;
}
