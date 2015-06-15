#include <iostream>
#include "GameObject.h"
#include "Font.h"
#include "String"
#ifndef PLAYER_H
#define PLAYER_H


#include "Texture.h"

class Player : public GameObject
{
public:
	Player();
	
	float fRotation;
	float fFuel;
	Font* fuel;
	std::string sFuel;
	~Player();

private:

};
#endif