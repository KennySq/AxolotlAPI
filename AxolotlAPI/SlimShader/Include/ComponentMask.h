#pragma once

#include "PCH.h"

namespace SlimShader
{
	enum class ComponentMask
	{
		None = 0,

		X = 1,
		Y = 2,
		Z = 4,
		W = 8,

		R = 1,
		G = 2,
		B = 4,
		A = 8,

		All = X | Y | Z | W // 15
	};

	std::string ToStringShex(ComponentMask value);
};