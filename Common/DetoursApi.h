/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Common
	File: DetoursApi.h
	Desc: Implements simplified functions for Detours
*/
#ifndef COMMON_DETOURSAPI_H
#define COMMON_DETOURSAPI_H
#pragma once

#define DAPIFUNC_START static TDetourFunc s_psDetourFuncs[] = {
#define DAPIFUNC_END };
#define DAPIFUNC_ADD(x) { &(PVOID&)True##x, My##x, #x },
#define DAPIFUNC_DEF(name, ret, calltype, args) static ret (calltype * True##name) args = name; static ret calltype My##name args

typedef struct SDetourFunc
{
	PVOID* pSrc;
	PVOID pDetour;
	char szName[255];
} TDetourFunc, * PTDetourFunc;

BOOL DAPI_Begin(PTDetourFunc pFuncs, size_t nSize);
BOOL DAPI_End(PTDetourFunc pFuncs, size_t nSize);

#endif // COMMON_DETOURSAPI_H