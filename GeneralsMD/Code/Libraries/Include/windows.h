#pragma once
#ifndef WINDOWS_STUB_H
#define WINDOWS_STUB_H

#ifdef _WIN32
// On Windows, include the real Windows SDK header
// Use full path to bypass this stub - MSVC doesn't support #include_next
#if __has_include(<../windows.h>)
#include <../windows.h>
#else
#include <Windows.h>
#endif
#else
// On non-Windows, include our cross-platform compatibility layer
#include "CrossPlatform.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

// Provide commonly used Windows API macros and types
#ifndef MAX_PATH
#define MAX_PATH 260
#endif

#ifndef CALLBACK
#define CALLBACK
#endif

#ifndef WINAPI
#define WINAPI
#endif

#ifndef APIENTRY
#define APIENTRY WINAPI
#endif

#ifndef FAR
#define FAR
#endif

#ifndef NEAR
#define NEAR
#endif

typedef DWORD COLORREF;
typedef DWORD HRESULT;

// Additional Windows API stubs for non-Windows
#define MB_OK               0x00000000L
#define MB_OKCANCEL         0x00000001L
#define MB_YESNOCANCEL      0x00000003L
#define MB_YESNO            0x00000004L
#define MB_TASKMODAL        0x00002000L
#define IDOK                1
#define IDCANCEL            2
#define IDYES               6
#define IDNO                7

#define SW_HIDE             0
#define SW_SHOW             5
#define SW_MINIMIZE         6

#define VK_ESCAPE           0x1B
#define VK_RETURN           0x0D
#define VK_SPACE            0x20
#define VK_TAB              0x09
#define VK_BACK             0x08

// File attributes
#define FILE_ATTRIBUTE_NORMAL   0x00000080
#define FILE_ATTRIBUTE_READONLY 0x00000001
#define FILE_ATTRIBUTE_HIDDEN   0x00000002

// Window messages
#define WM_CLOSE            0x0010
#define WM_INITDIALOG       0x0110
#define WM_COMMAND          0x0111

// Registry
#define HKEY_LOCAL_MACHINE  ((void*)(unsigned long*)0x80000002)
#define HKEY_CURRENT_USER   ((void*)(unsigned long*)0x80000001)
#define KEY_READ            0x20019
#define KEY_WRITE           0x20006
#define KEY_ALL_ACCESS      0xF003F
#define REG_SZ              1
#define REG_DWORD           4
#define REG_BINARY          3
#define ERROR_SUCCESS       0L

// COM
#ifndef COINIT_MULTITHREADED
#define COINIT_MULTITHREADED 0x0
#endif

// Thread
#define STILL_ACTIVE        259

// Process
#define INFINITE            0xFFFFFFFF

// File seek
#define FILE_BEGIN           0
#define FILE_CURRENT         1
#define FILE_END             2

// Inline stub functions
static inline int MessageBoxW(void* hwnd, const wchar_t* text, const wchar_t* caption, unsigned int type) {
    (void)hwnd; (void)type;
    if (caption) fwprintf(stderr, L"%ls: %ls\n", caption, text);
    else fwprintf(stderr, L"%ls\n", text);
    return 1; // IDOK
}

static inline int MessageBoxA(void* hwnd, const char* text, const char* caption, unsigned int type) {
    (void)hwnd; (void)type;
    fprintf(stderr, "%s: %s\n", caption ? caption : "Message", text ? text : "");
    return 1; // IDOK
}

#ifdef UNICODE
#define MessageBox MessageBoxW
#else
#define MessageBox MessageBoxA
#endif

// Missing types from CrossPlatform.h
typedef void* HKEY;
typedef void* HMENU;
typedef void* HICON;
typedef void* HBRUSH;
typedef void* HCURSOR;
typedef void* HPEN;
typedef void* HFONT;
typedef void* HBITMAP;

typedef struct tagMSG {
    void*   hwnd;
    unsigned int message;
    unsigned long wParam;
    long lParam;
    unsigned long time;
    struct { long x, y; } pt;
} MSG;

typedef struct tagWNDCLASSA {
    unsigned int style;
    void* lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    const char* lpszMenuName;
    const char* lpszClassName;
} WNDCLASSA;

typedef struct tagRECT {
    LONG left, top, right, bottom;
} RECT;

#endif // !_WIN32

#endif // WINDOWS_STUB_H
