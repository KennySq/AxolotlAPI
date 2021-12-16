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

	void* mRaw;
};

__global__ void CreateDeviceTexture2D(const AX_TEXTURE2D_DESC desc)
{
	eAXFormat format = desc.Format;
	unsigned int perPixel;
	if (format == AX_R8G8B8A8_FLOAT)
	{
		perPixel = 32;
	}

	return;
}