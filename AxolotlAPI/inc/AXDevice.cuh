#pragma once
#include<pch.h>

struct IAXResource;
struct AXCommandList;
struct AXTexture2D;
struct AXRenderTargetView;
struct AXDeviceMemoryPool;
struct AXBuffer;

struct AX_TEXTURE2D_DESC;
struct AX_RENDER_TARGET_VIEW_DESC;
struct AX_BUFFER_DESC;

#define CREATE_AXDEVICE_DEBUG 0xffffffff

struct AXDevice
{
	struct AX_DEVICE_INFO
	{
		unsigned long long MemoryCapacity;
	};

public:
	AXDevice(unsigned int flag);
	~AXDevice();

	std::shared_ptr<AXTexture2D> CreateTexture2D(const AX_TEXTURE2D_DESC& desc);
	std::shared_ptr<AXCommandList> CreateCommandList();

	std::shared_ptr<AXInputLayout> CreateInputLayout(AX_INPUT_ELEMENT* const inputElements, unsigned int elementCount);

	std::shared_ptr<AXBuffer> CreateBuffer(const AX_BUFFER_DESC& desc, void* subResource);

	std::shared_ptr<AXRenderTargetView> CreateRenderTargetView(std::shared_ptr<IAXResource> resource, const AX_RENDER_TARGET_VIEW_DESC& desc);

private:
	HWND mWinHandle;
	HINSTANCE mWinInstance;

	unsigned int mDeviceFlag;
	static unsigned int mInterfaceCounter;

	

	std::shared_ptr<AXDeviceMemoryPool> mMemory;
};

std::shared_ptr<AXDevice> AXCreateDevice(unsigned int flag);
