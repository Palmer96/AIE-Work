#include <iostream>
#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	background = new Texture("./Images/Background.png");
	rTexture = new Texture("./Images/Rock.png");
	pTexture = new Texture("./Images/Paper.png");
	sTexture = new Texture("./Images/Scissors.png");

	posX = 200.0f;
	posY = 200.0f;
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	delete pTexture;
	delete sTexture;
}

void Game1::PlayerSelect()
{
	while (true)
	{
		std::cin >> playerChoice;
		if ((playerChoice == 1) || (playerChoice == 2) || (playerChoice == 3))
			break;
	}
}
void Game1::AiSelect()
{
	aiChoice = rand() % 3 + 1;
}

void Game1::Update(float deltaTime)
{

	games++;
	if (((playerChoice == 1) && (aiChoice == 3)) ||
		((playerChoice == 2) && (aiChoice == 1)) ||
		((playerChoice == 3) && (aiChoice == 2)))
	{
		wins++;
	}
	if (((playerChoice == 1) && (aiChoice == 2)) ||
		((playerChoice == 2) && (aiChoice == 3)) ||
		((playerChoice == 3) && (aiChoice == 1)))
	{
		loses++;
	}

	percentage = (wins / games) * 100;




	//				Input * InputManager = GetInput();
	//					if (InputManager->WasKeyPressed(GLFW_KEY_UP))
	//					{
	//						jump = true;
	//					}
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	// TODO: draw stuff.

	m_spritebatch->DrawSprite(background, 320, 240, 640, 480);

	m_spritebatch->DrawSprite(rTexture, posX, posY, 150, 150);
	//m_spritebatch->DrawSprite(pTexture, posX, posY, 150, 150);
	//m_spritebatch->DrawSprite(sTexture, posX, posY, 150, 150);


	m_spritebatch->End();

}