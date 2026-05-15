#pragma once
// GameSpy GP SDK stub — service shut down in 2014.
#include <windows.h>

#define GP_SUCCESS 0
#define GP_ERROR -1

typedef int GPConnection;
typedef int GPResult;
typedef int GPCallback;

__inline GPResult gpInitialize(GPConnection* c, void*) { *c = 0; return GP_SUCCESS; }
__inline GPResult gpDestroy(GPConnection c) { return GP_SUCCESS; }
__inline GPResult gpThink(GPConnection c) { return GP_SUCCESS; }
__inline GPResult gpSetCallback(GPConnection c, GPCallback, void*) { return GP_SUCCESS; }
