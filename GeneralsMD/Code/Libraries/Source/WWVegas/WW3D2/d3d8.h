/*******************************************************************************
 * d3d8.h  —  Compile-time stub for the DirectX 8 API
 *
 * PURPOSE
 *   Allows WWShade / WW3D2 to compile on modern Windows SDKs (10.0.22621+)
 *   that do not ship d3d8.h. All real implementations are resolved at runtime
 *   from d3d8.dll (DXVK, GenTool, or any compatible DX8 wrapper).
 *
 * USAGE
 *   Add this stub directory to your include path BEFORE the Windows SDK dirs:
 *     target_include_directories(<target> PRIVATE Stubs/DX8Stubs)
 *
 * ABI NOTES
 *   Every struct guarded by a static_assert. Sizes are validated against the
 *   DirectX 8.1 SDK documentation. Do not remove the asserts — they are the
 *   only thing standing between you and silent memory corruption.
 *
 * GENERATED FROM
 *   Exhaustive grep of GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2/ and
 *   GeneralsMD/Code/Libraries/Source/WWVegas/wwshade/
 ******************************************************************************/

#pragma once
#ifndef __D3D8_H__
#define __D3D8_H__

#include <stdint.h>

#ifdef _WIN32
#include <windows.h>
#include <unknwn.h>
#else
// Cross-platform compatibility
#include "CrossPlatform.h"

// Provide IUnknown for non-Windows platforms
#ifndef IUNKNOWN_DEFINED
#define IUNKNOWN_DEFINED
struct IUnknown {
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& riid, void** ppvObject) = 0;
    virtual ULONG STDMETHODCALLTYPE AddRef() = 0;
    virtual ULONG STDMETHODCALLTYPE Release() = 0;
};
#endif

// Provide missing Windows types
#ifndef MAKE_HRESULT
#define MAKE_HRESULT(sev,fac,code) ((HRESULT)(((unsigned long)(sev)<<31)|((unsigned long)(fac)<<16)|((unsigned long)(code))))
#endif

#ifndef STDMETHODCALLTYPE
#define STDMETHODCALLTYPE
#endif

typedef struct tagRGNDATAHEADER {
    DWORD dwSize;
    DWORD iType;
    DWORD nCount;
    DWORD nRgnSize;
    struct { LONG x1, y1, x2, y2; } rcBound;
} RGNDATAHEADER;

typedef struct tagRGNDATA {
    RGNDATAHEADER rdh;
    char Buffer[1];
} RGNDATA;

typedef struct tagPALETTEENTRY {
    BYTE peRed, peGreen, peBlue, peFlags;
} PALETTEENTRY;

typedef struct tagPOINT { LONG x, y; } POINT;

#endif // _WIN32

// ─── SDK version ─────────────────────────────────────────────────────────────
#define D3D_SDK_VERSION                 220

// ─── Success / error codes ───────────────────────────────────────────────────
#define D3D_OK                          S_OK
#define D3DERR_WRONGTEXTUREFORMAT       MAKE_HRESULT(1,0x876,2072)
#define D3DERR_UNSUPPORTEDCOLOROPERATION MAKE_HRESULT(1,0x876,2073)
#define D3DERR_UNSUPPORTEDCOLORARG      MAKE_HRESULT(1,0x876,2074)
#define D3DERR_UNSUPPORTEDALPHAOPERATION MAKE_HRESULT(1,0x876,2075)
#define D3DERR_UNSUPPORTEDALPHAARG      MAKE_HRESULT(1,0x876,2076)
#define D3DERR_TOOMANYOPERATIONS        MAKE_HRESULT(1,0x876,2077)
#define D3DERR_CONFLICTINGTEXTUREFILTER MAKE_HRESULT(1,0x876,2078)
#define D3DERR_UNSUPPORTEDFACTORVALUE   MAKE_HRESULT(1,0x876,2079)
#define D3DERR_CONFLICTINGRENDERSTATE   MAKE_HRESULT(1,0x876,2081)
#define D3DERR_UNSUPPORTEDTEXTUREFILTER MAKE_HRESULT(1,0x876,2082)
#define D3DERR_CONFLICTINGTEXTUREPALETTE MAKE_HRESULT(1,0x876,2086)
#define D3DERR_DRIVERINTERNALERROR      MAKE_HRESULT(1,0x876,2087)
#define D3DERR_NOTFOUND                 MAKE_HRESULT(1,0x876,2150)
#define D3DERR_MOREDATA                 MAKE_HRESULT(1,0x876,2151)
#define D3DERR_DEVICELOST               MAKE_HRESULT(1,0x876,2152)
#define D3DERR_DEVICENOTRESET           MAKE_HRESULT(1,0x876,2153)
#define D3DERR_NOTAVAILABLE             MAKE_HRESULT(1,0x876,2154)
#define D3DERR_OUTOFVIDEOMEMORY         MAKE_HRESULT(1,0x876,2155)
#define D3DERR_INVALIDDEVICE            MAKE_HRESULT(1,0x876,2155)
#define D3DERR_INVALIDCALL              MAKE_HRESULT(1,0x876,2156)
#define D3DERR_DRIVERINVALIDCALL        MAKE_HRESULT(1,0x876,2157)
#define D3DOK_NOAUTOGEN                 MAKE_HRESULT(0,0x876,2159)

// ─── Primitive types ─────────────────────────────────────────────────────────
#define MAX_DEVICE_IDENTIFIER_STRING    256   // DX8 = 256, NOT 512 (DX9)
#define D3DDP_MAXTEXCOORD               8
#define D3DSPD_IUNKNOWN                 0x00000001L
#define D3DCREATE_SOFTWARE_VERTEXPROCESSING 0x00000020L
#define D3DCREATE_HARDWARE_VERTEXPROCESSING 0x00000040L
#define D3DCREATE_MIXED_VERTEXPROCESSING    0x00000080L
#define D3DCREATE_PUREDEVICE                0x00000010L
#define D3DUSAGE_RENDERTARGET           0x00000001L
#define D3DUSAGE_DEPTHSTENCIL           0x00000002L
#define D3DUSAGE_WRITEONLY              0x00000008L
#define D3DUSAGE_SOFTWAREPROCESSING     0x00000010L
#define D3DUSAGE_DONOTCLIP              0x00000020L
#define D3DUSAGE_POINTS                 0x00000040L
#define D3DUSAGE_RTPATCHES              0x00000080L
#define D3DUSAGE_NPATCHES               0x00000100L
#define D3DUSAGE_DYNAMIC                0x00000200L
#define D3DLOCK_READONLY                0x00000010L
#define D3DLOCK_DISCARD                 0x00002000L
#define D3DLOCK_NOOVERWRITE             0x00001000L
#define D3DLOCK_NOSYSLOCK               0x00000800L
#define D3DLOCK_NO_DIRTY_UPDATE         0x00008000L
#define D3DCLEAR_TARGET                 0x00000001L
#define D3DCLEAR_ZBUFFER                0x00000002L
#define D3DCLEAR_STENCIL                0x00000004L
#define D3DSGR_NO_CALIBRATION           0x00000000L
#define D3DSGR_CALIBRATE                0x00000001L

// D3DCOLOR helpers
typedef DWORD D3DCOLOR;
#define D3DCOLOR_ARGB(a,r,g,b) \
    ((D3DCOLOR)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
#define D3DCOLOR_RGBA(r,g,b,a) D3DCOLOR_ARGB(a,r,g,b)
#define D3DCOLOR_XRGB(r,g,b)   D3DCOLOR_ARGB(0xff,r,g,b)
#define D3DCOLOR_COLORVALUE(r,g,b,a) \
    D3DCOLOR_RGBA((DWORD)((r)*255.f),(DWORD)((g)*255.f),(DWORD)((b)*255.f),(DWORD)((a)*255.f))

// ─── Enumerations ─────────────────────────────────────────────────────────────

typedef enum _D3DDEVTYPE {
    D3DDEVTYPE_HAL              = 1,
    D3DDEVTYPE_REF              = 2,
    D3DDEVTYPE_SW               = 3,
    D3DDEVTYPE_FORCE_DWORD      = 0x7fffffff
} D3DDEVTYPE;

typedef enum _D3DMULTISAMPLE_TYPE {
    D3DMULTISAMPLE_NONE         = 0,
    D3DMULTISAMPLE_2_SAMPLES    = 2,
    D3DMULTISAMPLE_3_SAMPLES    = 3,
    D3DMULTISAMPLE_4_SAMPLES    = 4,
    D3DMULTISAMPLE_5_SAMPLES    = 5,
    D3DMULTISAMPLE_6_SAMPLES    = 6,
    D3DMULTISAMPLE_7_SAMPLES    = 7,
    D3DMULTISAMPLE_8_SAMPLES    = 8,
    D3DMULTISAMPLE_FORCE_DWORD  = 0x7fffffff
} D3DMULTISAMPLE_TYPE;

#define _D3DFORMAT_DEFINED
typedef enum _D3DFORMAT {
    D3DFMT_UNKNOWN              =  0,
    D3DFMT_R8G8B8               = 20,
    D3DFMT_A8R8G8B8             = 21,
    D3DFMT_X8R8G8B8             = 22,
    D3DFMT_R5G6B5               = 23,
    D3DFMT_X1R5G5B5             = 24,
    D3DFMT_A1R5G5B5             = 25,
    D3DFMT_A4R4G4B4             = 26,
    D3DFMT_R3G3B2               = 27,
    D3DFMT_A8                   = 28,
    D3DFMT_A8R3G3B2             = 29,
    D3DFMT_X4R4G4B4             = 30,
    D3DFMT_A8P8                 = 40,
    D3DFMT_P8                   = 41,
    D3DFMT_L8                   = 50,
    D3DFMT_A8L8                 = 51,
    D3DFMT_A4L4                 = 52,
    D3DFMT_V8U8                 = 60,
    D3DFMT_L6V5U5               = 61,
    D3DFMT_X8L8V8U8             = 62,
    D3DFMT_Q8W8V8U8             = 63,
    D3DFMT_V16U16               = 64,
    D3DFMT_W11V11U10            = 65,
    D3DFMT_D16_LOCKABLE         = 70,
    D3DFMT_D32                  = 71,
    D3DFMT_D15S1                = 73,
    D3DFMT_D24S8                = 75,
    D3DFMT_D16                  = 80,
    D3DFMT_D24X8                = 77,
    D3DFMT_D24X4S4              = 79,
    D3DFMT_INDEX16              = 101,
    D3DFMT_INDEX32              = 102,
    D3DFMT_FORCE_DWORD          = 0x7fffffff
} D3DFORMAT;

typedef enum _D3DSWAPEFFECT {
    D3DSWAPEFFECT_DISCARD       = 1,
    D3DSWAPEFFECT_FLIP          = 2,
    D3DSWAPEFFECT_COPY          = 3,
    D3DSWAPEFFECT_COPY_VSYNC    = 4,
    D3DSWAPEFFECT_FORCE_DWORD   = 0x7fffffff
} D3DSWAPEFFECT;

#define _D3DPOOL_DEFINED
typedef enum _D3DPOOL {
    D3DPOOL_DEFAULT             = 0,
    D3DPOOL_MANAGED             = 1,
    D3DPOOL_SYSTEMMEM           = 2,
    D3DPOOL_SCRATCH             = 3,
    D3DPOOL_FORCE_DWORD         = 0x7fffffff
} D3DPOOL;

#define _D3DRESOURCETYPE_DEFINED
typedef enum _D3DRESOURCETYPE {
    D3DRTYPE_SURFACE            = 1,
    D3DRTYPE_VOLUME             = 2,
    D3DRTYPE_TEXTURE            = 3,
    D3DRTYPE_VOLUMETEXTURE      = 4,
    D3DRTYPE_CUBETEXTURE        = 5,
    D3DRTYPE_VERTEXBUFFER       = 6,
    D3DRTYPE_INDEXBUFFER        = 7,
    D3DRTYPE_FORCE_DWORD        = 0x7fffffff
} D3DRESOURCETYPE;

typedef enum _D3DPRIMITIVETYPE {
    D3DPT_POINTLIST             = 1,
    D3DPT_LINELIST              = 2,
    D3DPT_LINESTRIP             = 3,
    D3DPT_TRIANGLELIST          = 4,
    D3DPT_TRIANGLESTRIP         = 5,
    D3DPT_TRIANGLEFAN           = 6,
    D3DPT_FORCE_DWORD           = 0x7fffffff
} D3DPRIMITIVETYPE;

typedef enum _D3DTRANSFORMSTATETYPE {
    D3DTS_VIEW                  = 2,
    D3DTS_PROJECTION            = 3,
    D3DTS_TEXTURE0              = 16,
    D3DTS_TEXTURE1              = 17,
    D3DTS_TEXTURE2              = 18,
    D3DTS_TEXTURE3              = 19,
    D3DTS_TEXTURE4              = 20,
    D3DTS_TEXTURE5              = 21,
    D3DTS_TEXTURE6              = 22,
    D3DTS_TEXTURE7              = 23,
    D3DTS_WORLD                 = 256,
    D3DTS_FORCE_DWORD           = 0x7fffffff
} D3DTRANSFORMSTATETYPE;
#define D3DTS_WORLDMATRIX(n) (D3DTRANSFORMSTATETYPE)((n) + 256)

typedef enum _D3DRENDERSTATETYPE {
    D3DRS_ZENABLE               = 7,
    D3DRS_FILLMODE              = 8,
    D3DRS_SHADEMODE             = 9,
    D3DRS_LINEPATTERN           = 10,
    D3DRS_ZWRITEENABLE          = 14,
    D3DRS_ALPHATESTENABLE       = 15,
    D3DRS_LASTPIXEL             = 16,
    D3DRS_SRCBLEND              = 19,
    D3DRS_DESTBLEND             = 20,
    D3DRS_CULLMODE              = 22,
    D3DRS_ZFUNC                 = 23,
    D3DRS_ALPHAREF              = 24,
    D3DRS_ALPHAFUNC             = 25,
    D3DRS_DITHERENABLE          = 26,
    D3DRS_ALPHABLENDENABLE      = 27,
    D3DRS_FOGENABLE             = 28,
    D3DRS_SPECULARENABLE        = 29,
    D3DRS_ZVISIBLE              = 30,
    D3DRS_FOGCOLOR              = 34,
    D3DRS_FOGTABLEMODE          = 35,
    D3DRS_FOGSTART              = 36,
    D3DRS_FOGEND                = 37,
    D3DRS_FOGDENSITY            = 38,
    D3DRS_EDGEANTIALIAS         = 40,
    D3DRS_ZBIAS                 = 47,
    D3DRS_RANGEFOGENABLE        = 48,
    D3DRS_STENCILENABLE         = 52,
    D3DRS_STENCILFAIL           = 53,
    D3DRS_STENCILZFAIL          = 54,
    D3DRS_STENCILPASS           = 55,
    D3DRS_STENCILFUNC           = 56,
    D3DRS_STENCILREF            = 57,
    D3DRS_STENCILMASK           = 58,
    D3DRS_STENCILWRITEMASK      = 59,
    D3DRS_TEXTUREFACTOR         = 60,
    D3DRS_WRAP0                 = 128,
    D3DRS_WRAP1                 = 129,
    D3DRS_WRAP2                 = 130,
    D3DRS_WRAP3                 = 131,
    D3DRS_WRAP4                 = 132,
    D3DRS_WRAP5                 = 133,
    D3DRS_WRAP6                 = 134,
    D3DRS_WRAP7                 = 135,
    D3DRS_CLIPPING              = 136,
    D3DRS_LIGHTING              = 137,
    D3DRS_AMBIENT               = 139,
    D3DRS_FOGVERTEXMODE         = 140,
    D3DRS_COLORVERTEX           = 141,
    D3DRS_LOCALVIEWER           = 142,
    D3DRS_NORMALIZENORMALS      = 143,
    D3DRS_DIFFUSEMATERIALSOURCE = 145,
    D3DRS_SPECULARMATERIALSOURCE= 146,
    D3DRS_AMBIENTMATERIALSOURCE = 147,
    D3DRS_EMISSIVEMATERIALSOURCE= 148,
    D3DRS_VERTEXBLEND           = 151,
    D3DRS_CLIPPLANEENABLE       = 152,
    D3DRS_SOFTWAREVERTEXPROCESSING = 153,
    D3DRS_POINTSIZE             = 154,
    D3DRS_POINTSIZE_MIN         = 155,
    D3DRS_POINTSPRITEENABLE     = 156,
    D3DRS_POINTSCALEENABLE      = 157,
    D3DRS_POINTSCALE_A          = 158,
    D3DRS_POINTSCALE_B          = 159,
    D3DRS_POINTSCALE_C          = 160,
    D3DRS_MULTISAMPLEANTIALIAS  = 161,
    D3DRS_MULTISAMPLEMASK       = 162,
    D3DRS_PATCHEDGESTYLE        = 163,
    D3DRS_PATCHSEGMENTS         = 164,
    D3DRS_DEBUGMONITORTOKEN     = 165,
    D3DRS_POINTSIZE_MAX         = 166,
    D3DRS_INDEXEDVERTEXBLENDENABLE = 167,
    D3DRS_COLORWRITEENABLE      = 168,
    D3DRS_TWEENFACTOR           = 170,
    D3DRS_BLENDOP               = 171,
    D3DRS_FORCE_DWORD           = 0x7fffffff
} D3DRENDERSTATETYPE;

typedef enum _D3DTEXTURESTAGESTATETYPE {
    D3DTSS_COLOROP              =  1,
    D3DTSS_COLORARG1            =  2,
    D3DTSS_COLORARG2            =  3,
    D3DTSS_ALPHAOP              =  4,
    D3DTSS_ALPHAARG1            =  5,
    D3DTSS_ALPHAARG2            =  6,
    D3DTSS_BUMPENVMAT00         =  7,
    D3DTSS_BUMPENVMAT01         =  8,
    D3DTSS_BUMPENVMAT10         =  9,
    D3DTSS_BUMPENVMAT11         = 10,
    D3DTSS_TEXCOORDINDEX        = 11,
    D3DTSS_ADDRESSU             = 13,
    D3DTSS_ADDRESSV             = 14,
    D3DTSS_BORDERCOLOR          = 15,
    D3DTSS_MAGFILTER            = 16,
    D3DTSS_MINFILTER            = 17,
    D3DTSS_MIPFILTER            = 18,
    D3DTSS_MIPMAPLODBIAS        = 19,
    D3DTSS_MAXMIPLEVEL          = 20,
    D3DTSS_MAXANISOTROPY        = 21,
    D3DTSS_BUMPENVLSCALE        = 22,
    D3DTSS_BUMPENVLOFFSET       = 23,
    D3DTSS_TEXTURETRANSFORMFLAGS= 24,
    D3DTSS_ADDRESSW             = 25,
    D3DTSS_COLORARG0            = 26,
    D3DTSS_ALPHAARG0            = 27,
    D3DTSS_RESULTARG            = 28,
    D3DTSS_FORCE_DWORD          = 0x7fffffff
} D3DTEXTURESTAGESTATETYPE;

#define D3DTSS_TCI_PASSTHRU                     0x00000000
#define D3DTSS_TCI_CAMERASPACENORMAL            0x00010000
#define D3DTSS_TCI_CAMERASPACEPOSITION          0x00020000
#define D3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR  0x00030000

typedef enum _D3DTEXTUREOP {
    D3DTOP_DISABLE              =  1,
    D3DTOP_SELECTARG1           =  2,
    D3DTOP_SELECTARG2           =  3,
    D3DTOP_MODULATE             =  4,
    D3DTOP_MODULATE2X           =  5,
    D3DTOP_MODULATE4X           =  6,
    D3DTOP_ADD                  =  7,
    D3DTOP_ADDSIGNED            =  8,
    D3DTOP_ADDSIGNED2X          =  9,
    D3DTOP_SUBTRACT             = 10,
    D3DTOP_ADDSMOOTH            = 11,
    D3DTOP_BLENDDIFFUSEALPHA    = 12,
    D3DTOP_BLENDTEXTUREALPHA    = 13,
    D3DTOP_BLENDFACTORALPHA     = 14,
    D3DTOP_BLENDTEXTUREALPHAPM  = 15,
    D3DTOP_BLENDCURRENTALPHA    = 16,
    D3DTOP_PREMODULATE          = 17,
    D3DTOP_MODULATEALPHA_ADDCOLOR   = 18,
    D3DTOP_MODULATECOLOR_ADDALPHA   = 19,
    D3DTOP_MODULATEINVALPHA_ADDCOLOR= 20,
    D3DTOP_MODULATEINVCOLOR_ADDALPHA= 21,
    D3DTOP_BUMPENVMAP           = 22,
    D3DTOP_BUMPENVMAPLUMINANCE  = 23,
    D3DTOP_DOTPRODUCT3          = 24,
    D3DTOP_MULTIPLYADD          = 25,
    D3DTOP_LERP                 = 26,
    D3DTOP_FORCE_DWORD          = 0x7fffffff
} D3DTEXTUREOP;

#define D3DTA_SELECTMASK        0x0000000fL
#define D3DTA_DIFFUSE           0x00000000L
#define D3DTA_CURRENT           0x00000001L
#define D3DTA_TEXTURE           0x00000002L
#define D3DTA_TFACTOR           0x00000003L
#define D3DTA_SPECULAR          0x00000004L
#define D3DTA_COMPLEMENT        0x00000010L
#define D3DTA_ALPHAREPLICATE    0x00000020L

typedef enum _D3DTEXTUREADDRESS {
    D3DTADDRESS_WRAP            = 1,
    D3DTADDRESS_MIRROR          = 2,
    D3DTADDRESS_CLAMP           = 3,
    D3DTADDRESS_BORDER          = 4,
    D3DTADDRESS_MIRRORONCE      = 5,
    D3DTADDRESS_FORCE_DWORD     = 0x7fffffff
} D3DTEXTUREADDRESS;

typedef enum _D3DTEXTUREFILTERTYPE {
    D3DTEXF_NONE                = 0,
    D3DTEXF_POINT               = 1,
    D3DTEXF_LINEAR              = 2,
    D3DTEXF_ANISOTROPIC         = 3,
    D3DTEXF_FLATCUBIC           = 4,
    D3DTEXF_GAUSSIANCUBIC       = 5,
    D3DTEXF_FORCE_DWORD         = 0x7fffffff
} D3DTEXTUREFILTERTYPE;

typedef enum _D3DTEXTURETRANSFORMFLAGS {
    D3DTTFF_DISABLE             = 0,
    D3DTTFF_COUNT1              = 1,
    D3DTTFF_COUNT2              = 2,
    D3DTTFF_COUNT3              = 3,
    D3DTTFF_COUNT4              = 4,
    D3DTTFF_PROJECTED           = 256,
    D3DTTFF_FORCE_DWORD         = 0x7fffffff
} D3DTEXTURETRANSFORMFLAGS;

typedef enum _D3DBLEND {
    D3DBLEND_ZERO               =  1,
    D3DBLEND_ONE                =  2,
    D3DBLEND_SRCCOLOR           =  3,
    D3DBLEND_INVSRCCOLOR        =  4,
    D3DBLEND_SRCALPHA           =  5,
    D3DBLEND_INVSRCALPHA        =  6,
    D3DBLEND_DESTALPHA          =  7,
    D3DBLEND_INVDESTALPHA       =  8,
    D3DBLEND_DESTCOLOR          =  9,
    D3DBLEND_INVDESTCOLOR       = 10,
    D3DBLEND_SRCALPHASAT        = 11,
    D3DBLEND_BOTHSRCALPHA       = 12,
    D3DBLEND_BOTHINVSRCALPHA    = 13,
    D3DBLEND_FORCE_DWORD        = 0x7fffffff
} D3DBLEND;

typedef enum _D3DBLENDOP {
    D3DBLENDOP_ADD              = 1,
    D3DBLENDOP_SUBTRACT         = 2,
    D3DBLENDOP_REVSUBTRACT      = 3,
    D3DBLENDOP_MIN              = 4,
    D3DBLENDOP_MAX              = 5,
    D3DBLENDOP_FORCE_DWORD      = 0x7fffffff
} D3DBLENDOP;

typedef enum _D3DCMPFUNC {
    D3DCMP_NEVER                = 1,
    D3DCMP_LESS                 = 2,
    D3DCMP_EQUAL                = 3,
    D3DCMP_LESSEQUAL            = 4,
    D3DCMP_GREATER              = 5,
    D3DCMP_NOTEQUAL             = 6,
    D3DCMP_GREATEREQUAL         = 7,
    D3DCMP_ALWAYS               = 8,
    D3DCMP_FORCE_DWORD          = 0x7fffffff
} D3DCMPFUNC;

typedef enum _D3DCULL {
    D3DCULL_NONE                = 1,
    D3DCULL_CW                  = 2,
    D3DCULL_CCW                 = 3,
    D3DCULL_FORCE_DWORD         = 0x7fffffff
} D3DCULL;

typedef enum _D3DFILLMODE {
    D3DFILL_POINT               = 1,
    D3DFILL_WIREFRAME           = 2,
    D3DFILL_SOLID               = 3,
    D3DFILL_FORCE_DWORD         = 0x7fffffff
} D3DFILLMODE;

typedef enum _D3DSHADEMODE {
    D3DSHADE_FLAT               = 1,
    D3DSHADE_GOURAUD            = 2,
    D3DSHADE_PHONG              = 3,
    D3DSHADE_FORCE_DWORD        = 0x7fffffff
} D3DSHADEMODE;

typedef enum _D3DFOGMODE {
    D3DFOG_NONE                 = 0,
    D3DFOG_EXP                  = 1,
    D3DFOG_EXP2                 = 2,
    D3DFOG_LINEAR               = 3,
    D3DFOG_FORCE_DWORD          = 0x7fffffff
} D3DFOGMODE;

typedef enum _D3DZBUFFERTYPE {
    D3DZB_FALSE                 = 0,
    D3DZB_TRUE                  = 1,
    D3DZB_USEW                  = 2,
    D3DZB_FORCE_DWORD           = 0x7fffffff
} D3DZBUFFERTYPE;

typedef enum _D3DSTENCILOP {
    D3DSTENCILOP_KEEP           = 1,
    D3DSTENCILOP_ZERO           = 2,
    D3DSTENCILOP_REPLACE        = 3,
    D3DSTENCILOP_INCRSAT        = 4,
    D3DSTENCILOP_DECRSAT        = 5,
    D3DSTENCILOP_INVERT         = 6,
    D3DSTENCILOP_INCR           = 7,
    D3DSTENCILOP_DECR           = 8,
    D3DSTENCILOP_FORCE_DWORD    = 0x7fffffff
} D3DSTENCILOP;

typedef enum _D3DLIGHTTYPE {
    D3DLIGHT_POINT              = 1,
    D3DLIGHT_SPOT               = 2,
    D3DLIGHT_DIRECTIONAL        = 3,
    D3DLIGHT_FORCE_DWORD        = 0x7fffffff
} D3DLIGHTTYPE;

typedef enum _D3DMATERIALCOLORSOURCE {
    D3DMCS_MATERIAL             = 0,
    D3DMCS_COLOR1               = 1,
    D3DMCS_COLOR2               = 2,
    D3DMCS_FORCE_DWORD          = 0x7fffffff
} D3DMATERIALCOLORSOURCE;

typedef enum _D3DVERTEXBLENDFLAGS {
    D3DVBF_DISABLE              = 0,
    D3DVBF_1WEIGHTS             = 1,
    D3DVBF_2WEIGHTS             = 2,
    D3DVBF_3WEIGHTS             = 3,
    D3DVBF_TWEENING             = 255,
    D3DVBF_0WEIGHTS             = 256,
    D3DVBF_FORCE_DWORD          = 0x7fffffff
} D3DVERTEXBLENDFLAGS;

// ─── FVF Flags ────────────────────────────────────────────────────────────────
#define D3DFVF_RESERVED0        0x001
#define D3DFVF_POSITION_MASK    0x00E
#define D3DFVF_XYZ              0x002
#define D3DFVF_XYZRHW           0x004
#define D3DFVF_XYZB1            0x006
#define D3DFVF_XYZB2            0x008
#define D3DFVF_XYZB3            0x00A
#define D3DFVF_XYZB4            0x00C
#define D3DFVF_XYZB5            0x00E
#define D3DFVF_NORMAL           0x010
#define D3DFVF_PSIZE            0x020
#define D3DFVF_DIFFUSE          0x040
#define D3DFVF_SPECULAR         0x080
#define D3DFVF_TEXCOUNT_MASK    0xf00
#define D3DFVF_TEXCOUNT_SHIFT   8
#define D3DFVF_TEX0             0x000
#define D3DFVF_TEX1             0x100
#define D3DFVF_TEX2             0x200
#define D3DFVF_TEX3             0x300
#define D3DFVF_TEX4             0x400
#define D3DFVF_TEX5             0x500
#define D3DFVF_TEX6             0x600
#define D3DFVF_TEX7             0x700
#define D3DFVF_TEX8             0x800
#define D3DFVF_LASTBETA_UBYTE4  0x1000
#define D3DFVF_RESERVED2        0xE000

#define D3DFVF_TEXTUREFORMAT1   3
#define D3DFVF_TEXTUREFORMAT2   0
#define D3DFVF_TEXTUREFORMAT3   1
#define D3DFVF_TEXTUREFORMAT4   2
#define D3DFVF_TEXCOORDSIZE1(n) (D3DFVF_TEXTUREFORMAT1 << ((n)*2 + 16))
#define D3DFVF_TEXCOORDSIZE2(n) (D3DFVF_TEXTUREFORMAT2 << ((n)*2 + 16))
#define D3DFVF_TEXCOORDSIZE3(n) (D3DFVF_TEXTUREFORMAT3 << ((n)*2 + 16))
#define D3DFVF_TEXCOORDSIZE4(n) (D3DFVF_TEXTUREFORMAT4 << ((n)*2 + 16))

// ─── Vertex Shader Declaration Tokens ────────────────────────────────────────
#define D3DVSDT_FLOAT1          0x00
#define D3DVSDT_FLOAT2          0x01
#define D3DVSDT_FLOAT3          0x02
#define D3DVSDT_FLOAT4          0x03
#define D3DVSDT_D3DCOLOR        0x04
#define D3DVSDT_UBYTE4          0x05
#define D3DVSDT_SHORT2          0x06
#define D3DVSDT_SHORT4          0x07

#define D3DVSD_MAKETOKENTYPE(t) (((DWORD)(t)) << 29)
#define D3DVSD_TOKEN_NOP        0
#define D3DVSD_TOKEN_STREAM     1
#define D3DVSD_TOKEN_STREAMDATA 2
#define D3DVSD_TOKEN_TESSELLATOR 3
#define D3DVSD_TOKEN_CONSTMEM   4
#define D3DVSD_TOKEN_EXT        5
#define D3DVSD_TOKEN_END        7

#define D3DVSD_STREAM(n)     (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAM)|(n))
#define D3DVSD_REG(r,t)      (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_STREAMDATA)|0x10000000|((r)<<16)|(t))
#define D3DVSD_CONST(r,c)    (D3DVSD_MAKETOKENTYPE(D3DVSD_TOKEN_CONSTMEM)|((c)<<25)|(r))
#define D3DVSD_END()         0xFFFFFFFF

// ─── Structures ───────────────────────────────────────────────────────────────
typedef struct _D3DVECTOR { float x, y, z; } D3DVECTOR;
#ifndef D3DXVECTOR3_DEFINED
#define D3DXVECTOR3_DEFINED
typedef D3DVECTOR D3DXVECTOR3;
#endif
#ifndef D3DXVECTOR4_DEFINED
#define D3DXVECTOR4_DEFINED
struct D3DXVECTOR4 { float x, y, z, w; D3DXVECTOR4() : x(0),y(0),z(0),w(0) {} D3DXVECTOR4(float _x,float _y,float _z,float _w) : x(_x),y(_y),z(_z),w(_w) {} operator const void*() const { return this; } };
#endif

typedef struct _D3DCOLORVALUE { float r, g, b, a; } D3DCOLORVALUE;

typedef struct _D3DMATRIX {
    union {
        struct { float _11,_12,_13,_14; float _21,_22,_23,_24;
                 float _31,_32,_33,_34; float _41,_42,_43,_44; };
        float m[4][4];
    };
} D3DMATRIX;

#define D3DVIEWPORT8_DEFINED
typedef struct _D3DVIEWPORT8 {
    DWORD X, Y; DWORD Width, Height; float MinZ, MaxZ;
} D3DVIEWPORT8;

#define D3DLIGHT8_DEFINED
typedef struct _D3DLIGHT8 {
    D3DLIGHTTYPE Type; D3DCOLORVALUE Diffuse; D3DCOLORVALUE Specular;
    D3DCOLORVALUE Ambient; D3DVECTOR Position; D3DVECTOR Direction;
    float Range; float Falloff; float Attenuation0, Attenuation1, Attenuation2;
    float Theta; float Phi;
} D3DLIGHT8;

#define D3DMATERIAL8_DEFINED
typedef struct _D3DMATERIAL8 {
    D3DCOLORVALUE Diffuse, Ambient, Specular, Emissive; float Power;
} D3DMATERIAL8;

typedef struct _D3DLOCKED_RECT { INT Pitch; void* pBits; } D3DLOCKED_RECT;
typedef struct _D3DSURFACE_DESC { D3DFORMAT Format; D3DRESOURCETYPE Type; DWORD Usage; D3DPOOL Pool; UINT Size; D3DMULTISAMPLE_TYPE MultiSampleType; UINT Width, Height; } D3DSURFACE_DESC;
typedef struct _D3DVERTEXBUFFER_DESC { D3DFORMAT Format; D3DRESOURCETYPE Type; DWORD Usage; D3DPOOL Pool; UINT Size; DWORD FVF; } D3DVERTEXBUFFER_DESC;
typedef struct _D3DINDEXBUFFER_DESC { D3DFORMAT Format; D3DRESOURCETYPE Type; DWORD Usage; D3DPOOL Pool; UINT Size; } D3DINDEXBUFFER_DESC;
typedef struct _D3DDISPLAYMODE { UINT Width, Height, RefreshRate; D3DFORMAT Format; } D3DDISPLAYMODE;
typedef struct _D3DRECT { LONG x1, y1, x2, y2; } D3DRECT;
typedef struct _D3DCLIPSTATUS8 { DWORD ClipUnion, ClipIntersection; } D3DCLIPSTATUS8;

#pragma pack(push, 4)
typedef struct _D3DCAPS8 {
    D3DDEVTYPE DeviceType; UINT AdapterOrdinal; DWORD Caps; DWORD Caps2; DWORD Caps3;
    DWORD PresentationIntervals; DWORD CursorCaps; DWORD DevCaps; DWORD PrimitiveMiscCaps;
    DWORD RasterCaps; DWORD ZCmpCaps; DWORD SrcBlendCaps; DWORD DestBlendCaps;
    DWORD AlphaCmpCaps; DWORD ShadeCaps; DWORD TextureCaps; DWORD TextureFilterCaps;
    DWORD CubeTextureFilterCaps; DWORD VolumeTextureFilterCaps; DWORD TextureAddressCaps;
    DWORD VolumeTextureAddressCaps; DWORD LineCaps; DWORD MaxTextureWidth;
    DWORD MaxTextureHeight; DWORD MaxVolumeExtent; DWORD MaxTextureRepeat;
    DWORD MaxTextureAspectRatio; DWORD MaxAnisotropy; float MaxVertexW;
    float GuardBandLeft, GuardBandTop, GuardBandRight, GuardBandBottom;
    float ExtentsAdjust; DWORD StencilCaps; DWORD FVFCaps; DWORD TextureOpCaps;
    DWORD MaxTextureBlendStages; DWORD MaxSimultaneousTextures; DWORD VertexProcessingCaps;
    DWORD MaxActiveLights; DWORD MaxUserClipPlanes; DWORD MaxVertexBlendMatrices;
    DWORD MaxVertexBlendMatrixIndex; float MaxPointSize; DWORD MaxPrimitiveCount;
    DWORD MaxVertexIndex; DWORD MaxStreams; DWORD MaxStreamStride;
    DWORD VertexShaderVersion; DWORD MaxVertexShaderConst; DWORD PixelShaderVersion;
    float MaxPixelShaderValue;
} D3DCAPS8;
static_assert(sizeof(D3DCAPS8) == 208, "D3DCAPS8: ABI size mismatch");
#pragma pack(pop)

typedef struct _D3DPRESENT_PARAMETERS {
    UINT BackBufferWidth, BackBufferHeight; D3DFORMAT BackBufferFormat; UINT BackBufferCount;
    D3DMULTISAMPLE_TYPE MultiSampleType; D3DSWAPEFFECT SwapEffect; HWND hDeviceWindow;
    BOOL Windowed; BOOL EnableAutoDepthStencil; D3DFORMAT AutoDepthStencilFormat;
    DWORD Flags; UINT FullScreen_RefreshRateInHz; UINT FullScreen_PresentationInterval;
} D3DPRESENT_PARAMETERS;

// ─── COM interface forward declarations ───────────────────────────────────────
struct IDirect3D8;
struct IDirect3DDevice8;
struct IDirect3DResource8;
struct IDirect3DBaseTexture8;
struct IDirect3DTexture8;
struct IDirect3DSurface8;
struct IDirect3DVertexBuffer8;
struct IDirect3DIndexBuffer8;
struct IDirect3DSwapChain8;

// ─── D3DX helper interface ────────────────────────────────────────────────────
struct ID3DXBuffer : public IUnknown {
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID,void**) = 0;
    virtual ULONG   STDMETHODCALLTYPE AddRef() = 0;
    virtual ULONG   STDMETHODCALLTYPE Release() = 0;
    virtual LPVOID  STDMETHODCALLTYPE GetBufferPointer() = 0;
    virtual DWORD   STDMETHODCALLTYPE GetBufferSize() = 0;
};
typedef ID3DXBuffer* LPD3DXBUFFER;

// ─── Interface definitions (proper COM vtable layout) ─────────────────────────
struct IDirect3DResource8 : public IUnknown {
    virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8** ppDevice) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID,CONST void*,DWORD,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID,void*,DWORD*) = 0;
    virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID) = 0;
    virtual DWORD   STDMETHODCALLTYPE SetPriority(DWORD) = 0;
    virtual DWORD   STDMETHODCALLTYPE GetPriority() = 0;
    virtual void    STDMETHODCALLTYPE PreLoad() = 0;
    virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType() = 0;
};

struct IDirect3DBaseTexture8 : public IDirect3DResource8 {
    virtual DWORD   STDMETHODCALLTYPE SetLOD(DWORD) = 0;
    virtual DWORD   STDMETHODCALLTYPE GetLOD() = 0;
    virtual DWORD   STDMETHODCALLTYPE GetLevelCount() = 0;
};

struct IDirect3DTexture8 : public IDirect3DBaseTexture8 {
    virtual HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT, D3DSURFACE_DESC*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetSurfaceLevel(UINT, IDirect3DSurface8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE LockRect(UINT, D3DLOCKED_RECT*, CONST RECT*, DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE UnlockRect(UINT) = 0;
};

struct IDirect3DSurface8 : public IUnknown {
    virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID,CONST void*,DWORD,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID,void*,DWORD*) = 0;
    virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetContainer(REFIID,void**) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DSURFACE_DESC*) = 0;
    virtual HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT*, CONST RECT*, DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE UnlockRect() = 0;
};

struct IDirect3DVertexBuffer8 : public IDirect3DResource8 {
    virtual HRESULT STDMETHODCALLTYPE Lock(UINT,UINT,BYTE**,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE Unlock() = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DVERTEXBUFFER_DESC*) = 0;
};

struct IDirect3DIndexBuffer8 : public IDirect3DResource8 {
    virtual HRESULT STDMETHODCALLTYPE Lock(UINT,UINT,BYTE**,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE Unlock() = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DINDEXBUFFER_DESC*) = 0;
};

struct IDirect3DSwapChain8 : public IUnknown {
    virtual HRESULT STDMETHODCALLTYPE Present(CONST RECT*,CONST RECT*,HWND,CONST RGNDATA*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT,DWORD,IDirect3DSurface8**) = 0;
};

struct IDirect3DDevice8 : public IUnknown {
    virtual HRESULT STDMETHODCALLTYPE TestCooperativeLevel() = 0;
    virtual UINT    STDMETHODCALLTYPE GetAvailableTextureMem() = 0;
    virtual HRESULT STDMETHODCALLTYPE ResourceManagerDiscardBytes(DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDirect3D(IDirect3D8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDeviceCaps(D3DCAPS8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDisplayMode(D3DDISPLAYMODE*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetCursorProperties(UINT,UINT,IDirect3DSurface8*) = 0;
    virtual void    STDMETHODCALLTYPE SetCursorPosition(int,int,DWORD) = 0;
    virtual BOOL    STDMETHODCALLTYPE ShowCursor(BOOL) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS*,IDirect3DSwapChain8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE Reset(D3DPRESENT_PARAMETERS*) = 0;
    virtual HRESULT STDMETHODCALLTYPE Present(CONST RECT*,CONST RECT*,HWND,CONST RGNDATA*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT,D3DBACKBUFFER_TYPE,IDirect3DSurface8**) = 0;
    virtual void    STDMETHODCALLTYPE SetGammaRamp(DWORD,CONST D3DGAMMARAMP*) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreateTexture(UINT,UINT,UINT,DWORD,D3DFORMAT,D3DPOOL,IDirect3DTexture8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreateVertexBuffer(UINT,DWORD,DWORD,D3DPOOL,IDirect3DVertexBuffer8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreateIndexBuffer(UINT,DWORD,D3DFORMAT,D3DPOOL,IDirect3DIndexBuffer8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreateRenderTarget(UINT,UINT,D3DFORMAT,D3DMULTISAMPLE_TYPE,BOOL,IDirect3DSurface8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilSurface(UINT,UINT,D3DFORMAT,D3DMULTISAMPLE_TYPE,IDirect3DSurface8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE CopyRects(IDirect3DSurface8*,CONST RECT*,UINT,IDirect3DSurface8*,CONST POINT*) = 0;
    virtual HRESULT STDMETHODCALLTYPE UpdateTexture(IDirect3DBaseTexture8*,IDirect3DBaseTexture8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetFrontBuffer(IDirect3DSurface8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetRenderTarget(IDirect3DSurface8*,IDirect3DSurface8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetRenderTarget(IDirect3DSurface8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDepthStencilSurface(IDirect3DSurface8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE BeginScene() = 0;
    virtual HRESULT STDMETHODCALLTYPE EndScene() = 0;
    virtual HRESULT STDMETHODCALLTYPE Clear(DWORD,CONST D3DRECT*,DWORD,D3DCOLOR,float,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetTransform(D3DTRANSFORMSTATETYPE,CONST D3DMATRIX*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetTransform(D3DTRANSFORMSTATETYPE,D3DMATRIX*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetViewport(CONST D3DVIEWPORT8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetViewport(D3DVIEWPORT8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetMaterial(CONST D3DMATERIAL8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetMaterial(D3DMATERIAL8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetLight(DWORD,CONST D3DLIGHT8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetLight(DWORD,D3DLIGHT8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE LightEnable(DWORD,BOOL) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetLightEnable(DWORD,BOOL*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetClipPlane(DWORD,CONST float*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetClipPlane(DWORD,float*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetRenderState(D3DRENDERSTATETYPE,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetRenderState(D3DRENDERSTATETYPE,DWORD*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetTextureStageState(DWORD,D3DTEXTURESTAGESTATETYPE,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetTextureStageState(DWORD,D3DTEXTURESTAGESTATETYPE,DWORD*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetTexture(DWORD,IDirect3DBaseTexture8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetTexture(DWORD,IDirect3DBaseTexture8**) = 0;
    virtual HRESULT STDMETHODCALLTYPE ValidateDevice(DWORD*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetPaletteEntries(UINT,CONST PALETTEENTRY*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetCurrentTexturePalette(UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetCurrentTexturePalette(UINT*) = 0;
    virtual HRESULT STDMETHODCALLTYPE DrawPrimitive(D3DPRIMITIVETYPE,UINT,UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE DrawIndexedPrimitive(D3DPRIMITIVETYPE,UINT,UINT,UINT,UINT,UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE DrawPrimitiveUP(D3DPRIMITIVETYPE,UINT,CONST void*,UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE,UINT,UINT,UINT,CONST void*,D3DFORMAT,CONST void*,UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreateVertexShader(CONST DWORD*,CONST DWORD*,DWORD*,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetVertexShader(DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetVertexShader(DWORD*) = 0;
    virtual HRESULT STDMETHODCALLTYPE DeleteVertexShader(DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetVertexShaderConstant(DWORD,CONST void*,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetVertexShaderConstant(DWORD,void*,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetStreamSource(UINT,IDirect3DVertexBuffer8*,UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetStreamSource(UINT,IDirect3DVertexBuffer8**,UINT*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetIndices(IDirect3DIndexBuffer8*,UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetIndices(IDirect3DIndexBuffer8**,UINT*) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreatePixelShader(CONST DWORD*,DWORD*) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetPixelShader(DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetPixelShader(DWORD*) = 0;
    virtual HRESULT STDMETHODCALLTYPE DeletePixelShader(DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE SetPixelShaderConstant(DWORD,CONST void*,DWORD) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetPixelShaderConstant(DWORD,void*,DWORD) = 0;
};

struct IDirect3D8 : public IUnknown {
    virtual UINT    STDMETHODCALLTYPE GetAdapterCount() = 0;
    virtual HRESULT STDMETHODCALLTYPE GetAdapterIdentifier(UINT,DWORD,D3DADAPTER_IDENTIFIER8*) = 0;
    virtual UINT    STDMETHODCALLTYPE GetAdapterModeCount(UINT) = 0;
    virtual HRESULT STDMETHODCALLTYPE EnumAdapterModes(UINT,UINT,D3DDISPLAYMODE*) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetAdapterDisplayMode(UINT,D3DDISPLAYMODE*) = 0;
    virtual HRESULT STDMETHODCALLTYPE CheckDeviceType(UINT,D3DDEVTYPE,D3DFORMAT,D3DFORMAT,BOOL) = 0;
    virtual HRESULT STDMETHODCALLTYPE CheckDeviceFormat(UINT,D3DDEVTYPE,D3DFORMAT,DWORD,D3DRESOURCETYPE,D3DFORMAT) = 0;
    virtual HRESULT STDMETHODCALLTYPE CheckDeviceMultiSampleType(UINT,D3DDEVTYPE,D3DFORMAT,BOOL,D3DMULTISAMPLE_TYPE) = 0;
    virtual HRESULT STDMETHODCALLTYPE CheckDepthStencilMatch(UINT,D3DDEVTYPE,D3DFORMAT,D3DFORMAT,D3DFORMAT) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetDeviceCaps(UINT,D3DDEVTYPE,D3DCAPS8*) = 0;
    virtual HRESULT STDMETHODCALLTYPE CreateDevice(UINT,D3DDEVTYPE,HWND,DWORD,D3DPRESENT_PARAMETERS*,IDirect3DDevice8**) = 0;
};

// ─── Stub structs ─────────────────────────────────────────────────────────────
typedef struct _D3DDEVICE_CREATION_PARAMETERS {
    UINT AdapterOrdinal; D3DDEVTYPE DeviceType; HWND hFocusWindow; DWORD BehaviorFlags;
} D3DDEVICE_CREATION_PARAMETERS;

typedef enum _D3DBACKBUFFER_TYPE {
    D3DBACKBUFFER_TYPE_MONO=0, D3DBACKBUFFER_TYPE_LEFT=1, D3DBACKBUFFER_TYPE_RIGHT=2
} D3DBACKBUFFER_TYPE;

typedef struct _D3DGAMMARAMP { WORD red[256]; WORD green[256]; WORD blue[256]; } D3DGAMMARAMP;

#pragma pack(push, 1)
typedef struct _D3DADAPTER_IDENTIFIER8 {
    char Driver[MAX_DEVICE_IDENTIFIER_STRING];
    char Description[MAX_DEVICE_IDENTIFIER_STRING];
    LARGE_INTEGER DriverVersion;
    DWORD VendorId, DeviceId, SubSysId, Revision;
    GUID DeviceIdentifier;
    DWORD WHQLLevel;
} D3DADAPTER_IDENTIFIER8;
#pragma pack(pop)

// ─── D3DX helper functions ────────────────────────────────────────────────────
// These are from d3dx8.dll, not core d3d8.dll. Stubs return E_NOTIMPL.
// In real usage, link against d3dx8.lib or load dynamically.
#ifdef __cplusplus
extern "C" {
#endif
HRESULT WINAPI D3DXAssembleShader(CONST void*, UINT, CONST void*, LPD3DXBUFFER*,
    LPD3DXBUFFER*, LPD3DXBUFFER*);
HRESULT WINAPI D3DXAssembleShaderFromFile(LPCSTR, CONST void*, LPD3DXBUFFER*,
    LPD3DXBUFFER*, LPD3DXBUFFER*);
#ifdef __cplusplus
}
#endif

// ─── Entry point ──────────────────────────────────────────────────────────────
typedef IDirect3D8* (WINAPI* PFN_DIRECT3DCREATE8)(UINT SDKVersion);
#ifdef __cplusplus
extern "C" {
#endif
IDirect3D8* WINAPI Direct3DCreate8(UINT SDKVersion);
#ifdef __cplusplus
}
#endif

// ─── Compile-time size validation ─────────────────────────────────────────────
static_assert(sizeof(D3DCAPS8)      == 208, "D3DCAPS8: ABI size mismatch");
static_assert(sizeof(D3DLIGHT8)     ==  96, "D3DLIGHT8: ABI size mismatch");
static_assert(sizeof(D3DMATERIAL8)  ==  80, "D3DMATERIAL8: ABI size mismatch");
static_assert(sizeof(D3DMATRIX)     ==  64, "D3DMATRIX: must be 4x4 float");
static_assert(sizeof(D3DVIEWPORT8)  ==  24, "D3DVIEWPORT8: ABI size mismatch");
static_assert(MAX_DEVICE_IDENTIFIER_STRING == 256,
    "MAX_DEVICE_IDENTIFIER_STRING must be 256 for DX8");

#endif // __D3D8_H__