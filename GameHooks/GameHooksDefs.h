/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: GameHooks
	File: GameHooksDefs.h
	Desc: Definition for specific games
*/
#ifndef GAMEHOOKS_GAMEHOOKSDEFS_H
#define GAMEHOOKS_GAMEHOOKSDEFS_H
#pragma once

enum ECommon
{
	ID_GAMEWINDOW = 1,
	ID_GAMECLASS,

	ID_CACHE_WINDOWINFO = 1,
};

#if IS_WA
enum EWA // Worms: Armageddon specific
{
	
	ID_SOCKETWINDOW,
	ID_AFXWINDOW,
	ID_SOCKETCLASS,
};
#endif

#endif // GAMEHOOKS_GAMEHOOKSDEFS_H
