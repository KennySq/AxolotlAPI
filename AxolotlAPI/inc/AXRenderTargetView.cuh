#pragma once
#include"AXView.h"

struct AX_RENDER_TARGET_VIEW_DESC
{
	eAXDimension Dimension;
};

struct IAXResource;
struct AXDeviceTexture2D;
 struct AXRenderTargetView
{
	 friend struct AXContext;
	friend struct AXDevice;
public:

	AXRenderTargetView();
	~AXRenderTargetView();
private:
	eAXDimension mDimension;
	std::shared_ptr<IAXResource> mResource;
};