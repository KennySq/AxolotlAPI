#include<pch.h>
#include"AXBytecode.h"

AXBytecode::AXBytecode(void* ptr, size_t size)
	: mPtr(reinterpret_cast<unsigned char*>(ptr)), mSize(size)
{
}

AXBytecode::~AXBytecode()
{
	delete[] mPtr;
	mSize = 0;

	return;
}
