#include<pch.h>
#include "..\inc\AXChain.h"

AXChain::AXChain()
{
}

AXChain::~AXChain()
{
}

void AXChain::Present()
{
	
}

std::shared_ptr<AXChain> AXCreateChain(const AX_CHAIN_DESC& desc)
{
	std::shared_ptr<AXChain> chain = std::make_shared<AXChain>();
	unsigned int bufferCount = desc.BufferCount;
	HDC dc = GetDC(desc.Hwnd);
	chain->mMemoryDC.push_back(CreateCompatibleDC(dc));

	BITMAPINFO bitmapInfo{};

	bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bitmapInfo.bmiHeader.biBitCount = 
	
	for (unsigned int i = 0; i < BufferCount; i++)
	{

	}

	


	return chain;
}
