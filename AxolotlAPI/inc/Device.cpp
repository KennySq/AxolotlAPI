#include "pch.h"
#include "Device.h"

#include"Texture.h"

unsigned int Device::mInterfaceCounter = 0;

Device::Device(HWND hWnd, HINSTANCE hInstance)
	: mWinHandle(hWnd), mWinInstance(hInstance)
{
}

Device::~Device()
{
}

std::shared_ptr<Texture2D> Device::CreateTexture2D(const AX_TEXTURE2D_DESC& desc)
{
	std::shared_ptr<Texture2D> tex = std::make_shared<Texture2D>(desc);

	mInterfaceCounter++;

	return tex;
}
