#include "Video/IVideoPlayer.h"

class FFmpegVideoPlayer : public IVideoPlayer {
    int m_width = 0;
    int m_height = 0;
    bool m_finished = false;

public:
    bool Open(const char* path) override {
        return false;
    }

    bool DecodeFrame() override {
        return false;
    }

    void Close() override {
    }

    int GetWidth() const override { return m_width; }
    int GetHeight() const override { return m_height; }
    bool IsFinished() const override { return m_finished; }
};
