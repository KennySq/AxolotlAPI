#pragma once
#include<AX3DMath.h>
#include<Singleton.h>

template<typename _VertTy>
struct AXShaderStream : Singleton<AXShaderStream>
{
public:
	AXShaderStream();
	~AXShaderStream();

	static void ResizeInputStream(size_t size) { GetInstance()->mInputStreams.resize(size); }
	static void ResizeOutputStream(size_t size) { GetInstance()->mOutputStreams.resize(size); }

private:
	std::vector<_VertTy> mInputStreams;
	std::vector<_VertTy> mOutputStreams;

	AXFLOAT4* mSystemPosition;
};