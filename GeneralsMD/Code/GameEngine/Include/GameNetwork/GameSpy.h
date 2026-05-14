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
// GameSpy SDK Stub Header
// GameSpy service was shut down in 2014 - this provides stub implementations
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef __GAMESPY_H__
#define __GAMESPY_H__

#include "Common/AsciiString.h"
#include "Common/UnicodeString.h"
#include "GameClient/GameWindow.h"
#include "GameNetwork/NetworkDefs.h"

// Forward declarations - stub types
typedef void* PEER;
typedef int GServer;
typedef int RoomType;
typedef int Bool;

enum {
    FALSE = 0,
    TRUE = 1
};

enum RoomTypeEnum {
    GroupRoom = 0,
    StagingRoom = 1
};

// Stub GameSpyGroupRoom class
class GameSpyGroupRoom
{
public:
    GameSpyGroupRoom() { m_name = AsciiString::TheEmptyString; m_groupID = m_numWaiting = m_maxWaiting = m_numGames = m_numPlaying = 0; }
    AsciiString m_name;
    Int m_groupID;
    Int m_numWaiting;
    Int m_maxWaiting;
    Int m_numGames;
    Int m_numPlaying;
};

// Stub colors enum
enum GameSpyColors {
    GSCOLOR_DEFAULT = 0,
    GSCOLOR_SYSTEM = 1,
    GSCOLOR_ADMIN = 2,
    GSCOLOR_PLAYER = 3
};

// Stub callback types
typedef void (*peerEnumPlayersCallback)(PEER peer, const char* nick, int profileId, int flags, void* userData);
typedef void (*peerListingGamesCallback)(PEER peer, int serverKey, const char* gamename, int open, int botCount, int maxPlayers, int avgSkill, int gameVersion, int gameFlags, void* userData);

// Stub GameSpyChatInterface class
class GameSpyChatInterface : public SubsystemInterface
{
public:
    virtual ~GameSpyChatInterface() { };

    virtual void init( void ) = 0;
    virtual void reset( void ) = 0;
    virtual void update( void ) = 0;

    virtual Bool isConnected( void ) = 0;
    virtual void login(AsciiString loginName, AsciiString password = AsciiString::TheEmptyString, AsciiString email = AsciiString::TheEmptyString) = 0;
    virtual void reconnectProfile( void ) = 0;
    virtual void disconnectFromChat( void ) = 0;

    virtual void UTMRoom( RoomType roomType, const char *key, const char *val, Bool authenticate = FALSE ) = 0;
    virtual void UTMPlayer( const char *name, const char *key, const char *val, Bool authenticate = FALSE ) = 0;
    virtual void startGame( void ) = 0;
    virtual void leaveRoom( RoomType roomType ) = 0;
    virtual void setReady( Bool ready ) = 0;
    virtual void enumPlayers( RoomType roomType, peerEnumPlayersCallback callback, void *userData ) = 0;
    virtual void startListingGames( peerListingGamesCallback callback ) = 0;
    virtual void stopListingGames( void ) = 0;

    virtual void joinGroupRoom( Int ID ) = 0;
    virtual void joinStagingRoom( GServer server, AsciiString password ) = 0;
    virtual void createStagingRoom( AsciiString gameName, AsciiString password, Int maxPlayers ) = 0;
    virtual void joinBestGroupRoom( void ) = 0;

    inline PEER getPeer( void ) { return m_peer; }
    
protected:
    PEER m_peer;
};

// External pointer to the GameSpy chat interface
extern GameSpyChatInterface* TheGameSpyChat;

// Stub functions
Bool GameSpySendChat(UnicodeString message, Bool isAction, GameWindow *playerListbox = NULL);
void GameSpyAddText( UnicodeString message, GameSpyColors color = GSCOLOR_DEFAULT );

#endif // __GAMESPY_H__
