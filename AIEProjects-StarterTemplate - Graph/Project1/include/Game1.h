
/*-----------------------------------------------------------------------------
Author:			
Description:	
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"
#include "Graph.h"

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
	Texture * playerTex;
	Texture * personTex;
	Texture * roadTex;
	Texture * roofTex;
	Texture * bloodTex;





	Graph *pGraph;


	//Agents person;


	Vector3 playerPos;
	Matrix3 playerMat;


	float rotate;
	Vector3 scale;

	Vector2 agentPos;

	int k;



	int counter1;
	int counter2;
	int counter3;
	int counter4;
	int counter5;
	int counter6;
	int counter7;
	int counter8;
	int counter9;
	int counter10;
	int counter11;
	int counter12;
	int counter13;
	int counter14;
	int counter15;
	int counter16;
	int counter17;
	int counter18;
	int counter19;
	int counter20;
	int counter21;
	
	Vector3 Blood1;
	Vector3 Blood2;
	Vector3 Blood3;
	Vector3 Blood4;
	Vector3 Blood5;
	Vector3 Blood6;
	Vector3 Blood7;
	Vector3 Blood8;
	Vector3 Blood9;
	Vector3 Blood10;
	Vector3 Blood11;
	Vector3 Blood12;
	Vector3 Blood13;
	Vector3 Blood14;
	Vector3 Blood15;
	Vector3 Blood16;
	Vector3 Blood17;
	Vector3 Blood18;
	Vector3 Blood19;
	Vector3 Blood20;
	Vector3 Blood21;

	int Alpha;





private:
};

#endif