#pragma once
#include<pch.h>
#include"IAXResource.h"
#include"AXFormat.h"

struct AX_TEXTURE2D_DESC
{
	unsigned int Width;
	unsigned int Height;
	
	eAXFormat Format;
};

struct AXDeviceTexture2D;
struct AXTexture2D : public IAXResource
{
	friend struct AXDevice;
	friend struct AXChain;
	explicit AXTexture2D();
	~AXTexture2D();

	AX_TEXTURE2D_DESC GetDesc() const;

private:
	eAXFormat mFormat;

	unsigned int mWidth;
	unsigned int mHeight;
};