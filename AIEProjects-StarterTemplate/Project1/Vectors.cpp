#include <iostream>
#include "Vectors.h"
#include "Game1.h"
#include <vector>


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
}

Vector2 Vector2::operator-(const Vector2& v2)const
{
	Vector2 newVec;
	newVec.x = x - v2.x;
	newVec.y = y - v2.y;
	return newVec;
}
Vector2& Vector2::operator-=(const Vector2& v2)
{
	x -= v2.x;
	y -= v2.y;
}


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

/*
Vector2 Vector2::VecFlo(Vector2 a, float Float)
{
	float x3 = x * Float;
	float y3 = y * Float;
	return (x3, y3);

}


float Vector2::FloVec(float x, float y, float Float)
{

	float x3 = x * Float;
	float y3 = y * Float;

	return x3 + y3;

}

float Vector2::MatVec(float x, float y, float Matrix)
{


}

float Vector2::MatMat(float Matrix1, float Matrix2)
{


}
*/




