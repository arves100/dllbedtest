/*
    Bedtest libraries for games
    Copyright © 2020 Arves100.

    Project: d3d9
    File: IDirect3DDevice9.hpp
    Desc: Implementation of IDirect3DDevice9 COM object
*/
#ifndef D3D9_IDIRECT3DDEVICE9_HPP
#define D3D9_IDIRECT3DDEVICE9_HPP
#pragma once

#define STDMETHOD_NV(method) COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE method // no virtual
#define STDMETHOD_NV_(ret, method) COM_DECLSPEC_NOTHROW ret STDMETHODCALLTYPE method
#define PUREIMPL(x, y) { return m_pOriginal->##x y ; }
#define PUREIMPL_(x) { return m_pOriginal->##x(); }
#define PUREIMPLN(x, y) { m_pOriginal->##x y ; }

class WDirect3DDevice9 : public IDirect3DDevice9
{
public:
    WDirect3DDevice9(IDirect3DDevice9* pOriginal);
    ~WDirect3DDevice9();

    /*** IUnknown methods ***/
    STDMETHOD_NV(QueryInterface)(REFIID riid, void** ppvObj) PUREIMPL(QueryInterface, (riid, ppvObj) )
    STDMETHOD_NV_(ULONG, AddRef)() PUREIMPL_(AddRef);
    STDMETHOD_NV_(ULONG, Release)() PUREIMPL_(Release);

    /*** Custom ***/
    COM_DECLSPEC_NOTHROW UINT STDMETHODCALLTYPE GetAvailableTextureMem();
    COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE GetDeviceCaps(D3DCAPS9* pCaps);

    /*** IDirect3DDevice9 methods ***/
    STDMETHOD_NV(TestCooperativeLevel)(THIS) PUREIMPL_(TestCooperativeLevel);
    //STDMETHOD_NV_(UINT, GetAvailableTextureMem)(THIS) PUREIMPL_(GetAvailableTextureMem);
    STDMETHOD_NV(EvictManagedResources)(THIS) PUREIMPL_(EvictManagedResources);
    STDMETHOD_NV(GetDirect3D)(THIS_ IDirect3D9** ppD3D9) PUREIMPL(GetDirect3D, (ppD3D9));
    //STDMETHOD_NV(GetDeviceCaps)(THIS_ D3DCAPS9* pCaps) PUREIMPL(GetDeviceCaps, (pCaps));
    STDMETHOD_NV(GetDisplayMode)(THIS_ UINT iSwapChain, D3DDISPLAYMODE* pMode) PUREIMPL(GetDisplayMode, (iSwapChain, pMode));
    STDMETHOD_NV(GetCreationParameters)(THIS_ D3DDEVICE_CREATION_PARAMETERS* pParameters) PUREIMPL(GetCreationParameters, (pParameters));
    STDMETHOD_NV(SetCursorProperties)(THIS_ UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap) PUREIMPL(SetCursorProperties, (XHotSpot, YHotSpot, pCursorBitmap));
    STDMETHOD_NV_(void, SetCursorPosition)(THIS_ int X, int Y, DWORD Flags) PUREIMPLN(SetCursorPosition, (X, Y, Flags));
    STDMETHOD_NV_(BOOL, ShowCursor)(THIS_ BOOL bShow) PUREIMPL(ShowCursor, (bShow));
    STDMETHOD_NV(CreateAdditionalSwapChain)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain) PUREIMPL(CreateAdditionalSwapChain, (pPresentationParameters, pSwapChain));
    STDMETHOD_NV(GetSwapChain)(THIS_ UINT iSwapChain, IDirect3DSwapChain9** pSwapChain) PUREIMPL(GetSwapChain, (iSwapChain, pSwapChain));
    STDMETHOD_NV_(UINT, GetNumberOfSwapChains)(THIS) PUREIMPL_(GetNumberOfSwapChains);
    STDMETHOD_NV(Reset)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters) PUREIMPL(Reset, (pPresentationParameters));
    STDMETHOD_NV(Present)(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion) PUREIMPL(Present, (pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion));
    STDMETHOD_NV(GetBackBuffer)(THIS_ UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer) PUREIMPL(GetBackBuffer, (iSwapChain, iBackBuffer, Type, ppBackBuffer));
    STDMETHOD_NV(GetRasterStatus)(THIS_ UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus) PUREIMPL(GetRasterStatus, (iSwapChain, pRasterStatus));
    STDMETHOD_NV(SetDialogBoxMode)(THIS_ BOOL bEnableDialogs) PUREIMPL(SetDialogBoxMode, (bEnableDialogs));
    STDMETHOD_NV_(void, SetGammaRamp)(THIS_ UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp) PUREIMPLN(SetGammaRamp, (iSwapChain, Flags, pRamp));
    STDMETHOD_NV_(void, GetGammaRamp)(THIS_ UINT iSwapChain, D3DGAMMARAMP* pRamp) PUREIMPLN(GetGammaRamp, (iSwapChain, pRamp));
    STDMETHOD_NV(CreateTexture)(THIS_ UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle) 
        PUREIMPL(CreateTexture, (Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle))
    STDMETHOD_NV(CreateVolumeTexture)(THIS_ UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
        PUREIMPL(CreateVolumeTexture, (Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle))
    STDMETHOD_NV(CreateCubeTexture)(THIS_ UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
        PUREIMPL(CreateCubeTexture, (EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle));
    STDMETHOD_NV(CreateVertexBuffer)(THIS_ UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
        PUREIMPL(CreateVertexBuffer, (Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle));
    STDMETHOD_NV(CreateIndexBuffer)(THIS_ UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
        PUREIMPL(CreateIndexBuffer, (Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle));
    STDMETHOD_NV(CreateRenderTarget)(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
        PUREIMPL(CreateRenderTarget, (Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle));
    STDMETHOD_NV(CreateDepthStencilSurface)(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
        PUREIMPL(CreateDepthStencilSurface, (Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle));
    STDMETHOD_NV(UpdateSurface)(THIS_ IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint)
        PUREIMPL(UpdateSurface, (pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint));
    STDMETHOD_NV(UpdateTexture)(THIS_ IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
        PUREIMPL(UpdateTexture, (pSourceTexture, pDestinationTexture));
    STDMETHOD_NV(GetRenderTargetData)(THIS_ IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
        PUREIMPL(GetRenderTargetData, (pRenderTarget, pDestSurface));
    STDMETHOD_NV(GetFrontBufferData)(THIS_ UINT iSwapChain, IDirect3DSurface9* pDestSurface)
        PUREIMPL(GetFrontBufferData, (iSwapChain, pDestSurface));
    STDMETHOD_NV(StretchRect)(THIS_ IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
        PUREIMPL(StretchRect, (pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter));
    STDMETHOD_NV(ColorFill)(THIS_ IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color) PUREIMPL(ColorFill, (pSurface, pRect, color));
    STDMETHOD_NV(CreateOffscreenPlainSurface)(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
        PUREIMPL(CreateOffscreenPlainSurface, (Width, Height, Format, Pool, ppSurface, pSharedHandle));
    STDMETHOD_NV(SetRenderTarget)(THIS_ DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget) PUREIMPL(SetRenderTarget, (RenderTargetIndex, pRenderTarget));
    STDMETHOD_NV(GetRenderTarget)(THIS_ DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget) PUREIMPL(GetRenderTarget, (RenderTargetIndex, ppRenderTarget));
    STDMETHOD_NV(SetDepthStencilSurface)(THIS_ IDirect3DSurface9* pNewZStencil) PUREIMPL(SetDepthStencilSurface, (pNewZStencil));
    STDMETHOD_NV(GetDepthStencilSurface)(THIS_ IDirect3DSurface9** ppZStencilSurface) PUREIMPL(GetDepthStencilSurface, (ppZStencilSurface));
    STDMETHOD_NV(BeginScene)(THIS) PUREIMPL_(BeginScene);
    STDMETHOD_NV(EndScene)(THIS) PUREIMPL_(EndScene);
    STDMETHOD_NV(Clear)(THIS_ DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil) PUREIMPL(Clear, (Count, pRects, Flags, Color, Z, Stencil));
    STDMETHOD_NV(SetTransform)(THIS_ D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix) PUREIMPL(SetTransform, (State, pMatrix));
    STDMETHOD_NV(GetTransform)(THIS_ D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix) PUREIMPL(GetTransform, (State, pMatrix));
    STDMETHOD_NV(MultiplyTransform)(THIS_ D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix) PUREIMPL(MultiplyTransform, (State, pMatrix));
    STDMETHOD_NV(SetViewport)(THIS_ CONST D3DVIEWPORT9* pViewport) PUREIMPL(SetViewport, (pViewport));
    STDMETHOD_NV(GetViewport)(THIS_ D3DVIEWPORT9* pViewport) PUREIMPL(GetViewport, (pViewport));
    STDMETHOD_NV(SetMaterial)(THIS_ CONST D3DMATERIAL9* pMaterial) PUREIMPL(SetMaterial, (pMaterial));
    STDMETHOD_NV(GetMaterial)(THIS_ D3DMATERIAL9* pMaterial) PUREIMPL(GetMaterial, (pMaterial));
    STDMETHOD_NV(SetLight)(THIS_ DWORD Index, CONST D3DLIGHT9* pLight) PUREIMPL(SetLight, (Index, pLight));
    STDMETHOD_NV(GetLight)(THIS_ DWORD Index, D3DLIGHT9* pLight) PUREIMPL(GetLight, (Index, pLight));
    STDMETHOD_NV(LightEnable)(THIS_ DWORD Index, BOOL Enable) PUREIMPL(LightEnable, (Index, Enable));
    STDMETHOD_NV(GetLightEnable)(THIS_ DWORD Index, BOOL* pEnable) PUREIMPL(GetLightEnable, (Index, pEnable));
    STDMETHOD_NV(SetClipPlane)(THIS_ DWORD Index, CONST float* pPlane) PUREIMPL(SetClipPlane, (Index, pPlane));
    STDMETHOD_NV(GetClipPlane)(THIS_ DWORD Index, float* pPlane) PUREIMPL(GetClipPlane, (Index, pPlane));
    STDMETHOD_NV(SetRenderState)(THIS_ D3DRENDERSTATETYPE State, DWORD Value) PUREIMPL(SetRenderState, (State, Value));
    STDMETHOD_NV(GetRenderState)(THIS_ D3DRENDERSTATETYPE State, DWORD* pValue) PUREIMPL(GetRenderState, (State, pValue));
    STDMETHOD_NV(CreateStateBlock)(THIS_ D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB) PUREIMPL(CreateStateBlock, (Type, ppSB));
    STDMETHOD_NV(BeginStateBlock)(THIS) PUREIMPL_(BeginStateBlock);
    STDMETHOD_NV(EndStateBlock)(THIS_ IDirect3DStateBlock9** ppSB) PUREIMPL(EndStateBlock, (ppSB));
    STDMETHOD_NV(SetClipStatus)(THIS_ CONST D3DCLIPSTATUS9* pClipStatus) PUREIMPL(SetClipStatus, (pClipStatus));
    STDMETHOD_NV(GetClipStatus)(THIS_ D3DCLIPSTATUS9* pClipStatus) PUREIMPL(GetClipStatus, (pClipStatus));
    STDMETHOD_NV(GetTexture)(THIS_ DWORD Stage, IDirect3DBaseTexture9** ppTexture) PUREIMPL(GetTexture, (Stage, ppTexture));
    STDMETHOD_NV(SetTexture)(THIS_ DWORD Stage, IDirect3DBaseTexture9* pTexture) PUREIMPL(SetTexture, (Stage, pTexture));
    STDMETHOD_NV(GetTextureStageState)(THIS_ DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue) PUREIMPL(GetTextureStageState, (Stage, Type, pValue));
    STDMETHOD_NV(SetTextureStageState)(THIS_ DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value) PUREIMPL(SetTextureStageState, (Stage, Type, Value));
    STDMETHOD_NV(GetSamplerState)(THIS_ DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue) PUREIMPL(GetSamplerState, (Sampler, Type, pValue));
    STDMETHOD_NV(SetSamplerState)(THIS_ DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value) PUREIMPL(SetSamplerState, (Sampler, Type, Value));
    STDMETHOD_NV(ValidateDevice)(THIS_ DWORD* pNumPasses) PUREIMPL(ValidateDevice, (pNumPasses));
    STDMETHOD_NV(SetPaletteEntries)(THIS_ UINT PaletteNumber, CONST PALETTEENTRY* pEntries) PUREIMPL(SetPaletteEntries, (PaletteNumber, pEntries));
    STDMETHOD_NV(GetPaletteEntries)(THIS_ UINT PaletteNumber, PALETTEENTRY* pEntries) PUREIMPL(GetPaletteEntries, (PaletteNumber, pEntries));
    STDMETHOD_NV(SetCurrentTexturePalette)(THIS_ UINT PaletteNumber) PUREIMPL(SetCurrentTexturePalette, (PaletteNumber));
    STDMETHOD_NV(GetCurrentTexturePalette)(THIS_ UINT* PaletteNumber) PUREIMPL(GetCurrentTexturePalette, (PaletteNumber));
    STDMETHOD_NV(SetScissorRect)(THIS_ CONST RECT* pRect) PUREIMPL(SetScissorRect, (pRect));
    STDMETHOD_NV(GetScissorRect)(THIS_ RECT* pRect) PUREIMPL(GetScissorRect, (pRect));
    STDMETHOD_NV(SetSoftwareVertexProcessing)(THIS_ BOOL bSoftware) PUREIMPL(SetSoftwareVertexProcessing, (bSoftware));
    STDMETHOD_NV_(BOOL, GetSoftwareVertexProcessing)(THIS) PUREIMPL_(GetSoftwareVertexProcessing);
    STDMETHOD_NV(SetNPatchMode)(THIS_ float nSegments) PUREIMPL(SetNPatchMode, (nSegments));
    STDMETHOD_NV_(float, GetNPatchMode)(THIS) PUREIMPL_(GetNPatchMode);
    STDMETHOD_NV(DrawPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
        PUREIMPL(DrawPrimitive, (PrimitiveType, StartVertex, PrimitiveCount));
    STDMETHOD_NV(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
        PUREIMPL(DrawIndexedPrimitive, (PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount));
    STDMETHOD_NV(DrawPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
        PUREIMPL(DrawPrimitiveUP, (PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride));
    STDMETHOD_NV(DrawIndexedPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
        PUREIMPL(DrawIndexedPrimitiveUP, (PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride));
    STDMETHOD_NV(ProcessVertices)(THIS_ UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
        PUREIMPL(ProcessVertices, (SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags));
    STDMETHOD_NV(CreateVertexDeclaration)(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
        PUREIMPL(CreateVertexDeclaration, (pVertexElements, ppDecl));
    STDMETHOD_NV(SetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9* pDecl) PUREIMPL(SetVertexDeclaration, (pDecl));
    STDMETHOD_NV(GetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9** ppDecl) PUREIMPL(GetVertexDeclaration, (ppDecl));
    STDMETHOD_NV(SetFVF)(THIS_ DWORD FVF) PUREIMPL(SetFVF, (FVF));
    STDMETHOD_NV(GetFVF)(THIS_ DWORD* pFVF) PUREIMPL(GetFVF, (pFVF));
    STDMETHOD_NV(CreateVertexShader)(THIS_ CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader) PUREIMPL(CreateVertexShader, (pFunction, ppShader));
    STDMETHOD_NV(SetVertexShader)(THIS_ IDirect3DVertexShader9* pShader) PUREIMPL(SetVertexShader, (pShader));
    STDMETHOD_NV(GetVertexShader)(THIS_ IDirect3DVertexShader9** ppShader) PUREIMPL(GetVertexShader, (ppShader));
    STDMETHOD_NV(SetVertexShaderConstantF)(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount) 
        PUREIMPL(SetVertexShaderConstantF, (StartRegister, pConstantData, Vector4fCount));
    STDMETHOD_NV(GetVertexShaderConstantF)(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount)
        PUREIMPL(GetVertexShaderConstantF, (StartRegister, pConstantData, Vector4fCount));
    STDMETHOD_NV(SetVertexShaderConstantI)(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
        PUREIMPL(SetVertexShaderConstantI, (StartRegister, pConstantData, Vector4iCount));
    STDMETHOD_NV(GetVertexShaderConstantI)(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount)
        PUREIMPL(GetVertexShaderConstantI, (StartRegister, pConstantData, Vector4iCount));
    STDMETHOD_NV(SetVertexShaderConstantB)(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount)
        PUREIMPL(SetVertexShaderConstantB, (StartRegister, pConstantData, BoolCount));
    STDMETHOD_NV(GetVertexShaderConstantB)(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
        PUREIMPL(GetVertexShaderConstantB, (StartRegister, pConstantData, BoolCount));
    STDMETHOD_NV(SetStreamSource)(THIS_ UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride) 
        PUREIMPL(SetStreamSource, (StreamNumber, pStreamData, OffsetInBytes, Stride));
    STDMETHOD_NV(GetStreamSource)(THIS_ UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride)
        PUREIMPL(GetStreamSource, (StreamNumber, ppStreamData, pOffsetInBytes, pStride));
    STDMETHOD_NV(SetStreamSourceFreq)(THIS_ UINT StreamNumber, UINT Setting)
        PUREIMPL(SetStreamSourceFreq, (StreamNumber, Setting));
    STDMETHOD_NV(GetStreamSourceFreq)(THIS_ UINT StreamNumber, UINT* pSetting) PUREIMPL(GetStreamSourceFreq, (StreamNumber, pSetting));
    STDMETHOD_NV(SetIndices)(THIS_ IDirect3DIndexBuffer9* pIndexData) PUREIMPL(SetIndices, (pIndexData));
    STDMETHOD_NV(GetIndices)(THIS_ IDirect3DIndexBuffer9** ppIndexData) PUREIMPL(GetIndices, (ppIndexData));
    STDMETHOD_NV(CreatePixelShader)(THIS_ CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader) PUREIMPL(CreatePixelShader, (pFunction, ppShader));
    STDMETHOD_NV(SetPixelShader)(THIS_ IDirect3DPixelShader9* pShader) PUREIMPL(SetPixelShader, (pShader));
    STDMETHOD_NV(GetPixelShader)(THIS_ IDirect3DPixelShader9** ppShader) PUREIMPL(GetPixelShader, (ppShader));
    STDMETHOD_NV(SetPixelShaderConstantF)(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
        PUREIMPL(SetPixelShaderConstantF, (StartRegister, pConstantData, Vector4fCount));
    STDMETHOD_NV(GetPixelShaderConstantF)(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount)
        PUREIMPL(GetPixelShaderConstantF, (StartRegister, pConstantData, Vector4fCount));
    STDMETHOD_NV(SetPixelShaderConstantI)(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
        PUREIMPL(SetPixelShaderConstantI, (StartRegister, pConstantData, Vector4iCount));
    STDMETHOD_NV(GetPixelShaderConstantI)(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount)
        PUREIMPL(GetPixelShaderConstantI, (StartRegister, pConstantData, Vector4iCount));
    STDMETHOD_NV(SetPixelShaderConstantB)(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount)
        PUREIMPL(SetPixelShaderConstantB, (StartRegister, pConstantData, BoolCount));
    STDMETHOD_NV(GetPixelShaderConstantB)(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
        PUREIMPL(GetPixelShaderConstantB, (StartRegister, pConstantData, BoolCount));
    STDMETHOD_NV(DrawRectPatch)(THIS_ UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo)
        PUREIMPL(DrawRectPatch, (Handle, pNumSegs, pRectPatchInfo));
    STDMETHOD_NV(DrawTriPatch)(THIS_ UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo)
        PUREIMPL(DrawTriPatch, (Handle, pNumSegs, pTriPatchInfo));
    STDMETHOD_NV(DeletePatch)(THIS_ UINT Handle) PUREIMPL(DeletePatch, (Handle));
    STDMETHOD_NV(CreateQuery)(THIS_ D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery) PUREIMPL(CreateQuery, (Type, ppQuery));

private:
    IDirect3DDevice9* m_pOriginal;
};

#endif // D3D9_IDIRECT3DDEVICE9_HPP
