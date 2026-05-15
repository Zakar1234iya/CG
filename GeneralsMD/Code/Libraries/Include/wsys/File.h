#pragma once
// wsys/File.h stub — platform file system wrapper
#include <windows.h>
#include <cstdio>

class File {
public:
    File() : m_handle(NULL) {}
    virtual ~File() { Close(); }
    virtual bool Open(const char* path, const char* mode) {
        fopen_s(&m_handle, path, mode);
        return m_handle != NULL;
    }
    virtual void Close() { if (m_handle) { fclose(m_handle); m_handle = NULL; } }
    virtual int Read(void* buf, int size) {
        if (!m_handle) return 0;
        return (int)fread(buf, 1, size, m_handle);
    }
    virtual int Write(const void* buf, int size) {
        if (!m_handle) return 0;
        return (int)fwrite(buf, 1, size, m_handle);
    }
    virtual bool Seek(int pos, int origin) {
        if (!m_handle) return false;
        return fseek(m_handle, pos, origin) == 0;
    }
    virtual int Tell() {
        if (!m_handle) return 0;
        return (int)ftell(m_handle);
    }
protected:
    FILE* m_handle;
};
