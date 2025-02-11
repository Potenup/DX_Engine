#include "Vector2.h"
#include "Windows.h"
#include "cmath"

namespace Blue
{
	// 기본 값.
	const Vector2 Vector2::Zero = Vector2(0.0f, 0.0f);
	const Vector2 Vector2::One = Vector2(1.0f, 1.0f);
	const Vector2 Vector2::Right = Vector2(1.0f, 0.0f);
	const Vector2 Vector2::Up = Vector2(0.0f, 1.0f);

	std::wstring Vector2::ToString()
	{
		wchar_t buffer[256];
		swprintf_s(buffer, 256, TEXT("(%f, %f)"), x, y);

		return (buffer);
	}
	
	float Vector2::Length()
	{
		return sqrtf((x * x) + (y * y));
	}
	// 벡터가 1개 일때 각도를 구할 때는 tan로 구함 (sin cos도 가능하지만 tan 빗면이 없어서 상대적으로 쉬움)
	float Vector2::Dot(const Vector2& other)
	{
		return ((x * other.x) + (y * other.y));
	}

	Vector2 Vector2::Normalized()
	{
		float length = Length();
		return Vector2(x / length, y / length);
	}

	bool Vector2::Equals(const Vector2& other) const 
	{
		return (x == other.x && y == other.y);
	}
}