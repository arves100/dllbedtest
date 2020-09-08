/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Common
	File: DetoursApi.cpp
	Desc: Implements simplified functions for Detours
*/
#include "StdAfx.h"
#include "DetoursApi.h"

#include <detours/detours.h>

BOOL DAPI_Begin(PTDetourFunc func, size_t size)
{
	DetourRestoreAfterWith();
	
#if 0
	if (!DetourTransactionBegin())
	{
		spdlog::critical("Cannot initiate detours start transaction");
		return FALSE;
	}
#else
	DetourTransactionBegin();
#endif

	for (size_t i = 0; i < size; i++)
	{
		spdlog::info("Attaching {}", func[i].szName);
		DetourAttach(func[i].pSrc, func[i].pDetour);
	}

	DetourTransactionCommit();

	spdlog::info("Detours start transaction committed");

	return TRUE;
}

BOOL DAPI_End(PTDetourFunc func, size_t size)
{
#if 0
	if (!DetourTransactionBegin())
	{
		spdlog::critical("Cannot initiate detours end transaction");
		return FALSE;
	}
#else
	DetourTransactionBegin();
#endif

	DetourUpdateThread(GetCurrentThread());

	for (size_t i = 0; i < size; i++)
	{
		spdlog::info("Detaching {}", func[i].szName);
		DetourDetach(func[i].pSrc, func[i].pDetour);
	}

	DetourTransactionCommit();

	spdlog::info("Detours end transaction committed");

	return TRUE;
}
