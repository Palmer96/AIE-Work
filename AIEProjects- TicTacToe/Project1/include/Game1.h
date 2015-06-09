
/*-----------------------------------------------------------------------------
Author:
Description:
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"
class SpriteBatch;

class Game1 : public Application
{
public:

	// assets loaded in constructor
	Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);

	// assets destroyed in destructor
	virtual ~Game1();

	void PlayerSelect();
	void AiSelect();
	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	SpriteBatch *m_spritebatch;
	Texture * background;

	Texture * rTexture;
	Texture * pTexture;
	Texture * sTexture;

	float posX;
	float posY;


	int playerChoice;
	int aiChoice;

	float games;
	float wins;
	int loses;
	float percentage;

	
};

#endif