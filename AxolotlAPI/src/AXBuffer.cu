#include<pch.h>
#include"AXBuffer.cuh"

AXBuffer::AXBuffer()
{
}

AXBuffer::~AXBuffer()
{
}

AX_BUFFER_DESC AXBuffer::GetDesc() const
{
    AX_BUFFER_DESC desc{};

    desc.BindFlags = mBindFlags;
    desc.ByteSize = mSize;

    return desc;
}
