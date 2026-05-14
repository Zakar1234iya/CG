/*
** Cross-Platform Compatibility Header
** Replaces Windows-specific types and functions for cross-platform builds
*/

#ifndef CROSSPLATFORM_H
#define CROSSPLATFORM_H

#include "always.h"

// Platform detection
#if defined(_WIN32) || defined(_WIN64)
    #define WW_PLATFORM_WINDOWS 1
    #include <windows.h>
#else
    #define WW_PLATFORM_WINDOWS 0
    
    // Basic Windows type replacements
    typedef unsigned char BYTE;
    typedef unsigned short WORD;
    typedef unsigned int DWORD;
    typedef int BOOL;
    typedef void* HWND;
    typedef void* HINSTANCE;
    typedef void* HMODULE;
    typedef void* HDC;
    typedef void* HGLRC;
    typedef long LONG;
    typedef unsigned long ULONG;
    typedef float FLOAT;
    
    #define TRUE 1
    #define FALSE 0
    
    #define CALLBACK
    #define WINAPI
    #define APIENTRY
    
    // Include POSIX headers
    #include <pthread.h>
    #include <dlfcn.h>
#endif

// Compiler-specific macros
#if defined(_MSC_VER)
    #define WW_MSC_VER _MSC_VER
    #define WW_FORCE_INLINE __forceinline
    #define WW_RESTRICT __restrict
    #define WW_ALIGN(n) __declspec(align(n))
    #define WW_DEPRECATED __declspec(deprecated)
    #define WW_THREAD_LOCAL __declspec(thread)
    
    // Disable specific MSVC warnings
    #pragma warning(disable: 4267) // conversion to smaller type
    #pragma warning(disable: 4244) // conversion possible loss of data
    #pragma warning(disable: 4100) // unreferenced formal parameter
    #pragma warning(disable: 4189) // local variable initialized but not referenced
#else
    #define WW_MSC_VER 0
    #define WW_FORCE_INLINE inline __attribute__((always_inline))
    #define WW_RESTRICT __restrict__
    #define WW_ALIGN(n) __attribute__((aligned(n)))
    #define WW_DEPRECATED __attribute__((deprecated))
    #define WW_THREAD_LOCAL __thread
    
    // GCC/Clang specific
    #if defined(__GNUC__) && !defined(__clang__)
        #define WW_GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
    #endif
    
    #if defined(__clang__)
        #define WW_CLANG_VERSION (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
    #endif
#endif

// Calling convention macros (only meaningful on Windows x86)
#if !WW_PLATFORM_WINDOWS || defined(_M_X64) || defined(__x86_64__)
    #define __cdecl
    #define __stdcall
    #define __fastcall
#endif

// Secure CRT replacements for non-MSVC compilers
#if !WW_MSC_VER
    #ifndef _CRT_SECURE_NO_WARNINGS
        #define _CRT_SECURE_NO_WARNINGS
    #endif
    
    // Safe string functions
    #ifndef strcpy_s
        #define strcpy_s(dest, destSize, src) strncpy(dest, src, destSize)
    #endif
    
    #ifndef strcat_s
        #define strcat_s(dest, destSize, src) strncat(dest, src, destSize - strlen(dest) - 1)
    #endif
    
    #ifndef sprintf_s
        #define sprintf_s(dest, destSize, format, ...) snprintf(dest, destSize, format, ##__VA_ARGS__)
    #endif
    
    #ifndef memcpy_s
        #define memcpy_s(dest, destSize, src, count) memcpy(dest, src, count)
    #endif
    
    #ifndef memset_s
        #define memset_s(dest, destSize, val, count) memset(dest, val, count)
    #endif
    
    // File operations
    #ifndef fopen_s
        #define fopen_s(pFile, filename, mode) (*(pFile) = fopen(filename, mode)) == NULL
    #endif
    
    // Other secure functions
    #ifndef _stricmp
        #define _stricmp strcasecmp
    #endif
    
    #ifndef _snprintf
        #define _snprintf snprintf
    #endif
    
    #ifndef _vsnprintf
        #define _vsnprintf vsnprintf
    #endif
#endif

// Threading abstraction
#if WW_PLATFORM_WINDOWS
    typedef HANDLE WWThreadHandle;
    typedef CRITICAL_SECTION WWCriticalSection;
    
    #define WW_InitCriticalSection(cs) InitializeCriticalSection(cs)
    #define WW_DeleteCriticalSection(cs) DeleteCriticalSection(cs)
    #define WW_EnterCriticalSection(cs) EnterCriticalSection(cs)
    #define WW_LeaveCriticalSection(cs) LeaveCriticalSection(cs)
    #define WW_TryEnterCriticalSection(cs) TryEnterCriticalSection(cs)
#else
    typedef pthread_t WWThreadHandle;
    typedef pthread_mutex_t WWCriticalSection;
    
    #define WW_InitCriticalSection(cs) pthread_mutex_init(cs, NULL)
    #define WW_DeleteCriticalSection(cs) pthread_mutex_destroy(cs)
    #define WW_EnterCriticalSection(cs) pthread_mutex_lock(cs)
    #define WW_LeaveCriticalSection(cs) pthread_mutex_unlock(cs)
    #define WW_TryEnterCriticalSection(cs) (pthread_mutex_trylock(cs) == 0)
#endif

// Dynamic library loading abstraction
#if WW_PLATFORM_WINDOWS
    #define WW_LoadLibrary(name) LoadLibraryA(name)
    #define WW_FreeLibrary(lib) FreeLibrary(lib)
    #define WW_GetProcAddress(lib, name) GetProcAddress(lib, name)
#else
    #define WW_LoadLibrary(name) dlopen(name, RTLD_NOW)
    #define WW_FreeLibrary(lib) dlclose(lib)
    #define WW_GetProcAddress(lib, name) dlsym(lib, name)
#endif

// Math helpers for portable color conversion
#include <cmath>
#include <algorithm>

namespace WWMath {
    inline float Clamp(float value, float minVal, float maxVal) {
        return std::max(minVal, std::min(maxVal, value));
    }
    
    inline int FloatToIntTruncate(float value) {
        return static_cast<int>(value);
    }
    
    // Portable color conversion (replaces inline assembly)
    inline unsigned int ConvertColorFloatToRGBA(float r, float g, float b, float a) {
        const float scale = 255.0f;
        
        // Clamp values to [0, 1] range
        r = Clamp(r, 0.0f, 1.0f);
        g = Clamp(g, 0.0f, 1.0f);
        b = Clamp(b, 0.0f, 1.0f);
        a = Clamp(a, 0.0f, 1.0f);
        
        // Convert to integer (truncate towards zero)
        unsigned int ir = FloatToIntTruncate(r * scale);
        unsigned int ig = FloatToIntTruncate(g * scale);
        unsigned int ib = FloatToIntTruncate(b * scale);
        unsigned int ia = FloatToIntTruncate(a * scale);
        
        // Pack into RGBA format (AA RR GG BB)
        return (ia << 24) | (ir << 16) | (ig << 8) | ib;
    }
    
    inline void ClampColorVector(float* color, int components) {
        for (int i = 0; i < components; ++i) {
            color[i] = Clamp(color[i], 0.0f, 1.0f);
        }
    }
}

// Vector/Math type compatibility
#ifndef __VECTOR_CLASS_DEFINED__
struct Vector3 {
    float X, Y, Z;
    Vector3() : X(0), Y(0), Z(0) {}
    Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
    float& operator[](int i) { return (&X)[i]; }
    const float& operator[](int i) const { return (&X)[i]; }
};

struct Vector4 {
    float X, Y, Z, W;
    Vector4() : X(0), Y(0), Z(0), W(0) {}
    Vector4(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) {}
    float& operator[](int i) { return (&X)[i]; }
    const float& operator[](int i) const { return (&X)[i]; }
};
#endif

// Debug macros
#ifdef _DEBUG
    #define WW_DEBUG_BREAK() \
        do { \
            #if WW_MSC_VER \
                __debugbreak(); \
            #else \
                __builtin_trap(); \
            #endif \
        } while(0)
#else
    #define WW_DEBUG_BREAK()
#endif

#endif // CROSSPLATFORM_H
