#include "pch.h"
#include "AXContext.h"
#include"AXCommandList.h"
#include"Command.h"

#include"AXTexture.h"
#include"AXRenderTargetView.cuh"

AXContext::AXContext(unsigned int flag)
	: mFlag(flag), mCommandIndex(0), mCommandBuffer(1024)
{
}

AXContext::~AXContext()
{
}

__global__ void KernelClearRenderTarget(void* ptr, unsigned int width, unsigned height, unsigned int componentSize, float r, float g, float b, float a)
{
	unsigned int blockId = blockIdx.x + blockIdx.y * gridDim.x;
	unsigned int index = blockId * (blockDim.x * blockDim.y) + (threadIdx.y * blockDim.x) + threadIdx.x;
	
	DWORD* asPixel = reinterpret_cast<DWORD*>(ptr);

	BYTE comp0 = r * 255.999f;
	BYTE comp1 = g * 255.999f;
	BYTE comp2 = b * 255.999f;
	BYTE comp3 = a * 255.999f;

	DWORD color = 0;

	color |= (comp3 << 24);
	color |= (comp0 << 16);
	color |= (comp1 << 8);
	color |= (comp2 << 0);

	asPixel[index] = color;
}

void AXContext::ClearRenderTarget(std::shared_ptr<AXRenderTargetView> rtv, float clearColor[4])
{
	std::shared_ptr<IAXResource> resource = rtv->mResource;
	std::shared_ptr<AXTexture2D> asTex2d = std::static_pointer_cast<AXTexture2D>(resource);

	AX_TEXTURE2D_DESC desc = asTex2d->GetDesc();
	unsigned int width = desc.Width;
	unsigned int height = desc.Height;

	dim3 block = dim3(8, 8, 1);
	dim3 grid = dim3(width / block.y, height / block.y, 1);

	Command cmd;

	float r, g, b, a;

	r = clearColor[0];
	g = clearColor[1];
	b = clearColor[2];
	a = clearColor[3];

	KernelClearRenderTarget << <grid, block >> > (resource->mRaw, width, height, 8, r, g, b, a);
	cudaDeviceSynchronize();
	//cmd.Bind<8, void*, unsigned int, unsigned int, unsigned int, float, float, float, float>
	//	(WrapperClearRenderTarget, resource->mRaw, width, height, (unsigned int)8, clearColor[0], clearColor[1], clearColor[2], clearColor[3]);

	//mCommandBuffer[mCommandIndex] = cmd;
	//mCommandIndex++;
	//cmd.Bind<void*, unsigned int, unsigned int, unsigned int, float, float, float, float>
	//	(WrapperClearRenderTarget, resource->mRaw, width, height, (unsigned int)8, clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
	//// update from here 2021/12/16 10:38 PM
	//auto b = std::bind(WrapperClearRenderTarget, resource->mRaw, width, height, (unsigned int)8, clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
	//std::bind<std::function<void(float)>, float>(floatFn, 0.0f);
	//mCommandBuffer.push_back();
}

void AXContext::ExecuteCommandList(const std::shared_ptr<AXCommandList>& cmdList) const
{
	unsigned int size = cmdList->mCommands.size();

	for (unsigned int i = 0; i < size; i++)
	{
		cmdList->mCommands[i].Execute();
	}

	cmdList->mbClosed = false;
}

void AXContext::FinishCommandList(std::shared_ptr<AXCommandList>* cmdList)
{
	unsigned int size = mCommandBuffer.size();

	for (unsigned int i = 0; i < size; i++)
	{
		Command cmd = mCommandBuffer[i];
		(*cmdList)->mCommands[i] = cmd;
	}
	(*cmdList)->mbClosed = true;

	mCommandBuffer.clear();
	mCommandBuffer.resize(1024);
	mCommandIndex = 0;
}
