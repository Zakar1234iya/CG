#pragma once
#include <d3d11.h>

class IUpscaler {
public:
    virtual ~IUpscaler() = default;
    virtual void Init(ID3D11Device* device, int renderW, int renderH, int outputW, int outputH) = 0;
    virtual void Upscale(
        ID3D11ShaderResourceView* color,
        ID3D11ShaderResourceView* depth,
        ID3D11ShaderResourceView* motionVectors,
        ID3D11UnorderedAccessView* output) = 0;
    virtual const char* Name() const = 0;
};

class BilinearUpscaler : public IUpscaler {
public:
    void Init(ID3D11Device*, int, int, int, int) override {}
    void Upscale(ID3D11ShaderResourceView*, ID3D11ShaderResourceView*, ID3D11ShaderResourceView*, ID3D11UnorderedAccessView*) override {}
    const char* Name() const override { return "Bilinear"; }
};
