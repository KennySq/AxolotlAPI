#pragma once

#include<Axolotl.h>

#include<iostream>

#pragma comment(lib, "Axolotl.lib")

struct SampleApp
{
public:
	SampleApp(HWND hWnd);
	~SampleApp();

	void Init();
	void Update(float delta);
	void Render(float delta);
	void Release();
private:
	std::shared_ptr<AXDevice> mDevice;
	std::shared_ptr<AXChain> mChain;
	std::shared_ptr<AXContext> mContext;

	std::shared_ptr<AXCommandList> mCmdList;

	std::shared_ptr<AXTexture2D> mTexture;
	std::shared_ptr<AXRenderTargetView> mRTV;

	std::shared_ptr<AXBuffer> mVertexBuffer;
	std::shared_ptr<AXBuffer> mIndexBuffer;

	
};