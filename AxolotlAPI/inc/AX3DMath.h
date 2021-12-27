#pragma once

#include<immintrin.h>

struct AXFLOAT2
{
	__vectorcall AXFLOAT2(float _x, float _y)
		: x(_x), y(_y)
	{
	}
	__vectorcall AXFLOAT2()
		: x(.0f), y(.0f)
	{

	}

	union
	{
		float r[2];
		struct
		{
			float x;
			float y;
		};
	};
};

struct AXFLOAT3
{
	__vectorcall AXFLOAT3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z)
	{

	}
	__vectorcall AXFLOAT3()
		: x(.0f), y(.0f), z(.0f)
	{

	}
	union
	{
		float r[3];
		struct
		{
			float x;
			float y;
			float z;
		};
	};
};

struct AXFLOAT4
{
	__vectorcall AXFLOAT4(float _x, float _y, float _z, float _w)
		: x(_x), y(_y), z(_z), w(_w)
	{

	}
	__vectorcall AXFLOAT4()
		: x(.0f), y(.0f), z(.0f), w(.0f)
	{

	}
	union
	{
		float r[4];
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};

struct __AXFLOAT2X2PRV
{
	__AXFLOAT2X2PRV(float s0, float s1, float s2, float s3)
		: _11(s0), _12(s1), _21(s2), _22(s3)
	{

	}
	union
	{
		float r[4];
		struct
		{
			float _11, _12;
			float _21, _22;
		};
	};
};

struct AXFLOAT3X3
{
	static AXFLOAT3X3 Identity()
	{
		return AXFLOAT3X3(1, 0, 0, 0, 1, 0, 0, 0, 1);
	}

	__vectorcall AXFLOAT3X3()
	{
	}

	__vectorcall AXFLOAT3X3(float s0, float s1, float s2, float s3, float s4, float s5, float s6, float s7, float s8)
		: _11(s0), _12(s1), _13(s2), _21(s3), _22(s4), _23(s5), _31(s6), _32(s7), _33(s8)
	{

	}

	union
	{
		__m128 r;
		struct
		{
			float _11; float _12; float _13;
			float _21; float _22; float _23;
			float _31; float _32; float _33;
		};
	};

};

struct AXVECTOR
{
	AXVECTOR(float _x, float _y, float _z, float _w)
		: x(_x), y(_y), z(_z), w(_w)
	{

	}

	AXVECTOR(const AXFLOAT2& v)
		: x(v.x), y(v.y)
	{

	}

	AXVECTOR(const AXFLOAT3& v)
		: x(v.x), y(v.y), z(v.z)
	{
		
	}

	AXVECTOR(const AXFLOAT4& v)
		: x(v.x), y(v.y), z(v.z), w(v.w)
	{

	}

	union
	{
		__m128 r;
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};

struct AXFLOAT4X4
{
	static AXFLOAT4X4 Identity()
	{
		return AXFLOAT4X4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	}

	__vectorcall AXFLOAT4X4()
	{

	}
	__vectorcall AXFLOAT4X4(float s0, float s1, float s3, float s4, float s5, float s6, float s7, float s8, float s9, float s10, float s11, float s12, float s13, float s14, float s15, float s16)
		: _11(s0), _12(s1), _13(s3), _14(s4), _21(s5), _22(s6), _23(s7), _24(s8), _31(s9), _32(s10), _33(s11), _34(s12), _41(s13), _42(s14), _43(s15), _44(s16)
	{

	}
	union
	{
		AXFLOAT4 r[4];
		struct
		{
			float _11; float _12; float _13; float _14;
			float _21; float _22; float _23; float _24;
			float _31; float _32; float _33; float _34;
			float _41; float _42; float _43; float _44;
		};
	};
};

//---------------------------------------------------------------
// AXFLOAT2

inline AXFLOAT2 __vectorcall operator+(const AXFLOAT2& v1, const AXFLOAT2& v2)
{
	return AXFLOAT2(v1.x + v2.x, v1.y + v2.y);
}

inline void __vectorcall operator+=(AXFLOAT2& v1, const AXFLOAT2& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
}

inline AXFLOAT2 __vectorcall operator-(const AXFLOAT2& v1, const AXFLOAT2& v2)
{
	return AXFLOAT2(v1.x - v2.x, v1.y - v2.y);
}

inline void __vectorcall operator-=(AXFLOAT2& v1, const AXFLOAT2& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
}


inline AXFLOAT2 __vectorcall operator*(const AXFLOAT2& v1, float s)
{
	return AXFLOAT2(v1.x * s, v1.y * s);
}

inline void __vectorcall operator*=(AXFLOAT2& v, float s)
{
	v.x *= s;
	v.y *= s;
}

inline AXFLOAT2 __vectorcall operator/(const AXFLOAT2& v1, float s)
{
	return AXFLOAT2(v1.x / s, v1.y / s);
}

inline void __vectorcall operator/=(AXFLOAT2& v, float s)
{
	v.x /= s;
	v.y /= s;
}

//---------------------------------------------------------------
// AXFLOAT3

inline AXFLOAT3 __vectorcall operator+(const AXFLOAT3& v1, const AXFLOAT3& v2)
{
	return AXFLOAT3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline void __vectorcall operator+=(AXFLOAT3& v1, const AXFLOAT3& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
}

inline AXFLOAT3 __vectorcall operator-(const AXFLOAT3& v1, const AXFLOAT3& v2)
{
	return AXFLOAT3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline void __vectorcall operator-=(AXFLOAT3& v1, const AXFLOAT3& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
}

inline AXFLOAT3 __vectorcall operator*(const AXFLOAT3& v, float s)
{
	return AXFLOAT3(v.x * s, v.y * s, v.z * s);
}

inline void __vectorcall operator*=(AXFLOAT3& v, float s)
{
	v.x *= s;
	v.y *= s;
	v.z *= s;
}

inline AXFLOAT3 __vectorcall operator/(const AXFLOAT3& v1, float s)
{
	return AXFLOAT3(v1.x / s, v1.y / s, v1.z / s);
}

inline void __vectorcall operator/=(AXFLOAT3& v, float s)
{
	v.x /= s;
	v.y /= s;
	v.z /= s;
}

//---------------------------------------------------------------
// AXFLOAT4

inline AXFLOAT4 __vectorcall operator+(const AXFLOAT4& v1, const AXFLOAT4& v2)
{
	return AXFLOAT4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

inline void __vectorcall operator+=(AXFLOAT4& v1, const AXFLOAT4& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	v1.w += v2.w;
}

inline AXFLOAT4 __vectorcall operator-(const AXFLOAT4& v1, const AXFLOAT4& v2)
{
	return AXFLOAT4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

inline void __vectorcall operator-=(AXFLOAT4& v1, const AXFLOAT4& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	v1.w -= v2.w;
}

inline AXFLOAT4 __vectorcall operator*(const AXFLOAT4& v, float s)
{
	return AXFLOAT4(v.x * s, v.y * s, v.z * s, v.w * s);
}

inline void __vectorcall operator*=(AXFLOAT4& v, float s)
{
	v.x *= s;
	v.y *= s;
	v.z *= s;
	v.w *= s;
}

inline AXFLOAT4 __vectorcall operator/(const AXFLOAT4& v1, float s)
{
	return AXFLOAT4(v1.x / s, v1.y / s, v1.z / s, v1.w / s);
}

inline void __vectorcall operator/=(AXFLOAT4& v, float s)
{
	v.x /= s;
	v.y /= s;
	v.z /= s;
	v.w /= s;
}

//---------------------------------------------------------------
// other methods

AXFLOAT2 inline __vectorcall AXFloat2Abs(const AXFLOAT2& v)
{
	return AXFLOAT2(abs(v.x), abs(v.y));
}

AXFLOAT3 inline __vectorcall AXFloat3Abs(const AXFLOAT3& v)
{
	return AXFLOAT3(abs(v.x), abs(v.y), abs(v.z));
}

AXFLOAT4 inline __vectorcall AXFloat4Abs(const AXFLOAT4& v)
{
	return AXFLOAT4(abs(v.x), abs(v.y), abs(v.z), abs(v.w));
}

float inline __vectorcall AXFloat2Length(const AXFLOAT2& v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

float inline __vectorcall AXFloat3Length(const AXFLOAT3& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

float inline __vectorcall AXFloat4Length(const AXFLOAT4& v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

float inline __vectorcall AXFloat2Dot(const AXFLOAT2& v1, const AXFLOAT2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}
float inline __vectorcall AXFloat3Dot(const AXFLOAT3& v1, const AXFLOAT3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float inline __vectorcall AXFloat4Dot(const AXFLOAT4& v1, const AXFLOAT4& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

AXFLOAT3 inline __vectorcall AXFloat3Cross(const AXFLOAT3& v1, const AXFLOAT3& v2)
{
	static AXFLOAT3 right = AXFLOAT3(1, 0, 0), up = AXFLOAT3(0, 1, 0), forward = AXFLOAT3(0, 0, 1);

	AXFLOAT3 s0 = right * (v1.y * v2.z - v1.z * v2.y); 
	AXFLOAT3 s1 = up * (v1.x * v2.z - v1.z * v2.x);
	AXFLOAT3 s3 = forward * (v1.x * v2.y - v1.y * v2.x);

	return s0 + s1 + s3;
}

AXFLOAT2 inline __vectorcall AXFloat2Cross(const AXFLOAT2& v1, const AXFLOAT2& v2)
{
	static AXFLOAT2 right = AXFLOAT2(1, 0);
	
	AXFLOAT2 s0 = right * (v1.y * v2.x - v1.x * v2.y);

	return AXFLOAT2(s0.x, s0.x);
}

// -----------------------------------------------------------------
// Matrix 4x4

float inline __vectorcall AXFloat2x2Determinant(const __AXFLOAT2X2PRV& m)
{
	return m._11 * m._22 - m._12 * m._21;
}

float inline __vectorcall AXFloat3x3Determinant(const AXFLOAT3X3& m)
{
	__AXFLOAT2X2PRV a = __AXFLOAT2X2PRV(m._22, m._23, m._32, m._33);
	__AXFLOAT2X2PRV b = __AXFLOAT2X2PRV(m._21, m._23, m._31, m._33);
	__AXFLOAT2X2PRV c = __AXFLOAT2X2PRV(m._21, m._22, m._31, m._32);

	float s0 = m._11 * AXFloat2x2Determinant(a);
	float s1 = m._12 * AXFloat2x2Determinant(b);
	float s2 = m._13 * AXFloat2x2Determinant(c);

	return s0 - s1 + s2;
}

float inline __vectorcall AXFloat4x4Determinant(const AXFLOAT4X4& m)
{
	AXFLOAT3X3 a = AXFLOAT3X3(m._22, m._23, m._24, m._32, m._33, m._34, m._42, m._43, m._44);
	AXFLOAT3X3 b = AXFLOAT3X3(m._12, m._13, m._14, m._32, m._33, m._34, m._42, m._43, m._44);
	AXFLOAT3X3 c = AXFLOAT3X3(m._12, m._13, m._14, m._22, m._23, m._24, m._42, m._43, m._44);
	AXFLOAT3X3 d = AXFLOAT3X3(m._12, m._13, m._14, m._22, m._23, m._24, m._32, m._33, m._34);

	float s0 = m._11 * AXFloat3x3Determinant(a);
	float s1 = m._21 * AXFloat3x3Determinant(b);
	float s2 = m._31 * AXFloat3x3Determinant(c);
	float s3 = m._41 * AXFloat3x3Determinant(d);

	return s0 - s1 + s2 - s3;
}

AXFLOAT4X4 inline __vectorcall AXFloat4x4Multiply(const AXFLOAT4X4& m1, const AXFLOAT4X4& m2)
{
	AXFLOAT4X4 mat;

	mat._11 = m1._11 * m2._11 + m1._12 * m2._21 + m1._13 * m2._31 + m1._14 * m2._41;
	mat._12 = m1._11 * m2._12 + m1._12 * m2._22 + m1._13 * m2._32 + m1._14 * m2._42;
	mat._13 = m1._11 * m2._13 + m1._12 * m2._23 + m1._13 * m2._33 + m1._14 * m2._43;
	mat._14 = m1._11 * m2._14 + m1._12 * m2._24 + m1._13 * m2._34 + m1._14 * m2._44;

	mat._21 = m1._21 * m2._11 + m1._22 * m2._21 + m1._23 * m2._31 + m1._24 * m2._41;
	mat._22 = m1._21 * m2._12 + m1._22 * m2._22 + m1._23 * m2._32 + m1._24 * m2._42;
	mat._23 = m1._21 * m2._13 + m1._22 * m2._23 + m1._23 * m2._33 + m1._24 * m2._43;
	mat._24 = m1._21 * m2._14 + m1._22 * m2._24 + m1._23 * m2._34 + m1._24 * m2._44;

	mat._31 = m1._31 * m2._11 + m1._32 * m2._21 + m1._33 * m2._31 + m1._34 * m2._41;
	mat._32 = m1._31 * m2._12 + m1._32 * m2._22 + m1._33 * m2._32 + m1._34 * m2._42;
	mat._33 = m1._31 * m2._13 + m1._32 * m2._23 + m1._33 * m2._33 + m1._34 * m2._43;
	mat._34 = m1._31 * m2._14 + m1._32 * m2._24 + m1._33 * m2._34 + m1._34 * m2._44;

	mat._41 = m1._41 * m2._11 + m1._42 * m2._21 + m1._43 * m2._31 + m1._44 * m2._41;
	mat._42 = m1._41 * m2._12 + m1._42 * m2._22 + m1._43 * m2._32 + m1._44 * m2._42;
	mat._43 = m1._41 * m2._13 + m1._42 * m2._23 + m1._43 * m2._33 + m1._44 * m2._43;
	mat._44 = m1._41 * m2._14 + m1._42 * m2._24 + m1._43 * m2._34 + m1._44 * m2._44;

	return mat;
}

AXFLOAT4X4 inline __vectorcall AXFloat4x4Translate(const AXFLOAT3& translate)
{
	return AXFLOAT4X4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, translate.x, translate.y, translate.z, 1);
}

AXFLOAT4X4 inline __vectorcall AXFloat4x4Scale(const AXFLOAT3& scale)
{
	return AXFLOAT4X4(scale.x, 0, 0, 0, 0, scale.y, 0, 0, 0, 0, scale.z, 0, 0, 0, 0, 1);
}

AXFLOAT4X4 inline __vectorcall AXFloat4x4RotationX(float theta)
{
	return AXFLOAT4X4(1, 0, 0, 0, 0, cos(theta), sin(theta), 0, 0, -sin(theta), cos(theta), 0, 0, 0, 0, 1);
}

AXFLOAT4X4 inline __vectorcall AXFloat4x4RotationY(float theta)
{
	return AXFLOAT4X4(cos(theta), 0, -sin(theta), 0, 0, 1, 0, 0, sin(theta), 0, cos(theta), 0, 0, 0, 0, 1);
}

AXFLOAT4X4 inline __vectorcall AXFloat4x4RotationZ(float theta)
{
	return AXFLOAT4X4(cos(theta), -sin(theta), 0, 0, sin(theta), cos(theta), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
}

inline __device__ __host__ DWORD deviceConvertRGB(float r, float g, float b, float a)
{
	BYTE comp0 = r * 255.999f;
	BYTE comp1 = g * 255.999f;
	BYTE comp2 = b * 255.999f;
	BYTE comp3 = a * 255.999f;

	DWORD color = 0;

	color |= (comp3 << 24); // alpha first.
	color |= (comp0 << 16); // r
	color |= (comp1 << 8);  // g
	color |= (comp2 << 0);  // b

	return color;
}
