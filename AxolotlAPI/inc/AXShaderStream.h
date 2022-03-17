#pragma once
#include<AX3DMath.h>
#include<Singleton.h>

struct AXShaderStream : public Singleton<AXShaderStream>
{
public:
	AXShaderStream();
	~AXShaderStream();

	static std::vector<AXFLOAT4>& GetInputRegisters() { return GetInstance()->mInputRegisters; }
	static std::vector<AXFLOAT4>& GetOutputRegisters() { return GetInstance()->mOutputRegisters; }

	static void SetInputRegisterValue(size_t index, AXFLOAT4 value) { GetInstance()->mInputRegisters[index] = value; }
	static void SetOutputRegisterValue(size_t index, AXFLOAT4 value) { GetInstance()->mOutputRegisters[index] = value; }

private:
	std::vector<AXFLOAT4> mInputRegisters;
	std::vector<AXFLOAT4> mOutputRegisters;
};