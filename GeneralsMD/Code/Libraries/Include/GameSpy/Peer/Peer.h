#pragma once
// GameSpy Peer SDK stub — GameSpy service shut down in 2014.
// All functions return error codes. Real implementation required for networking.
#include <windows.h>

#define PEER_SUCCESS 0
#define PEER_ERROR -1

typedef int PEER;
typedef int PEER_CONNECTION;
typedef int PEER_LISTENER;

typedef struct _PEER_TYPE { int unused; } PEER_TYPE;

#define PEER_CONNECT_SUCCESS 0
#define PEER_DISCONNECTED 1
#define PEER_CONNECT_FAILED 2

typedef void (*PEER_CONNECT_CALLBACK)(PEER, PEER_CONNECTION, int, void*);
typedef void (*PEER_DISCONNECT_CALLBACK)(PEER, PEER_CONNECTION, void*);

__inline int peerInitialize(PEER* p, PEER_TYPE*, void*, void*) { *p = 0; return PEER_SUCCESS; }
__inline int peerDestroy(PEER p) { return PEER_SUCCESS; }
__inline int peerStartup(PEER p, int) { return PEER_SUCCESS; }
__inline int peerThink(PEER p) { return PEER_SUCCESS; }
__inline int peerConnect(PEER p, const char*, int, PEER_CONNECTION*) { return PEER_SUCCESS; }
__inline int peerDisconnect(PEER p, PEER_CONNECTION c) { return PEER_SUCCESS; }
__inline int peerSend(PEER p, PEER_CONNECTION c, const char*, int, int) { return PEER_SUCCESS; }
__inline int peerSetConnectCallback(PEER p, PEER_CONNECT_CALLBACK, void*) { return PEER_SUCCESS; }
__inline int peerSetDisconnectCallback(PEER p, PEER_DISCONNECT_CALLBACK, void*) { return PEER_SUCCESS; }
