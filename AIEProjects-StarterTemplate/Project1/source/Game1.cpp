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
	pTexture = new Texture("./Images/Grump.png");
	pLTexture = new Texture("./Images/Grump_Left.png");
	pRTexture = new Texture("./Images/Grump_Right.png");
	
	s1LTexture = new Texture("./Images/shot_Left.png");
	s1RTexture = new Texture("./Images/shot_Right.png");
	s2LTexture = new Texture("./Images/lavafireball_Left.png");
	s2RTexture = new Texture("./Images/lavafireball_Right.png");
	e1Texture = new Texture("./Images/download.png");
	e2Texture = new Texture("./Images/ship.png");
	wTexture = new Texture("./Images/wall.png");


	gTexture = new Texture("./Images/gear.png");

//	Vector2 PlayerVec(300.0f, 400.0f);
		posX = 300.0f;
		posY = 400.0f;

	sX = posX;
	sY = posY - 50.0f;

	eX = 0.0f;
	eY = 375.0f;

	wallX = 320.0f;
	wallY = 414.5f;

	speed = 150;
	bullets[100];
	bulletCount = 0;
	shoot = false;
	jump = false;
	gravity = 20.0f;//9.81;

	Left = false;
	Leftbullet = false;
	fall = false;

	peak = -200.0f;
	floor = posY;

	shooting = false;
	change = false;

	i = 0;
	j = 0;
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	//	delete pTexture;

	//	delete background;
	//	delete pTexture;
	//	delete pLTexture;
	//	delete pRTexture;
	//
	//	delete sLTexture;
	//	delete sRTexture;
	//
	//	delete eTexture;
	//	delete wTexture;


}


void Game1::Update(float deltaTime)
{
	Input * InputManager = GetInput();

	if (InputManager->WasKeyPressed(GLFW_KEY_UP))
	{
		if (fall == false)
		{
			jump = true;
			peak = posY - 10.0f;
			//floor = posY;
		}
	}
	if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
	{
		posX -= speed * deltaTime;

		Left = true;
	}
	if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
	{
		posX += speed * deltaTime;

		Left = false;
	}

	if (shoot == false)
	{
		sX = posX;
		sY = posY - 15.0f;
	}

	if (InputManager->WasKeyPressed(GLFW_KEY_SPACE))
	{
		shoot = true;
		shooting = true;

		if (Left == true)
		{
			Leftbullet = true;
		}
		else
		{
			Leftbullet = false;
		}
	}

	if (sY <= 5.0f)
	{
		shoot = false;
		sX = posX;
		sY = posY;
	}

	// shooting
	if (shoot == true)
	{

		if (Leftbullet == true)
		{
			sX -= speed * deltaTime;
		}
		else
		{
			sX += speed * deltaTime;
		}
		
	}


	// jump / Gravity

	if (jump == true)
	{
		posY -= peak * deltaTime;
		peak -= gravity;
	}

	if (posY >= floor)
	{
		jump = false;
	}


	// possible way to break up shoot to set a limit on how many at a time
	// set i to 0 in constructor
	// if i != 10,i++ each update
	// if i = 10, able to shoot == true

	// if spacebar,
	//				create bullet
	//				set i to 0
	//				set able to shoot to false




	// ememy move towards player
	if (eX > posX)
		eX -= 75 * deltaTime;
	else
		eX += 75 * deltaTime;

	//	if (eY > posY)
	//		eY -= 75 * deltaTime;
	//	else
	//		eY += 75 * deltaTime;

	if (eX > posX && eY > posY)
	{


	}



	// collision

	if (eX + 25 == posX - 25 || eX - 25 == posX + 25 || eY + 25 == posY - 25 || eY - 25 == posY + 25)
	{
		posX = 400.0f;
		posY = 400.0f;

	}

	if (sX <= 0.0f || sX >= 640.0f)
	{
		shoot = false;
		sX = posX;
		sY = posY;
	}



	// ememy and bullet

	//if ((eY + 14 <= sY) && (sX >= eX || sX <= eX))
	if ((eY == sY) && (eX == sX))
	{
		eX = 100.0f;
		eY = 100.0f;
	}

	
	if (change == false)
	{
		i++;

		if (i == 10)
		{
			change = true;
			i = 0;
		}
	} 
	if (change == true)
	{
		j++;
		if (j == 10)
		{
			change = false;
			j = 0;
		}


	}
}

void Game1::Draw()
{
	// clear the back buffer
	//Vector2 PlayerVec(300.0f, 400.0f);
	ClearScreen();
	m_spritebatch->Begin();


	// TODO: draw stuff.

	m_spritebatch->DrawSprite(background, 320, 240, 640, 480);
	m_spritebatch->DrawSprite(gTexture, 100, 170, 40, 40);




	if (shoot == true)
	{
		if (Leftbullet == true)
		{
			if (change == true)
			{
				m_spritebatch->DrawSprite(s1LTexture, sX, sY, 25, 25);
			}
			else
			{
				m_spritebatch->DrawSprite(s2LTexture, sX, sY, 25, 25);
			}
		}
		else
			if (change == true)
			{
				m_spritebatch->DrawSprite(s1RTexture, sX, sY, 25, 25);
			}
			else
			{
				m_spritebatch->DrawSprite(s2RTexture, sX, sY, 25, 25);
			}
	}


	if (Left == true)
	{
		//m_spritebatch->DrawSprite(pLTexture, PlayerVec.x, PlayerVec.y, 30, 56);
		m_spritebatch->DrawSprite(pLTexture, posX, posY, 30, 56);
	}
	else
	{
		m_spritebatch->DrawSprite(pRTexture, posX, posY, 30, 56);
	}

		m_spritebatch->DrawSprite(e1Texture, eX, eY, 50, 50);



	m_spritebatch->DrawSprite(wTexture, wallX, wallY, 640, 25);
	m_spritebatch->DrawSprite(wTexture, 200, 200, 640, 25);

	m_spritebatch->End();

}