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

    // Win32 API stubs - these need proper implementations
    #define Sleep(ms) usleep((ms) * 1000)
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
    
    // Safe string functions
    #ifndef strcpy_s
        #define strcpy_s(dest, size, src) strncpy(dest, src, size)
    #endif
    #ifndef strcat_s
        #define strcat_s(dest, size, src) strncat(dest, src, size - strlen(dest) - 1)
    #endif
    #ifndef sprintf_s
        #define sprintf_s(buf, size, fmt, ...) snprintf(buf, size, fmt, ##__VA_ARGS__)
    #endif
    #ifndef memcpy_s
        #define memcpy_s(dest, destSize, src, count) memcpy(dest, src, count)
    #endif
    #ifndef fopen_s
        #define fopen_s(pFile, filename, mode) (*(pFile) = fopen(filename, mode)) == NULL ? errno : 0
    #endif
#endif

// _countof macro
#ifndef _countof
    #define _countof(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

// Interlocked operations (atomic operations)
#ifndef _MSC_VER
    #include <stdatomic.h>
    
    #define InterlockedIncrement(ptr) atomic_fetch_add_explicit((atomic_int*)(ptr), 1, memory_order_seq_cst) + 1
    #define InterlockedDecrement(ptr) atomic_fetch_sub_explicit((atomic_int*)(ptr), 1, memory_order_seq_cst) - 1
    #define InterlockedExchange(ptr, val) atomic_exchange_explicit((atomic_int*)(ptr), (int)(val), memory_order_seq_cst)
    #define InterlockedCompareExchange(ptr, exchange, comparand) atomic_compare_exchange_strong_explicit((atomic_int*)(ptr), &(comparand), (exchange), memory_order_seq_cst, memory_order_seq_cst)
#endif

// TLS (Thread Local Storage)
#ifndef _MSC_VER
    #define __declspec(x) __attribute__((x))
    #define thread_local _Thread_local
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
