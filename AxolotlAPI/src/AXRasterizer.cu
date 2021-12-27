#include<pch.h>
#include"AXRasterizer.cuh"
#include"AXVertexStage.cuh"
#include"AX3DMath.h"
#include"IAXResource.h"

__device__ AXFLOAT2* gProjectedBuffer = nullptr;

AXRasterizer::AXRasterizer()
{
}

__device__ void deviceSetPixel(void* ptr, unsigned int x, unsigned int y, unsigned int width, float r, float g, float b, float a)
{
	unsigned int index = (y * width) + x;

	DWORD* texture = reinterpret_cast<DWORD*>(ptr);

	texture[index] = deviceConvertRGB(r, g, b, a);
}

__device__ void deviceDrawLine(void* ptr, AXFLOAT2 p0, AXFLOAT2 p1, unsigned int width)
{
	float deltax = p0.x - p1.x;
	float deltay = p0.y - p1.y;

	float slope = deltay / deltax;

	if (slope <= 1.0f)
	{
		AXFLOAT2 point = AXFLOAT2(p0.x, p0.y);
		for (unsigned int i = 0; i < deltax; i++)
		{
			deviceSetPixel(ptr, point.x, point.y, width, 1.0f, 0.0, 0.0f, 0.0f);
			point.x += i;
			point.y += slope;
			// update from here 2021/12/27 2:50 PM
		}
	}

	else
	{
		AXFLOAT2 point = AXFLOAT2(p0.x, p0.y);
		for (unsigned int i = 0; i < deltay; i++)
		{
			deviceSetPixel(ptr, point.x, point.y, width, 1.0f, 0.0, 0.0f, 0.0f);
			point.x += slope;
			point.y += i;
		}
	}
}

// runs triangle scale
__global__ void KernelDetermineRasterize(void* renderTarget, AXFLOAT2* projectedPoints, unsigned int width)
{
	unsigned int blockId = blockIdx.x + blockIdx.y * gridDim.x;
	unsigned int index = blockId * (blockDim.x * blockDim.y) + (threadIdx.y * blockDim.x) + threadIdx.x;

	AXFLOAT2 position0 = projectedPoints[threadIdx.x];
	AXFLOAT2 position1 = projectedPoints[threadIdx.x + 1];
	AXFLOAT2 position2 = projectedPoints[threadIdx.x + 2];

	deviceDrawLine(renderTarget, position0, position1, width);
	deviceDrawLine(renderTarget, position1, position2, width);
	deviceDrawLine(renderTarget, position2, position0, width);



}
void AXRasterizer::Process(std::shared_ptr<IAXResource> texture, unsigned int width, unsigned int height, void* projectedData, unsigned int vertexCount)
{
	// update from here 2021/12/27 11:37 AM
	dim3 grid = dim3(vertexCount / 3);
	dim3 block = dim3(32, 1, 1);
	KernelDetermineRasterize<<<grid, block>>>(texture->mRaw, projectedData, width);
	
}