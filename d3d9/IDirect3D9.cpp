/*
    Bedtest libraries for games
    Copyright © 2020 Arves100.

    Project: d3d9
    File: IDirect3D9.cpp
    Desc: Implementation of IDirect3DDevice9 COM object
*/
#include "StdAfx.h"
#include "IDirect3D9.hpp"
#include "IDirect3DDevice9.hpp"

/*
    TODO: COM is not implemented due to my failure in figuring out the correct way
    of making a COM object.

    This is primary a fast hack developed for messing around with DirectX 9, nothing
    that could be used in real production.
*/



#if 0
static WDirect3D9* g_wD3D = nullptr;
static bool bNoDelete = false;
#endif

WDirect3D9::WDirect3D9(IDirect3D9* pOriginal)
	: m_pOriginal(pOriginal), m_pDevice(nullptr)
{
#if 0
    if (g_wD3D)
    {
        MessageBox(nullptr, _T("Bad code error\nAfter OK the program will crash."), _T(".,,,.,.."), MB_OK | MB_ICONERROR);

        // Simulate crash!
        int* a = (int*)0;
        *a = 45;
    }


    g_wD3D = this;
    bNoDelete = false;
#endif
}

WDirect3D9::~WDirect3D9()
{
    if (m_pDevice)
        m_pDevice->Release();

    m_pOriginal->Release();

    m_pDevice = nullptr;
    m_pOriginal = nullptr;

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

/*** IUnknown methods ***/
COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::QueryInterface(REFIID riid, void** ppvObj)
{
	return m_pOriginal->QueryInterface(riid, ppvObj);
}

COM_DECLSPEC_NOTHROW ULONG STDMETHODCALLTYPE WDirect3D9::AddRef()
{
	return m_pOriginal->AddRef();
}

COM_DECLSPEC_NOTHROW ULONG STDMETHODCALLTYPE WDirect3D9::Release()
{
    // todo: make the fake release use COM like it should
	return m_pOriginal->Release();
}

/*** IDirect3D9 methods ***/
COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::RegisterSoftwareDevice(void* pInitializeFunction)
{
	return m_pOriginal->RegisterSoftwareDevice(pInitializeFunction);
}

COM_DECLSPEC_NOTHROW UINT STDMETHODCALLTYPE WDirect3D9::GetAdapterCount()
{
//#if IS_TMN
	return 1; // Hook: force one adapter
/*#else
    return m_pOriginal->GetAdapterCount();
#endif*/
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    if (!pIdentifier)
        return E_INVALIDARG;

    D3DADAPTER_IDENTIFIER9 idi;
    HRESULT hr = m_pOriginal->GetAdapterIdentifier(Adapter, Flags, &idi);

    if (FAILED(hr))
        return hr;

    strncpy_s(pIdentifier->Driver, _countof(pIdentifier->Driver), "BedTest libraries", MAX_DEVICE_IDENTIFIER_STRING);
    strncpy_s(pIdentifier->Description, _countof(pIdentifier->Description), "D3D9 Hookpoint for games", MAX_DEVICE_IDENTIFIER_STRING);
    strncpy_s(pIdentifier->DeviceName, _countof(pIdentifier->DeviceName), idi.DeviceName, 32);
    pIdentifier->DriverVersion.QuadPart = 0x000000000000000A;
    pIdentifier->VendorId = 0;
    pIdentifier->DeviceId = idi.DeviceId;
    pIdentifier->Revision = APP_VERSION;
    pIdentifier->DeviceIdentifier = IID_BEDTEST_D3D9;
    pIdentifier->WHQLLevel = idi.WHQLLevel;

    return S_OK;
}

COM_DECLSPEC_NOTHROW UINT STDMETHODCALLTYPE WDirect3D9::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    return m_pOriginal->GetAdapterModeCount(Adapter, Format);
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    return m_pOriginal->EnumAdapterModes(Adapter, Format, Mode, pMode);
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    return m_pOriginal->GetAdapterDisplayMode(Adapter, pMode);
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::CheckDeviceType(UINT Adapter, D3DDEVTYPE DevType, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed)
{
    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    return m_pOriginal->CheckDeviceType(Adapter, DevType, AdapterFormat, BackBufferFormat, bWindowed);
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    return m_pOriginal->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    return m_pOriginal->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    return m_pOriginal->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    return m_pOriginal->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    HRESULT hr = m_pOriginal->GetDeviceCaps(Adapter, DeviceType, pCaps);

    if (FAILED(hr))
        return hr;

    return S_OK;
}

COM_DECLSPEC_NOTHROW HMONITOR STDMETHODCALLTYPE WDirect3D9::GetAdapterMonitor(UINT Adapter)
{
    if (Adapter != 0)
        return nullptr;

    return m_pOriginal->GetAdapterMonitor(Adapter);
}

COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE WDirect3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
    spdlog::info("CreateDevice called");

    if (Adapter != 0)
        return D3DERR_INVALIDCALL;

    if (!ppReturnedDeviceInterface)
        return E_INVALIDARG;

    if (m_pDevice)
    {
        *ppReturnedDeviceInterface = m_pDevice;
        return S_OK;
    }

    IDirect3DDevice9* pOriginalDev = nullptr;

#if IS_WA
	//pPresentationParameters->BackBufferWidth = 800;
	//pPresentationParameters->BackBufferHeight = 600;
	pPresentationParameters->Windowed = TRUE;
    //pPresentationParameters->BackBufferFormat = D3DFMT_X8R8G8B8;
    //pPresentationParameters->BackBufferCount = 1;
    pPresentationParameters->FullScreen_RefreshRateInHz = 0;
    //pPresentationParameters->SwapEffect = D3DSWAPEFFECT_DISCARD;
#endif

   

    HRESULT hr = m_pOriginal->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, &pOriginalDev);

    if (FAILED(hr))
        return hr;

    m_pDevice = new WDirect3DDevice9(pOriginalDev);

    *ppReturnedDeviceInterface = m_pDevice;

    return S_OK;
}
