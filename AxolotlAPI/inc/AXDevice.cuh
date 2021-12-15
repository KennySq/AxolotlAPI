#pragma once
#include<pch.h>
struct AXCommandList;
struct AXTexture2D;
struct AXRenderTargetView;

struct AX_TEXTURE2D_DESC;
struct AX_RENDER_TARGET_VIEW_DESC;

#define CREATE_AXDEVICE_DEBUG 0xffffffff

struct AXDevice
{
public:
	__declspec(dllexport) AXDevice(unsigned int flag);
	__declspec(dllexport) ~AXDevice();

	std::shared_ptr<AXTexture2D> CreateTexture2D(const AX_TEXTURE2D_DESC& desc);
	std::shared_ptr<AXCommandList> CreateCommandList();
	__declspec(dllexport) std::shared_ptr<AXRenderTargetView> CreateRenderTargetView(const AX_RENDER_TARGET_VIEW_DESC& desc);

private:
	HWND mWinHandle;
	HINSTANCE mWinInstance;

	unsigned int mDeviceFlag;
	static unsigned int mInterfaceCounter;
};

__declspec(dllexport) std::shared_ptr<AXDevice> AXCreateDevice(unsigned int flag);
