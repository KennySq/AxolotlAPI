#pragma once
#include<AX3DMath.h>
#include<Singleton.h>
#include<AXShaderAssembly.h>

static __host__ __device__ void AXShaderDot(AXShaderAssemblyVector dest, AXShaderAssemblyVector asmv0, AXShaderAssemblyVector asmv1)
{
	AXFLOAT4* v0 = asmv0.Vector;
	AXFLOAT4* v1 = asmv1.Vector;
	AXFLOAT4* v2 = dest.Vector;
	
	float result = (v0->x * v1->y) + (v0->y * v1->y) + (v0->z * v1->z) + (v0->w * v1->w);

	AXFLOAT4 temp = AXFLOAT4(result, result, result, result);
	
	swizzle(v2, temp, dest.Operand);
}