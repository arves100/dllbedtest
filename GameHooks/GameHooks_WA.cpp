/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: GameHooks
	File: GameHooks_WA.cpp
	Desc: Worms: Armageddon game hooks
*/
#include "StdAfx.h"
#include "GameHooks.hpp"

#if IS_WA

#include "../Common/Cache.hpp"

#include <fstream>

DAPIFUNC_IMP(CreateWindowExA, HWND, WINAPI, (DWORD dwExStyle,
	LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle,
	int X, int Y, int nWidth, int nHeight, HWND hWndParent,
	HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam))
{
#if IS_WA
	bool bIsWAclass = false, bIsSKclass = false, bIsAfxClass = false;

	std::ofstream ofs("windows.txt", std::ios::app);
	ofs << "--> " << lpClassName << ":" << lpWindowName << std::endl;
	ofs.close();

	if (strcmp("Worms2D", lpClassName) == 0)
	{
		bIsWAclass = true;
	}
	else if (strcmp("Socket Event Window", lpClassName) == 0)
	{
		bIsSKclass = true;
	}
	else if (strncmp("Afx:00400000:0:00010003:00900011", lpClassName, 32) == 0)
	{
		bIsWAclass = true;
		bIsAfxClass = true;
	}

	if (bIsWAclass)
	{
		dwStyle = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_BORDER;
		hWndParent = NULL;
		nWidth = 800;
		nHeight = 600;
	}

	HWND ret = TrueCreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y,
		nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);

	if (ret && (bIsSKclass || bIsWAclass))
	{
		//if (!bIsSKclass)
		{
			ShowWindow(ret, SW_SHOW);
			UpdateWindow(ret);
		}

		// Add the window to the cache
		auto cE = CCache::Instance()->Get(ID_CACHE_WINDOWINFO);

		if (!cE)
		{
			cE = new CElement();
			CCache::Instance()->Add(ID_CACHE_WINDOWINFO, cE);
		}

		cE->Add(bIsSKclass ? ID_SOCKETWINDOW : bIsAfxClass ? ID_AFXWINDOW : ID_GAMEWINDOW, ret);
	}

	return ret;
#else
	return TrueCreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y,
		nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
#endif
}

DAPIFUNC_IMP(RegisterClassA, ATOM, WINAPI, (const WNDCLASSA* lpWndClass))
{
#if IS_WA
	bool bIsWAclass = false, bIsSKclass = false;

	std::ofstream ofs("registers.txt", std::ios::app);
	ofs << "--> " << lpWndClass->lpszClassName << std::endl;
	ofs.close();

	if (strcmp("Worms2D", lpWndClass->lpszClassName) == 0)
	{
		bIsWAclass = true;
	}
	else if (strcmp("Socket Event Window", lpWndClass->lpszClassName) == 0)
	{
		bIsWAclass = true;
		bIsSKclass = true;
	}
	else if (strncmp("Afx:00400000:0:00010003:00900011", lpWndClass->lpszClassName, 32) == 0)
	{
		bIsWAclass = true;
	}

#if 0
	auto cE = CCache::Instance()->Get(ID_CACHE_WINDOWINFO);
	if (!cE)
	{
		cE = new CElement();
		CCache::Instance()->Add(ID_CACHE_WINDOWINFO, cE);
	}
#endif

	WNDCLASSA* wca = const_cast<WNDCLASSA*>(lpWndClass);

	if (bIsWAclass && !bIsSKclass)
	{
		wca->style = CS_VREDRAW | CS_HREDRAW;
		wca->hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	}

	ATOM atom = TrueRegisterClassA(wca);

#if 0
	if (atom)
		cE->Add(bIsSKclass ? ID_SOCKETCLASS : ID_GAMECLASS, atom);
#endif

	return atom;
#else
	return TrueRegisterClassA(lpWndClass);
#endif
}

DAPIFUNC_IMP(MoveWindow, BOOL, WINAPI, (HWND hWnd, int X, int Y,
	int nWidth, int nHeight, BOOL bRepaint))
{
	if (hWnd == CCache::Instance()->GetElement(ID_CACHE_WINDOWINFO, ID_GAMEWINDOW)
		|| hWnd == CCache::Instance()->GetElement(ID_CACHE_WINDOWINFO, ID_AFXWINDOW))
	{
		return TRUE;
	}

	return TrueMoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint);
}

DAPIFUNC_IMP(SetWindowPos, BOOL, WINAPI, (HWND hWnd, HWND hWndInsertAfter,
	int X, int Y, int cx, int cy, UINT uFlags))
{
	if (hWnd == CCache::Instance()->GetElement(ID_CACHE_WINDOWINFO, ID_GAMEWINDOW)
		|| hWnd == CCache::Instance()->GetElement(ID_CACHE_WINDOWINFO, ID_AFXWINDOW))
	{
		return TRUE;

#if 0
		cx = 800;
		cy = 600;
		hWndInsertAfter = HWND_TOPMOST;

		uFlags &= ~SWP_HIDEWINDOW;
		uFlags &= SWP_NOZORDER | SWP_NOREPOSITION | SWP_NOSIZE | SWP_NOMOVE;
#endif
	}

	return TrueSetWindowPos(hWnd, hWndInsertAfter, X, Y, cx, cy, uFlags);
}

DAPIFUNC_IMP(SetWindowLongA, LONG, WINAPI, (HWND hWnd, int nIndex,
	LONG dwNewLong))
{
	if (hWnd == CCache::Instance()->GetElement(ID_CACHE_WINDOWINFO, ID_GAMEWINDOW)
		|| hWnd == CCache::Instance()->GetElement(ID_CACHE_WINDOWINFO, ID_AFXWINDOW))
	{
		if (nIndex == GWL_STYLE)
		{
			dwNewLong = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_BORDER;
		}
		else if (nIndex == GWL_EXSTYLE)
		{
			dwNewLong = 0;
		}
	}

	return TrueSetWindowLongA(hWnd, nIndex, dwNewLong);
}

DAPIFUNC_IMP(LoadLibraryA, HMODULE, WINAPI, (LPCSTR lpLibFileName))
{
	LPCSTR szFileName = lpLibFileName;

	if (strcmp(lpLibFileName, "d3d9.dll") == 0)
	{
		szFileName = "d3dk.dll"; // Load the custom Direct3D9 library
	}

	return TrueLoadLibraryA(szFileName);
}

DAPIFUNC_IMP(AdjustWindowRectEx, BOOL, WINAPI, (LPRECT lpRect, DWORD dwStyle,
	BOOL bMenu, DWORD dwExStyle))
{
	// §todo stub
	return TRUE;
}

DAPIFUNC_IMP(SetWindowPlacement, BOOL, WINAPI, (HWND hWnd, const WINDOWPLACEMENT* lpwndpl))
{
	// §todo stub
	return TRUE;
}

DAPIFUNC_IMP(ShowWindow, BOOL, WINAPI, (HWND hWnd, int nCmdShow))
{
	return TrueShowWindow(hWnd, SW_SHOW);
}

DAPIFUNC_IMP(SendMessageA, LRESULT, WINAPI, (
	HWND   hWnd,
	UINT   Msg,
	WPARAM wParam,
	LPARAM lParam
	))
{
	if (hWnd == CCache::Instance()->GetElement(ID_CACHE_WINDOWINFO, ID_GAMEWINDOW)
		|| hWnd == CCache::Instance()->GetElement(ID_CACHE_WINDOWINFO, ID_AFXWINDOW))
	{
		return 0;

		switch (Msg)
		{
		case WM_ACTIVATE:
		case WM_SIZE:
		case WM_MOVE:
		case WM_STYLECHANGED:
		case WM_STYLECHANGING:
		case WM_MOVING:
		case WM_SIZECLIPBOARD:
		case WM_SIZING:
		case WM_DPICHANGED:
		case WM_DPICHANGED_AFTERPARENT:
		case WM_DPICHANGED_BEFOREPARENT:
		case WM_GETDPISCALEDSIZE:
		case WM_SHOWWINDOW:
			return 0;
		default:
			break;
		}
	}

	return TrueSendMessageA(hWnd, Msg, wParam, lParam);
}

DAPIFUNC_IMP(LockWindowUpdate, BOOL, WINAPI, (HWND hWndLock))
{
	return TRUE;
}

DAPIFUNC_IMP(EnableWindow, BOOL, WINAPI, (
	HWND hWnd,
	BOOL bEnable
	))
{
	return TRUE;
}

#endif // IS_WA

