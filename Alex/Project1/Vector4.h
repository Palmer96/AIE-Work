#include <iostream>
#include "Matrix4.h"

#ifndef Vector4_H_
#define Vector4_H_

class Vector4
{
public:

	Vector4();
	Vector4(float xpos, float ypos, float zpos);
	Vector4 operator+(Vector4 vInput);
	Vector4 operator-(Vector4 vInput);
	Vector4 operator*(float fInput);
	float DotProduct(Vector4 vInput);
	Vector4 Normalise();
	float Length();



	~Vector4();



	float x;
	float y;
	float z;

private:

};

Vector4 operator*(float fInput, Vector4& v3);

Vector4 operator*(Matrix3 mInput, Vector4& v3);

#endif Vector4_H_