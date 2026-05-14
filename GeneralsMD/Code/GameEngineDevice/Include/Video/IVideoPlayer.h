#pragma once
#ifndef __IVIDEOPLAYER_H__
#define __IVIDEOPLAYER_H__

class IVideoPlayer {
public:
    virtual ~IVideoPlayer() = default;
    virtual bool Open(const char* path) = 0;
    virtual bool DecodeFrame() = 0;
    virtual void Close() = 0;
    virtual int GetWidth() const = 0;
    virtual int GetHeight() const = 0;
    virtual bool IsFinished() const = 0;
};

#endif
