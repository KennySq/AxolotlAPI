#pragma once
#include<AX3DMath.h>
#include<Singleton.h>

struct AXShaderStream
{
public:
	AXShaderStream();
	~AXShaderStream();

	AXFLOAT4* GetInputRegister(size_t index) { return &mInputRegisters.data()[index]; }
	AXFLOAT4* GetOutputRegister(size_t index) { return &mOutputRegisters.data()[index]; }
	AXFLOAT4* GetTemporalRegister(size_t index) { return &mTemporalRegisters.data()[index]; }

	void SetInputRegisterValue(size_t index, AXFLOAT4 value) { mInputRegisters[index] = value; }
	void SetOutputRegisterValue(size_t index, AXFLOAT4 value) { mOutputRegisters[index] = value; }
	void SetTemporalRegisterValue(size_t index, AXFLOAT4 value) { mTemporalRegisters[index] = value; }

private:
	std::vector<AXFLOAT4> mInputRegisters;
	std::vector<AXFLOAT4> mTemporalRegisters;
	std::vector<AXFLOAT4> mOutputRegisters;
};