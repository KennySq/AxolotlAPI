#pragma once
#include"AXTexture.h"

struct AXDeviceTexture2D
{
public:
	__device__ AXDeviceTexture2D();
	__device__ ~AXDeviceTexture2D();

private:
	unsigned int mWidth;
	unsigned int mHeight;

	eAXFormat mFormat;

	DWORD* mRaw;
};