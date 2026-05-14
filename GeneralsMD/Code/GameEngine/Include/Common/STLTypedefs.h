#pragma once
#ifndef __STLTYPEDEFS_H__
#define __STLTYPEDEFS_H__

#include "Common/AsciiString.h"
#include "Common/UnicodeString.h"
#include "Common/GameCommon.h"
#include "Common/GameMemory.h"

class Object;
enum NameKeyType : unsigned int;
enum ObjectID : int;
enum DrawableID : int;

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

typedef std::list<AsciiString> AsciiStringList;
typedef std::list<AsciiString>::iterator AsciiStringListIterator;
typedef std::list<AsciiString>::const_iterator AsciiStringListConstIterator;

typedef std::list<Object*> ObjectPointerList;
typedef std::list<Object*>::iterator ObjectPointerListIterator;

typedef std::vector<ObjectID> ObjectIDVector;
typedef std::vector<ObjectID>::iterator ObjectIDVectorIterator;

typedef std::vector<Coord3D> VecCoord3D;
typedef VecCoord3D::iterator VecCoord3DIt;

typedef std::pair<ICoord2D, Coord3D> PosRequest;
typedef std::vector<PosRequest> VecPosRequests;
typedef std::vector<PosRequest>::iterator VecPosRequestsIt;

typedef std::pair<AsciiString, Object*> NamedRequest;
typedef std::vector<NamedRequest> VecNamedRequests;
typedef std::vector<NamedRequest>::iterator VecNamedRequestsIt;

typedef std::vector<Bool> BoolVector;
typedef std::vector<Bool>::iterator BoolVectorIterator;

typedef std::map<NameKeyType, Real, std::less<NameKeyType>> ProductionChangeMap;
typedef std::map<NameKeyType, VeterancyLevel, std::less<NameKeyType>> ProductionVeterancyMap;

namespace rts {

template<typename T> struct hash {
    size_t operator()(const T& t) const {
        return std::hash<T>{}(t);
    }
};

template<typename T> struct equal_to {
    Bool operator()(const T& t1, const T& t2) const {
        return (t1 == t2);
    }
};

template<typename T> struct less_than_nocase {
    bool operator()(const T& t1, const T& t2) const {
        return (t1 < t2);
    }
};

template<> struct hash<NameKeyType> {
    size_t operator()(NameKeyType nkt) const {
        return std::hash<UnsignedInt>{}((UnsignedInt)nkt);
    }
};

template<> struct hash<DrawableID> {
    size_t operator()(DrawableID nkt) const {
        return std::hash<UnsignedInt>{}((UnsignedInt)nkt);
    }
};

template<> struct hash<ObjectID> {
    size_t operator()(ObjectID nkt) const {
        return std::hash<UnsignedInt>{}((UnsignedInt)nkt);
    }
};

template<> struct equal_to<const char*> {
    Bool operator()(const char* s1, const char* s2) const {
        return strcmp(s1, s2) == 0;
    }
};

template<> struct hash<AsciiString> {
    size_t operator()(AsciiString ast) const {
        return std::hash<const char*>{}((const char*)ast.str());
    }
};

template<> struct equal_to<AsciiString> {
    Bool operator()(const AsciiString& t1, const AsciiString& t2) const {
        return (t1 == t2);
    }
};

template<> struct less_than_nocase<AsciiString> {
    bool operator()(const AsciiString& t1, const AsciiString& t2) const {
        return (t1.compareNoCase(t2) < 0);
    }
};

template<> struct less_than_nocase<UnicodeString> {
    bool operator()(const UnicodeString& t1, const UnicodeString& t2) const {
        return (t1.compareNoCase(t2) < 0);
    }
};

} // namespace rts

#endif
