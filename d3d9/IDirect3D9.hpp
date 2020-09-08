/*
    Bedtest libraries for games
    Copyright © 2020 Arves100.

    Project: d3d9
    File: IDirect3D9.hpp
    Desc: Implementation of IDirect3DDevice9 COM object
*/
#ifndef D3D9_IDIRECT3D9_HPP
#define D3D9_IDIRECT3D9_HPP
#pragma once

class WDirect3D9 : public IDirect3D9
{
public:
    WDirect3D9(IDirect3D9* pOriginal);
    ~WDirect3D9();

    /*** IUnknown methods ***/
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObj);
    COM_DECLSPEC_NOTHROW ULONG STDMETHODCALLTYPE AddRef();
    COM_DECLSPEC_NOTHROW ULONG STDMETHODCALLTYPE Release();

    /*** IDirect3D9 methods ***/
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE RegisterSoftwareDevice(void* pInitializeFunction);
    COM_DECLSPEC_NOTHROW UINT STDMETHODCALLTYPE GetAdapterCount();
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9 * pIdentifier);
    COM_DECLSPEC_NOTHROW UINT STDMETHODCALLTYPE GetAdapterModeCount(UINT Adapter, D3DFORMAT Format);
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE * pMode);
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE * pMode);
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE CheckDeviceType(UINT Adapter, D3DDEVTYPE DevType, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed);
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat);
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD * pQualityLevels);
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat);
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat);
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps);
    COM_DECLSPEC_NOTHROW HMONITOR STDMETHODCALLTYPE GetAdapterMonitor(UINT Adapter);
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS * pPresentationParameters, IDirect3DDevice9 * *ppReturnedDeviceInterface);

private:
    IDirect3D9* m_pOriginal;
    IDirect3DDevice9* m_pDevice;
};

#endif // D3D9_IDIRECT3D9_HPP
