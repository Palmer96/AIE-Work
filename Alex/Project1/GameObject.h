#include <iostream>
#include <Texture.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"


#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

class GameObject
{
public:
	GameObject();

	void CollisionSet();
	
	void Follow(GameObject target, float deltatime);
	
	unsigned int fSpriteHeight;
	unsigned int fSpriteWidth;

	float fObjectSpeed;
	bool bCheckGravity;
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

	



	~GameObject();


private:
	
	
};
#endif