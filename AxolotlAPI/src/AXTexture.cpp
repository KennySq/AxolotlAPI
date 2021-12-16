#include"pch.h"
#include"AXTexture.h"
#include"AXUtil.h"

AXTexture2D::AXTexture2D()
{


}

AXTexture2D::~AXTexture2D()
{
}

void AXTexture2D::bindDeviceTexture(std::shared_ptr<AXDeviceTexture2D> tex)
{
	mDeviceTexture = tex;
}
