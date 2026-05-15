#pragma once
// Minimal atlbase.h stub for Smart COM pointers and ATL types
// This is NOT a real ATL implementation - just enough to compile PreRTS.h

#ifdef _WIN32
#include <windows.h>
#include <unknwn.h>
#else
#include "CrossPlatform.h"
#ifndef IUNKNOWN_DEFINED
#define IUNKNOWN_DEFINED
struct IUnknown {
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& riid, void** ppvObject) = 0;
    virtual ULONG STDMETHODCALLTYPE AddRef() = 0;
    virtual ULONG STDMETHODCALLTYPE Release() = 0;
};
#endif
#endif

template <class T>
class CComPtr {
public:
    CComPtr() : p(NULL) {}
    CComPtr(T* lp) : p(lp) { if (p) p->AddRef(); }
    CComPtr(const CComPtr<T>& lp) : p(lp.p) { if (p) p->AddRef(); }
    ~CComPtr() { if (p) p->Release(); }
    void Release() { if (p) { p->Release(); p = NULL; } }
    operator T*() const { return p; }
    T& operator*() const { return *p; }
    T** operator&() { return &p; }
    T* operator->() const { return p; }
    T* operator=(T* lp) { if (p) p->Release(); p = lp; if (p) p->AddRef(); return p; }
    T* operator=(const CComPtr<T>& lp) { return operator=(lp.p); }
    bool operator!() const { return (p == NULL); }
    typedef T* CComPtr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return p ? &CComPtr::p : 0; }
private:
    T* p;
};

template <class T>
class CComQIPtr : public CComPtr<T> {
public:
    CComQIPtr(IUnknown* lp) : CComPtr<T>() { if (lp) lp->QueryInterface(__uuidof(T), (void**)&p); }
};

typedef struct _ATL_BASE_MODULE {
    int cbSize;
    HINSTANCE m_hInst;
    HINSTANCE m_hInstResource;
    const void* m_pAtlFuncMgr;
} ATL_BASE_MODULE;

#define DECLARE_REGISTRY_RESOURCEID(x)
#define DECLARE_PROTECT_FINAL_CONSTRUCT()
#define OBJECT_ENTRY_AUTO(classid, classname)

extern void __stdcall AtlSetPerUserRegistration(bool);
extern HRESULT __stdcall AtlInitializePerUserRegistration();

// ATL conversion macros (simplified)
#define USES_CONVERSION int _convert = 0
#define W2A(lpw) lpw ? "W2A-stub" : NULL
#define A2W(lpa) lpa ? L"A2W-stub" : NULL

#ifndef ATL_NO_VTABLE
#define ATL_NO_VTABLE __declspec(novtable)
#endif

#ifndef _ATL_FUNC_THRESHOLD
#define _ATL_FUNC_THRESHOLD 20
#endif
