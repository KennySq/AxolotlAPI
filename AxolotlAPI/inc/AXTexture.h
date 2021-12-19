#pragma once
#include<pch.h>
#include"IAXResource.h"

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

struct AX_PIXEL_DESC
{
	enum eType
	{
		TYPE_FLOAT,
		TYPE_UNORM,
		TYPE_SNORM,
		TYPE_UINT,
		TYPE_SINT,
	};

	unsigned int BitPerComponent;
	unsigned int Components;
	eType Type;
};

static AX_PIXEL_DESC GetPixelDesc(eAXFormat format)
{
	AX_PIXEL_DESC desc{};

	switch (format)
	{
	case AX_R32G32B32A32_FLOAT:
		desc.BitPerComponent = 32;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_FLOAT;
		break;

	case AX_R32G32B32A32_UNORM:
		desc.BitPerComponent = 32;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_UNORM;
		break;

	case AX_R32G32B32A32_SNORM:
		desc.BitPerComponent = 32;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_SNORM;
		break;
	case AX_R32G32B32A32_UINT:
		desc.BitPerComponent = 32;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_UINT;
		break;

		//-----------------------------------------------
	case AX_R16G16B16A16_FLOAT:
		desc.BitPerComponent = 16;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_FLOAT;
		break;

	case AX_R16G16B16A16_UNORM:
		desc.BitPerComponent = 16;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_UNORM;
		break;

	case AX_R16G16B16A16_SNORM:
		desc.BitPerComponent = 16;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_SNORM;
		break;

	case AX_R16G16B16A16_UINT:
		desc.BitPerComponent = 16;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_UINT;
		break;

		//---------------------------------------

	case AX_R8G8B8A8_FLOAT:
		desc.BitPerComponent = 8;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_FLOAT;
		break;
	case AX_R8G8B8A8_UNORM:
		desc.BitPerComponent = 8;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_UNORM;
		break;
	case AX_R8G8B8A8_SNORM:
		desc.BitPerComponent = 8;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_SNORM;
		break;
	case AX_R8G8B8A8_UINT:
		desc.BitPerComponent = 8;
		desc.Components = 4;
		desc.Type = AX_PIXEL_DESC::TYPE_UINT;
		break;

		//-------------------------------------------

	case AX_R32G32B32_FLOAT:
		desc.BitPerComponent = 32;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_FLOAT;
		break;
	case AX_R32G32B32_UNORM:
		desc.BitPerComponent = 32;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_UNORM;
		break;
	case AX_R32G32B32_SNORM:
		desc.BitPerComponent = 32;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_SNORM;
		break;
	case AX_R32G32B32_UINT:
		desc.BitPerComponent = 32;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_UINT;
		break;

		//---------------------------------------------

	case AX_R16G16B16_FLOAT:
		desc.BitPerComponent = 16;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_FLOAT;
		break;
	case AX_R16G16B16_UNORM:
		desc.BitPerComponent = 16;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_UNORM;
		break;
	case AX_R16G16B16_SNORM:
		desc.BitPerComponent = 16;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_SNORM;
		break;
	case AX_R16G16B16_UINT:
		desc.BitPerComponent = 16;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_UINT;
		break;

		//--------------------------------------------
	case AX_R8G8B8_FLOAT:
		desc.BitPerComponent = 8;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_FLOAT;
		break;
	case AX_R8G8B8_UNORM:
		desc.BitPerComponent = 8;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_UNORM;
		break;
	case AX_R8G8B8_SNORM:
		desc.BitPerComponent = 8;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_SNORM;
		break;
	case AX_R8G8B8_UINT:
		desc.BitPerComponent = 8;
		desc.Components = 3;
		desc.Type = AX_PIXEL_DESC::TYPE_UINT;
		break;

		//---------------------------------------------
	case AX_R32G32_FLOAT:
		desc.BitPerComponent = 32;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_FLOAT;
		break;
	case AX_R32G32_UNORM:
		desc.BitPerComponent = 32;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_UNORM;
		break;
	case AX_R32G32_SNORM:
		desc.BitPerComponent = 32;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_SNORM;
		break;
	case AX_R32G32_UINT:
		desc.BitPerComponent = 32;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_UINT;
		break;
		//---------------------------------------------
	case AX_R16G16_FLOAT:
		desc.BitPerComponent = 16;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_FLOAT;
		break;
	case AX_R16G16_UNORM:
		desc.BitPerComponent = 16;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_UNORM;
		break;
	case AX_R16G16_SNORM:
		desc.BitPerComponent = 16;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_SNORM;
		break;
	case AX_R16G16_UINT:
		desc.BitPerComponent = 16;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_UINT;
		break;
		//---------------------------------------------
	case AX_R8G8_FLOAT:
		desc.BitPerComponent = 8;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_FLOAT;
		break;
	case AX_R8G8_UNORM:
		desc.BitPerComponent = 8;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_UNORM;
		break;
	case AX_R8G8_SNORM:
		desc.BitPerComponent = 8;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_SNORM;
		break;
	case AX_R8G8_UINT:
		desc.BitPerComponent = 8;
		desc.Components = 2;
		desc.Type = AX_PIXEL_DESC::TYPE_UINT;
		break;
		//---------------------------------------------
	case AX_R32_FLOAT:
		desc.BitPerComponent = 32;
		desc.Components = 1;
		desc.Type = AX_PIXEL_DESC::TYPE_FLOAT;
		break;
	case AX_R32_UNORM:
		desc.BitPerComponent = 32;
		desc.Components = 1;
		desc.Type = AX_PIXEL_DESC::TYPE_UNORM;
		break;
	case AX_R32_SNORM:
		desc.BitPerComponent = 32;
		desc.Components = 1;
		desc.Type = AX_PIXEL_DESC::TYPE_SNORM;
		break;
	case AX_R32_UINT:
		desc.BitPerComponent = 32;
		desc.Components = 1;
		desc.Type = AX_PIXEL_DESC::TYPE_UINT;
		break;
		//---------------------------------------------
	}

	return desc;
}
struct AXDeviceTexture2D;
struct AXTexture2D : public IAXResource
{
	friend struct AXDevice;
	friend struct AXChain;
	explicit AXTexture2D();
	~AXTexture2D();

	AX_TEXTURE2D_DESC GetDesc() const;

private:
	eAXFormat mFormat;

	unsigned int mWidth;
	unsigned int mHeight;
};