#include<pch.h>
#include"AXUtil.h"
#include"AXShader.h"

std::shared_ptr<AXShader> AXShader::AXCompile(const char* path, const char* target, const char* entry, unsigned int flag)
{
    std::shared_ptr<AXShader> shader = std::make_shared<AXShader>();
	shader->mPath = path;

	std::string fileStr = path;
	size_t slashIndex = fileStr.find_last_of("/");

	fileStr = slashIndex == MAXSSIZE_T ? fileStr.substr(fileStr.find_last_of('\\') + 1) : fileStr.substr(slashIndex + 1);

	std::string outPath = fileStr.substr(0, fileStr.find_last_of('.'));
	outPath += ".o";
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

	bool bParseResult = parseShader(shader);
	if (bParseResult == false)
	{
		Log("Failed to parse shader.");
	}
	assert(bParseResult == true);

    return shader;
}

bool AXShader::parseShader(const std::shared_ptr<AXShader>& shader)
{
	std::stringstream shaderAsm = std::stringstream(shader->mShaderAsm.str());
	
	while (shaderAsm.eof() == false)
	{
		AXShaderInstruction instruction;
		char buffer[1024];

		shaderAsm.getline(buffer, 1024);

		std::string line = buffer;

		if (line[0] == '/')
		{
			continue;
		}

		std::string opcode;
		
		size_t opcodeSpacer = line.find_first_of(' ');
		if (opcodeSpacer == line.npos)
		{
			continue;
		}
		opcode = line.substr(0, opcodeSpacer);
		line = line.substr(opcodeSpacer);

		instruction.Opcode = opcode;

		size_t lineSize = line.size();
		size_t operandCount = 0;
		for (int i = 0; i < lineSize; i++)
		{
			if (line[i] == ' ')
			{
				operandCount++;
			}
		}

		instruction.Operands.resize(operandCount);

		for (int i = 0; i < operandCount; i++)
		{
			std::string operand = line.substr(line.find_first_of(' ') + 1);
			size_t nextOperand = operand.find_first_of(',');
			if (nextOperand != operand.npos)
			{
				operand = operand.substr(0, nextOperand);
				line = line.substr(line.find_last_of(' ') + 1);

			}
			instruction.Operands[i] = operand;
		}

		shader->mInstructions.emplace_back(instruction);
	}

	return true;
}

bool AXShader::bindInsturction(const AXShaderInstruction& instruction)
{
	if (instruction.Opcode == "dcl_input")
	{
		
	}

	return true;
}
