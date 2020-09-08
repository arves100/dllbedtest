/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: XAPOFX1_5
	File: XAPOFX1_5.cpp
	Desc: DLL entrypoint

	Entrypoint used by:
		- Blue Protocol
*/
#include "../GameHooks/StdAfx.h"
#include <xapofx.h>

#include "../GameHooks/GameHooks.hpp"
#include "../Common/Cache.hpp"

enum : uint64_t
{
	ID_CACHE_LIBRARY = 1,
	ID_CACHE_FARPROCS,

	ID_LIBRARY = 1,

	ID_CALLBACK_INIT = 1,
};

static BOOL DllAttach()
{
	LOG_Start("XAPOFX1_5");

	// Open Steam_API library

	HMODULE hOriginal = LoadLibrary(_T("oem\\XAPOFX1_5.dll"));

	if (!hOriginal)
	{
		spdlog::critical("Unable to open XAPOFX1_5 original library! Win32 native error: {}", GetLastError());
		return FALSE;
	}

	// Get required FarProcs

	FARPROC fpInit = GetProcAddress(hOriginal, "CreateFX");

	if (!fpInit)
	{
		spdlog::critical("Cannot get required procedure address! Invalid DLL?");
		FreeLibrary(hOriginal);
		return FALSE;
	}

	// Store the library inside the cache

	CLibraryElement* cLE = new CLibraryElement();
	cLE->Add(ID_LIBRARY, hOriginal);

	CCache::Instance()->Add(ID_CACHE_LIBRARY, cLE);

	// Store FARPROCs in the cache

	CElement* cFPE = new CElement();
	cFPE->Add(ID_CALLBACK_INIT, fpInit);

	CCache::Instance()->Add(ID_CACHE_FARPROCS, cFPE);

	// Initialize Detours

	spdlog::info("Successfully loaded original procedures!");

	return SetupGameHooks();
}

static BOOL DllDetach()
{
	return DestroyGameHooks();
}

DLLMAIN(DllAttach, DllDetach)

typedef HRESULT (__cdecl * CreateFX_Callback)(
	REFCLSID                clsid,
	IUnknown** pEffect,
	const void* pInitDat,
	UINT32 InitDataByteSize
);

extern "C" FX_API_(HRESULT) CreateFX(
	REFCLSID                clsid,
	IUnknown * *pEffect,
	const void* pInitDat,
	UINT32 InitDataByteSize
)
{
	CreateFX_Callback cb = reinterpret_cast<CreateFX_Callback>(CCache::Instance()->GetElement(ID_CACHE_FARPROCS, ID_CALLBACK_INIT));

	if (!cb)
	{
		spdlog::critical("Cannot get CreateFX callback from cache");
		return false;
	}

	return cb(clsid, pEffect, pInitDat, InitDataByteSize);
}
