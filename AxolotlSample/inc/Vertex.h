#pragma once
#include"AX3DMath.h"

struct Vertex
{
	Vertex(float px, float py, float pz, float cx, float cy, float cz)
		: Position(px, py, pz), Color(cx, cy, cz)
	{

	}

	AXFLOAT3 Position;
	AXFLOAT3 Color;
};