#include<pch.h>
#include"AXDeviceMemoryPool.cuh"

__device__ void* gPoolRaw = nullptr;


AXDeviceMemoryAllocator::AXDeviceMemoryAllocator(void* poolPtr, unsigned int size, unsigned int offset)
	: Size(size), Raw(poolPtr), Offset(offset)
{
	
}

AXDeviceMemoryAllocator::~AXDeviceMemoryAllocator()
{

}

AXDeviceMemoryPool::AXDeviceMemoryPool(unsigned int size)
	: mOffset(0)
{
	cudaDeviceProp prop;
	int deviceIndex;

	cudaGetDevice(&deviceIndex);
	cudaGetDeviceProperties(&prop, deviceIndex);

	std::string memoryStr = std::to_string(prop.totalGlobalMem) + " bytes";
	std::string sizeStr = std::to_string(size);
	Log(std::string("Available device memory : ") + memoryStr);
	Log(std::string("Request ") + sizeStr + " bytes.");

	cudaError_t error = cudaMalloc(reinterpret_cast<void**>(&gPoolRaw), size);
	mRaw = gPoolRaw;

	if (error != NULL)
	{
		Log(cudaGetErrorString(error));
	}

	Log(std::string("Memory requesting success, " + sizeStr + " bytes allocated."));
}

AXDeviceMemoryPool::~AXDeviceMemoryPool()
{
}

void* AXDeviceMemoryPool::Alloc(unsigned int size)
{
	void* ptr = (void*)((size_t)(mRaw) + mOffset);

	std::shared_ptr<AXDeviceMemoryAllocator> ma = std::make_shared<AXDeviceMemoryAllocator>(gPoolRaw, size, mOffset);

	mBlock.insert_or_assign(ptr , ma);

	mOffset += size;

	return ptr;
}

void AXDeviceMemoryPool::ReleasePool()
{
	cudaFree(gPoolRaw);
}
