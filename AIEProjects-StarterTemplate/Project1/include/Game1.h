
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

	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	SpriteBatch *m_spritebatch;
	Texture * background;

	Texture * pTexture;
	Texture * pLTexture;
	Texture * pRTexture;

	Texture * s1LTexture;
	Texture * s1RTexture;
	Texture * s2LTexture;
	Texture * s2RTexture;

	Texture * e1Texture;
	Texture * e2Texture;
	Texture * wTexture;

	Texture * gTexture;

	float posX;
	float posY;

	float sX;
	float sY;

	float eX;
	float eY;

	float wallX;
	float wallY;
	int speed;

	bool shoot;

	bool jump;

	int bullets[100];
	int bulletCount = 0;

	bool Left;
	bool Leftbullet;

	float peak;
	bool fall;
	float floor;

	float gravity;

	bool shooting;

	bool change;

	int i;
	int j;

	

private:
};

#endif