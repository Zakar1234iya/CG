/*
**      Command & Conquer Generals Zero Hour(tm)
**      Copyright 2025 Electronic Arts Inc.
**
**      This program is free software: you can redistribute it and/or modify
**      it under the terms of the GNU General Public License as published by
**      the Free Software Foundation, either version 3 of the License, or
**      (at your option) any later version.
**
**      This program is distributed in the hope that it will be useful,
**      but WITHOUT ANY WARRANTY; without even the implied warranty of
**      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**      GNU General Public License for more details.
**
**      You should have received a copy of the GNU General Public License
**      along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

////////////////////////////////////////////////////////////////////////////////
// Cross-Platform Compatibility Header
// Provides definitions for non-Windows platforms
////////////////////////////////////////////////////////////////////////////////

#ifndef CROSSPLATFORM_H
#define CROSSPLATFORM_H

// Platform detection
#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_WINDOWS 1
#elif defined(__linux__) || defined(__FreeBSD__)
    #define PLATFORM_LINUX 1
#elif defined(__APPLE__)
    #define PLATFORM_MACOS 1
#else
    #define PLATFORM_UNKNOWN 1
#endif

// Compiler detection
#if defined(_MSC_VER)
    #define COMPILER_MSVC 1
    #define COMPILER_VERSION _MSC_VER
#elif defined(__GNUC__)
    #define COMPILER_GCC 1
    #define COMPILER_VERSION __VERSION__
#elif defined(__clang__)
    #define COMPILER_CLANG 1
    #define COMPILER_VERSION __clang_version__
#else
    #define COMPILER_UNKNOWN 1
#endif

// Calling convention macros (__cdecl is MSVC-specific)
#ifndef _MSC_VER
    #define __cdecl
    #define __stdcall
    #define __fastcall
#endif

// MSVC-specific pragmas
#ifdef _MSC_VER
    #define MSVC_PRAGMA(x) __pragma(x)
    #define DISABLE_WARNING(w) __pragma(warning(disable : w))
#else
    #define MSVC_PRAGMA(x)
    #define DISABLE_WARNING(w)
#endif

// Common MSVC warning disables for GCC/Clang
#ifndef _MSC_VER
    // Disable unused parameter warnings
    #define UNUSED_PARAM(x) (void)(x)
#else
    #define UNUSED_PARAM(x)
#endif

// Windows.h replacements for POSIX systems
#ifndef PLATFORM_WINDOWS

    // Basic Windows types
    #ifndef _WINDOWS_
        typedef unsigned char BYTE;
        typedef unsigned short WORD;
        typedef unsigned int DWORD;
        typedef int BOOL;
        typedef void* HWND;
        typedef void* HINSTANCE;
        typedef void* HMODULE;
        typedef void* HANDLE;
        typedef void* HDC;
        typedef void* HGLRC;
        typedef unsigned long ULONG;
        typedef long LONG;
        typedef float FLOAT;
        typedef double DOUBLE;
        
        #define TRUE 1
        #define FALSE 0
        
        #ifndef NULL
            #ifdef __cplusplus
                #define NULL 0
            #else
                #define NULL ((void*)0)
            #endif
        #endif
    #endif

    // Win32 API stubs - replaced with inline functions for safety and correctness
    
    // Fixed: Use nanosleep instead of deprecated usleep, include proper headers
    // Function name is PlatformSleep to avoid conflict with Windows.h Sleep()
    static inline void PlatformSleep(uint32_t ms) {
        #if defined(PLATFORM_WINDOWS)
            // This branch won't compile on Windows (guarded by #ifndef PLATFORM_WINDOWS)
            // but kept for completeness
            (void)ms;
        #else
            #include <time.h>
            struct timespec ts;
            ts.tv_sec = ms / 1000;
            ts.tv_nsec = (ms % 1000) * 1000000L;
            nanosleep(&ts, NULL);
        #endif
    }
    
    // Legacy macro for backward compatibility (deprecated, use PlatformSleep)
    #define Sleep(ms) PlatformSleep(ms)
    
    #define MessageBoxA(hwnd, text, caption, type) printf("%s: %s\n", caption, text)
    #define MessageBoxW(hwnd, text, caption, type) printf("MessageBoxW called\n")
    
    #ifdef UNICODE
        #define MessageBox MessageBoxW
    #else
        #define MessageBox MessageBoxA
    #endif

    // File mapping constants
    #define GENERIC_READ 0x80000000
    #define GENERIC_WRITE 0x40000000
    #define OPEN_EXISTING 3
    #define CREATE_ALWAYS 2
    
    // Memory mapping
    #define PAGE_READONLY 0x02
    #define PAGE_READWRITE 0x04
    #define FILE_MAP_READ 0x04
    #define FILE_MAP_WRITE 0x02
    
    // Thread priorities
    #define THREAD_PRIORITY_NORMAL 0
    #define THREAD_PRIORITY_HIGHEST 2
    
    // Virtual memory
    #define MEM_COMMIT 0x1000
    #define MEM_RESERVE 0x2000
    #define MEM_RELEASE 0x8000
    #define PAGE_EXECUTE_READWRITE 0x40

// COM/Windows compatibility
typedef DWORD HRESULT;

#ifndef STDMETHODCALLTYPE
#define STDMETHODCALLTYPE
#endif

#ifndef MAKE_HRESULT
#define MAKE_HRESULT(sev,fac,code) \
    ((HRESULT)(((unsigned long)(sev)<<31)|((unsigned long)(fac)<<16)|((unsigned long)(code))))
#endif

#ifndef S_OK
#define S_OK ((HRESULT)0L)
#endif

#ifndef E_FAIL
#define E_FAIL ((HRESULT)0x80004005L)
#endif

#ifndef E_NOTIMPL
#define E_NOTIMPL ((HRESULT)0x80004001L)
#endif

#ifndef E_INVALIDARG
#define E_INVALIDARG ((HRESULT)0x80070057L)
#endif

#ifndef E_NOINTERFACE
#define E_NOINTERFACE ((HRESULT)0x80004002L)
#endif

#ifndef E_POINTER
#define E_POINTER ((HRESULT)0x80004003L)
#endif

#ifndef S_FALSE
#define S_FALSE ((HRESULT)1L)
#endif

#endif // !PLATFORM_WINDOWS

// Min/Max macros
#ifndef min
    #define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
    #define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

// NOMINMAX replacement
#ifndef NOMINMAX
    #define NOMINMAX
#endif

// WIN32_LEAN_AND_MEAN equivalent
#ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
#endif

// Secure CRT replacements
#ifndef _MSC_VER
    #define _CRT_SECURE_NO_WARNINGS
    #define _CRT_NONSTDC_NO_DEPRECATE
    
    // Safe string functions - FIXED: proper bounds checking
    #ifndef strcpy_s
        static inline int strcpy_s(char* dest, size_t size, const char* src) {
            if (!dest || !src || size == 0) return 22; // EINVAL
            size_t srclen = strlen(src);
            if (srclen >= size) {
                dest[0] = '\0';
                return 34; // ERANGE
            }
            memcpy(dest, src, srclen + 1);
            return 0;
        }
    #endif
    
    #ifndef strcat_s
        static inline int strcat_s(char* dest, size_t size, const char* src) {
            if (!dest || !src || size == 0) return 22; // EINVAL
            size_t destlen = strlen(dest);
            size_t srclen = strlen(src);
            if (destlen + srclen >= size) {
                dest[0] = '\0';
                return 34; // ERANGE
            }
            memcpy(dest + destlen, src, srclen + 1);
            return 0;
        }
    #endif
    
    #ifndef sprintf_s
        #define sprintf_s(buf, size, fmt, ...) snprintf(buf, size, fmt, ##__VA_ARGS__)
    #endif
    
    #ifndef memcpy_s
        static inline int memcpy_s(void* dest, size_t destSize, const void* src, size_t count) {
            if (!dest || !src) return 22; // EINVAL
            if (count > destSize) {
                memset(dest, 0, destSize);
                return 34; // ERANGE
            }
            memcpy(dest, src, count);
            return 0;
        }
    #endif
    
    #ifndef fopen_s
        static inline int fopen_s(FILE** pFile, const char* filename, const char* mode) {
            if (!pFile || !filename || !mode) return 22; // EINVAL
            *pFile = fopen(filename, mode);
            return (*pFile == NULL) ? errno : 0;
        }
    #endif
#endif

// _countof macro
#ifndef _countof
    #define _countof(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

// Interlocked operations (atomic operations)
// These must match Windows semantics exactly:
// - InterlockedCompareExchange takes comparand BY VALUE (not by reference)
// - Returns the PREVIOUS value (not a bool like C11 atomics)
#ifndef _MSC_VER
    #include <stdatomic.h>
    #include <stdbool.h>
    
    #define InterlockedIncrement(ptr) (atomic_fetch_add_explicit((atomic_long*)(ptr), 1L, memory_order_seq_cst) + 1L)
    #define InterlockedDecrement(ptr) (atomic_fetch_sub_explicit((atomic_long*)(ptr), 1L, memory_order_seq_cst) - 1L)
    #define InterlockedExchange(ptr, val) atomic_exchange_explicit((atomic_long*)(ptr), (long)(val), memory_order_seq_cst)
    
    // Fixed: comparand passed by value, returns previous value (Windows semantics)
    static inline long InterlockedCompareExchange(volatile long* ptr, long exchange, long comparand) {
        long expected = comparand;
        atomic_compare_exchange_strong_explicit(
            (atomic_long*)ptr,
            &expected,
            exchange,
            memory_order_seq_cst,
            memory_order_seq_cst
        );
        return expected;  // Returns the original value at *ptr (Windows semantics)
    }
#endif

// TLS (Thread Local Storage) and DLL export macros
// REMOVED: blanket __declspec(x) -> __attribute__((x)) mapping (incorrect for most uses)
// Use specific migration macros instead:
#ifndef _MSC_VER
    #define DLL_EXPORT __attribute__((visibility("default")))
    #define DLL_IMPORT __attribute__((visibility("default")))
    #define THREAD_LOCAL __thread
    #if __cplusplus < 201103L
    #define thread_local _Thread_local
    #endif
#else
    #define DLL_EXPORT __declspec(dllexport)
    #define DLL_IMPORT __declspec(dllimport)
    #define THREAD_LOCAL __declspec(thread)
    #if __cplusplus < 201103L
    #define thread_local __declspec(thread)
    #endif
#endif

// Force inline
#ifndef _MSC_VER
    #define __forceinline inline __attribute__((always_inline))
#endif

// Restric keyword
#ifndef _MSC_VER
    #define __restrict __restrict__
#endif

// Debug break
#ifndef _MSC_VER
    #define __debugbreak() raise(SIGTRAP)
    #include <signal.h>
#endif

// Large integer types
#ifndef _MSC_VER
    typedef signed char INT8;
    typedef unsigned char UINT8;
    typedef signed short INT16;
    typedef unsigned short UINT16;
    typedef signed int INT32;
    typedef unsigned int UINT32;
    typedef signed long long INT64;
    typedef unsigned long long UINT64;
    
    #define MAKEFOURCC(ch0, ch1, ch2, ch3) \
        ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) | \
        ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24))
#endif

// GUID/UUID support
#ifndef _MSC_VER
    typedef struct {
        unsigned int  Data1;
        unsigned short Data2;
        unsigned short Data3;
        unsigned char  Data4[8];
    } GUID;
    
    #define REFGUID const GUID&
    #define REFCLSID const GUID&
    #define REFIID const GUID&
#endif

#endif // CROSSPLATFORM_H
