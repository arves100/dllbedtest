/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Common
	File: StdAfx.h
	Desc: Precompiled header for the library
*/
#ifndef COMMON_STDAFX_H
#define COMMON_STDAFX_H
#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define APP_VERSION 1

#include <Windows.h>
#include <tchar.h>
#include <wchar.h>
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
#define EXTERN_C_START extern "C" {
#define EXTERN_C_END }
#ifndef EXTERN_C
#define EXTERN_C extern "C"
#endif
#else
#define EXTERN_C_START
#define EXTERN_C_END
#ifndef EXTERN_C
#define EXTERN_C
#endif
#endif

#include "GameData.h"
#include "DllMain.h"

#ifdef __cplusplus
#include "Log.hpp"
#endif

#endif // COMMON_STDAFX_H