#pragma once
#include <cmath>
#include <memory.h>
#include <limits>

namespace Math
{
	const float Pi = 3.1415926535f;
	const float TwoPi = Pi * 2.0f;
	const float PiOver2 = Pi / 2.0f;
	const float Infinity = std::numeric_limits<float>::infinity();
	const float NegInfinity = -std::numeric_limits<float>::infinity();

	inline float ToRadians(float degrees)
	{
		return degrees * Pi / 180.0f;
	}

	inline float ToDegrees(float radians)
	{
		return radians * 180.0f / Pi;
	}

	inline bool NearZero(float val, float epsilon = 0.001f)
	{
		if (fabs(val) <= epsilon)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template <typename T>
	T Max(const T& a, const T& b)
	{
		return (a < b ? b : a);
	}

	template <typename T>
	T Min(const T& a, const T& b)
	{
		return (a < b ? a : b);
	}

	template <typename T>
	T Clamp(const T& value, const T& lower, const T& upper)
	{
		return Min(upper, Max(lower, value));
	}

	inline float Abs(float value)
	{
		return fabs(value);
	}

	inline float Cos(float angle)
	{
		return cosf(angle);
	}

	inline float Sin(float angle)
	{
		return sinf(angle);
	}

	inline float Tan(float angle)
	{
		return tanf(angle);
	}

	inline float Acos(float value)
	{
		return acosf(value);
	}
	
	inline float Atan2(float y, float x)
	{
		return atan2f(y, x);
	}

	inline float Cot(float angle)
	{
		return 1.0f / Tan(angle);
	}

	inline float Lerp(float a, float b, float f)
	{
		return a + f * (b - a);
	}

	inline float Sqrt(float value)
	{
		return sqrtf(value);
	}
	
	inline float Fmod(float numer, float denom)
	{
		return fmod(numer, denom);
	}
}

// 2D Vector
class Vector2
{
public:
	float x = 0.f;
	float y = 0.f;

	Vector2()
		:x(0.0f)
		,y(0.0f)
	{}

	explicit Vector2(float inX, float inY)
		:x(inX)
		,y(inY)
	{}

	// Set both components in one line
	void Set(float inX, float inY)
	{
		x = inX;
		y = inY;
	}

	// Vector addition (a + b)
	friend Vector2 operator+(const Vector2& a, const Vector2& b)
	{
		return Vector2(a.x + b.x, a.y + b.y);
	}

	// Vector subtraction (a - b)
	friend Vector2 operator-(const Vector2& a, const Vector2& b)
	{
		return Vector2(a.x - b.x, a.y - b.y);
	}

	// Component-wise multiplication
	// (a.x * b.x, ...)
	friend Vector2 operator*(const Vector2& a, const Vector2& b)
	{
		return Vector2(a.x * b.x, a.y * b.y);
	}

	// Scalar multiplication
	friend Vector2 operator*(const Vector2& vec, float scalar)
	{
		return Vector2(vec.x * scalar, vec.y * scalar);
	}

	// Scalar multiplication
	friend Vector2 operator*(float scalar, const Vector2& vec)
	{
		return Vector2(vec.x * scalar, vec.y * scalar);
	}

	// Scalar *=
	Vector2& operator*=(float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	// Vector +=
	Vector2& operator+=(const Vector2& right)
	{
		x += right.x;
		y += right.y;
		return *this;
	}

	// Vector -=
	Vector2& operator-=(const Vector2& right)
	{
		x -= right.x;
		y -= right.y;
		return *this;
	}

	// Length squared of vector
	float LengthSq() const
	{
		return (x*x + y*y);
	}

	// Length of vector
	float Length() const
	{
		return (Math::Sqrt(LengthSq()));
	}

	// Normalize this vector
	void Normalize()
	{
		float length = Length();
		x /= length;
		y /= length;
	}

	// Normalize the provided vector
	static Vector2 Normalize(const Vector2& vec)
	{
		Vector2 temp = vec;
		temp.Normalize();
		return temp;
	}

	// Dot product between two vectors (a dot b)
	static float Dot(const Vector2& a, const Vector2& b)
	{
		return (a.x * b.x + a.y * b.y);
	}

	// Lerp from A to B by f
	static Vector2 Lerp(const Vector2& a, const Vector2& b, float f)
	{
		return Vector2(a + f * (b - a));
	}
};

class Vector2Int
{
public:
	int x = 0;
	int y = 0;

	Vector2Int()
	{

	}

	explicit Vector2Int(int inX, int inY)
		: x(inX)
		, y(inY)
	{}

	// Set both components in one line
	void Set(int inX, int inY)
	{
		x = inX;
		y = inY;
	}

	// Vector addition (a + b)
	friend Vector2Int operator+(const Vector2Int& a, const Vector2Int& b)
	{
		return Vector2Int(a.x + b.x, a.y + b.y);
	}

	// Vector subtraction (a - b)
	friend Vector2Int operator-(const Vector2Int& a, const Vector2Int& b)
	{
		return Vector2Int(a.x - b.x, a.y - b.y);
	}

	// Component-wise multiplication
	// (a.x * b.x, ...)
	friend Vector2Int operator*(const Vector2Int& a, const Vector2Int& b)
	{
		return Vector2Int(a.x * b.x, a.y * b.y);
	}

	// Scalar multiplication
	friend Vector2Int operator*(const Vector2Int& vec, int scalar)
	{
		return Vector2Int(vec.x * scalar, vec.y * scalar);
	}

	// Scalar multiplication
	friend Vector2Int operator*(int scalar, const Vector2Int& vec)
	{
		return Vector2Int(vec.x * scalar, vec.y * scalar);
	}

	friend Vector2Int operator/(const Vector2Int& vec, int scalar)
	{
		return Vector2Int(vec.x / scalar, vec.y / scalar);
	}

	friend Vector2Int operator/(int scalar, const Vector2Int& vec)
	{
		return Vector2Int(vec.x / scalar, vec.y / scalar);
	}

	// Scalar *=
	Vector2Int& operator*=(int scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	// Vector +=
	Vector2Int& operator+=(const Vector2Int& right)
	{
		x += right.x;
		y += right.y;
		return *this;
	}

	// Vector -=
	Vector2Int& operator-=(const Vector2Int& right)
	{
		x -= right.x;
		y -= right.y;
		return *this;
	}

	// Length squared of vector
	int LengthSq() const
	{
		return (x * x + y * y);
	}

	// Length of vector
	float Length() const
	{
		return (Math::Sqrt(static_cast<float>(LengthSq())));
	}
};

inline Vector2Int Vector2ToVector2Int(const Vector2& vec)
{
	return Vector2Int{ static_cast<int32>(vec.x), static_cast<int32>(vec.y) };
}

inline Vector2 Vector2IntToVector2(const Vector2Int& vec)
{
	return Vector2{ static_cast<float>(vec.x), static_cast<float>(vec.y) };
}