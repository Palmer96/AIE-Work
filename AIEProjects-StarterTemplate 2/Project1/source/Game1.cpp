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
	playerTex = new Texture("./Images/player.png");
	enemyTex = new Texture("./Images/enemy.png");
	
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	}


void Game1::Update(float deltaTime)
{
	Input * InputManager = GetInput();

	if (InputManager->WasKeyPressed(GLFW_KEY_UP))
	{
	//
	}
	
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();
	m_spritebatch->Begin();


	// TODO: draw stuff.

	m_spritebatch->DrawSprite(background, 320, 240, 640, 480);


	m_spritebatch->End();

}