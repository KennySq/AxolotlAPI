#include<pch.h>
#include "AXChain.cuh"
#include"AXTexture.h"
#include"AXUtil.h"

AXChain::AXChain()
{


}

AXChain::~AXChain()
{
}

void AXChain::Present()
{
	unsigned int size = (mWidth * mHeight *  4);
	cudaError_t error = cudaMemcpy(mBuffer, mVirtual, size, cudaMemcpyDeviceToHost);
	if (error != NULL)
	{
		Log(cudaGetErrorString(error));
	}

	cudaDeviceSynchronize();

	BitBlt(mMainDC, 0, 0, mWidth, mHeight, mMemoryDC, 0, 0, SRCCOPY);
}

void AXChain::BindTexture(unsigned int index, const std::shared_ptr<AXTexture2D>& outTexture)
{
	AX_TEXTURE2D_DESC texDesc{};

	//if (outTexture->mFormat != AX_R8G8B8A8_UNORM)
	//{
	//	Log("invalid format.");
	//	return;
	//}

	mVirtual = outTexture->mRaw;
}