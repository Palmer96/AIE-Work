#include <iostream>
#include "Vectors.h"

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}
Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}
Vector2::~Vector2()
{

}


Vector2 Vector2::operator+(const Vector2& v2)const
{
	Vector2 newVec;
	newVec.x = x + v2.x;
	newVec.y = y + v2.y;
	return newVec;
}

Vector2& Vector2::operator+=(const Vector2& v2)
{
x += v2.x;
y += v2.y;
return *this;
}

Vector2 Vector2::operator-(const Vector2& v2)const
{
	Vector2 newVec;
	newVec.x = x - v2.x;
	newVec.y = y - v2.y;
	return newVec;
}
/*
Vector2& Vector2::operator-=(const Vector2& v2)
{
x -= v2.x;
y -= v2.y;
}
*/


Vector2 Vector2::operator/(float v2)const
{
	return Vector2(x / v2, y / v2);
}
/*
Vector2& Vector2::operator/=(const Vector2& v2)
{
x /= v2.x;
y /= v2.y;
}
*/
Vector2 Vector2::operator*(float v2)const
{
	return Vector2(x * v2, y * v2);
}
/*
Vector2& Vector2::operator*=(const Vector2& v2)
{
x *= v2.x;
y *= v2.y;
}

*/




Vector2 Vector2::AddVec(Vector2 a_1, Vector2 a_2)
{
	Vector2 a_3 = a_1 + a_2;
	return a_3;
}
Vector2 Vector2::SubVec(Vector2 a_1, Vector2 a_2)
{
	Vector2 a_3 = a_1 - a_2;
	return a_3;

}
Vector2 Vector2::VecFlo(Vector2 a, float Float)
{
	Vector2 a2 = a * Float;

	return a2;

}
float Vector2::FloVec(Vector2 a, float Float)
{

	float a1 = Float * a.x;
	float a2 = Float * a.y;

	return a1 + a2;

}

//		Incomplete
/*
float MatVec(Vector2 a, float Matrix)
{

}
float MatMat(float Matrix1, float Matrix2)
{

}

float Dot(Vector2 a_1, Vector2 a_2)
{

}
float Cross(Vector2 a_1, Vector2 a_2)
{

}
float Magnitude(Vector2 a)
{
	//square root of x*x + y*y
}
float Normalised(Vector2 a)
{}
*/

#KAYNELOVESTHE-D


