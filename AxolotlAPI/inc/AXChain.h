#pragma once
#include<Windows.h>
#include"AXTexture.h"
#include"AXUtil.h"

struct AXTexture2D;

struct AX_CHAIN_DESC
{
	AX_CHAIN_DESC()
	{

	}
	AX_CHAIN_DESC(const AX_CHAIN_DESC& right)
		: Flag(right.Flag), Hwnd(right.Hwnd),
		BufferCount(right.BufferCount), BufferFormat(right.BufferFormat),
		Width(right.Width), Height(right.Height)
	{

	}
	unsigned int Flag;
	HWND Hwnd;
	unsigned int BufferCount;
	eAXFormat BufferFormat;
	unsigned int Width;
	unsigned int Height;
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
	HBITMAP mBitmap;

	DWORD* mBuffer;

	unsigned int mBufferCount;
};

inline std::shared_ptr<AXChain> AXCreateChain(const AX_CHAIN_DESC& desc)
{
	std::shared_ptr<AXChain> chain = std::make_shared<AXChain>();
	unsigned int bufferCount = desc.BufferCount;
	HDC dc = GetDC(desc.Hwnd);
	chain->mMemoryDC = CreateCompatibleDC(dc);

	BITMAPINFO bitmapInfo{};

	bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);

	AX_PIXEL_DESC pixelDesc = GetPixelDesc(desc.BufferFormat);

	bitmapInfo.bmiHeader.biBitCount = pixelDesc.BitPerComponent;
	bitmapInfo.bmiHeader.biWidth = desc.Width;
	bitmapInfo.bmiHeader.biHeight = desc.Height;
	bitmapInfo.bmiHeader.biCompression = BI_RGB;
	bitmapInfo.bmiHeader.biPlanes = 1;

	chain->mBitmap = CreateDIBSection(chain->mMemoryDC, &bitmapInfo, DIB_RGB_COLORS, reinterpret_cast<void**>(&chain->mBuffer), NULL, 0);

	if (chain->mBitmap == nullptr)
	{
		Log("failed to create dib section.");
	}

	return chain;
}