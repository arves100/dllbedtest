/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Steam_API
	File: Steam_API.cpp
	Desc: Steam API dll implementation
*/
#include "StdAfx.h"
#include "../Common/Cache.hpp"

S_API bool S_CALLTYPE SteamAPI_RestartAppIfNecessary(uint32 unOwnAppID)
{
	Callback_RestartAppIfNecessary cb = reinterpret_cast<Callback_RestartAppIfNecessary>(CCache::Instance()->GetElement(ID_CACHE_FARPROCS, ID_CALLBACK_RESTART));
	
	if (!cb)
	{
		spdlog::critical("Cannot get SteamAPI_RestartAppIfNecessary callback from cache");
		return false;
	}

	return cb(unOwnAppID);
}

S_API bool S_CALLTYPE SteamAPI_Init()
{
	Callback_Init cb = reinterpret_cast<Callback_Init>(CCache::Instance()->GetElement(ID_CACHE_FARPROCS, ID_CALLBACK_INIT));
	
	if (!cb)
	{
		spdlog::critical("Cannot get SteamAPI_Init callback from cache");
		return false;
	}

	return cb();
}

S_API void* S_CALLTYPE SteamApps()
{
	Callback_SteamApps cb = reinterpret_cast<Callback_SteamApps>(CCache::Instance()->GetElement(ID_CACHE_FARPROCS, ID_CALLBACK_STEAMAPPS));

	if (!cb)
	{
		spdlog::critical("Cannot get SteamApps callback from cache");
		return nullptr;
	}

	return cb();
}
