/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: d3d9
	File: DllMain.cpp
	Desc: DLL entrypoint

	Entrypoint used by:
		- Worms: Armageddon (as d3dk.dll)
		- Trackmania Nations
*/
#include "StdAfx.h"

#include "../Common/DetoursApi.h"
#include "../Common/Cache.hpp"

static BOOL DllAttach()
{
	LOG_Start("d3d9");

	// Open d3d9 library

	HMODULE hOriginalDLL = LoadLibrary(_T("oem\\d3d9.dll"));

	if (!hOriginalDLL)
	{
		spdlog::critical("Unable to open d3d9 original library! Win32 native error: {}", GetLastError());
		return FALSE;
	}

	FARPROC fpCreate9 = GetProcAddress(hOriginalDLL, "Direct3DCreate9");

	if (!fpCreate9)
	{
		spdlog::critical("Cannot get required procedure address! Invalid DLL?");
		FreeLibrary(hOriginalDLL);
		return FALSE;
	}

	// Store the library inside the cache

	CLibraryElement* cLE = new CLibraryElement();
	cLE->Add(ID_LIBRARY, hOriginalDLL);

	CCache::Instance()->Add(ID_CACHE_LIBRARY, cLE);

	// Store FARPROCs in the cache

	CElement* cFPE = new CElement();
	cFPE->Add(ID_CALLBACK_CREATE, fpCreate9);

	CCache::Instance()->Add(ID_CACHE_FARPROCS, cFPE);

	spdlog::info("Successfully loaded original procedures!");

	return TRUE;
}

static BOOL DllDetach()
{
	return TRUE;
}

DLLMAIN(DllAttach, DllDetach)
