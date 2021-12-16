#pragma once
#include<Windows.h>

struct AXTexture2D;

struct AX_CHAIN_DESC
{
	unsigned int Flag;
	HWND Hwnd;
	unsigned int BufferCount;
};

struct AXChain
{
	friend std::shared_ptr<AXChain> AXCreateChain(const AX_CHAIN_DESC& desc);
public:
	AXChain();
	~AXChain();

	void Present();

	void GetBuffer(unsigned int index, const std::shared_ptr<AXTexture2D>& outTexture);

private:
	HDC mMemoryDC;
	std::vector<HBITMAP> mBitmap;

	DWORD* mBuffer;

	unsigned int mBufferCount;
};

std::shared_ptr<AXChain> AXCreateChain(unsigned int flag, HWND hWnd);