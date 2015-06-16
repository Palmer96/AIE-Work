#ifndef _PLAYER_H
#define _PLAYER_H

#include "Vectors.h"
#include "Object.h"

class Player//:public Object
{
	Player();
	Player(Vector2 playerPos);
	~Player();
	void Move();

	Vector2 playerPos;

	float playerPosx;
	float playerPosy;
	float playerPosz;



};



#endif //_PLAYER_H