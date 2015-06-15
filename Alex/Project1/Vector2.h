#include <iostream>


#ifndef Vector2_H_
#define Vector2_H_

class Vector2
{
public:

	Vector2();
	Vector2(float xpos, float ypos);
	Vector2 operator+(Vector2 vInput);
	Vector2 operator-(Vector2 vInput);
	Vector2 operator*(float fInput);
	float DotProduct(Vector2 vInput);
	Vector2 Normalise();
	float Length();
	


	~Vector2();

	
	
	float x;
	float y;

private:
	
};

Vector2 operator*(float fInput, Vector2& v2);

#endif Vector2_H_