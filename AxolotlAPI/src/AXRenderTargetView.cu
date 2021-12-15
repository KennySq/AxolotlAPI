#include"pch.h"
#include"AXRenderTargetView.cuh"

__global__ void KernelInvokeRTV()
{
	printf("Hello World\n");
	return;
}

AXRenderTargetView::AXRenderTargetView()
{
	mClearRTV = KernelInvokeRTV;

	KernelInvokeRTV << <1, 1,1>> > ();
//	KernelInvokeRTV<<<1,1>>>();
	cudaDeviceSynchronize();

	mClearRTV();
	cudaDeviceSynchronize();

	printf("Hello World\n");

}

AXRenderTargetView::~AXRenderTargetView()
{
}
