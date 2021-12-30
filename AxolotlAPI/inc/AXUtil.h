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

#ifdef _DEBUG | DEBUG
static void DebugLog(const std::string& str)
{
	OutputDebugStringA(str.c_str());
}

static void DebugLog(const char* str)
{
	OutputDebugStringA(str);
}
#endif
static void Log(const char* str)
{
	auto t = std::time(nullptr);
	auto localTime = *std::localtime(&t);

	std::cout << std::put_time(&localTime, "%d/%m/%y %H:%M:%S | ") << str << '\n';

#ifdef _DEBUG | DEBUG
	OutputDebugStringA(str);
#endif
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

template<typename _Ty>
__device__ _Ty* Cast(void* ptr)
{
	_Ty* castPtr = reinterpret_cast<_Ty*>(ptr);

	castPtr = new (*castPtr)_Ty;

	return castPtr;
}