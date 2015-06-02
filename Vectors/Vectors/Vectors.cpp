#include <iostream>
#include "Vectors.h"


//-------------------------------------------------------------------------//
//--------//	Vector 2D	//---------------------------------------------//
//-------------------------------------------------------------------------//

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
Vector2& Vector2::operator-=(const Vector2& v2)
{
	x -= v2.x;
	y -= v2.y;
	return *this;
}

Vector2 Vector2::operator/(float v2)const
{
	return Vector2(x / v2, y / v2);
}
Vector2& Vector2::operator/=(const Vector2& v2)
{
	x /= v2.x;
	y /= v2.y;
	return *this;
}
Vector2 Vector2::operator*(float v2)const
{
	return Vector2(x * v2, y * v2);
}
Vector2& Vector2::operator*=(const Vector2& v2)
{
	x *= v2.x;
	y *= v2.y;
	return *this;
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
float Dot(Vector2 a_1, Vector2 a_2)
{
	float dot = (a_1.x*a_2.x) + (a_1.y*a_2.y);
	return dot;
}
float Magnitude(Vector2 a)
{
	float x = a.x * a.x;
	float y = a.y * a.y;

	return sqrt(x + y);
}
Vector2 Normalised(Vector2 a, float magnitude)
{
	a.x /= magnitude;
	a.y /= magnitude;

	return a;
}


















//-------------------------------------------------------------------------//
//--------//	Vector 3D	//---------------------------------------------//
//-------------------------------------------------------------------------//


Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}
Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}
Vector3::~Vector3()
{

}


Vector3 Vector3::operator+(const Vector3& v3)const
{
	Vector3 newVec;
	newVec.x = x + v3.x;
	newVec.y = y + v3.y;
	newVec.z = z + v3.z;
	return newVec;
}

Vector3& Vector3::operator+=(const Vector3& v3)
{
	x += v3.x;
	y += v3.y;
	z += v3.z;
	return *this;
}
Vector3 Vector3::operator-(const Vector3& v3)const
{
	Vector3 newVec;
	newVec.x = x - v3.x;
	newVec.y = y - v3.y;
	newVec.z = z - v3.z;
	return newVec;
}
Vector3& Vector3::operator-=(const Vector3& v3)
{
	x -= v3.x;
	y -= v3.y;
	z -= v3.z;
	return *this;
}

Vector3 Vector3::operator/(float v3)const
{
	return Vector3(x / v3, y / v3, z / v3);
}
Vector3& Vector3::operator/=(const Vector3& v3)
{
	x /= v3.x;
	y /= v3.y;
	z /= v3.z;
	return *this;
}
Vector3 Vector3::operator*(float v3)const
{
	return Vector3(x * v3, y * v3, z * v3);
}
Vector3& Vector3::operator*=(const Vector3& v3)
{
	x *= v3.x;
	y *= v3.y;
	z *= v3.z;
	return *this;
}


Vector3 Vector3::VecFlo(Vector3 a, float Float)
{
	return a * Float;
}
float Vector3::FloVec(Vector3 a, float Float)
{
	return Float * a.x + Float * a.y + Float * a.z;
}


float Dot(Vector3 a_1, Vector3 a_2, Vector3 a_z)
{
	float dot = (a_1.x*a_2.x) + (a_1.y*a_2.y) + (a_1.z*a_2.z);
	return dot;
}
Vector3 Cross(Vector3 a_1, Vector3 a_2, Vector3 a_z)
{
	Vector3 cross((a_1.y*a_2.z) - (a_1.z*a_2.y),(a_1.z*a_2.x) - (a_1.x*a_2.z), (a_1.x*a_2.y) - (a_1.y*a_2.x));
	return cross;
}
float Magnitude(Vector3 a)
{
	float x = a.x * a.x;
	float y = a.y * a.y;
	float z = a.z * a.z;
	return sqrt(x + y + z);
}
Vector3 Normalised(Vector3 a, float magnitude)
{
	a.x /= magnitude;
	a.y /= magnitude;
	a.z /= magnitude;

	return a;
}

















//-------------------------------------------------------------------------//
//--------//	Vector 4D	//---------------------------------------------//			convert to 4D
//-------------------------------------------------------------------------//


Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	q = 0.0f;
}
Vector4::Vector4(float a_x, float a_y, float a_z, float a_q)
{
	x = a_x;
	y = a_y;
	z = a_z;
	q = a_q;
}
Vector4::~Vector4()
{

}


Vector4 Vector4::operator+(const Vector4& v4)const
{
	Vector4 newVec;
	newVec.x = x + v4.x;
	newVec.y = y + v4.y;
	newVec.z = z + v4.z;
	newVec.q = q + v4.q;
	return newVec;
}
Vector4& Vector4::operator+=(const Vector4& v4)
{
	x += v4.x;
	y += v4.y;
	z += v4.z;
	q += v4.q;
	return *this;
}
Vector4 Vector4::operator-(const Vector4& v4)const
{
	Vector4 newVec;
	newVec.x = x - v4.x;
	newVec.y = y - v4.y;
	newVec.z = z - v4.z;
	newVec.q = q - v4.q;
	return newVec;
}
Vector4& Vector4::operator-=(const Vector4& v4)
{
	x -= v4.x;
	y -= v4.y;
	z -= v4.z;
	q -= v4.q;
	return *this;
}

Vector4 Vector4::operator/(float v4)const
{
	return Vector4(x / v4, y / v4, z / v4, q / v4);
}
Vector4& Vector4::operator/=(const Vector4& v4)
{
	x /= v4.x;
	y /= v4.y;
	z /= v4.z;
	q /= v4.q;
	return *this;
}
Vector4 Vector4::operator*(float v4)const
{
	return Vector4(x * v4, y * v4, z * v4, q * v4);
}
Vector4& Vector4::operator*=(const Vector4& v4)
{
	x *= v4.x;
	y *= v4.y;
	z *= v4.z;
	q *= v4.q;
	return *this;
}


Vector4 Vector4::VecFlo(Vector4 a, float Float)
{
	return a * Float;
}
float Vector4::FloVec(Vector4 a, float Float)
{
	return Float * a.x + Float * a.y + Float * a.z + Float * a.q;
}


float Dot(Vector4 a_1, Vector4 a_2, Vector4 a_z)
{
	float dot = (a_1.x*a_2.x) + (a_1.y*a_2.y) + (a_1.z*a_2.z) + (a_1.q*a_2.q);
	return dot;
}
//-----------Later
/*
			Vector4 Cross(Vector4 a_1, Vector4 a_2, Vector4 a_z)
			{
				Vector4 cross((a_1.y*a_2.z) - (a_1.z*a_2.y), (a_1.z*a_2.x) - (a_1.x*a_2.z), (a_1.x*a_2.y) - (a_1.y*a_2.x));
				return cross;
			}
*/		
float Magnitude(Vector4 a)
{
	return sqrt ((a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.q * a.q));
}
Vector4 Normalised(Vector4 a, float magnitude)
{
	a.x /= magnitude;
	a.y /= magnitude;
	a.z /= magnitude;
	a.q /= magnitude;

	return a;
}







