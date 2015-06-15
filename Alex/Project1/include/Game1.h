
/*-----------------------------------------------------------------------------
Author:			
Description:	
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Player.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "Application.h"
#include "GameObject.h"
#include "Trail.h"
#include "Ring.h"
#include "String"
class SpriteBatch;

class Game1 : public Application
{
public:

	// assets loaded in constructor
	Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);

	
	void Gravity(float deltaTime);
	// assets destroyed in destructor
	virtual ~Game1();
	
	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	void Reset();
	virtual void Draw();
	
protected:
	int printCounter;
	float fGravMultiplier;
	float fTimer;
	float fOrbitTimer;
	float fGameTimer;
	float fWinTimer;
	bool bStart;
	bool bWon;
	std::string sGameTimer;
	std::string sOrbitTimer;
	std::string sWinTimer;
	int iTrailCount;
	int iTrailAmount;
	int iBallCount;
	float fPastLength;
	SpriteBatch *m_spritebatch;
	GameObject follower[5000];
	Trail trail[10000];
	Player player;
	Ring ring;
	Matrix3 derp; 
	Matrix3 herp;
	Matrix3 blerp;
	Texture* redCircle;
	Texture* blueCircle;
	Texture* rocket;
	Texture* rocketFire;
	Texture* purpleSquare;
	Texture* purpleCircle;
	Texture* deepRedCircle;
	Texture* deepGreenCircle;
	Texture* redRing;
	Texture* yellowRing;
	Texture* greenRing;


	Vector3 vector3;
	Vector3 other;

private:
};

#endif