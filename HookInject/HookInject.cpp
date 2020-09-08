/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: HookInject
	File: HookInject.cpp
	Desc: Simple DLL to inject for enabling GameHooks
*/
#include "../GameHooks/StdAfx.h"
#include "../GameHooks/GameHooks.hpp"

static BOOL DllAttach()
{
	LOG_Start("HookInject");

	return SetupGameHooks();
}

static BOOL DllDetach()
{
	return DestroyGameHooks();
}

DLLMAIN(DllAttach, DllDetach)
