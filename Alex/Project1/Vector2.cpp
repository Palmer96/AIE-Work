#include <iostream>
#include "Vector2.h"


Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
	
}

Vector2::Vector2(float ypos, float xpos)
{
	x = xpos;
	y = ypos;
}

Vector2 Vector2::operator+(Vector2 vInput)
{
	Vector2 fish;

	fish.x = x + vInput.x;
	fish.y = y + vInput.y;

	return fish;
}

Vector2 Vector2::operator-(Vector2 vInput)
{
	Vector2 fish;

	fish.x = x - vInput.x;
	fish.y = y - vInput.y;

	return fish;
}

Vector2 Vector2::operator*(float fInput)
{
	Vector2 fish;

	fish.x = x * fInput;
	fish.y = y * fInput;

	return fish;
}

float Vector2::DotProduct(Vector2 vInput)
{
	float fProduct;

	fProduct = (x*vInput.x) + (y*vInput.y); 
	
	return fProduct;

}

Vector2 Vector2::Normalise()
{
	Vector2 Normalised;
	float fLength = Length();
	Normalised.x = (x / fLength);
	Normalised.y = (y / fLength);
	return Normalised;
}

float Vector2::Length()
{
	float hypotenuse;
	hypotenuse = sqrt(pow(x, 2) + pow(y ,2));
	return hypotenuse;
}

Vector2::~Vector2()
{


}

Vector2 operator*(float fInput, Vector2& v2)
{
	Vector2 fish;

	fish.x = v2.x * fInput;
	fish.y = v2.y * fInput;

	return fish;

}
