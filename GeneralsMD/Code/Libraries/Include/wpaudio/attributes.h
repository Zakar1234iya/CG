#pragma once
// Minimal wpaudio stub for GameSpeech compilation
// This is NOT a real Windows Platform Audio SDK header

#ifdef _WIN32
#include <windows.h>
#else
#include "CrossPlatform.h"
#endif

typedef struct _SPAUDIO_STATE {
    DWORD size;
} SPAUDIO_STATE;

#define SPAUDIO_DEFAULT_STATE 0
