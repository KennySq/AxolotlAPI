#pragma once
#include<pch.h>
#include<fstream>
#include"AXUtil.h"
#include"AXBytecode.h"

static bool AXCompileFromFile(const char* path, const char* target, const char* entry, unsigned int flag, std::shared_ptr<AXBytecode> pOutBytecode)
{
	std::string fileStr = path;
	size_t slashIndex = fileStr.find_last_of("/");
	
	fileStr = slashIndex == MAXSSIZE_T ? fileStr.substr(fileStr.find_last_of('\\') + 1) : fileStr.substr(slashIndex + 1);

	std::string outPath = fileStr.substr(0, fileStr.find_last_of('.'));
	outPath += ".o";
	std::string args = std::string(" /T ") + target + " /E " + entry + " /Fo " + outPath;
	
	std::string exeCmd = std::string("C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x64/fxc ");
	std::string arg = exeCmd + std::string(path) + args;

	STARTUPINFOA info{};

	char computerName[256];
	DWORD nameLength;
	bool result = GetComputerNameA(computerName, &nameLength);
	if (result != true)
	{
		Log("failed to getting user name");
	}
	info.cb = sizeof(STARTUPINFOA);
	info.lpDesktop = computerName;
	info.dwX = CW_USEDEFAULT;
	info.dwY = CW_USEDEFAULT;
	info.dwXSize = CW_USEDEFAULT;
	info.dwYSize = CW_USEDEFAULT;

	PROCESS_INFORMATION processInfo;

	result = CreateProcessA(nullptr, (char*)arg.c_str(), NULL, NULL, false, NORMAL_PRIORITY_CLASS, NULL, NULL, &info, &processInfo);
	
	HRESULT error = HRESULT_FROM_WIN32(GetLastError());
	if (result != true)
	{
		Log("failed to start the fxc.exe.");
	}

	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);

	std::ifstream file;
	
	file.open(path, std::ifstream::binary);

	if (!file)
	{
		std::cout << "Failed.\n";
	}

	file.seekg(0, file.end);

	size_t binarySize = file.tellg();

	file.seekg(0, file.beg);

	
	unsigned char* binaryPtr = new unsigned char[binarySize];
	
	file.read((char*)binaryPtr, binarySize);
	file.close();
	
	pOutBytecode = std::make_shared<AXBytecode>(binaryPtr, binarySize);

	return result;
}