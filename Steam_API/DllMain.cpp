/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Steam_API
	File: DllMain.cpp
	Desc: DLL entrypoint

	Entrypoint used by:
		- Worms: Armageddon
*/
#include "StdAfx.h"

#include "../GameHooks/GameHooks.hpp"
#include "../Common/Cache.hpp"

static BOOL DllAttach()
{
	LOG_Start("Steam_API");

	// Open Steam_API library

	HMODULE hOriginal = LoadLibrary(_T("oem\\Steam_API.dll"));

	if (!hOriginal)
	{
		spdlog::critical("Unable to open Steam_API original library! Win32 native error: {}", GetLastError());
		return FALSE;
	}

	// Get required FarProcs

	FARPROC fpInit = GetProcAddress(hOriginal, "SteamAPI_Init");
	FARPROC fpApps = GetProcAddress(hOriginal, "SteamApps");
	FARPROC fpRestart = GetProcAddress(hOriginal, "SteamAPI_RestartAppIfNecessary");

	if (!fpInit || !fpApps || !fpRestart)
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
	cFPE->Add(ID_CALLBACK_RESTART, fpRestart);
	cFPE->Add(ID_CALLBACK_STEAMAPPS, fpApps);

	CCache::Instance()->Add(ID_CACHE_FARPROCS, cFPE);

	// Initialize Detours (Hookpoint for WA)

	spdlog::info("Successfully loaded original procedures!");

	return SetupGameHooks();
}

static BOOL DllDetach()
{
	return DestroyGameHooks();
}

DLLMAIN(DllAttach, DllDetach)
