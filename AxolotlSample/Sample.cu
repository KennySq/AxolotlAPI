#include<Axolotl.h>
#include<AX3DMath.h>
#include "Sample.h"
#include"inc/Vertex.h"

SampleApp::SampleApp(HWND hWnd)
{
	mDevice = AXCreateDevice(CREATE_AXDEVICE_DEBUG);

	AX_TEXTURE2D_DESC texDesc{};
	AX_BUFFER_DESC vbDesc{}, ibDesc{};
	AX_RENDER_TARGET_VIEW_DESC rtvDesc{};
	texDesc.Format = AX_R32G32B32A32_UNORM;
	texDesc.Width = 1280;
	texDesc.Height = 720;

	Vertex vertices[] =
	{
		{-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f},
		{ 0.0f, 0.75f, 0.0f, 0.0f, 1.0f, 0.0f},
		{ 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f},
	};

	unsigned int indices[] =
	{
		0, 1, 2
	};

	vbDesc.BindFlags = AX_BIND_VERTEX_BUFFER;
	vbDesc.ByteSize = sizeof(Vertex) * 3;

	ibDesc.BindFlags = AX_BIND_INDEX_BUFFER;
	ibDesc.ByteSize = sizeof(unsigned int) * 3;

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

	mVertexBuffer = mDevice->CreateBuffer(vbDesc, vertices);
	mIndexBuffer = mDevice->CreateBuffer(ibDesc, indices);

	return;
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

	AXFLOAT3 v1 = AXFLOAT3(0, 1, 0);
	AXFLOAT3 v2 = AXFLOAT3(0, 0, 1);

	AXFLOAT3 crossed = AXFloat3Cross(v1, v2);

	AXFLOAT2 v3 = AXFLOAT2(1, 0);
	AXFLOAT2 v4 = AXFLOAT2(0, 1);

	AXFLOAT2 crossed2d = AXFloat2Cross(v3, v4);

	AXFLOAT4X4 mat1, mat2;

	mat1 = AXFLOAT4X4::Identity();
	mat2 = AXFLOAT4X4::Identity();

	mat1 = AXFloat4x4Multiply(mat1, mat2);

	AXFLOAT4X4 mat3 = AXFLOAT4X4(5, 3, 77, 45, 33.2, 1.57, 35.66, 43, 69, 21, 12, 5, 68, 9, 11, 49);
	float det = AXFloat4x4Determinant(mat3);


}

void SampleApp::Update(float delta)
{
	static float clearColor[4] = { 1.0f, 1.0f, 0.0f, 0.0f };

	mContext->ClearRenderTarget(mRTV, clearColor);

	
}

void SampleApp::Render(float delta)
{
	mChain->Present();
}

void SampleApp::Release()
{
}
