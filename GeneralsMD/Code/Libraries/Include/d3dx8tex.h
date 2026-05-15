#pragma once
#ifndef __D3DX8TEX_H__
#define __D3DX8TEX_H__

/*******************************************************************************
 * d3dx8tex.h  —  Compile-time stub for the D3DX8 texture functions
 *
 * PURPOSE
 *   Allows the Generals Zero Hour codebase to compile on platforms where
 *   d3dx8.dll / d3dx8.lib are not available. The real implementations are
 *   resolved at runtime from d3dx8.dll (or a wrapper like DXVK).
 *
 * USAGE
 *   All function stubs return E_NOTIMPL. The calling code wraps these with
 *   DX8_ErrorCode() which logs the failure but does not crash.
 *
 * CALLERS
 *   - TerrainTex.cpp   : D3DXFilterTexture()
 *   - W3DTreeBuffer.cpp: D3DXFilterTexture()
 *   - surfaceclass.cpp : D3DXLoadSurfaceFromSurface()
 *   - missingtexture.cpp: D3DXLoadSurfaceFromSurface()
 ******************************************************************************/

#include "d3d8.h"

/* ─── Filter flags ────────────────────────────────────────────────────────── */
#define D3DX_FILTER_NONE       0x00000001
#define D3DX_FILTER_POINT      0x00000002
#define D3DX_FILTER_LINEAR     0x00000003
#define D3DX_FILTER_TRIANGLE   0x00000004
#define D3DX_FILTER_BOX        0x00000005

#define D3DX_FILTER_MIRROR_U   0x00010000
#define D3DX_FILTER_MIRROR_V   0x00020000
#define D3DX_FILTER_MIRROR_W   0x00040000
#define D3DX_FILTER_MIRROR     (D3DX_FILTER_MIRROR_U | \
                                D3DX_FILTER_MIRROR_V | \
                                D3DX_FILTER_MIRROR_W)

#define D3DX_DEFAULT           0xFFFFFFFF

/* ─── Function stubs ──────────────────────────────────────────────────────── */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * D3DXFilterTexture  —  Generates mipmaps for a texture.
 *
 * Stub: returns E_NOTIMPL. On Windows, link against d3dx8.lib or load
 * d3dx8.dll at runtime for the real implementation.
 */
HRESULT WINAPI D3DXFilterTexture(
    IDirect3DTexture8*  pTexture,
    CONST PALETTEENTRY* pPalette,
    UINT                SrcLevel,
    DWORD               MipFilter
);

/**
 * D3DXLoadSurfaceFromSurface  —  Copies / converts between surfaces.
 *
 * Stub: returns E_NOTIMPL. On Windows, link against d3dx8.lib or load
 * d3dx8.dll at runtime for the real implementation.
 */
HRESULT WINAPI D3DXLoadSurfaceFromSurface(
    IDirect3DSurface8*  pDestSurface,
    CONST PALETTEENTRY* pDestPalette,
    CONST RECT*         pDestRect,
    IDirect3DSurface8*  pSrcSurface,
    CONST PALETTEENTRY* pSrcPalette,
    CONST RECT*         pSrcRect,
    DWORD               Filter,
    D3DCOLOR            ColorKey
);

#ifdef __cplusplus
}
#endif

#endif /* __D3DX8TEX_H__ */
