#include<Axolotl.h>
#include "Sample.h"

SampleApp::SampleApp()
{
	mDevice = AXCreateDevice(CREATE_AXDEVICE_DEBUG);

	AX_TEXTURE2D_DESC texDesc{};
	AX_RENDER_TARGET_VIEW_DESC rtvDesc{};

	std::shared_ptr<AXRenderTargetView> rtv = mDevice->CreateRenderTargetView(rtvDesc);

	std::shared_ptr<AXChain> chain = AXCreateChain(0);
}

SampleApp::~SampleApp()
{
}

void SampleApp::Init()
{
}

void SampleApp::Update(float delta)
{
}

void SampleApp::Render(float delta)
{
}

void SampleApp::Release()
{
}
