#pragma once
#include<AX3DMath.h>
#include<Singleton.h>

static __host__ __device__ float AXShaderDot(const AXFLOAT4* v0, const AXFLOAT4* v1)
{
	return (v0->x * v1->x) + (v0->y * v1->y) + (v0->z * v1->z) + (v0->w * v1->w);
}