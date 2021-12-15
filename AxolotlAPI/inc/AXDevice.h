#pragma once
#include<pch.h>
struct AXTexture2D;
struct AX_TEXTURE2D_DESC;
struct AXDevice
{
public:
	AXDevice(HWND hWnd, HINSTANCE hInstance);
	~AXDevice();

	std::shared_ptr<AXTexture2D> CreateTexture2D(const AX_TEXTURE2D_DESC& desc);

private:
	HWND mWinHandle;
	HINSTANCE mWinInstance;

	static unsigned int mInterfaceCounter;
};