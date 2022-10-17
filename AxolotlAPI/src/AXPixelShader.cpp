#include<pch.h>
#include<AXPixelShader.h>
#include"AXDeviceTexture2D.cuh"

void AXPixelShader::BindRenderTarget(std::shared_ptr<AXDeviceTexture2D> texture)
{
}

void AXPixelShader::Execute()
{
	runInstructions();
}
