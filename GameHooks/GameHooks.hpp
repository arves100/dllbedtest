/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: GameHooks
	File: GameHooks.hpp
	Desc: GameHooks common definitions
*/
#ifndef GAMEHOOKS_GAMEHOOKS_HPP
#define GAMEHOOKS_GAMEHOOKS_HPP
#pragma once

#ifdef DAPIFUNC_DEF
#undef DAPIFUNC_DEF
#endif

#include "GameHooksDefs.h"

#define DAPIFUNC_DEF(name, ret, calltype, args) static ret (calltype * True##name) args = name; extern ret calltype My##name args;
#define DAPIFUNC_IMP(name, ret, calltype, args) ret calltype My##name args

// User32
DAPIFUNC_DEF(RegisterClassA, ATOM, WINAPI, (const WNDCLASSA* lpWndClass));
DAPIFUNC_DEF(CreateWindowExA, HWND, WINAPI, (DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam))
DAPIFUNC_DEF(SendMessageA, LRESULT, WINAPI, (HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam));
DAPIFUNC_DEF(SetWindowPos, BOOL, WINAPI, (HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags));
DAPIFUNC_DEF(SetWindowLongA, LONG, WINAPI, (HWND hWnd, int nIndex, LONG dwNewLong));
DAPIFUNC_DEF(SetWindowPlacement, BOOL, WINAPI, (HWND hWnd, const WINDOWPLACEMENT* lpwndpl));
DAPIFUNC_DEF(ShowWindow, BOOL, WINAPI, (HWND hWnd, int nCmdShow));
DAPIFUNC_DEF(EnableWindow, BOOL, WINAPI, (HWND hWnd, BOOL bEnable));
DAPIFUNC_DEF(MoveWindow, BOOL, WINAPI, (HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint));
DAPIFUNC_DEF(LockWindowUpdate, BOOL, WINAPI, (HWND hWndLock));
DAPIFUNC_DEF(AdjustWindowRectEx, BOOL, WINAPI, (LPRECT lpRect, DWORD dwStyle, BOOL bMenu, DWORD dwExStyle));

// Kernel32
DAPIFUNC_DEF(LoadLibraryA, HMODULE, WINAPI, (LPCSTR lpLibFileName));

// WinSock2
DAPIFUNC_DEF(socket, SOCKET, WSAAPI, (int af, int type, int protocol));

// GameHooks init
extern BOOL SetupGameHooks();
extern BOOL DestroyGameHooks();

#endif // GAMEHOOKS_GAMEHOOKS_HPP
