#pragma once
#include<Windows.h>

struct AXChain
{
public:
	AXChain();
	~AXChain();

	void Present();

private:
	HDC mMemoryDC;
	HBITMAP mBitmap;

	DWORD* mBuffer;

	unsigned int mBufferCount;
};

std::shared_ptr<AXChain> AXCreateChain(unsigned int flag);