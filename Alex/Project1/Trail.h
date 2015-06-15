#include <iostream>
#include <Texture.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"


#ifndef TRAIL_H_
#define TRAIL_H_

class Trail
{
public:
	Trail();

	void CollisionSet();


	unsigned int fSpriteHeight;
	unsigned int fSpriteWidth;

	float fObjectSpeed;
	float fSpriteSize;
	Texture* sprite;
	Vector2 coords;
	Vector2 TopLeft;
	Vector2 BottomLeft;
	Vector2 TopRight;
	Vector2 BottomRight;
	Vector2 momentum;


	Vector3 direction;
	Vector3 newDirection;

	Matrix3 rotation;





	~Trail();


private:


};
#endif