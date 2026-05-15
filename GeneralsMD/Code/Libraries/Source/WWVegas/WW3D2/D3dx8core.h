#pragma once
#ifndef __D3DX8CORE_H__
#define __D3DX8CORE_H__

// Minimal stub for D3dx8core.h — provides types needed by the WW3D2 Core library.
#include "d3d8.h"

typedef struct ID3DXMatrixStack : IUnknown {
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID,void**) = 0;
    virtual ULONG   STDMETHODCALLTYPE AddRef() = 0;
    virtual ULONG   STDMETHODCALLTYPE Release() = 0;
    virtual HRESULT STDMETHODCALLTYPE Push() = 0;
    virtual HRESULT STDMETHODCALLTYPE Pop() = 0;
    virtual HRESULT STDMETHODCALLTYPE LoadIdentity() = 0;
    virtual HRESULT STDMETHODCALLTYPE LoadMatrix(CONST D3DMATRIX*) = 0;
    virtual HRESULT STDMETHODCALLTYPE MultMatrix(CONST D3DMATRIX*) = 0;
    virtual HRESULT STDMETHODCALLTYPE ScaleLocal(float,float,float) = 0;
    virtual HRESULT STDMETHODCALLTYPE TranslateLocal(float,float,float) = 0;
    virtual HRESULT STDMETHODCALLTYPE Scale(float,float,float) = 0;
    virtual HRESULT STDMETHODCALLTYPE Translate(float,float,float) = 0;
    virtual HRESULT STDMETHODCALLTYPE RotateYPR(float,float,float) = 0;
    virtual HRESULT STDMETHODCALLTYPE RotateAxisLocal(CONST D3DVECTOR*,float) = 0;
    virtual HRESULT STDMETHODCALLTYPE GetTop(D3DMATRIX*) = 0;
} ID3DXMatrixStack;
typedef ID3DXMatrixStack* LPD3DXMATRIXSTACK;

#endif // __D3DX8CORE_H__