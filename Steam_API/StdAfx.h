/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Steam_API
	File: StdAfx.h
	Desc: Precompiled header for the library
*/
#ifndef STEAM_API_STDAFX_H
#define STEAM_API_STDAFX_H
#pragma once

#include "../GameHooks/StdAfx.h"

// STEAM API Documentation: https://partner.steamgames.com/doc/api

typedef uint32_t uint32;

#define S_CALLTYPE CALLBACK
#define S_API EXTERN_C

typedef bool (S_CALLTYPE* Callback_RestartAppIfNecessary)(uint32 unOwnAppID);
typedef bool (S_CALLTYPE* Callback_Init)();
typedef void* (S_CALLTYPE* Callback_SteamApps)();

enum : uint64_t
{
	ID_CACHE_LIBRARY = 1,
	ID_CACHE_FARPROCS,

	ID_LIBRARY = 1,

	ID_CALLBACK_INIT = 1,
	ID_CALLBACK_STEAMAPPS,
	ID_CALLBACK_RESTART,
};

#endif // STEAM_API_STDAFX_H
