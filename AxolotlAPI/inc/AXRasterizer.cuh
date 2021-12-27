#pragma once
#include<pch.h>
#include"AX3DMath.h"

struct AXInputAssembler;
struct AXVertexStage;
struct IAXResource;

struct AXRasterizer
{
public:
	AXRasterizer();

	void Process(std::shared_ptr<IAXResource> texture, unsigned int width, unsigned int height, AXFLOAT2* projectedData, unsigned int vertexCount);
private:
	unsigned int mWidth;
	unsigned int mHeight;
};