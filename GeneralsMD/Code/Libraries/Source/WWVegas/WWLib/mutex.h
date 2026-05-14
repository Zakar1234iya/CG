#pragma once
#ifndef __MUTEX_H__
#define __MUTEX_H__

#include <windows.h>
#include "critsection.h"

#pragma pack(push, 8)
class FastCriticalSectionClass {
public:
    LONG Flag;
    LONG Padding[15];
    CRITICAL_SECTION WinCS;

    FastCriticalSectionClass() : Flag(0) {
        InitializeCriticalSection(&WinCS);
    }
    ~FastCriticalSectionClass() {
        DeleteCriticalSection(&WinCS);
    }

    class LockClass {
        FastCriticalSectionClass& cs;
    public:
        __forceinline LockClass(FastCriticalSectionClass& critical_section) : cs(critical_section) {
            EnterCriticalSection(&cs.WinCS);
        }
        ~LockClass() {
            LeaveCriticalSection(&cs.WinCS);
        }
    };
};
#pragma pack(pop)

class MutexClass {
    void *handle;
    bool locked;
public:
    MutexClass(const char *name = NULL);
    ~MutexClass();
    bool Lock(int time = INFINITE);
    void Unlock();
};

#endif
