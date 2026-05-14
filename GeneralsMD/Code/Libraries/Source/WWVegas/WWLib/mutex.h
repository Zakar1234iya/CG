#pragma once
#ifndef __MUTEX_H__
#define __MUTEX_H__

#include "CrossPlatform.h"
#include "critsection.h"

#ifdef PLATFORM_WINDOWS
    #include <windows.h>
#else
    #include <pthread.h>
    #include <unistd.h>
#endif

#pragma pack(push, 8)
class FastCriticalSectionClass {
public:
#ifdef PLATFORM_WINDOWS
    LONG Flag;
    LONG Padding[15];
    CRITICAL_SECTION WinCS;

    FastCriticalSectionClass() : Flag(0) {
        InitializeCriticalSection(&WinCS);
    }
    ~FastCriticalSectionClass() {
        DeleteCriticalSection(&WinCS);
    }
#else
    pthread_mutex_t Mutex;

    FastCriticalSectionClass() {
        pthread_mutex_init(&Mutex, NULL);
    }
    ~FastCriticalSectionClass() {
        pthread_mutex_destroy(&Mutex);
    }
#endif

    class LockClass {
        FastCriticalSectionClass& cs;
    public:
#ifdef PLATFORM_WINDOWS
        __forceinline LockClass(FastCriticalSectionClass& critical_section) : cs(critical_section) {
            EnterCriticalSection(&cs.WinCS);
        }
        ~LockClass() {
            LeaveCriticalSection(&cs.WinCS);
        }
#else
        __forceinline LockClass(FastCriticalSectionClass& critical_section) : cs(critical_section) {
            pthread_mutex_lock(&cs.Mutex);
        }
        ~LockClass() {
            pthread_mutex_unlock(&cs.Mutex);
        }
#endif
    };
};
#pragma pack(pop)

class MutexClass {
    void *handle;
    bool locked;
public:
    MutexClass(const char *name = NULL);
    ~MutexClass();
    bool Lock(int time = -1);  // -1 replaces INFINITE for cross-platform
    void Unlock();
};

#endif
