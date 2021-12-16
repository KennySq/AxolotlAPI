#pragma once
#include<Windows.h>

struct AXTexture2D;
struct AXChain
{
public:
	AXChain();
	~AXChain();

	void Present();

	void GetBuffer(unsigned int index, const std::shared_ptr<AXTexture2D>& outTexture);

private:
	std::vector<HDC> mMemoryDC;
	std::vector<HBITMAP> mBitmap;

	DWORD* mBuffer;

	unsigned int mBufferCount;
};

std::shared_ptr<AXChain> AXCreateChain(unsigned int flag);