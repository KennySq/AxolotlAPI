#pragma once

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
	float x;
	float y;
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
	float x;
	float y;
	float z;
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
	float x;
	float y;
	float z;
	float w;
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

AXFLOAT2 AXFloat2Cross(const AXFLOAT2& v1, const AXFLOAT2& v2)
{
	static AXFLOAT2 up(0, 1);
	


}