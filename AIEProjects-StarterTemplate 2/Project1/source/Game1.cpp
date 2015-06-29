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
	ballTex = new Texture("./Images/arrow.png");


	//Vector3 playerPos(300.0f, 300.0f, 1.0f);
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

	Object cannon(cannonPos);

	Matrix3 cannonMat(1.0f, 0.0f, cannonPos.x,
		0.0f, 1.0f, cannonPos.y,
		0.0f, 0.0f, 1.0f);

	Vector3 VTankSpeed(10.0f, 10.0f, 1.0f);
	tankSpeed = 100.0f;

	rotateLeft = false;
	rotateRight = false;

	rotate = 20.0f;

	Vector3 directionT(playerPos.x, playerPos.y + 20.0f, 1.0f);
	Matrix3 directionTMat(1.0f, 0.0f, 0.0f,
						  0.0f, 1.0f, 0.0f,
						playerPos.x, playerPos.y, 1.0f);

	//Matrix3 directionTMat(1.0f, 0.0f, playerPos.x,
	//					  0.0f, 1.0f, playerPos.y,
	//					  0.0f, 0.0f, 1.0f);


	Vector3 directionC(playerPos.x, playerPos.y + 20.0f, 1.0f);
	Vector2 line(100.0f, 100.0f);
	shoot = false;


	Vector2 ballPos(100.0f, 100.0f);
	Vector2 ballVel(10.0f, 10.0f);

	Matrix3 MatTranslation = MatTranslation.Translation(playerPos);
	Matrix3 MatRotate = MatTranslation.Rotation(0);
	Matrix3 CanMatRotate = MatTranslation.Rotation(0);
	Matrix3 MatScale = MatTranslation.Scale(playerPos);
	i = 15;
	enemyTotal = 0;
	Vector2 enemy(300.0f, 300.0f);
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
		//--------Move Foward

		playerPos.y -= 10.0f;
		cannonPos.y -= 10.0f;
		//playerPos *= directionT;
		//MatTranslation = playerMat.Translation(playerPos) * directionTMat;
	}

	if (InputManager->IsKeyDown(GLFW_KEY_S))
	{
		//--------Move Back
		playerPos.y += 10.0f;
		cannonPos.y += 10.0f;

	}
	if (InputManager->IsKeyDown(GLFW_KEY_A))
	{
		//--------Rotate Tank and Cannon Left
		MatRotate = MatRotate * playerMat.Rotation(1 * deltaTime);
		CanMatRotate = CanMatRotate * cannonMat.Rotation(1 * deltaTime);
	}
	if (InputManager->IsKeyDown(GLFW_KEY_D))
	{
		//--------Rotate Tank and Cannon Right
		MatRotate = MatRotate * playerMat.Rotation(-1 * deltaTime);
		CanMatRotate = CanMatRotate * cannonMat.Rotation(-1 * deltaTime);
	}

	if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
	{
		//--------Rotate Cannon Left
		CanMatRotate = CanMatRotate * cannonMat.Rotation(1.5 * deltaTime);
	}
	if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
	{
		//--------Rotate Cannon Right
		CanMatRotate = CanMatRotate * cannonMat.Rotation(-1.5 * deltaTime);
	}

	if (InputManager->WasKeyPressed(GLFW_KEY_SPACE))
	{
		//--------Shoot based on cannon rotation
		shoot = true;
		line.x += 10.0f * deltaTime;
	}

	if (shoot == true)
	{
		line.x += 10.0f * deltaTime;
	}

	//ballPos += (ballPos.VecFlo(ballVel, deltaTime));
	ballPos = ballPos + ballVel;

	//		i++;
	//		if (i = 100)
	//		{
	//			i = 0;
	//			enemyTotal++;
	//		}
//	enemy[j].y += 10.0f;
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

	


	playerMat = playerMat.Translation(playerPos) *  MatRotate * MatScale;
	cannonMat = cannonMat.Translation(cannonPos) *  CanMatRotate * MatScale;
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();
	m_spritebatch->Begin();


	// TODO: draw stuff.
	m_spritebatch->DrawSpriteTransformed3x3(tankTex, playerMat.GetMatrix(), 100.0f, 100.0f);
	m_spritebatch->DrawSpriteTransformed3x3(cannonTex, cannonMat.GetMatrix(), 100.0f, 100.0f);

	m_spritebatch->DrawSpriteTransformed3x3(ballTex, player.playerMat.GetMatrix(), 20.0f, 10.0f, 0.5, 8);
	m_spritebatch->DrawSpriteTransformed3x3(ballTex, cannonMat.GetMatrix(), 20.0f, 10.0f, 0.5, 9);

	//while (j <= enemyTotal)
	//{
	//	m_spritebatch->DrawSprite(cannonTex, enemy[j].x, enemy[j].y, 75.0f, 75.0f);
	//	j++;
	//}
	//j = 0;


	m_spritebatch->End();

}