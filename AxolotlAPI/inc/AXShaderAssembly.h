#pragma once
#include"AX3DMath.h"
#include"AXShaderStream.h"

struct AXShaderAssemblyVector
{
	AXShaderAssemblyVector()
		: Index(-1), Vector(nullptr)
	{

	}
	AXShaderAssemblyVector(size_t index, AXFLOAT4* v)
		: Index(index), Vector(v)
	{

	}

	size_t Index;
	AXFLOAT4* Vector;
};

void swizzle(AXFLOAT4* dest, const AXFLOAT4& src, const std::string& operand)
{
	size_t operandCount = operand.size();
	size_t componentIndex = operand.find('.' + 1);

	std::string components = operand.substr(componentIndex);
	size_t componentCount = components.size();

	for (size_t j = 0; j < componentCount; j++)
	{
		if (components[j] == 'x')
		{
			dest->r[j] = src.x;
		}
		else if (components[j] == 'y')
		{
			dest->r[j] = src.y;
		}
		else if (components[j] == 'z')
		{
			dest->r[j] = src.z;
		}
		else if (components[j] == 'w')
		{
			dest->r[j] = src.w;
		}
	}

	return;
}


static __host__ __device__  AXShaderAssemblyVector AsAXShaderAssemblyVector(const std::string& operand, const std::shared_ptr<AXShaderStream>& stream)
{
	// v#.xxxx
	std::string indexString = operand.substr(1, operand.find('.') - 1);
	size_t index = static_cast<size_t>(atoi(indexString.c_str()));

	std::string registerString = operand.substr(0, operand.find('.') - 1);
	AXFLOAT4* registerPtr;

	if (registerString == "v")
	{
		registerPtr = stream->GetInputRegister(index);
	}
	else if (registerString == "o")
	{
		registerPtr = stream->GetOutputRegister(index);
	}
	else if (registerString == "r")
	{
		registerPtr = stream->GetTemporalRegister(index);
	}

	return AXShaderAssemblyVector(index, registerPtr);
}

static __host__ __device__ void AXShaderMov(AXFLOAT4* v0, AXFLOAT4* v1)
{
	AXFLOAT4 t = *v0;

	*v0 = *v1;

	*v1 = t;

	return;
}