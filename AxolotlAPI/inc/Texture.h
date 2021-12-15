#pragma once
#include<pch.h>

enum eAXFormat
{
	// RGBA 128 bit
	AX_R32G32B32A32_FLOAT,
	AX_R32G32B32A32_UNORM,
	AX_R32G32B32A32_SNORM,
	AX_R32G32B32A32_UINT,

	// RGBA 64 bit
	AX_R16G16B16A16_FLOAT,
	AX_R16G16B16A16_UNORM,
	AX_R16G16B16A16_SNORM,
	AX_R16G16B16A16_UINT,

	// RGBA 32 bit
	AX_R8G8B8A8_FLOAT,
	AX_R8G8B8A8_UNORM,
	AX_R8G8B8A8_SNORM,
	AX_R8G8B8A8_UINT,
	
	// RGB 96 bit
	AX_R32G32B32_FLOAT,
	AX_R32G32B32_UNORM,
	AX_R32G32B32_SNORM,
	AX_R32G32B32_UINT,

	// RGB 48 bit
	AX_R16G16B16_FLOAT,
	AX_R16G16B16_UNORM,
	AX_R16G16B16_SNORM,
	AX_R16G16B16_UINT,

	// RGB 24 bit
	AX_R8G8B8_FLOAT,
	AX_R8G8B8_UNORM,
	AX_R8G8B8_SNORM,
	AX_R8G8B8_UINT,

	// RG 64 bit
	AX_R32G32_FLOAT,
	AX_R32G32_UNORM,
	AX_R32G32_SNORM,
	AX_R32G32_UINT,
	
	// RG 32 bit
	AX_R16G16_FLOAT,
	AX_R16G16_UNORM,
	AX_R16G16_SNORM,
	AX_R16G16_UINT,
	
	// RG 16 bit
	AX_R8G8_FLOAT,
	AX_R8G8_UNORM,
	AX_R8G8_SNORM,
	AX_R8G8_UINT,

	// R 32 bit
	AX_R32_FLOAT,
	AX_R32_UNORM,
	AX_R32_SNORM,
	AX_R32_UINT,
};

struct AX_TEXTURE2D_DESC
{
	unsigned int Width;
	unsigned int Height;
	
	eAXFormat Format;
};

struct Texture2D
{
	explicit Texture2D(const AX_TEXTURE2D_DESC& descriptor);
	~Texture2D();

private:

	const eAXFormat mFormat;

	unsigned int mWidth;
	unsigned int mHeight;

	DWORD* mRaw;
	HBITMAP* mBitmap;
	HDC* mMemoryDC;
};