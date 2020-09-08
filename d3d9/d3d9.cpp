/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: d3d9
	File: d3d9.cpp
	Desc: Implementation of Direct3D9 library
*/
#include "StdAfx.h"
#include "IDirect3D9.hpp"

#include "../Common/Cache.hpp"

EXTERN_C IDirect3D9* WINAPI Direct3DCreate9(
	UINT SDKVersion
)
{
	Direct3DCreate9Callback cb = reinterpret_cast<Direct3DCreate9Callback>(CCache::Instance()->GetElement(ID_CACHE_FARPROCS, ID_CALLBACK_CREATE));

	if (!cb)
	{
		spdlog::critical("Cannot get Direct3DCreate9 callback");
		return nullptr;
	}

	IDirect3D9* pOriginal = cb(SDKVersion);

	if (!pOriginal)
	{
		spdlog::error("Direct3DCreate9 original call failed");
		return nullptr;
	}

	spdlog::info("Direct3DCreate9 called");

	return new WDirect3D9(pOriginal);
}

EXTERN_C void WINAPI D3DPERF_SetOptions(
	DWORD options
)
{
	// Stub
	spdlog::info("D3DPERF_SetOptions stub {}", options);
}
