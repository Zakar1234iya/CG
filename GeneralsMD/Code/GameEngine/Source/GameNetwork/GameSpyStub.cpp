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
// GameSpy SDK Stub Implementation
// GameSpy service was shut down in 2014 - this provides stub implementations
// All functions are no-ops or return failure/disconnected state
////////////////////////////////////////////////////////////////////////////////

#include "PreRTS.h"
#include "GameNetwork/GameSpy.h"
#include "GameNetwork/GameSpyChat.h"
#include "GameNetwork/GameSpyGP.h"
#include "GameNetwork/GameSpyGameInfo.h"
#include "GameNetwork/GameSpyOverlay.h"
#include "GameNetwork/GameSpyThread.h"
#include "GameNetwork/GameSpyPersistentStorage.h"

// Global stub instance pointer - always null/disconnected
GameSpyChatInterface* TheGameSpyChat = nullptr;

// Stub implementation class
class GameSpyChatStub : public GameSpyChatInterface
{
public:
    GameSpyChatStub() { m_peer = nullptr; }
    
    virtual void init(void) override {
        // No-op - GameSpy is disabled
    }
    
    virtual void reset(void) override {
        // No-op
    }
    
    virtual void update(void) override {
        // No-op
    }
    
    virtual Bool isConnected(void) override {
        return FALSE; // Always disconnected
    }
    
    virtual void login(AsciiString loginName, AsciiString password, AsciiString email) override {
        // No-op - cannot login to defunct service
        DEBUG_LOG(("GameSpy login attempted but service is disabled\n"));
    }
    
    virtual void reconnectProfile(void) override {
        // No-op
    }
    
    virtual void disconnectFromChat(void) override {
        // No-op - already disconnected
    }
    
    virtual void UTMRoom(RoomType roomType, const char* key, const char* val, Bool authenticate) override {
        // No-op
    }
    
    virtual void UTMPlayer(const char* name, const char* key, const char* val, Bool authenticate) override {
        // No-op
    }
    
    virtual void startGame(void) override {
        // No-op
    }
    
    virtual void leaveRoom(RoomType roomType) override {
        // No-op
    }
    
    virtual void setReady(Bool ready) override {
        // No-op
    }
    
    virtual void enumPlayers(RoomType roomType, peerEnumPlayersCallback callback, void* userData) override {
        // No-op - no players
    }
    
    virtual void startListingGames(peerListingGamesCallback callback) override {
        // No-op - no games
    }
    
    virtual void stopListingGames(void) override {
        // No-op
    }
    
    virtual void joinGroupRoom(Int ID) override {
        // No-op
    }
    
    virtual void joinStagingRoom(GServer server, AsciiString password) override {
        // No-op
    }
    
    virtual void createStagingRoom(AsciiString gameName, AsciiString password, Int maxPlayers) override {
        // No-op
    }
    
    virtual void joinBestGroupRoom(void) override {
        // No-op
    }
};

// Stub function implementations
Bool GameSpySendChat(UnicodeString message, Bool isAction, GameWindow* playerListbox)
{
    // Message sending is disabled - GameSpy is offline
    DEBUG_LOG(("GameSpy chat disabled - message not sent: %s\n", message.str()));
    return FALSE;
}

void GameSpyAddText(UnicodeString message, GameSpyColors color)
{
    // Text display stub - could log to console in debug builds
    #ifdef _DEBUG
    DEBUG_LOG(("GameSpy Chat [%d]: %s\n", color, message.str()));
    #endif
}

// Initialize the stub on startup
static class GameSpyInit
{
public:
    GameSpyInit() {
        TheGameSpyChat = new GameSpyChatStub();
    }
    ~GameSpyInit() {
        delete TheGameSpyChat;
        TheGameSpyChat = nullptr;
    }
} s_gameSpyInit;

// Additional stub implementations for other GameSpy files

// GameSpyGP.cpp stubs
GPConnection TheGPConnectionObj;
GPConnection* TheGPConnection = &TheGPConnectionObj;
GPProfile GameSpyLocalProfile = 0;
char GameSpyProfilePassword[64];

// GameSpyOverlay.cpp stubs
void GameSpyOverlayInit(void) {}
void GameSpyOverlayReset(void) {}
void GameSpyOverlayUpdate(void) {}
Bool GameSpyOverlayIsVisible(void) { return FALSE; }
void GameSpyOverlayShow(void) {}
void GameSpyOverlayHide(void) {}

// GameSpyGameInfo.cpp stubs
void GameSpyGameInfoInit(void) {}
void GameSpyGameInfoReset(void) {}
void GameSpyGameInfoUpdate(void) {}

// GameSpyThread.cpp stubs  
void GameSpyThreadInit(void) {}
void GameSpyThreadReset(void) {}
void GameSpyThreadUpdate(void) {}
void GameSpyThreadShutdown(void) {}

// GameSpyPersistentStorage.cpp stubs
void GameSpyPersistentStorageInit(void) {}
void GameSpyPersistentStorageReset(void) {}
void GameSpyPersistentStorageUpdate(void) {}
Bool GameSpySaveProfileData(const char* profileName, const char* data) { return FALSE; }
Bool GameSpyLoadProfileData(const char* profileName, char* buffer, int bufferSize) { return FALSE; }
