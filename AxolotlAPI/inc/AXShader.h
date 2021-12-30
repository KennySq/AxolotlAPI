#pragma once

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

private:
	std::string mName;
	std::string mPath;

	eShaderType mType;

	unsigned int mInstructionCount;
};