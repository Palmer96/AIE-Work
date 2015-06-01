#ifndef _PLAYER_H
#define _PLAYER_H

#include "Vectors.h"
#include "Object.h"

class Player::public Object
{
	Player();
	~Player();
	void Move();


	Vector2 Vec;




};



#endif //_PLAYER_H