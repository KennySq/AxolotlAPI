#pragma once
#include<sstream>
#include<AX3DMath.h>

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
	struct AXBaseInstruction
	{
		AXBaseInstruction()
		{

		}

		AXBaseInstruction(const std::string& opcode, const std::vector<std::string>& operands)
			: Opcode(opcode), Operands(operands)
		{

		}
		std::string Opcode;
		std::vector<std::string> Operands;
	};

	template<typename _Fx>
	struct AXShaderInstruction : public AXBaseInstruction
	{
		AXShaderInstruction(const AXBaseInstruction& inst)
			: AXBaseInstruction(inst)
		{

		}
		std::function<_Fx> Instruction;
	};

	static bool parseShader(const std::shared_ptr<AXShader>& shader);
	template<typename _Fx, typename... _Args>
	static void bindInsturction(std::shared_ptr<AXShaderInstruction<_Fx>> instruction, _Fx* func, _Args... args)
	{
		instruction->Instruction = std::bind<_Fx>(*func, args);
	}
	template<typename _Fx>
	static void bindInsturction(std::shared_ptr<AXShaderInstruction<_Fx>> instruction, _Fx* func)
	{
		instruction->Instruction = std::bind<void()>(*func);
	}

	static AXFLOAT4 swizzle(const AXFLOAT4& src, const std::string& operand);

	void processInstructions();


	std::string mName;
	std::string mPath;

	eShaderType mType;

	unsigned int mInstructionCount;
	
	std::ostringstream mShaderAsm;

	std::vector<std::shared_ptr<AXBaseInstruction>> mInstructions;
};