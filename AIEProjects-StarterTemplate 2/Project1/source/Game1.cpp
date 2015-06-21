#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vectors.h"

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
	Matrix3 Matrix(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, playerPos.x, playerPos.y, 1.0f);

	Vector3 enemyPos(playerPos.x, playerPos.y, playerPos.z);
	Vector3 cannonPos(200.0f, 200.0f, 1.0f);

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

	rotateLeft = false;
	rotateRight = false;

	//playerPos = (Matrix.Rotation(rotate)  * playerPos) * deltaTime;
	//rotate += 10.0f;

std::cout << playerPos.x << " " << playerPos.y << " " << playerPos.z << std::endl;
	if (InputManager->IsKeyDown(GLFW_KEY_W))
	{
		playerPos.y -= tankSpeed * deltaTime;
		cannonPos.y -= tankSpeed * deltaTime;
	}

	if (InputManager->IsKeyDown(GLFW_KEY_S))
	{
		playerPos.y += tankSpeed * deltaTime;
		cannonPos.y += tankSpeed * deltaTime;
	}
	if (InputManager->IsKeyDown(GLFW_KEY_A))
	{
		//Matrix = 
		Matrix = Matrix.ChangeRotate(Matrix,rotate);
		//Matrix.ChangeRotate(playerPos, rotate);// *deltaTime;
		rotate += 10.0f;
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
		rotateLeft = true;
	}
	if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
	{
		//Rotate Cannon Right
	}

	if (InputManager->IsKeyDown(GLFW_KEY_SPACE))
	{
		//Shoot based on cannon rotation
	}

	std::cout << playerPos.x << " " << playerPos.y << " " << playerPos.z << std::endl;

	

}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();
	m_spritebatch->Begin();
	//Matrix3 scale;

	// TODO: draw stuff.

	m_spritebatch->DrawSprite(background, 320, 240, 640, 480);
	//m_spritebatch->DrawSprite(tankTex, playerPosx, playerPosy, 50.0f, 50.0f);
	//if (rotateLeft == true)
	//{
		m_spritebatch->DrawSpriteTransformed3x3(tankTex, Matrix.GetMatrix(), 100.0f, 100.0f, Matrix.a11, Matrix.a22);
	//}
	m_spritebatch->DrawSprite(cannonTex, cannonPos.x, cannonPos.y, 50.0f, 50.0f);
	m_spritebatch->DrawSprite(enemyTex, enemyPos.x, enemyPos.y, 50.0f, 50.0f);


	m_spritebatch->DrawSprite(arrowTex, arrowPosx, arrowPosy, 25.0f, 200.0f);

	m_spritebatch->End();

}