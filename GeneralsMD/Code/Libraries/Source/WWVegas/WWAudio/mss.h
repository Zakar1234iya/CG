#pragma once

#ifndef MSS_H_STUB
#define MSS_H_STUB

// Minimal Microsoft MSS (Miles Sound System) stub for compilation only.

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
// Cross-platform type definitions (subset of windows.h)
typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned int   DWORD;
typedef int            BOOL;
typedef void*          HANDLE;
typedef wchar_t        WCHAR;
#define TRUE  1
#define FALSE 0
#endif

// ---------------------------------------------------------------------------
// Integer types
// ---------------------------------------------------------------------------
typedef long            S32;
typedef unsigned long   U32;
typedef float           F32;

// ---------------------------------------------------------------------------
// Opaque handle types
// ---------------------------------------------------------------------------
struct HSAMPLE__       { int unused; };
struct HSTREAM__       { int unused; };
struct H3DSAMPLE__     { int unused; };
struct H3DPOBJECT__    { int unused; };
struct HPROVIDER__     { int unused; };
struct HPROENUM__      { int unused; };

typedef HSAMPLE__*      HSAMPLE;
typedef HSTREAM__*      HSTREAM;
typedef H3DSAMPLE__*    H3DSAMPLE;
typedef H3DPOBJECT__*   H3DPOBJECT;
typedef HPROVIDER__*    HPROVIDER;
typedef HPROENUM__*     HPROENUM;

// HDIGDRIVER - pointer to DIG_DRIVER struct (needs emulated_ds member)
typedef struct DIG_DRIVER {
    int   unused;
    int   emulated_ds;
} DIG_DRIVER, *HDIGDRIVER;

// Timer handle
typedef int             HTIMER;

// ---------------------------------------------------------------------------
// WAVEFORMATEX / LPWAVEFORMAT
// ---------------------------------------------------------------------------
typedef struct WAVEFORMATEX {
    WORD  wFormatTag;
    WORD  nChannels;
    DWORD nSamplesPerSec;
    DWORD nAvgBytesPerSec;
    WORD  nBlockAlign;
    WORD  wBitsPerSample;
    WORD  cbSize;
} WAVEFORMATEX, *LPWAVEFORMAT, *NPWAVEFORMAT, *PWAVEFORMATEX;

// ---------------------------------------------------------------------------
// PCMWAVEFORMAT (from mmsystem.h)
// ---------------------------------------------------------------------------
typedef struct tPCMWAVEFORMAT {
    WAVEFORMATEX wf;
    WORD         wBitsPerSample;
} PCMWAVEFORMAT;

// ---------------------------------------------------------------------------
// AILSOUNDINFO
// ---------------------------------------------------------------------------
typedef struct AILSOUNDINFO {
    U32  format;
    U32  rate;
    S32  bits;
    S32  channels;
    S32  samples;
    U32  handle;
    void* data_ptr;
    U32  data_len;
    char* file_name;
    U32  file_offset;
    U32  file_size;
} AILSOUNDINFO;

// ---------------------------------------------------------------------------
// Calling convention
// ---------------------------------------------------------------------------
#define AILCALLBACK __stdcall

// ---------------------------------------------------------------------------
// Enumerator constant
// ---------------------------------------------------------------------------
#define HPROENUM_FIRST ((HPROENUM)0)

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------
#define AIL_NO_ERROR            0
#define M3D_NOERR               0
#define AIL_LOCK_PROTECTION     1
#define DIG_USE_WAVEOUT         2
#define DP_FILTER               1
#define AIL_3D_2_SPEAKER        0
#define ENVIRONMENT_GENERIC     0
#ifndef WAVE_FORMAT_PCM
#define WAVE_FORMAT_PCM         1
#endif
#ifndef WAVE_FORMAT_IMA_ADPCM
#define WAVE_FORMAT_IMA_ADPCM   0x0011
#endif

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE  1
#endif
#ifndef NO
#define NO    0
#endif

// ---------------------------------------------------------------------------
// Static inline stub functions (2D sample API)
// ---------------------------------------------------------------------------
static inline void        AIL_startup(void) {}
static inline void        AIL_lock(void) {}
static inline void        AIL_unlock(void) {}
static inline S32         AIL_set_preference(U32 pref, S32 val) { (void)pref; (void)val; return AIL_NO_ERROR; }
static inline S32         AIL_waveOutOpen(HDIGDRIVER* driver, void* w, U32 a, LPWAVEFORMAT fmt) { (void)driver; (void)w; (void)a; (void)fmt; return AIL_NO_ERROR; }
static inline void        AIL_waveOutClose(HDIGDRIVER driver) { (void)driver; }
static inline char*       AIL_last_error(void) { return (char*)""; }
static inline HSAMPLE     AIL_allocate_sample_handle(HDIGDRIVER driver) { (void)driver; return NULL; }
static inline void        AIL_release_sample_handle(HSAMPLE s) { (void)s; }
static inline void        AIL_init_sample(HSAMPLE s) { (void)s; }
static inline void        AIL_set_named_sample_file(HSAMPLE s, char* fn, unsigned char* buf, U32 len, U32 offs) { (void)s; (void)fn; (void)buf; (void)len; (void)offs; }
static inline void        AIL_start_sample(HSAMPLE s) { (void)s; }
static inline void        AIL_stop_sample(HSAMPLE s) { (void)s; }
static inline void        AIL_resume_sample(HSAMPLE s) { (void)s; }
static inline void        AIL_end_sample(HSAMPLE s) { (void)s; }
static inline void        AIL_set_sample_pan(HSAMPLE s, S32 pan) { (void)s; (void)pan; }
static inline S32         AIL_sample_pan(HSAMPLE s) { (void)s; return 64; }
static inline void        AIL_set_sample_volume(HSAMPLE s, S32 vol) { (void)s; (void)vol; }
static inline S32         AIL_sample_volume(HSAMPLE s) { (void)s; return 0; }
static inline void        AIL_set_sample_loop_count(HSAMPLE s, U32 count) { (void)s; (void)count; }
static inline U32         AIL_sample_loop_count(HSAMPLE s) { (void)s; return 0; }
static inline void        AIL_set_sample_ms_position(HSAMPLE s, U32 ms) { (void)s; (void)ms; }
static inline void        AIL_sample_ms_position(HSAMPLE s, S32* len, S32* pos) { (void)s; if (len) *len = 0; if (pos) *pos = 0; }
static inline void        AIL_set_sample_user_data(HSAMPLE s, S32 i, U32 val) { (void)s; (void)i; (void)val; }
static inline U32         AIL_sample_user_data(HSAMPLE s, S32 i) { (void)s; (void)i; return 0; }
static inline S32         AIL_sample_playback_rate(HSAMPLE s) { (void)s; return 0; }
static inline void        AIL_set_sample_playback_rate(HSAMPLE s, S32 rate) { (void)s; (void)rate; }

// ---------------------------------------------------------------------------
// 3D sample API
// ---------------------------------------------------------------------------
static inline H3DSAMPLE  AIL_allocate_3D_sample_handle(HPROVIDER prov) { (void)prov; return NULL; }
static inline void        AIL_release_3D_sample_handle(H3DSAMPLE s) { (void)s; }
static inline U32         AIL_set_3D_sample_file(H3DSAMPLE s, unsigned char* buf) { (void)s; (void)buf; return 1; }
static inline void        AIL_start_3D_sample(H3DSAMPLE s) { (void)s; }
static inline void        AIL_stop_3D_sample(H3DSAMPLE s) { (void)s; }
static inline void        AIL_resume_3D_sample(H3DSAMPLE s) { (void)s; }
static inline void        AIL_end_3D_sample(H3DSAMPLE s) { (void)s; }
static inline void        AIL_set_3D_sample_volume(H3DSAMPLE s, S32 vol) { (void)s; (void)vol; }
static inline S32         AIL_3D_sample_volume(H3DSAMPLE s) { (void)s; return 0; }
static inline void        AIL_set_3D_sample_loop_count(H3DSAMPLE s, U32 count) { (void)s; (void)count; }
static inline U32         AIL_3D_sample_loop_count(H3DSAMPLE s) { (void)s; return 0; }
static inline void        AIL_set_3D_sample_offset(H3DSAMPLE s, U32 offs) { (void)s; (void)offs; }
static inline U32         AIL_3D_sample_offset(H3DSAMPLE s) { (void)s; return 0; }
static inline U32         AIL_3D_sample_length(H3DSAMPLE s) { (void)s; return 0; }
static inline void        AIL_set_3D_object_user_data(H3DSAMPLE s, S32 i, U32 val) { (void)s; (void)i; (void)val; }
static inline U32         AIL_3D_object_user_data(H3DSAMPLE s, S32 i) { (void)s; (void)i; return 0; }
static inline S32         AIL_3D_sample_playback_rate(H3DSAMPLE s) { (void)s; return 0; }
static inline void        AIL_set_3D_sample_playback_rate(H3DSAMPLE s, S32 rate) { (void)s; (void)rate; }
static inline void        AIL_set_3D_position(H3DSAMPLE s, float a, float b, float c) { (void)s; (void)a; (void)b; (void)c; }
static inline void        AIL_set_3D_orientation(H3DSAMPLE s, float a1, float a2, float a3, float b1, float b2, float b3) { (void)s; (void)a1; (void)a2; (void)a3; (void)b1; (void)b2; (void)b3; }
static inline void        AIL_set_3D_velocity_vector(H3DSAMPLE s, float a, float b, float c) { (void)s; (void)a; (void)b; (void)c; }
static inline void        AIL_set_3D_sample_distances(H3DSAMPLE s, float a, float b) { (void)s; (void)a; (void)b; }
static inline void        AIL_set_3D_sample_effects_level(H3DSAMPLE s, float level) { (void)s; (void)level; }
static inline H3DPOBJECT  AIL_3D_open_listener(HPROVIDER prov) { (void)prov; return NULL; }

// ---------------------------------------------------------------------------
// 3D provider / streaming API
// ---------------------------------------------------------------------------
static inline int         AIL_enumerate_3D_providers(HPROENUM* next, HPROVIDER* prov, char** name) { (void)next; (void)prov; (void)name; return 0; }
static inline int         AIL_open_3D_provider(HPROVIDER prov) { (void)prov; return M3D_NOERR; }
static inline void        AIL_close_3D_provider(HPROVIDER prov) { (void)prov; }
static inline void        AIL_set_3D_speaker_type(HPROVIDER prov, U32 type) { (void)prov; (void)type; }
static inline HSTREAM     AIL_open_stream_by_sample(HDIGDRIVER driver, HSAMPLE samp, char* fn, U32 offs) { (void)driver; (void)samp; (void)fn; (void)offs; return NULL; }
static inline void        AIL_start_stream(HSTREAM s) { (void)s; }
static inline void        AIL_pause_stream(HSTREAM s, U32 pause) { (void)s; (void)pause; }
static inline void        AIL_close_stream(HSTREAM s) { (void)s; }
static inline void        AIL_set_stream_pan(HSTREAM s, S32 pan) { (void)s; (void)pan; }
static inline S32         AIL_stream_pan(HSTREAM s) { (void)s; return 64; }
static inline void        AIL_set_stream_volume(HSTREAM s, S32 vol) { (void)s; (void)vol; }
static inline S32         AIL_stream_volume(HSTREAM s) { (void)s; return 0; }
static inline void        AIL_set_stream_loop_block(HSTREAM s, U32 a, S32 b) { (void)s; (void)a; (void)b; }
static inline void        AIL_set_stream_loop_count(HSTREAM s, U32 count) { (void)s; (void)count; }
static inline U32         AIL_stream_loop_count(HSTREAM s) { (void)s; return 0; }
static inline void        AIL_set_stream_ms_position(HSTREAM s, U32 ms) { (void)s; (void)ms; }
static inline void        AIL_stream_ms_position(HSTREAM s, S32* len, S32* pos) { (void)s; if (len) *len = 0; if (pos) *pos = 0; }
static inline S32         AIL_stream_playback_rate(HSTREAM s) { (void)s; return 0; }
static inline void        AIL_set_stream_playback_rate(HSTREAM s, S32 rate) { (void)s; (void)rate; }

// ---------------------------------------------------------------------------
// Filter / effects API
// ---------------------------------------------------------------------------
static inline void        AIL_set_sample_processor(HSAMPLE s, U32 type, HPROVIDER filter) { (void)s; (void)type; (void)filter; }
static inline void        AIL_set_filter_sample_preference(HSAMPLE s, const char* key, void* val) { (void)s; (void)key; (void)val; }

// ---------------------------------------------------------------------------
// Utility API
// ---------------------------------------------------------------------------
static inline int         AIL_WAV_info(unsigned char* buf, AILSOUNDINFO* info) { (void)buf; if (info) { info->rate = 22050; info->channels = 1; info->bits = 16; info->format = WAVE_FORMAT_PCM; info->samples = 0; } return 1; }

#endif // MSS_H_STUB
