#include<pch.h>
#include"AXUtil.h"
#include"AXShader.h"

#include<AXShaderStream.h>
#include<AXShaderMath.h>
#include<AXShaderAssembly.h>



AXShader::AXShader()
	: mStream(std::make_shared<AXShaderStream>())
{
}

AXShader::~AXShader()
{

}

bool AXShader::parseShader(const std::shared_ptr<AXShader>& shader)
{
	std::stringstream shaderAsm = std::stringstream(shader->mShaderAsm.str());

	while (shaderAsm.eof() == false)
	{
		std::shared_ptr<AXShaderInstruction> instruction = std::make_shared<AXShaderInstruction>();
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

		instruction->Opcode = opcode;

		size_t lineSize = line.size();
		size_t operandCount = 0;
		for (int i = 0; i < lineSize; i++)
		{
			if (line[i] == ' ')
			{
				operandCount++;
			}
		}

		instruction->Operands.resize(operandCount);
		line = line.substr(line.find_first_of(' ') + 1);
		for (int i = 0; i < operandCount; i++)
		{
			std::string operand = line.substr(0, line.find_first_of(' '));
			size_t nextOperand = line.find_first_of(' ');

			bool bComma = (operand.find(',') != operand.npos);

			if (bComma == true)
			{
				operand = operand.substr(0, operand.find(','));
			}

			if (nextOperand != operand.npos)
			{
				line = line.substr(line.find_first_of(' ') + 1);
			}




			//if (nextOperand != operand.npos)
			//{
			//	operand = operand.substr(0, nextOperand);

			//	size_t nextStart = line.find(' ') + 1;
			//	line = line.substr(nextStart, line.size() - nextStart);

			//}
			instruction->Operands[i] = operand;
		}

		shader->mInstructions.emplace_back(instruction);
	}

	return true;
}

void AXShader::processInstructions()
{
	size_t instructionCount = mInstructions.size();
	for (size_t i = 0; i < instructionCount; i++)
	{
		if (mInstructions[i]->Opcode == "dcl_output_siv")
		{
			//std::shared_ptr<AXShaderInstruction<void(size_t, AXFLOAT4)>> instruction
			//	= std::make_shared<AXShaderInstruction<void(size_t, AXFLOAT4)>>(*mInstructions[i]);

			//AXShaderStream* shaderStream = AXShaderStream::GetInstance();

			//auto ptr = shaderStream->;
			//
			//const std::string& destionation = mInstructions[i]->Operands[0];
			//const std::string& systemDescription = mInstructions[i]->Operands[1];
			//
			//// v##.xyzw

			//if (systemDescription == "position")
			//{
			//	// treat as system position
			//}

			//std::string registerIndexString = destionation.substr(1, destionation.find('.') - 1);
			//int registerIndex = atoi(registerIndexString.c_str());

			//bindInsturction<void(size_t, AXFLOAT4)>(instruction, ptr);
		}

		if (mInstructions[i]->Opcode == "dp4")
		{
			auto&& dotFunc = AXShaderDot;

			const std::string& operand0 = mInstructions[i]->Operands[0];
			const std::string& operand1 = mInstructions[i]->Operands[1];
			const std::string& operand2 = mInstructions[i]->Operands[2];

			AXShaderAssemblyVector destination = AsAXShaderAssemblyVector(operand0, mStream);
			AXShaderAssemblyVector source0 = AsAXShaderAssemblyVector(operand1, mStream);
			AXShaderAssemblyVector source1 = AsAXShaderAssemblyVector(operand2, mStream);

			bindInsturction(mInstructions[i], dotFunc, destination, source0, source1);
		}

		if (mInstructions[i]->Opcode == "mov")
		{
			auto&& movFunc = AXShaderMov;

			const std::string& operand0 = mInstructions[i]->Operands[0];
			const std::string& operand1 = mInstructions[i]->Operands[1];

			AXShaderAssemblyVector asmVector0 = AsAXShaderAssemblyVector(operand0, mStream);
			AXShaderAssemblyVector asmVector1 = AsAXShaderAssemblyVector(operand1, mStream);

			bindInsturction(mInstructions[i], movFunc, asmVector0.Vector, asmVector1.Vector);
		}
	}
}

void AXShader::runInstructions()
{
	size_t instructionCount = mInstructions.size();
	for (size_t i = 0; i < instructionCount; i++)
	{
		if (mInstructions[i]->Instruction != nullptr)
		{
			mInstructions[i]->Instruction();
		}
	}
}
