#pragma once
#include"IAXResource.h"

struct IAXResource;

struct AX_BUFFER_DESC
{
	size_t ByteSize;
	AX_BIND_FLAG BindFlags;
};

struct AXBuffer : public IAXResource
{
	friend struct AXDevice;
	friend struct AXContext;
public:
	explicit AXBuffer();
	~AXBuffer();

	void* GetVirtual() const { return mVirtual; }

	AX_BUFFER_DESC GetDesc() const;

private:
	void* mVirtual;
	unsigned int mSize;
	AX_BIND_FLAG mBindFlags;
};