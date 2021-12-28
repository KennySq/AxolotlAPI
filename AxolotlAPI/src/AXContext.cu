#include "pch.h"
#include "AXContext.h"
#include"AXUtil.h"
#include"AXCommandList.h"
#include"Command.h"

#include"AXInputAssembler.cuh"
#include"AXVertexStage.cuh"
#include"AXRasterizer.cuh"
#include"AXOutputMerger.cuh"
#include"AXPixelStage.cuh"

#include"AX3DMath.h"

#include"AXTexture.h"
#include"AXRenderTargetView.cuh"
#include"AXBuffer.cuh"

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

	asPixel[index] = deviceConvertRGB(r, g, b, a);
}

void AXContext::IASetVertexBuffer(std::shared_ptr<AXBuffer>* const buffer, unsigned int count, unsigned int* const strides, unsigned int* const offsets)
{
	assert(strides != nullptr && "strides cannot be null.");

	for (unsigned int i = 0; i < count; i++)
	{
		AX_BIND_FLAG bindFlag = buffer[i]->mBindFlags;
		
		if ((bindFlag & AX_BIND_VERTEX_BUFFER) != 1)
		{
			Log("This buffer cannot be bound on IA stage.");
		}

		mAssembler->VertexBuffers.push_back(buffer[i]);
		mAssembler->VertexStrides.push_back(strides[i]);
	}
}

void AXContext::IASetIndexBuffer(std::shared_ptr<AXBuffer> buffer)
{
	if (buffer == nullptr)
	{
		Log("Invalid argument");
	}

	AX_BIND_FLAG bindFlag = buffer->mBindFlags;
	if ((bindFlag & AX_BIND_INDEX_BUFFER) != 1)
	{
		Log("This buffer cannot be bound on IA stage.");
	}

	mAssembler->IndexBuffer = buffer;


}

void AXContext::DrawIndexed(unsigned int indexCount, unsigned int offset)
{
	std::shared_ptr<AXRenderTargetView> rtv = mOutputStage->GetRenderTargetView(0);
	std::shared_ptr<IAXResource> resource = rtv->mResource;
	std::shared_ptr<AXTexture2D> asTex2d = std::static_pointer_cast<AXTexture2D>(resource);

	AX_TEXTURE2D_DESC texDesc = asTex2d->GetDesc();
	unsigned int vertexCount = mAssembler->VertexBuffers[0]->mSize / mAssembler->VertexStrides[0];

	mVertexStage->Process(mAssembler);
	cudaDeviceSynchronize();
	mRasterStage->Process(resource, texDesc.Width, texDesc.Height, mVertexStage->GetOutput(), vertexCount);
	cudaDeviceSynchronize();
}

void AXContext::ClearRenderTarget(std::shared_ptr<AXRenderTargetView> rtv, float clearColor[4])
{
	std::shared_ptr<IAXResource> resource = rtv->mResource;
	std::shared_ptr<AXTexture2D> asTex2d = std::static_pointer_cast<AXTexture2D>(resource);

	AX_TEXTURE2D_DESC desc = asTex2d->GetDesc();
	unsigned int width = desc.Width;
	unsigned int height = desc.Height;

	dim3 block = dim3(32, 30, 1);
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
