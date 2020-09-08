/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: GameHooks
	File: GameHooks.cpp
	Desc: Detour bootup and shutdown for GameHooks
*/
#include "StdAfx.h"
#include "../Common/DetoursApi.h"
#include "GameHooks.hpp"

DAPIFUNC_START

// Users32
DAPIFUNC_ADD(CreateWindowExA)
DAPIFUNC_ADD(RegisterClassA)
DAPIFUNC_ADD(SendMessageA)
DAPIFUNC_ADD(SetWindowPos)
DAPIFUNC_ADD(SetWindowLongA)
DAPIFUNC_ADD(SetWindowPlacement)
DAPIFUNC_ADD(ShowWindow)
DAPIFUNC_ADD(EnableWindow)
DAPIFUNC_ADD(MoveWindow)
DAPIFUNC_ADD(LockWindowUpdate)
DAPIFUNC_ADD(AdjustWindowRectEx)

// Kernel32
DAPIFUNC_ADD(LoadLibraryA)

// ws2_32
DAPIFUNC_ADD(socket)
DAPIFUNC_ADD(connect)

DAPIFUNC_END
#define DAPIFUNC_COUNT 14

BOOL SetupGameHooks()
{
	return DAPI_Begin(s_psDetourFuncs, DAPIFUNC_COUNT);
}

BOOL DestroyGameHooks()
{
	return DAPI_End(s_psDetourFuncs, DAPIFUNC_COUNT);
}
