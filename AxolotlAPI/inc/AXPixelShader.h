#pragma once
#include<AXShader.h>

struct AXDeviceTexture2D;
struct AXPixelShader : public AXShader
{
public:
	AXPixelShader() {}
	~AXPixelShader() {}

	void BindRenderTarget(std::shared_ptr<AXDeviceTexture2D> texture);
	virtual void Execute() override;

private:
	std::shared_ptr<AXDeviceTexture2D> mBoundTexture;

};