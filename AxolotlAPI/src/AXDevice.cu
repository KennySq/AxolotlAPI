#include"pch.h"
#include "AXDevice.cuh"
#include"AXTexture.h"
#include"AXCommandList.h"
#include"AXRenderTargetView.h"

#include<Windows.h>

unsigned int AXDevice::mInterfaceCounter = 0;

AXDevice::AXDevice(unsigned int flag)
	: mDeviceFlag(flag)
{
}

AXDevice::~AXDevice()
{
}

__global__ void KernelCreateTexture2D(const AX_TEXTURE2D_DESC desc)
{
	
}

std::shared_ptr<AXTexture2D> AXDevice::CreateTexture2D(const AX_TEXTURE2D_DESC& desc)
{

	mInterfaceCounter++;

	return nullptr;
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