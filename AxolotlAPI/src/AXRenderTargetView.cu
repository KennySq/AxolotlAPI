#include"pch.h"
#include"AXRenderTargetView.cuh"

__global__ void KernelClearRTV()
{
	
	return;
}

AXRenderTargetView::AXRenderTargetView()
{
	KernelClearRTV<< <1, 1,1>> > ();
	cudaDeviceSynchronize();

}

AXRenderTargetView::~AXRenderTargetView()
{
}
