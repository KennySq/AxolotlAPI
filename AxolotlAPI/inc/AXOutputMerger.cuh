#pragma once

struct AXRenderTargetView;
struct AXOutputMerger
{
public:
	AXOutputMerger();

	std::shared_ptr<AXRenderTargetView> GetRenderTargetView(unsigned int slot) const
	{
		assert(slot < 8 && slot >= 0);

		return mRenderTargets[slot];
	}
private:
	std::vector<std::shared_ptr<AXRenderTargetView>> mRenderTargets;
	// std::shared_ptr<AXDepthStencilView> mDepthStencil;
};