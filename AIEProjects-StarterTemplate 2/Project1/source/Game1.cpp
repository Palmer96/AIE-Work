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

	Vector3 directionC(playerPos.x, playerPos.y + 20.0f, 1.0f);
	Vector2 line(100.0f, 100.0f);
	shoot = false;


	Vector2 ballPos(100.0f, 100.0f);
	Vector2 ballVel(10.0f, 10.0f);
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

		//playerMat = player.playerMat.Translation(VTankSpeed * deltaTime) *playerMat;

		//playerPos = playerMat.Translation(playerPos) * direction;
		playerMat = playerMat * playerMat.Transpose(playerMat.Translation(playerPos));
	}

	if (InputManager->IsKeyDown(GLFW_KEY_S))
	{
		//--------Move Back

	}
	if (InputManager->IsKeyDown(GLFW_KEY_A))
	{
		//--------Rotate Tank and Cannon Left
		player.playerMat = player.playerMat.ChangeRotation(player.playerMat, 1 * deltaTime);
		cannonMat = cannonMat.ChangeRotation(cannonMat, 1 * deltaTime);
	//	directionTMat = player.playerMat.ChangeRotation(player.playerMat, 1 * deltaTime);
	}
	if (InputManager->IsKeyDown(GLFW_KEY_D))
	{
		//--------Rotate Tank and Cannon Right
		player.playerMat = player.playerMat.ChangeRotation(player.playerMat, -1 * deltaTime);
		cannonMat = cannonMat.ChangeRotation(cannonMat, -1 * deltaTime);
	//	directionTMat = player.playerMat.ChangeRotation(player.playerMat, -1 * deltaTime);
	}

	if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
	{
		//--------Rotate Cannon Left
		cannonMat = cannonMat.ChangeRotation(cannonMat, 1.5f * deltaTime);
	}
	if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
	{
		//--------Rotate Cannon Right
		cannonMat = cannonMat.ChangeRotation(cannonMat, -1.5f * deltaTime);
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


	std::cout << ballPos.x << " " << ballPos.y << " " << std::endl;

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
	cannon.UpdateTransform();
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();
	m_spritebatch->Begin();


	// TODO: draw stuff.

	//m_spritebatch->DrawSprite(background, 320, 240, 640, 480);
	m_spritebatch->DrawSpriteTransformed3x3(tankTex, player.playerMat.GetMatrix(), 100.0f, 100.0f);
	m_spritebatch->DrawSpriteTransformed3x3(cannonTex, cannonMat.GetMatrix(), 100.0f, 100.0f);

	m_spritebatch->DrawSpriteTransformed3x3(ballTex, player.playerMat.GetMatrix(), 20.0f, 10.0f, 0.5, 8);
	m_spritebatch->DrawSpriteTransformed3x3(ballTex, cannonMat.GetMatrix(), 20.0f, 10.0f, 0.5, 9);


	//	m_spritebatch->DrawLine(line.x, line.y, line.x+100.0f, line.y, 5.0f);

	//m_spritebatch->DrawSprite(ballTex, ballPos.x, ballPos.y, 50.0f, 50.0f);

	//m_spritebatch->DrawSpriteTransformed3x3(tankTex, player.playerMat.GetMatrix(), 200.0f, 200.0f, 100.0f, 100.0f);

	//m_spritebatch->DrawSprite(enemyTex, enemyPos.x, enemyPos.y, 50.0f, 50.0f);

	m_spritebatch->End();

}