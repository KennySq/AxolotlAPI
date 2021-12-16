#pragma once

#include<pch.h>
#include<ctime>
#include<iomanip>

static void Log(const std::string& str)
{
	auto t = std::time(nullptr);
	auto localTime = *std::localtime(&t);

	std::cout <<  std::put_time(&localTime, "%d/%m/%y %H:%M:%S | ") << str << '\n';
}

static void Log(const char* str)
{
	auto t = std::time(nullptr);
	auto localTime = *std::localtime(&t);

	std::cout << std::put_time(&localTime, "%d/%m/%y %H:%M:%S | ") << str << '\n';
}

static void Log(float numeric)
{
	auto t = std::time(nullptr);
	auto localTime = *std::localtime(&t);

	std::cout << std::put_time(&localTime, "%d/%m/%y %H:%M:%S | ") << numeric << '\n';
}

static void Log(int numeric)
{
	auto t = std::time(nullptr);
	auto localTime = *std::localtime(&t);

	std::cout << std::put_time(&localTime, "%d/%m/%y %H:%M:%S | ") << numeric << '\n';
}

static void Log(size_t numeric)
{
	auto t = std::time(nullptr);
	auto localTime = *std::localtime(&t);

	std::cout << std::put_time(&localTime, "%d/%m/%y %H:%M:%S | ") << numeric << '\n';
}