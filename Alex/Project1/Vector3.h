#include <iostream>
#include "Matrix3.h"

#ifndef Vector3_H_
#define Vector3_H_

class Vector3
{
public:

	Vector3();
	Vector3(float xpos, float ypos, float zpos);
	Vector3 operator+(Vector3 vInput);
	Vector3 operator-(Vector3 vInput);
	Vector3 operator*(float fInput);
	float DotProduct(Vector3 vInput);
	Vector3 Normalise();
	float Length();



	~Vector3();



	float x;
	float y;
	float z;

private:

};

Vector3 operator*(float fInput, Vector3& v3);

Vector3 operator*(Matrix3 mInput, Vector3& v3);

#endif Vector3_H_