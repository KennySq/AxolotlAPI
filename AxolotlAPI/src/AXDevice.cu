#include"pch.h"
#include "AXDevice.cuh"
#include"AXTexture.h"
#include"AXCommandList.h"
#include"AXRenderTargetView.cuh"
#include"AXDeviceTexture2D.cuh"
#include"AXDeviceMemoryPool.cuh"

#include<Windows.h>

unsigned int AXDevice::mInterfaceCounter = 0;

static __global__ void KernelWriteRaw(int data, void* raw, unsigned int offset)
{
	void* ptr = (void*)((size_t)raw + offset);
	int* asInt = reinterpret_cast<int*>(ptr);

	*asInt = data;
}

static __global__ void KernelViewRaw(unsigned int offset, void* raw)
{
	void* ptr = (void*)((size_t)raw + offset);
	int* asInt = reinterpret_cast<int*>(ptr);

	printf("%d\n", *reinterpret_cast<int*>(&asInt[0]));
	printf("%d\n", *reinterpret_cast<int*>(&asInt[1]));
	printf("%d\n", *reinterpret_cast<int*>(&asInt[2]));
}

AXDevice::AXDevice(unsigned int flag)
	: mDeviceFlag(flag)
{
	mMemory = std::make_shared<AXDeviceMemoryPool>(8294400);
	KernelViewRaw<<<1,1>>>(0, pool.GetRaw());
	cudaDeviceSynchronize();
}

AXDevice::~AXDevice()
{
}

std::shared_ptr<AXTexture2D> AXDevice::CreateTexture2D(const AX_TEXTURE2D_DESC& desc)
{
	unsigned int perPixel = 0;
	unsigned int totalSize = 0;
	if (desc.Format == AX_R8G8B8A8_FLOAT)
	{
		perPixel = 32;
		totalSize = desc.Width * desc.Height * perPixel;
	}

	void* devicePtr = mMemory->Alloc(totalSize);

	std::shared_ptr<AXTexture2D> tex = std::make_shared<AXTexture2D>();
	// update from here 2021/12/16 2:51 PM
	CreateDeviceTexture2D << <1, 1, 1 >> > (desc);
	tex->mWidth = desc.Width;
	tex->mHeight = desc.Height;
	tex->mFormat = desc.Format;
	
	mInterfaceCounter++;

	return tex;
}

std::shared_ptr<AXCommandList> AXDevice::CreateCommandList()
{
	std::shared_ptr<AXCommandList> cmdList = std::make_shared<AXCommandList>();
	
	cmdList->mCommands.resize(1024);

	mInterfaceCounter++;

	return cmdList;
}

std::shared_ptr<AXDevice> AXCreateDevice(unsigned int flag)
{
	std::shared_ptr<AXDevice> device = std::make_shared<AXDevice>(flag);

	if (flag & CREATE_AXDEVICE_DEBUG)
	{
		std::cout << "Debug Layer Active.\n";
		OutputDebugStringA("Debug Layer Active.\n");
	}



	return device;
}


std::shared_ptr<AXRenderTargetView> AXDevice::CreateRenderTargetView(const AX_RENDER_TARGET_VIEW_DESC& desc)
{
	std::shared_ptr<AXRenderTargetView> rtv = std::make_shared<AXRenderTargetView>();

	rtv->mDimension = desc.Dimension;

	return rtv;
}