#include<pch.h>
#include"AXOutputMerger.cuh"

// mRenderTargets will be initialized 8 size fixed vector due to ps_5_0 specification.
AXOutputMerger::AXOutputMerger()
	: mRenderTargets(8)
{
}
