#include<pch.h>
#include"AXTexture.h"

AXTexture2D::AXTexture2D(const AX_TEXTURE2D_DESC& descriptor)
	: mFormat(descriptor.Format), mWidth(descriptor.Width), mHeight(descriptor.Height)
{
	
}

AXTexture2D::~AXTexture2D()
{
}