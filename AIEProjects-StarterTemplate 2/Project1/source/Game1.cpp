#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vectors.h"





//Vector2 PlayerVec;

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	background = new Texture("./Images/Background.png");
	tankTex = new Texture("./Images/Tank_Body.png");
	cannonTex = new Texture("./Images/Tank_Cannon.png");
	enemyTex = new Texture("./Images/enemy.png");



	playerPosx = 300.0f;
	playerPosy = 300.0f;

	cannonPosx = playerPosx;
	cannonPosy = playerPosy;

	enemyPosx = 200.0f;
	enemyPosy = 200.0f;

	tankSpeed = 100.0f;
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	}


void Game1::Update(float deltaTime)
{
	Input * InputManager = GetInput();

	if (InputManager->IsKeyDown(GLFW_KEY_W))
	{
		playerPosy -= tankSpeed * deltaTime;
		cannonPosy -= tankSpeed * deltaTime;
	}
	if (InputManager->IsKeyDown(GLFW_KEY_S))
	{
		playerPosy += tankSpeed * deltaTime;
		cannonPosy += tankSpeed * deltaTime;
	}
	if (InputManager->IsKeyDown(GLFW_KEY_A))
	{
		playerPosx -= tankSpeed * deltaTime;
		cannonPosx -= tankSpeed * deltaTime;
		// will rotate tank with cannon Left
	}
	if (InputManager->IsKeyDown(GLFW_KEY_D))
	{
		playerPosx += tankSpeed * deltaTime;
		cannonPosx += tankSpeed * deltaTime;
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


}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();
	m_spritebatch->Begin();


	// TODO: draw stuff.

	m_spritebatch->DrawSprite(background, 320, 240, 640, 480);
	m_spritebatch->DrawSprite(tankTex, playerPosx, playerPosy, 50.0f, 50.0f);
	m_spritebatch->DrawSprite(cannonTex, cannonPosx, cannonPosy, 50.0f, 50.0f);
	m_spritebatch->DrawSprite(enemyTex, enemyPosx, enemyPosy, 50.0f, 50.0f);



	m_spritebatch->End();

}