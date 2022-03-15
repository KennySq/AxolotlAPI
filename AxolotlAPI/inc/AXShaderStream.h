#pragma once
#include<AX3DMath.h>
struct AXShaderStream
{
public:
	AXShaderStream();
	~AXShaderStream();

	void ResizeInputStream(size_t size) { mInputStreams.resize(size); }
	void ResizeOutputStream(size_t size) { mOutputStreams.resize(size); }

private:
	std::vector<AXFLOAT4> mInputStreams;
	std::vector<AXFLOAT4> mOutputStreams;

	AXFLOAT4* mSystemPosition;
};