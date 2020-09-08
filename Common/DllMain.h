/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Common
	File: DllMain.h
	Desc: Simple DLLMain declaration
*/
#ifndef COMMON_DLLMAIN_H
#define COMMON_DLLMAIN_H
#pragma once

#define DLLMAIN(attach, detach) BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved) \
{ \
	switch (fdwReason) \
	{ \
	case DLL_PROCESS_ATTACH: \
		return attach(); \
	case DLL_PROCESS_DETACH: \
		return detach(); \
	default: \
		break; \
	} \
	return TRUE; \
}

#endif // COMMON_DLLMAIN_H
