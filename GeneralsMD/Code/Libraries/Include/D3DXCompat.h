#pragma once

#ifndef D3DXCOMPAT_H
#define D3DXCOMPAT_H

/**
 * D3DXCompat.h - Unified Cross-Platform DX8 Type Definitions
 * 
 * This header provides type-compatible stubs for DirectX 8 types needed
 * to compile the Generals Zero Hour codebase on non-Windows platforms.
 * 
 * These are NOT functional implementations - they are type definitions
 * that allow compilation. Actual DX8 functionality requires Windows or
 * a compatibility layer like DXVK.
 *
 * NOTE: Core D3D types (D3DFORMAT, D3DLIGHT8, D3DMATERIAL8, etc.) are now
 * defined in d3d8.h. D3DXCompat.h only provides D3DX math/compat types.
 */

#include "CrossPlatform.h"

// Ensure DWORD, FLOAT and other Windows types are available
#ifdef _WIN32
#include <windows.h>
#include <DirectXMath.h>
#endif

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
#ifndef D3DXVECTOR3_DEFINED
#define D3DXVECTOR3_DEFINED
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
#endif // D3DXVECTOR3_DEFINED

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

// Helper macros for D3DCOLOR
#ifndef D3DCOLOR_ARGB
    #define D3DCOLOR_ARGB(a,r,g,b) \
        ((DWORD)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
#endif
#ifndef D3DCOLOR_COLORVALUE
    #define D3DCOLOR_COLORVALUE(r,g,b,a) \
        D3DCOLOR_ARGB((DWORD)((a)*255),(DWORD)((r)*255),(DWORD)((g)*255),(DWORD)((b)*255))
#endif

// ─── D3DXVECTOR4 type ──────────────────────────────────────────────────────────
#ifndef D3DXVECTOR4_DEFINED
#define D3DXVECTOR4_DEFINED
typedef struct D3DXVECTOR4 {
    float x, y, z, w;

#ifdef __cplusplus
    D3DXVECTOR4() : x(0), y(0), z(0), w(0) {}
    D3DXVECTOR4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
#endif
} D3DXVECTOR4, *LPD3DXVECTOR4;
#endif // D3DXVECTOR4_DEFINED

#ifdef __cplusplus
static_assert(sizeof(D3DXVECTOR4) == 16, "D3DXVECTOR4 must be 16 bytes");
#endif

// ─── Constants ─────────────────────────────────────────────────────────────────
#ifndef D3DX_PI
#define D3DX_PI 3.14159265358979323846f
#endif
#ifndef D3DX_1BYPI
#define D3DX_1BYPI (1.0f / D3DX_PI)
#endif

// ─── D3DXToRadian / D3DXToDegree ──────────────────────────────────────────────
#ifndef D3DXToRadian
#define D3DXToRadian(degree) ((degree) * (D3DX_PI / 180.0f))
#endif
#ifndef D3DXToDegree
#define D3DXToDegree(radian) ((radian) * (180.0f / D3DX_PI))
#endif

// Inline helper functions - cross-platform implementations
#ifdef __cplusplus

// ─── Vector functions ──────────────────────────────────────────────────────────
inline D3DXVECTOR3* D3DXVec3Normalize(D3DXVECTOR3* pOut, const D3DXVECTOR3* pV) {
    float len = sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
    if (len > 0.0f) {
        float invLen = 1.0f / len;
        pOut->x = pV->x * invLen;
        pOut->y = pV->y * invLen;
        pOut->z = pV->z * invLen;
    } else {
        pOut->x = pOut->y = pOut->z = 0.0f;
    }
    return pOut;
}

inline float D3DXVec3Length(const D3DXVECTOR3* pV) {
    return sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
}

inline float D3DXVec3LengthSq(const D3DXVECTOR3* pV) {
    return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z;
}

inline float D3DXVec3Dot(const D3DXVECTOR3* pV1, const D3DXVECTOR3* pV2) {
    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
}

inline D3DXVECTOR3* D3DXVec3Cross(D3DXVECTOR3* pOut, const D3DXVECTOR3* pV1, const D3DXVECTOR3* pV2) {
    D3DXVECTOR3 v;
    v.x = pV1->y * pV2->z - pV1->z * pV2->y;
    v.y = pV1->z * pV2->x - pV1->x * pV2->z;
    v.z = pV1->x * pV2->y - pV1->y * pV2->x;
    *pOut = v;
    return pOut;
}

inline D3DXVECTOR4* D3DXVec3Transform(D3DXVECTOR4* pOut, const D3DXVECTOR3* pV, const D3DXMATRIX* pM) {
    D3DXVECTOR4 v;
    v.x = pV->x * pM->m[0][0] + pV->y * pM->m[1][0] + pV->z * pM->m[2][0] + pM->m[3][0];
    v.y = pV->x * pM->m[0][1] + pV->y * pM->m[1][1] + pV->z * pM->m[2][1] + pM->m[3][1];
    v.z = pV->x * pM->m[0][2] + pV->y * pM->m[1][2] + pV->z * pM->m[2][2] + pM->m[3][2];
    v.w = pV->x * pM->m[0][3] + pV->y * pM->m[1][3] + pV->z * pM->m[2][3] + pM->m[3][3];
    *pOut = v;
    return pOut;
}

inline D3DXVECTOR4* D3DXVec4Transform(D3DXVECTOR4* pOut, const D3DXVECTOR4* pV, const D3DXMATRIX* pM) {
    D3DXVECTOR4 v;
    v.x = pV->x * pM->m[0][0] + pV->y * pM->m[1][0] + pV->z * pM->m[2][0] + pV->w * pM->m[3][0];
    v.y = pV->x * pM->m[0][1] + pV->y * pM->m[1][1] + pV->z * pM->m[2][1] + pV->w * pM->m[3][1];
    v.z = pV->x * pM->m[0][2] + pV->y * pM->m[1][2] + pV->z * pM->m[2][2] + pV->w * pM->m[3][2];
    v.w = pV->x * pM->m[0][3] + pV->y * pM->m[1][3] + pV->z * pM->m[2][3] + pV->w * pM->m[3][3];
    *pOut = v;
    return pOut;
}

inline float D3DXVec4Dot(const D3DXVECTOR4* pV1, const D3DXVECTOR4* pV2) {
    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z + pV1->w * pV2->w;
}

// ─── Matrix functions ──────────────────────────────────────────────────────────
inline D3DXMATRIX* D3DXMatrixIdentity(D3DXMATRIX* pOut) {
    if (pOut) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                pOut->m[i][j] = (i == j) ? 1.0f : 0.0f;
    }
    return pOut;
}

inline D3DXMATRIX* D3DXMatrixScaling(D3DXMATRIX* pOut, float sx, float sy, float sz) {
    D3DXMatrixIdentity(pOut);
    pOut->m[0][0] = sx;
    pOut->m[1][1] = sy;
    pOut->m[2][2] = sz;
    return pOut;
}

inline D3DXMATRIX* D3DXMatrixTranslation(D3DXMATRIX* pOut, float x, float y, float z) {
    D3DXMatrixIdentity(pOut);
    pOut->m[3][0] = x;
    pOut->m[3][1] = y;
    pOut->m[3][2] = z;
    return pOut;
}

inline D3DXMATRIX* D3DXMatrixRotationZ(D3DXMATRIX* pOut, float angle) {
    D3DXMatrixIdentity(pOut);
    float c = cosf(angle);
    float s = sinf(angle);
    pOut->m[0][0] = c;
    pOut->m[0][1] = s;
    pOut->m[1][0] = -s;
    pOut->m[1][1] = c;
    return pOut;
}

inline D3DXMATRIX* D3DXMatrixRotationX(D3DXMATRIX* pOut, float angle) {
    D3DXMatrixIdentity(pOut);
    float c = cosf(angle);
    float s = sinf(angle);
    pOut->m[1][1] = c;
    pOut->m[1][2] = s;
    pOut->m[2][1] = -s;
    pOut->m[2][2] = c;
    return pOut;
}

inline D3DXMATRIX* D3DXMatrixRotationY(D3DXMATRIX* pOut, float angle) {
    D3DXMatrixIdentity(pOut);
    float c = cosf(angle);
    float s = sinf(angle);
    pOut->m[0][0] = c;
    pOut->m[0][2] = -s;
    pOut->m[2][0] = s;
    pOut->m[2][2] = c;
    return pOut;
}

inline D3DXMATRIX* D3DXMatrixMultiply(D3DXMATRIX* pOut, const D3DXMATRIX* pM1, const D3DXMATRIX* pM2) {
    D3DXMATRIX result;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < 4; k++)
                result.m[i][j] += pM1->m[i][k] * pM2->m[k][j];
        }
    *pOut = result;
    return pOut;
}

inline D3DXMATRIX* D3DXMatrixTranspose(D3DXMATRIX* pOut, const D3DXMATRIX* pM) {
    D3DXMATRIX result;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            result.m[i][j] = pM->m[j][i];
    *pOut = result;
    return pOut;
}

// Cross-platform matrix inverse (no DirectXMath dependency)
inline D3DXMATRIX* D3DXMatrixInverse(D3DXMATRIX* pOut, float* pDeterminant, const D3DXMATRIX* pM) {
    // Cofactor expansion method - works on all platforms
    const float* m = &pM->m[0][0];
    float inv[16];

    inv[0]  =  m[5]*m[10]*m[15] - m[5]*m[11]*m[14] - m[9]*m[6]*m[15] + m[9]*m[7]*m[14] + m[13]*m[6]*m[11] - m[13]*m[7]*m[10];
    inv[4]  = -m[4]*m[10]*m[15] + m[4]*m[11]*m[14] + m[8]*m[6]*m[15] - m[8]*m[7]*m[14] - m[12]*m[6]*m[11] + m[12]*m[7]*m[10];
    inv[8]  =  m[4]*m[9]*m[15]  - m[4]*m[11]*m[13] - m[8]*m[5]*m[15] + m[8]*m[7]*m[13] + m[12]*m[5]*m[11] - m[12]*m[7]*m[9];
    inv[12] = -m[4]*m[9]*m[14]  + m[4]*m[10]*m[13] + m[8]*m[5]*m[14] - m[8]*m[6]*m[13] - m[12]*m[5]*m[10] + m[12]*m[6]*m[9];
    inv[1]  = -m[1]*m[10]*m[15] + m[1]*m[11]*m[14] + m[9]*m[2]*m[15] - m[9]*m[3]*m[14] - m[13]*m[2]*m[11] + m[13]*m[3]*m[10];
    inv[5]  =  m[0]*m[10]*m[15] - m[0]*m[11]*m[14] - m[8]*m[2]*m[15] + m[8]*m[3]*m[14] + m[12]*m[2]*m[11] - m[12]*m[3]*m[10];
    inv[9]  = -m[0]*m[9]*m[15]  + m[0]*m[11]*m[13] + m[8]*m[1]*m[15] - m[8]*m[3]*m[13] - m[12]*m[1]*m[11] + m[12]*m[3]*m[9];
    inv[13] =  m[0]*m[9]*m[14]  - m[0]*m[10]*m[13] - m[8]*m[1]*m[14] + m[8]*m[2]*m[13] + m[12]*m[1]*m[10] - m[12]*m[2]*m[9];
    inv[2]  =  m[1]*m[6]*m[15]  - m[1]*m[7]*m[14]  - m[5]*m[2]*m[15] + m[5]*m[3]*m[14] + m[13]*m[2]*m[7]  - m[13]*m[3]*m[6];
    inv[6]  = -m[0]*m[6]*m[15]  + m[0]*m[7]*m[14]  + m[4]*m[2]*m[15] - m[4]*m[3]*m[14] - m[12]*m[2]*m[7]  + m[12]*m[3]*m[6];
    inv[10] =  m[0]*m[5]*m[15]  - m[0]*m[7]*m[13]  - m[4]*m[1]*m[15] + m[4]*m[3]*m[13] + m[12]*m[1]*m[7]  - m[12]*m[3]*m[5];
    inv[14] = -m[0]*m[5]*m[14]  + m[0]*m[6]*m[13]  + m[4]*m[1]*m[14] - m[4]*m[2]*m[13] - m[12]*m[1]*m[6]  + m[12]*m[2]*m[5];
    inv[3]  = -m[1]*m[6]*m[11]  + m[1]*m[7]*m[10]  + m[5]*m[2]*m[11] - m[5]*m[3]*m[10] - m[9]*m[2]*m[7]   + m[9]*m[3]*m[6];
    inv[7]  =  m[0]*m[6]*m[11]  - m[0]*m[7]*m[10]  - m[4]*m[2]*m[11] + m[4]*m[3]*m[10] + m[8]*m[2]*m[7]   - m[8]*m[3]*m[6];
    inv[11] = -m[0]*m[5]*m[11]  + m[0]*m[7]*m[9]   + m[4]*m[1]*m[11] - m[4]*m[3]*m[9]  - m[8]*m[1]*m[7]   + m[8]*m[3]*m[5];
    inv[15] =  m[0]*m[5]*m[10]  - m[0]*m[6]*m[9]   - m[4]*m[1]*m[10] + m[4]*m[2]*m[9]  + m[8]*m[1]*m[6]   - m[8]*m[2]*m[5];

    float det = m[0]*inv[0] + m[1]*inv[4] + m[2]*inv[8] + m[3]*inv[12];
    if (pDeterminant) *pDeterminant = det;

    if (fabsf(det) < 1e-10f) {
        D3DXMatrixIdentity(pOut);
        return nullptr;
    }

    float invDet = 1.0f / det;
    for (int i = 0; i < 16; i++)
        (&pOut->m[0][0])[i] = inv[i] * invDet;

    return pOut;
}

// ─── FVF helper ───────────────────────────────────────────────────────────────
inline unsigned int D3DXGetFVFVertexSize(DWORD FVF) {
    unsigned int size = 0;
    // Position
    switch (FVF & D3DFVF_POSITION_MASK) {
        case D3DFVF_XYZ:    size += 12; break;
        case D3DFVF_XYZRHW: size += 16; break;
        case D3DFVF_XYZB1:  size += 16; break;
        case D3DFVF_XYZB2:  size += 20; break;
        case D3DFVF_XYZB3:  size += 24; break;
        case D3DFVF_XYZB4:  size += 28; break;
        case D3DFVF_XYZB5:  size += 32; break;
    }
    if (FVF & D3DFVF_NORMAL)   size += 12;
    if (FVF & D3DFVF_PSIZE)    size += 4;
    if (FVF & D3DFVF_DIFFUSE)  size += 4;
    if (FVF & D3DFVF_SPECULAR) size += 4;
    // Texture coordinates
    unsigned int numTex = (FVF & D3DFVF_TEXCOUNT_MASK) >> D3DFVF_TEXCOUNT_SHIFT;
    for (unsigned int i = 0; i < numTex; i++) {
        switch ((FVF >> (16 + i * 2)) & 0x3) {
            case D3DFVF_TEXTUREFORMAT1: size += 4;  break; // 1 float
            case D3DFVF_TEXTUREFORMAT2: size += 8;  break; // 2 floats
            case D3DFVF_TEXTUREFORMAT3: size += 12; break; // 3 floats
            case D3DFVF_TEXTUREFORMAT4: size += 16; break; // 4 floats
        }
    }
    return size;
}

#endif // __cplusplus

#endif // D3DXCOMPAT_H
