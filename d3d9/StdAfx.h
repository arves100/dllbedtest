/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: d3d9
	File: StdAfx.h
	Desc: Precompiled header for the library
*/
#pragma once

#include "../Common/StdAfx.h"

#include <d3d9.h>

typedef IDirect3D9* (WINAPI* Direct3DCreate9Callback)(UINT SDKVersion);
typedef void (WINAPI* D3DPERF_SetOptionsCallback)(DWORD options);

enum : uint64_t
{
	ID_CACHE_LIBRARY = 1,
	ID_CACHE_FARPROCS,

	ID_LIBRARY = 1,

	ID_CALLBACK_CREATE = 1,
};

/* {b05827c8-f000-49b1-8abb-7b9cf96f487a} */
const GUID IID_BEDTEST_D3D9 = {
	0xb05827c8, 0xf000, 0x49b1, 0x8a, 0xbb, 0x7b, 0x9c, 0xf9, 0x6f, 0x48, 0x7a
};
