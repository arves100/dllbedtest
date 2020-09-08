/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Common
	File: Log.cpp
	Desc: Logging implementation
*/
#include "StdAfx.h"

#include <spdlog/sinks/basic_file_sink.h>

void LOG_Start(std::string szExtraName)
{
    try
    {
        std::string szName = "logs/DLL_";
        szName += szExtraName;
        szName += ".log";

        auto logger = spdlog::basic_logger_mt("bedtest_log", szName.c_str());

        logger->set_level(spdlog::level::info);
        logger->info("-------------\n");
        logger->info("Start! Module: {}", szExtraName);

        spdlog::set_default_logger(logger);

    }
    catch (const spdlog::spdlog_ex& ex)
    {
        std::string err = "Cannot initialize logging system\nException: ";
        err += ex.what();

        MessageBoxA(nullptr, err.c_str(), "Bedtest library", MB_OK | MB_ICONERROR);
    }
}
