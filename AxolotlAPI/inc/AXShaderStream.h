#pragma once
#include<AX3DMath.h>
#include<Singleton.h>

struct AXShaderStream
{
public:
	__host__ __device__ AXShaderStream();
	__host__ __device__ ~AXShaderStream();

	__host__ __device__ AXFLOAT4* GetInputRegister(size_t index) { return &mInputRegisters.data()[index]; }
	__host__ __device__ AXFLOAT4* GetOutputRegister(size_t index) { return &mOutputRegisters.data()[index]; }
	__host__ __device__ AXFLOAT4* GetTemporalRegister(size_t index) { return &mTemporalRegisters.data()[index]; }

	__host__ __device__ void SetInputRegisterValue(size_t index, AXFLOAT4 value) { mInputRegisters[index] = value; }
	__host__ __device__ void SetOutputRegisterValue(size_t index, AXFLOAT4 value) { mOutputRegisters[index] = value; }
	__host__ __device__ void SetTemporalRegisterValue(size_t index, AXFLOAT4 value) { mTemporalRegisters[index] = value; }

private:
	std::vector<AXFLOAT4> mInputRegisters;
	std::vector<AXFLOAT4> mTemporalRegisters;
	std::vector<AXFLOAT4> mOutputRegisters;
};