#pragma once
#include<sstream>

enum eShaderType
{
	SHADER_VERTEX = 1,
	SHADER_GEOMETRY = 2,
	SHADER_DOMAIN = 4,
	SHADER_HULL = 8,
	SHADER_PIXEL = 16,
	SHADER_COMPUTE = 32,
};

struct AXShader
{
public:
	static std::shared_ptr<AXShader> AXCompile(const char* path, const char* target, const char* entry, unsigned int flag);

private:
	struct AXShaderInstruction
	{
		std::function<void()> Instruction;

		std::string Opcode;
		std::vector<std::string> Operands;
	};

	static bool parseShader(const std::shared_ptr<AXShader>& shader);
	static bool bindInsturction(const AXShaderInstruction& instruction);

	std::string mName;
	std::string mPath;

	eShaderType mType;

	unsigned int mInstructionCount;
	
	std::ostringstream mShaderAsm;

	std::vector<AXShaderInstruction> mInstructions;

	
};