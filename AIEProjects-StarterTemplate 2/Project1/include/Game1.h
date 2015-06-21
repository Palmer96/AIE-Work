
/*-----------------------------------------------------------------------------
Author:
Description:
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"

#include "Vectors.h"


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
	Texture * tankTex;
	Texture * cannonTex;
	Texture * enemyTex;

	Texture * arrowTex;

	float mouseX;
	float mouseY;

	
	float arrowPosx;
	float arrowPosy;


	float tankSpeed;

	bool rotateLeft;
	bool rotateRight;

	float rotate;

	Vector3 playerPos;
Vector3 cannonPos;
	Vector3 enemyPos;
	Matrix3 Matrix;

};

#endif