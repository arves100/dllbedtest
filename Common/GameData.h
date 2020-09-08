/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Common
	File: GameData.h
	Desc: Game definitions
*/
#ifndef COMMON_GAMEDATA_H
#define COMMON_GAMEDATA_H
#pragma once

#define GAME_NONE 0
#define GAME_TMN 1
#define GAME_WA 2
#define GAME_BP 3

#define IS_TMN GAME == GAME_TMN
#define IS_WA GAME == GAME_WA
#define IS_BP GAME == GAME_BP

#if !defined(GAME)
#error "Game is not defined!"
#endif

#if defined(_WIN64) && (IS_WA || IS_TMN)
#error "This game is not compatible with x64"
#endif

#if !defined(_WIN64) && (IS_BP)
#error "This game is not compatible with x86"
#endif

#endif // COMMON_GAMEDATA_H
