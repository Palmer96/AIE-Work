#include <iostream>
#include "Player.h"

Player::Player()
{
	fSpriteHeight = 772;
	fSpriteWidth = 440;
	fRotation = 0;
	fFuel = 1600.0000f;
	fuel = new Font("./Fonts/hobo_22px.fnt");

}
Player::~Player()
{


}
