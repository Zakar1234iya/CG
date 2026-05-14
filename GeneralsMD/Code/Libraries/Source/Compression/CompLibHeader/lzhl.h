#ifndef _LZHL_H
#define _LZHL_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

struct lzh_stream {};

inline int lzh_decompress(lzh_stream *, const uint8 *, uint32, uint8 *, uint32 *) { return -1; }
inline int lzh_compress(lzh_stream *, const uint8 *, uint32, uint8 *, uint32 *) { return -1; }

#endif
