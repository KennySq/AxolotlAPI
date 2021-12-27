#pragma once

enum AX_BIND_FLAG
{
	AX_BIND_VERTEX_BUFFER = 0,
	AX_BIND_INDEX_BUFFER = 1,
	AX_BIND_SHADER_RESOURCE = 2,
	AX_BIND_RENDER_TARGET = 4,
};

struct IAXResource
{
	friend struct AXContext;
	friend struct AXRasterizer;


protected:
	void* mRaw;
};