#include<pch.h>
#include"AXOutputMerger.cuh"

// mRenderTargets will be initialized 8 size fixed vector due to SM5 specification.
AXOutputMerger::AXOutputMerger()
	: mRenderTargets(8)
{
}
