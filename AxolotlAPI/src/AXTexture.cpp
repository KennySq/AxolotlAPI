#include"pch.h"
#include"AXTexture.h"
#include"AXUtil.h"

AXTexture2D::AXTexture2D()
{


}

AXTexture2D::~AXTexture2D()
{
}

AX_TEXTURE2D_DESC AXTexture2D::GetDesc() const
{
	AX_TEXTURE2D_DESC desc{};

	desc.Format = mFormat;
	desc.Height = mHeight;
	desc.Width = mWidth;

	return desc;
}
