#pragma once
#include"AXView.h"

struct AX_RENDER_TARGET_VIEW_DESC
{
	eAXDimension Dimension;
};

struct AXDeviceTexture2D;
 struct AXRenderTargetView
{
	friend struct AXDevice;
public:

	__declspec(dllexport) AXRenderTargetView();
	__declspec(dllexport) ~AXRenderTargetView();
private:
	eAXDimension mDimension;
};