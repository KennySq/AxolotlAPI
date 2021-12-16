#include "pch.h"
#include "AXContext.h"
#include"AXCommandList.h"
#include"Command.h"

#include"AXTexture.h"
#include"AXRenderTargetView.cuh"

AXContext::AXContext(unsigned int flag)
	: mFlag(flag)
{
}

AXContext::~AXContext()
{
}

__global__ void KernelClearRenderTarget(void* ptr, unsigned int width, unsigned height, unsigned int componentSize, float r, float g, float b, float a)
{
	printf("Kernel Call, Clear Render Target View!\n");
}

void WrapperClearRenderTarget(void* ptr, unsigned int width, unsigned int height, unsigned int componentSize, float r, float g, float b, float a)
{

}

void AXContext::ClearRenderTarget(std::shared_ptr<AXRenderTargetView> rtv, float clearColor[4])
{
	std::shared_ptr<IAXResource> resource = rtv->mResource;

	unsigned int width = 1280;
	unsigned int height = 720;
	KernelClearRenderTarget<<<width, height, 1>>>(resource->mRaw, width, height, 8, clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
	cudaDeviceSynchronize();

	//Command cmd = Command(WrapperClearRenderTarget);
	// update from here 2021/12/16 10:38 PM

	mCommandBuffer.push_back();
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
		(*cmdList)->mCommands.push_back(cmd);
	}
	(*cmdList)->mbClosed = true;

	mCommandBuffer.clear();
}
