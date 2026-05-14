#pragma once
/**
 * D3DXCompat.h - Unified Cross-Platform DX8 Type Definitions
 * 
 * This header provides type-compatible stubs for DirectX 8 types needed
 * to compile the Generals Zero Hour codebase on non-Windows platforms.
 * 
 * These are NOT functional implementations - they are type definitions
 * that allow compilation. Actual DX8 functionality requires Windows or
 * a compatibility layer like DXVK.
 */

#include "CrossPlatform.h"

// Forward declarations for COM interfaces (opaque pointers)
#ifdef __cplusplus
struct IDirect3D8;
struct IDirect3DDevice8;
struct IDirect3DTexture8;
struct IDirect3DVertexBuffer8;
struct IDirect3DIndexBuffer8;
struct IDirect3DSurface8;
struct IDirect3DVolume8;
struct IDirect3DCubeTexture8;
struct IDirect3DVolumeTexture8;
#else
typedef struct IDirect3D8 IDirect3D8;
typedef struct IDirect3DDevice8 IDirect3DDevice8;
typedef struct IDirect3DTexture8 IDirect3DTexture8;
typedef struct IDirect3DVertexBuffer8 IDirect3DVertexBuffer8;
typedef struct IDirect3DIndexBuffer8 IDirect3DIndexBuffer8;
typedef struct IDirect3DSurface8 IDirect3DSurface8;
typedef struct IDirect3DVolume8 IDirect3DVolume8;
typedef struct IDirect3DCubeTexture8 IDirect3DCubeTexture8;
typedef struct IDirect3DVolumeTexture8 IDirect3DVolumeTexture8;
#endif

// COM interface pointer typedefs
typedef IDirect3D8* LPDIRECT3D8;
typedef IDirect3DDevice8* LPDIRECT3DDEVICE8;
typedef IDirect3DTexture8* LPDIRECT3DTEXTURE8;
typedef IDirect3DVertexBuffer8* LPDIRECT3DVERTEXBUFFER8;
typedef IDirect3DIndexBuffer8* LPDIRECT3DINDEXBUFFER8;
typedef IDirect3DSurface8* LPDIRECT3DSURFACE8;
typedef IDirect3DVolume8* LPDIRECT3DVOLUME8;
typedef IDirect3DCubeTexture8* LPDIRECT3DCUBETEXTURE8;
typedef IDirect3DVolumeTexture8* LPDIRECT3DVOLUMETEXTURE8;

// D3D Vector types - layout compatible with original D3DXVECTOR3
typedef struct D3DXVECTOR3 {
    float x, y, z;
    
#ifdef __cplusplus
    D3DXVECTOR3() : x(0), y(0), z(0) {}
    D3DXVECTOR3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    
    // Basic operators
    D3DXVECTOR3& operator+=(const D3DXVECTOR3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    D3DXVECTOR3& operator-=(const D3DXVECTOR3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
    D3DXVECTOR3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    D3DXVECTOR3& operator/=(float s) { x /= s; y /= s; z /= s; return *this; }
    
    D3DXVECTOR3 operator+(const D3DXVECTOR3& v) const { return D3DXVECTOR3(x + v.x, y + v.y, z + v.z); }
    D3DXVECTOR3 operator-(const D3DXVECTOR3& v) const { return D3DXVECTOR3(x - v.x, y - v.y, z - v.z); }
    D3DXVECTOR3 operator*(float s) const { return D3DXVECTOR3(x * s, y * s, z * s); }
    D3DXVECTOR3 operator/(float s) const { return D3DXVECTOR3(x / s, y / s, z / s); }
    
    bool operator==(const D3DXVECTOR3& v) const { return x == v.x && y == v.y && z == v.z; }
    bool operator!=(const D3DXVECTOR3& v) const { return !(*this == v); }
    
    float* operator[](size_t i) { return &x + i; }
    const float* operator[](size_t i) const { return &x + i; }
#endif
} D3DXVECTOR3, *LPD3DXVECTOR3;

// Ensure size compatibility
#ifdef __cplusplus
static_assert(sizeof(D3DXVECTOR3) == 12, "D3DXVECTOR3 must be 12 bytes");
#endif

// D3D Color type
typedef struct D3DXCOLOR {
    float r, g, b, a;
    
#ifdef __cplusplus
    D3DXCOLOR() : r(0), g(0), b(0), a(1) {}
    D3DXCOLOR(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) {}
    D3DXCOLOR(DWORD color) {
        r = ((color >> 16) & 0xFF) / 255.0f;
        g = ((color >> 8) & 0xFF) / 255.0f;
        b = (color & 0xFF) / 255.0f;
        a = ((color >> 24) & 0xFF) / 255.0f;
    }
#endif
} D3DXCOLOR, *LPD3DXCOLOR;

#ifdef __cplusplus
static_assert(sizeof(D3DXCOLOR) == 16, "D3DXCOLOR must be 16 bytes");
#endif

// D3D Matrix type - row-major 4x4 matrix
typedef struct D3DXMATRIX {
    float m[4][4];
    
#ifdef __cplusplus
    D3DXMATRIX() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                m[i][j] = (i == j) ? 1.0f : 0.0f;
    }
    
    float& operator()(int row, int col) { return m[row][col]; }
    float operator()(int row, int col) const { return m[row][col]; }
    
    float* operator[](int row) { return m[row]; }
    const float* operator[](int row) const { return m[row]; }
    
    D3DXMATRIX& operator*=(const D3DXMATRIX& rhs) {
        D3DXMATRIX result;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                result.m[i][j] = 0;
                for (int k = 0; k < 4; k++)
                    result.m[i][j] += m[i][k] * rhs.m[k][j];
            }
        *this = result;
        return *this;
    }
#endif
} D3DXMATRIX, *LPD3DXMATRIX;

#ifdef __cplusplus
static_assert(sizeof(D3DXMATRIX) == 64, "D3DXMATRIX must be 64 bytes");
#endif

// D3D Viewport structure
typedef struct D3DVIEWPORT8 {
    DWORD X;
    DWORD Y;
    DWORD Width;
    DWORD Height;
    float MinZ;
    float MaxZ;
} D3DVIEWPORT8, *LPD3DVIEWPORT8;

// D3D Light structures
typedef struct D3DLIGHT8 {
    DWORD Type;
    D3DXVECTOR3 Diffuse;
    D3DXVECTOR3 Specular;
    D3DXVECTOR3 Ambient;
    D3DXVECTOR3 Position;
    D3DXVECTOR3 Direction;
    float Range;
    float Falloff;
    float Attenuation0;
    float Attenuation1;
    float Attenuation2;
    float Theta;
    float Phi;
} D3DLIGHT8, *LPD3DLIGHT8;

// D3D Material structure
typedef struct D3DMATERIAL8 {
    D3DXCOLOR Diffuse;
    D3DXCOLOR Ambient;
    D3DXCOLOR Specular;
    D3DXCOLOR Emissive;
    float Power;
} D3DMATERIAL8, *LPD3DMATERIAL8;

// Common HRESULT values
#ifndef D3D_OK
    #define D3D_OK 0
#endif
#ifndef D3DERR_INVALIDCALL
    #define D3DERR_INVALIDCALL 0x8876086A
#endif
#ifndef D3DERR_DEVICELOST
    #define D3DERR_DEVICELOST 0x88760868
#endif
#ifndef D3DERR_DEVICENOTRESET
    #define D3DERR_DEVICENOTRESET 0x88760869
#endif

// D3D Format enum (subset used by the game)
#ifndef _D3DFORMAT_DEFINED
#define _D3DFORMAT_DEFINED
typedef enum D3DFORMAT {
    D3DFMT_UNKNOWN          =  0,
    D3DFMT_R8G8B8           =  20,
    D3DFMT_A8R8G8B8         =  21,
    D3DFMT_X8R8G8B8         =  22,
    D3DFMT_R5G6B5           =  23,
    D3DFMT_X1R5G5B5         =  24,
    D3DFMT_A1R5G5B5         =  25,
    D3DFMT_A4R4G4B4         =  26,
    D3DFMT_R3G3B2           =  27,
    D3DFMT_A8               =  28,
    D3DFMT_A8R3G3B2         =  29,
    D3DFMT_X4R4G4B4         =  30,
    D3DFMT_A2B10G10R10      =  31,
    D3DFMT_A8B8G8R8         =  32,
    D3DFMT_X8B8G8R8         =  33,
    D3DFMT_G16R16           =  34,
    D3DFMT_A2R10G10B10      =  35,
    D3DFMT_A16B16G16R16     =  36,
    D3DFMT_D16_LOCKABLE     =  70,
    D3DFMT_D32              =  71,
    D3DFMT_D15S1            =  73,
    D3DFMT_D24S8            =  75,
    D3DFMT_D24X8            =  77,
    D3DFMT_D24X4S4          =  79,
    D3DFMT_D16              =  80,
    D3DFMT_D32F_LOCKABLE    =  82,
    D3DFMT_D24FS8           =  83,
    D3DFMT_L8               =  50,
    D3DFMT_A8L8             =  51,
    D3DFMT_A4L4             =  52,
    D3DFMT_V8U8             =  60,
    D3DFMT_L6V5U5           =  61,
    D3DFMT_X8L8V8U8         =  62,
    D3DFMT_Q8W8V8U8         =  63,
    D3DFMT_V16U16           =  64,
    D3DFMT_W11V11U10        =  65,
    D3DFMT_UYVY             =  89,
    D3DFMT_YUY2             =  82,
    D3DFMT_DXT1             =  83,
    D3DFMT_DXT2             =  84,
    D3DFMT_DXT3             =  85,
    D3DFMT_DXT4             =  86,
    D3DFMT_DXT5             =  87,
    D3DFMT_FORCE_DWORD      = 0x7fffffff
} D3DFORMAT;
#endif

// D3D Resource types
#ifndef _D3DRESOURCETYPE_DEFINED
#define _D3DRESOURCETYPE_DEFINED
typedef enum D3DRESOURCETYPE {
    D3DRTYPE_SURFACE        =  1,
    D3DRTYPE_VOLUME         =  2,
    D3DRTYPE_TEXTURE        =  3,
    D3DRTYPE_VOLUMETEXTURE  =  4,
    D3DRTYPE_CUBETEXTURE    =  5,
    D3DRTYPE_VERTEXBUFFER   =  6,
    D3DRTYPE_INDEXBUFFER    =  7,
    D3DRTYPE_FORCE_DWORD    = 0x7fffffff
} D3DRESOURCETYPE;
#endif

// D3D Pool types
#ifndef _D3DPOOL_DEFINED
#define _D3DPOOL_DEFINED
typedef enum D3DPOOL {
    D3DPOOL_DEFAULT         =  0,
    D3DPOOL_MANAGED         =  1,
    D3DPOOL_SYSTEMMEM       =  2,
    D3DPOOL_SCRATCH         =  3,
    D3DPOOL_FORCE_DWORD     = 0x7fffffff
} D3DPOOL;
#endif

// Helper macros for D3DCOLOR
#ifndef D3DCOLOR_ARGB
    #define D3DCOLOR_ARGB(a,r,g,b) \
        ((DWORD)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
#endif
#ifndef D3DCOLOR_COLORVALUE
    #define D3DCOLOR_COLORVALUE(r,g,b,a) \
        D3DCOLOR_ARGB((DWORD)((a)*255),(DWORD)((r)*255),(DWORD)((g)*255),(DWORD)((b)*255))
#endif

// Inline helper functions (stubs - actual implementation requires DX8)
#ifdef __cplusplus
inline D3DXVECTOR3 D3DXVECTOR3Normalize(const D3DXVECTOR3* pOut, const D3DXVECTOR3* pV) {
    float len = sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
    if (len > 0.0f) {
        float invLen = 1.0f / len;
        pOut->x = pV->x * invLen;
        pOut->y = pV->y * invLen;
        pOut->z = pV->z * invLen;
    }
    return *pOut;
}

inline float D3DXVec3Length(const D3DXVECTOR3* pV) {
    return sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
}

inline float D3DXVec3Dot(const D3DXVECTOR3* pV1, const D3DXVECTOR3* pV2) {
    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
}

inline D3DXVECTOR3 D3DXVec3Cross(D3DXVECTOR3* pOut, const D3DXVECTOR3* pV1, const D3DXVECTOR3* pV2) {
    pOut->x = pV1->y * pV2->z - pV1->z * pV2->y;
    pOut->y = pV1->z * pV2->x - pV1->x * pV2->z;
    pOut->z = pV1->x * pV2->y - pV1->y * pV2->x;
    return *pOut;
}

inline D3DXMATRIX D3DXMatrixIdentity() {
    D3DXMATRIX m;
    return m;
}
#endif

#endif // D3DXCOMPAT_H
