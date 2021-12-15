#include "AXDevice.h"
#include"AXTexture.h"

unsigned int AXDevice::mInterfaceCounter = 0;

AXDevice::AXDevice(HWND hWnd, HINSTANCE hInstance)
	: mWinHandle(hWnd), mWinInstance(hInstance)
{
}

AXDevice::~AXDevice()
{
}

std::shared_ptr<AXTexture2D> AXDevice::CreateTexture2D(const AX_TEXTURE2D_DESC& desc)
{
	std::shared_ptr<AXTexture2D> tex = std::make_shared<AXTexture2D>(desc);

	mInterfaceCounter++;

	return tex;
}
