// NOTE: This is a simple bilinear upscale, NOT actual DLSS
Texture2D ColorInput : register(t0);
Texture2D DepthInput : register(t1);
Texture2D MotionVectors : register(t2);
RWTexture2D<float4> Output : register(u0);

cbuffer UpscaleParams : register(b3) {
    float2 InputSize;
    float2 OutputSize;
};

[numthreads(8, 8, 1)]
void CSMain(uint3 id : SV_DispatchThreadID) {
    float2 uv = (id.xy + 0.5f) / OutputSize;
    Output[id.xy] = ColorInput.SampleLevel(LinearSampler, uv, 0);
}
