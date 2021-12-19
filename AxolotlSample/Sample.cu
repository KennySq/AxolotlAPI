#include<Axolotl.h>
#include<AX3DMath.h>
#include "Sample.h"

SampleApp::SampleApp(HWND hWnd)
{
	mDevice = AXCreateDevice(CREATE_AXDEVICE_DEBUG);

	AX_TEXTURE2D_DESC texDesc{};
	AX_BUFFER_DESC vbDesc{}, ibDesc{};
	AX_RENDER_TARGET_VIEW_DESC rtvDesc{};
	texDesc.Format = AX_R32G32B32A32_UNORM;
	texDesc.Width = 1280;
	texDesc.Height = 720;

	vbDesc.BindFlags = AX_BIND_VERTEX_BUFFER;
	

	rtvDesc.Dimension = AX_RTV_DIMENSION_TEXTURE2D;

	mTexture = mDevice->CreateTexture2D(texDesc);
	mRTV = mDevice->CreateRenderTargetView(mTexture, rtvDesc);

	AX_CHAIN_DESC chainDesc{};

	chainDesc.BufferCount = 1;
	chainDesc.BufferFormat = AX_R32G32B32A32_UNORM;
	chainDesc.Hwnd = hWnd;
	chainDesc.Width = 1280;
	chainDesc.Height = 720;

	mChain = AXCreateChain(chainDesc);
	mChain->BindTexture(0, mTexture);

	mContext = AXCreateContext(CREATE_AXDEVICE_DEBUG);
	mCmdList = mDevice->CreateCommandList();
}

SampleApp::~SampleApp()
{
}

void SampleApp::Init()
{
	AXFLOAT2 fl1(1, 2);
	AXFLOAT2 fl2(3, 5);

	AXFLOAT2 result = fl1 + fl2;
	result += fl1;
	result /= 2;
	result *= 3.0;

	AXFLOAT2 fl3(1, 0);

	float len = AXFloat2Length(fl3);
}

void SampleApp::Update(float delta)
{
	static float clearColor[4] = { 1.0f, 1.0f, 0.0f, 0.0f };

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
