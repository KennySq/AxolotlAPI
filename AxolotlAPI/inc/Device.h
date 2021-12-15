#pragma once
#include<pch.h>
struct Texture2D;
struct AX_TEXTURE2D_DESC;
struct Device
{
public:
	Device(HWND hWnd, HINSTANCE hInstance);
	~Device();

	std::shared_ptr<Texture2D> CreateTexture2D(const AX_TEXTURE2D_DESC& desc);

private:
	HWND mWinHandle;
	HINSTANCE mWinInstance;

	static unsigned int mInterfaceCounter;
};