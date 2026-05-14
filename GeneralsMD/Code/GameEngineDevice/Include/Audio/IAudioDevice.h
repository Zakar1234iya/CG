#pragma once
#ifndef __IAUDIODEVICE_H__
#define __IAUDIODEVICE_H__

#include <DirectXMath.h>

using SoundID = unsigned int;

class IAudioDevice {
public:
    virtual ~IAudioDevice() = default;
    virtual void PlaySFX(SoundID id, const DirectX::XMFLOAT3& worldPos, float volume = 1.0f) = 0;
    virtual void PlayMusic(const char* trackPath, bool loop = true) = 0;
    virtual void StopMusic() = 0;
    virtual void Set3DListener(const DirectX::XMFLOAT3& pos, const DirectX::XMFLOAT3& forward) = 0;
    virtual void Update(float dt) = 0;
    virtual void Initialize() = 0;
    virtual void Shutdown() = 0;
};

#endif
