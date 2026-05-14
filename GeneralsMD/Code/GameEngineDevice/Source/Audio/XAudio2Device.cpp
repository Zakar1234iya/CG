#include "Audio/IAudioDevice.h"
#include <XAudio2.h>
#include <x3daudio.h>

class XAudio2Device : public IAudioDevice {
    IXAudio2* m_xaudio = nullptr;
    IXAudio2MasteringVoice* m_master = nullptr;
    X3DAUDIO_HANDLE m_x3d;

public:
    void Initialize() override {
        XAudio2Create(&m_xaudio, 0, XAUDIO2_DEFAULT_PROCESSOR);
        m_xaudio->CreateMasteringVoice(&m_master);
    }

    void Shutdown() override {
        if (m_master) m_master->DestroyVoice();
        if (m_xaudio) m_xaudio->Release();
    }

    void PlaySFX(SoundID id, const DirectX::XMFLOAT3& worldPos, float volume) override {
    }

    void PlayMusic(const char* trackPath, bool loop) override {
    }

    void StopMusic() override {
    }

    void Set3DListener(const DirectX::XMFLOAT3& pos, const DirectX::XMFLOAT3& forward) override {
    }

    void Update(float dt) override {
    }
};
