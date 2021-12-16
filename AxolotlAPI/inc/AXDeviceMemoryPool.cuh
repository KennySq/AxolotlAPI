#pragma once;

#include"AXUtil.h"

struct AXDeviceMemoryAllocator
{
	AXDeviceMemoryAllocator(void* poolPtr, unsigned int size, unsigned int offset);
	~AXDeviceMemoryAllocator();

	inline void* GetPtr() const
	{
		return (void*)((size_t)Raw + Offset);
	}

	const unsigned int Size;
	const unsigned int Offset;
	void* Raw;
	

};

struct AXDeviceMemoryPool
{
public:
	AXDeviceMemoryPool(unsigned int size);
	~AXDeviceMemoryPool();

	void* Alloc(unsigned int size);
	void* GetRaw() const
	{
		return mRaw;
	}

	void ReleasePool();
private:

	std::map<void*, std::shared_ptr<AXDeviceMemoryAllocator>> mBlock;

	void* mRaw;
	unsigned int mOffset;


};