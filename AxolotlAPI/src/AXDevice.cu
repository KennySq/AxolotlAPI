#include"pch.h"
#include "AXDevice.cuh"
#include"AXTexture.h"
#include"AXCommandList.h"
#include"AXRenderTargetView.cuh"
#include"AXDeviceTexture2D.cuh"
#include"AXDeviceMemoryPool.cuh"
#include"AXBuffer.cuh"
#include"AXInputLayout.cuh"

#include"AXVertexShader.cuh"

#include"AXBytecode.h"


#include"IAXResource.h"

#include<Windows.h>

unsigned int AXDevice::mInterfaceCounter = 0;

__declspec(dllexport) __global__ void KernelWriteRaw(int data, void* raw, unsigned int offset)
{
	void* ptr = (void*)((size_t)raw + offset);
	int* asInt = reinterpret_cast<int*>(ptr);

	*asInt = data;
}

__declspec(dllexport) __global__ void KernelViewRaw(unsigned int offset, void* raw)
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
	cudaDeviceProp prop;
	int deviceIndex;

	cudaDeviceSynchronize();

	cudaGetDevice(&deviceIndex);
	cudaGetDeviceProperties(&prop, deviceIndex);
	
	std::string memoryStr = std::to_string(prop.totalGlobalMem / 4) + " bytes";
	Log(std::string("Available device memory : ") + memoryStr);

	mMemory = std::make_shared<AXDeviceMemoryPool>(prop.totalGlobalMem / 4);
}

AXDevice::~AXDevice()
{
	mMemory->ReleasePool();
}

std::shared_ptr<AXTexture2D> AXDevice::CreateTexture2D(const AX_TEXTURE2D_DESC& desc)
{
	unsigned int perPixel = 0;
	unsigned int totalSize = 0;

	AX_PIXEL_DESC pixelDesc = GetPixelDesc(desc.Format);

	totalSize = (desc.Width * desc.Height * pixelDesc.BitPerComponent * pixelDesc.Components) / 8;

	void* devicePtr = mMemory->Alloc(totalSize);

	std::shared_ptr<AXTexture2D> tex = std::make_shared<AXTexture2D>();
	// update from here 2021/12/16 2:51 PM

	tex->mWidth = desc.Width;
	tex->mHeight = desc.Height;
	tex->mFormat = desc.Format;
	tex->mRaw = devicePtr;

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

std::shared_ptr<AXInputLayout> AXDevice::CreateInputLayout(AX_INPUT_ELEMENT* const inputElements, unsigned int elementCount)
{
	std::shared_ptr<AXInputLayout> il = std::make_shared<AXInputLayout>();
	
	il->mElements.resize(elementCount);

	for (unsigned int i = 0; i < elementCount; i++)
	{	
		il->mElements[i] = inputElements[i];
	}

	return il;
}

std::shared_ptr<AXBuffer> AXDevice::CreateBuffer(const AX_BUFFER_DESC& desc, void* subResource)
{
	std::shared_ptr<AXBuffer> buffer = std::make_shared<AXBuffer>();

	buffer->mRaw = mMemory->Alloc(desc.ByteSize);

	if (subResource != nullptr)
	{
		cudaError_t error = cudaMemcpy(buffer->mRaw, subResource, desc.ByteSize, cudaMemcpyHostToDevice);

		if (error != NULL)
		{
			Log("subresource copy fail");
			Log(cudaGetErrorString(error));
		}
	}

	buffer->mSize = desc.ByteSize;
	buffer->mBindFlags = desc.BindFlags;

	return buffer;
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


std::shared_ptr<AXRenderTargetView> AXDevice::CreateRenderTargetView(std::shared_ptr<IAXResource> resource, const AX_RENDER_TARGET_VIEW_DESC& desc)
{
	std::shared_ptr<AXRenderTargetView> rtv = std::make_shared<AXRenderTargetView>();

	rtv->mDimension = desc.Dimension;
	rtv->mResource = resource;

	return rtv;
}

std::shared_ptr<AXVertexShader> AXDevice::CreateVertexShader(std::shared_ptr<AXBytecode> bytecode)
{
	//SlimShader::BytecodeReader reader = SlimShader::BytecodeReader(bytecode->)
	//return std::shared_ptr<AXVertexShader>();

	return nullptr;
}
