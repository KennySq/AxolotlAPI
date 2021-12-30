#include "PCH.h"

namespace SlimShader
{
	enum class TessellatorOutputPrimitive
	{
		Undefined = 0,

		Point = 1,
		Line = 2,
		TriangleCw = 3,
		TriangleCcw = 4
	};

	std::string ToStringShex(TessellatorOutputPrimitive value);
	std::string ToStringStat(TessellatorOutputPrimitive value);
};