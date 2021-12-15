#include<pch.h>
#include"Texture.h"

Texture2D::Texture2D(const AX_TEXTURE2D_DESC& descriptor)
	: mFormat(descriptor.Format), mWidth(descriptor.Width), mHeight(descriptor.Height)
{
	
}

Texture2D::~Texture2D()
{
}