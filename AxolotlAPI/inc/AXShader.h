#pragma once
#include<sstream>
#include<AX3DMath.h>

struct AXShaderStream;

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
	AXShader();

	void runInstructions();


private:

	struct AXShaderInstruction
	{
		std::function<void()> Instruction;
		std::string Opcode;
		std::vector<std::string> Operands;
	};

	static bool parseShader(const std::shared_ptr<AXShader>& shader);

	template<typename _Fx, typename... _Args>
	static void bindInsturction(std::shared_ptr<AXShaderInstruction> instruction, _Fx&& func, _Args&&... args)
	{
		instruction->Instruction = std::bind(func, args...);
	}

	void processInstructions();

	std::string mName;
	std::string mPath;

	eShaderType mType;

	unsigned int mInstructionCount;
	
	std::ostringstream mShaderAsm;

	std::vector<std::shared_ptr<AXShaderInstruction>> mInstructions;

	std::shared_ptr<AXShaderStream> mStream;
};