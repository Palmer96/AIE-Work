#include <iostream>
#include "GameObject.h"



GameObject::GameObject()
{
	coords.x = 40000000;
	coords.y = 40000000;
	fObjectSpeed = 32;
	fSpriteSize = 8;

	bCheckGravity = true;

	direction.x = 0.1;
	direction.y = 0.1;
	rotation.mm[0][0] = 1;
	rotation.mm[0][1] = 0;
	rotation.mm[0][2] = 0;
	rotation.mm[1][0] = 0;
	rotation.mm[1][1] = 1;
	rotation.mm[1][2] = 0;
	rotation.mm[2][0] = 0;
	rotation.mm[2][1] = 0;
	rotation.mm[2][2] = 1;

}

void GameObject::CollisionSet()
{
	float TempLeftX = coords.x - (fSpriteWidth / 2);
	float TempRightX = coords.x + (fSpriteWidth / 2);
	float TempBottomY = coords.y + (fSpriteHeight / 2);
	float TempTopY = coords.y - (fSpriteHeight / 2);

	fObjectSpeed = (fSpriteHeight / 2);

	TopLeft.x = TempLeftX;
	TopLeft.y = TempTopY;
	BottomLeft.x = TempLeftX;
	BottomLeft.y = TempBottomY;
	TopRight.x = TempRightX;
	TopRight.y = TempTopY;
	BottomRight.x = TempRightX;
	BottomRight.y = TempBottomY;
}

void GameObject::Follow(GameObject target, float deltatime)
{
	if (coords.x < target.coords.x && coords.y > target.coords.y)
	{
		coords.x += ((((target.coords.x - coords.x) / ((target.coords.x - coords.x) + (coords.y - target.coords.y))) * fObjectSpeed) * deltatime);
		coords.y -= ((((coords.y - target.coords.y) / ((target.coords.x - coords.x) + (coords.y - target.coords.y))) * fObjectSpeed) * deltatime);
	}
	if (coords.x < target.coords.x && coords.y < target.coords.y)
	{
		coords.x += ((((target.coords.x - coords.x) / ((target.coords.x - coords.x) + (coords.y - target.coords.y))) * fObjectSpeed) * deltatime);
		coords.y += ((((coords.y - target.coords.y) / ((target.coords.x - coords.x) + (coords.y - target.coords.y))) * fObjectSpeed) * deltatime);
	}
	if (coords.x > target.coords.x && coords.y < target.coords.y)
	{

	}
	if (coords.x > target.coords.x && coords.y > target.coords.y)
	{

	}

}

//int GameObject::CollisionTest()
//{
//	Col
//	for (int i = 0; i < 1000; i++)
//	{
//		if ()
//	}
//
//}

GameObject::~GameObject()
{

}