#pragma once
#include"pch.h"
#include"AXUtil.h"

static const std::pair<const char*, type_info&> comparisonPairs[] =
{
	std::make_pair("ps_5_0", typeid(AXPixelShader)),
	std::make_pair("PS_5_0", typeid(AXPixelShader)),

};

template<class _Ty>
std::shared_ptr<_Ty> AXCompile(const char* path, const char* target, const char* entry, unsigned int flag)
{
	std::shared_ptr<AXShader> shader = std::make_shared<_Ty>();
	shader->mPath = path;

	std::string fileStr = path;
	size_t slashIndex = fileStr.find_last_of("/");

	fileStr = slashIndex == MAXSSIZE_T ? fileStr.substr(fileStr.find_last_of('\\') + 1) : fileStr.substr(slashIndex + 1);

	std::string outPath = std::string("hlsl/") + fileStr.substr(0, fileStr.find_last_of('.'));
	outPath += ".o";

	bool bValid = false;
	
	type_info& templateType = typeid(_Ty);

	if (comparisonPairs[target] != templateType)
	{
		Log("target arguemnt mismatch.");
		assert(true);
	}

	std::string args = std::string(" /T ") + target + " /E " + entry + " /Fc " + outPath;

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

	file.open(outPath);

	if (!file)
	{
		std::cout << "Failed.\n";
		return nullptr;
	}

	while (file.eof() == false)
	{
		char buffer[1024];
		std::string bufferStr;
		file.getline(buffer, 1024);
		bufferStr = buffer;

		shader->mShaderAsm << buffer;
		shader->mShaderAsm << '\n';
	}

	file.close();

	bool bParseResult = AXShader::parseShader(shader);
	if (bParseResult == false)
	{
		Log("Failed to parse shader.");
	}
	assert(bParseResult == true);

	shader->processInstructions();

	return std::static_pointer_cast<AXPixelShader>(shader);
}
