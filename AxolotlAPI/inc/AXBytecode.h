#pragma once

struct AXBytecode
{
	friend static bool AXCompileFromFile(const char* path, const char* target, const char* entry, unsigned int flag, std::shared_ptr<AXBytecode> pOutBytecode);

	AXBytecode(void* ptr, size_t size);
	~AXBytecode();

	void* GetPointer() const { return mPtr; }
	size_t GetSize() const { return mSize; }
private:
	unsigned char* mPtr;
	size_t mSize;
};
