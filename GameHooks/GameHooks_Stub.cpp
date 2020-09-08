/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: GameHooks
	File: GameHooks_Stub.cpp
	Desc: Stub implementations of Detours functions
*/
#include "StdAfx.h"
#include "GameHooks.hpp"

#if !IS_WA

DAPIFUNC_IMP(LockWindowUpdate, BOOL, WINAPI, (HWND hWndLock))
{
	return TrueLockWindowUpdate(hWndLock);
}

DAPIFUNC_IMP(EnableWindow, BOOL, WINAPI, (
	HWND hWnd, BOOL bEnable))
{
	return TrueEnableWindow(hWnd, bEnable);
}

DAPIFUNC_IMP(CreateWindowExA, HWND, WINAPI, (DWORD dwExStyle,
	LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle,
	int X, int Y, int nWidth, int nHeight, HWND hWndParent,
	HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam))
{
	return TrueCreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y,
		nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

DAPIFUNC_IMP(RegisterClassA, ATOM, WINAPI, (const WNDCLASSA* lpWndClass))
{
	return TrueRegisterClassA(lpWndClass);
}

DAPIFUNC_IMP(MoveWindow, BOOL, WINAPI, (HWND hWnd, int X, int Y,
	int nWidth, int nHeight, BOOL bRepaint))
{
	return TrueMoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint);
}

DAPIFUNC_IMP(SetWindowPos, BOOL, WINAPI, (HWND hWnd, HWND hWndInsertAfter,
	int X, int Y, int cx, int cy, UINT uFlags))
{
	return TrueSetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags);
}

DAPIFUNC_IMP(SetWindowLongA, LONG, WINAPI, (HWND hWnd, int nIndex,
	LONG dwNewLong))
{
	return TrueSetWindowLongA(hWnd, nIndex, dwNewLong);
}

DAPIFUNC_IMP(LoadLibraryA, HMODULE, WINAPI, (LPCSTR lpLibFileName))
{
	return TrueLoadLibraryA(lpLibFileName);
}

DAPIFUNC_IMP(AdjustWindowRectEx, BOOL, WINAPI, (LPRECT lpRect, DWORD dwStyle,
	BOOL bMenu, DWORD dwExStyle))
{
	return TrueAdjustWindowRectEx(lpRect, dwStyle, hMenu, dwExStyle);
}

DAPIFUNC_IMP(SetWindowPlacement, BOOL, WINAPI, (HWND hWnd, const WINDOWPLACEMENT* lpwndpl))
{
	return TrueSetWindowPlacement(hWnd, lpwndpl);
}

DAPIFUNC_IMP(ShowWindow, BOOL, WINAPI, (HWND hWnd, int nCmdShow))
{
	return TrueShowWindow(hWnd, nCmdShow);
}

DAPIFUNC_IMP(SendMessageA, LRESULT, WINAPI, (
	HWND   hWnd,
	UINT   Msg,
	WPARAM wParam,
	LPARAM lParam
	))
{
	return TrueSendMessageA(hWnd, Msg, wParam, lParam);
}

#endif
