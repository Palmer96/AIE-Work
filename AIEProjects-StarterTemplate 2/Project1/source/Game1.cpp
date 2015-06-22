#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "MathLib.h"
#include "Object.h"
#include <iostream>



Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	background = new Texture("./Images/Background3.png");
	tankTex = new Texture("./Images/Tank_Body.png");
	cannonTex = new Texture("./Images/Tank_Cannon.png");
	enemyTex = new Texture("./Images/enemy.png");

	arrowTex = new Texture("./Images/arrow.png");

	
	Vector3 playerPos(300.0f, 300.0f, 1.0f);

	 Object player(playerPos);
	//Matrix3 playerMat(1.0f, 0.0f, playerPos.x,
	//				  0.0f, 1.0f, playerPos.y,
	//				  0.0f, 0.0f, 1.0f);

	Matrix3 playerMat(1.0f, 0.0f, 0.0f,
			          0.0f, 1.0f, 0.0f,
					  playerPos.x, playerPos.y, 1.0f);

	Vector3 enemyPos(playerPos.x, playerPos.y, 1.0f);

	Vector3 cannonPos(200.0f, 200.0f, 1.0f);
	Matrix3 cannonMat(1.0f, 0.0f, cannonPos.x,
					  0.0f, 1.0f, cannonPos.y,
					  0.0f, 0.0f, 1.0f);

	Vector3 VTankSpeed (10.0f,10.0f, 1.0f);
	tankSpeed = 100.0f;

	rotateLeft = false;
	rotateRight = false;

	rotate = 20.0f;

}



Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{
	Input * InputManager = GetInput();

	std::cout << playerPos.x << " " << playerPos.y << " " << std::endl;
	if (InputManager->IsKeyDown(GLFW_KEY_W))
	{
		playerPos.y -= tankSpeed * deltaTime;
		cannonPos.y -= tankSpeed * deltaTime;

		playerMat = playerMat * playerMat.Translation(VTankSpeed * deltaTime);
	}

	if (InputManager->IsKeyDown(GLFW_KEY_S))
	{
		playerPos.y += tankSpeed * deltaTime;
		cannonPos.y += tankSpeed * deltaTime;
	}
	if (InputManager->IsKeyDown(GLFW_KEY_A))
	{
		playerMat = playerMat.ChangeRotation(playerMat, 1*deltaTime);
		//rotate += 10.0f;
	}
	if (InputManager->IsKeyDown(GLFW_KEY_D))
	{
		playerPos.x += tankSpeed * deltaTime;
		cannonPos.x += tankSpeed * deltaTime;
		// will rotate tank with cannon Right
	}

	if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
	{
		//Rotate Cannon Left
	}
	if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
	{
		//Rotate Cannon Right
	}

	if (InputManager->IsKeyDown(GLFW_KEY_SPACE))
	{
		//Shoot based on cannon rotation
	}

	std::cout << playerPos.x << " " << playerPos.y << " " << std::endl;

	/*
	//--------player-Movement--------//
	// W/A = foward/back
	// A/D = rotate player and cannon

	//--------cannon-Movement--------//
	// cannon x/y = player x/y
	// Left/Right arrows = rotate cannon

	//--------Enemy-------//
	//spawn around edge
	
	// if player x > enemy x 
	// then enemy x increase
	// else x decrease

	// if player y > enemy y 
	// then enemy y increase
	// else enemy decrease
	*/

	player.UpdateTransform();

}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();
	m_spritebatch->Begin();
	//Matrix3 scale;

	// TODO: draw stuff.

	//m_spritebatch->DrawSprite(background, 320, 240, 640, 480);
	m_spritebatch->DrawSpriteTransformed3x3(tankTex, playerMat.GetMatrix(), 100.0f, 100.0f/*, playerMat.a11, playerMat.a22*/);

	m_spritebatch->DrawSprite(cannonTex, cannonPos.x, cannonPos.y, 50.0f, 50.0f);
	//m_spritebatch->DrawSprite(enemyTex, enemyPos.x, enemyPos.y, 50.0f, 50.0f);


	//m_spritebatch->DrawSprite(arrowTex, arrowPosx, arrowPosy, 25.0f, 200.0f);

	m_spritebatch->End();

}