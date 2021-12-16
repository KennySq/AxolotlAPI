#include<Axolotl.h>
#include "Sample.h"

SampleApp::SampleApp(HWND hWnd)
{
	mDevice = AXCreateDevice(CREATE_AXDEVICE_DEBUG);

	AX_TEXTURE2D_DESC texDesc{};
	AX_RENDER_TARGET_VIEW_DESC rtvDesc{};
	texDesc.Format = AX_R8G8B8A8_UNORM;
	texDesc.Width = 1280;
	texDesc.Height = 720;

	rtvDesc.Dimension = AX_RTV_DIMENSION_TEXTURE2D;

	mTexture = mDevice->CreateTexture2D(texDesc);
	mRTV = mDevice->CreateRenderTargetView(mTexture, rtvDesc);

	AX_CHAIN_DESC chainDesc{};

	chainDesc.BufferCount = 1;
	chainDesc.BufferFormat = AX_R8G8B8A8_UNORM;
	chainDesc.Hwnd = hWnd;
	chainDesc.Width = 1280;
	chainDesc.Height = 720;

	mChain = AXCreateChain(chainDesc);
	mContext = AXCreateContext(CREATE_AXDEVICE_DEBUG);
}

SampleApp::~SampleApp()
{
}

void SampleApp::Init()
{
}

void SampleApp::Update(float delta)
{
	static float clearColor[4] = { 1.0f, 0.0f, 1.0f, 1.0f };
	mContext->ClearRenderTarget(mRTV, clearColor);
	mContext->FinishCommandList(&mCmdList);
	mContext->ExecuteCommandList(mCmdList);
}

void SampleApp::Render(float delta)
{
	mChain->Present();
}

void SampleApp::Release()
{
}
