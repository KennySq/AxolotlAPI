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
	AXDeviceMemoryPool(size_t size);
	~AXDeviceMemoryPool();

	void* Alloc(unsigned int size);

	template<typename _Ty>
	_Ty* Alloc(unsigned int size)
	{
		_Ty* ptr = reinterpret_cast<_Ty*>((size_t)(mRaw)+mOffset);

		ptr = new(*ptr)_Ty;

		std::shared_ptr<AXDeviceMemoryAllocator> ma = std::make_shared<AXDeviceMemoryAllocator>(gPoolRaw, size, mOffset);

		mBlock.insert_or_assign(reinterpret_cast<void*>(ptr), ma);

		mOffset += size;

		return ptr;
	}


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