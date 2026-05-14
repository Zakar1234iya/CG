#pragma once
#include <cstdint>

// 64-bit port: static_assert guards for serialized structs
// These ensure that structure layouts don't change silently on Win64

#pragma pack(push, 1)

struct NetworkPacketHeader {
    uint32_t type;
    uint32_t size;
    uint32_t sequence;
    uint16_t checksum;
    uint16_t flags;
    uint32_t timestamp;
    uint32_t padding;
};
static_assert(sizeof(NetworkPacketHeader) == 24, "NetworkPacketHeader layout must be 24 bytes");

struct Coord3D_Serialized {
    float x, y, z;
};
static_assert(sizeof(Coord3D_Serialized) == 12, "Coord3D_Serialized layout must be 12 bytes");

struct ICoord2D_Serialized {
    int32_t x, y;
};
static_assert(sizeof(ICoord2D_Serialized) == 8, "ICoord2D_Serialized layout must be 8 bytes");

#pragma pack(pop)
