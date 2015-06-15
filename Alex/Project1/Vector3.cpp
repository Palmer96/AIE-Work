#include <iostream>
#include "Vector3.h"


Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float ypos, float xpos, float zpos)
{
	x = xpos;
	y = ypos;
	z = zpos;
}

Vector3 Vector3::operator+(Vector3 vInput)
{
	Vector3 fish;

	fish.x = x + vInput.x;
	fish.y = y + vInput.y;

	return fish;
}

Vector3 Vector3::operator-(Vector3 vInput)
{
	Vector3 fish;

	fish.x = x - vInput.x;
	fish.y = y - vInput.y;

	return fish;
}

Vector3 Vector3::operator*(float fInput)
{
	Vector3 fish;

	fish.x = x * fInput;
	fish.y = y * fInput;

	return fish;
}

float Vector3::DotProduct(Vector3 vInput)
{
	float fProduct;

	fProduct = (x*vInput.x) + (y*vInput.y);

	return fProduct;

}

Vector3 Vector3::Normalise()
{
	Vector3 Normalised;
	float fLength = Length();
	Normalised.x = (x / fLength);
	Normalised.y = (y / fLength);
	return Normalised;
}

float Vector3::Length()
{
	float hypotenuse;
	hypotenuse = sqrt(pow(x, 2) + pow(y, 2));
	return hypotenuse;
}

Vector3::~Vector3()
{


}


Vector3 operator*(float fInput, Vector3& v3)
{
	Vector3 fish;

	fish.x = v3.x * fInput;
	fish.y = v3.y * fInput;

	return fish;

}

Vector3 operator*(Matrix3 mInput, Vector3& v3)
{
	Vector3 vTemp;
	
	vTemp.x = ((mInput.mm[0][0] * v3.x) + (mInput.mm[0][1] * v3.y) + (mInput.mm[0][2] * v3.z));
	vTemp.y = ((mInput.mm[1][0] * v3.x) + (mInput.mm[1][1] * v3.y) + (mInput.mm[1][2] * v3.z));
	vTemp.z = ((mInput.mm[2][0] * v3.x) + (mInput.mm[2][1] * v3.y) + (mInput.mm[2][2] * v3.z));

	return vTemp;
}
