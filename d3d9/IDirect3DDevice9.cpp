/*
    Bedtest libraries for games
    Copyright © 2020 Arves100.

    Project: d3d9
    File: IDirect3DDevice9.cpp
    Desc: Implementation of IDirect3DDevice9 COM object
*/
#include "StdAfx.h"
#include "IDirect3DDevice9.hpp"

#if 0
static WDirect3DDevice9* g_wD3D = nullptr;
static bool bNoDelete = false;
#endif

WDirect3DDevice9::WDirect3DDevice9(IDirect3DDevice9* pOriginal) :
	m_pOriginal(pOriginal)
{
#if 0
    if (g_wD3D)
    {
        MessageBox(nullptr, _T("Bad code error #2\nAfter OK the program will crash."), _T(".,,,.,.."), MB_OK | MB_ICONERROR);

        // Simulate crash!
        int* a = (int*)0;
        *a = 45;
    }

    g_wD3D = this;
    bNoDelete = false;
#endif
}

WDirect3DDevice9::~WDirect3DDevice9()
{
	if (m_pOriginal)
		m_pOriginal->Release();

#if 0
    // todo: this is crap, please find a real way to use COM
    if (g_wD3D && bNoDelete)
    {
        delete g_wD3D;
        g_wD3D = nullptr;
        bNoDelete = true;
    }
#endif
}

COM_DECLSPEC_NOTHROW UINT STDMETHODCALLTYPE WDirect3DDevice9::GetAvailableTextureMem()
{
#if IS_TMN
    return 800;
#else
    return m_pOriginal->GetAvailableTextureMem();
#endif
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3DDevice9::GetDeviceCaps(D3DCAPS9* pCaps)
{
    HRESULT hr = m_pOriginal->GetDeviceCaps(pCaps);

    if (FAILED(hr))
        return hr;
    

    return S_OK;
}