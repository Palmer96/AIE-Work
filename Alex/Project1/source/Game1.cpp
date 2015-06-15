#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "Vector2.h"
#include <time.h>
#include "String"
#include <iostream>

/*
   ____  _____  ____ _____ _______       _                ___   ___  
  / __ \|  __ \|  _ \_   _|__   __|/\   | |              / _ \ |__ \ 
 | |  | | |__) | |_) || |    | |  /  \  | |       __   _| | | |   ) |
 | |  | |  _  /|  _ < | |    | | / /\ \ | |       \ \ / / | | |  / / 
 | |__| | | \ \| |_) || |_   | |/ ____ \| |____    \ V /| |_| | / /_ 
  \____/|_|  \_\____/_____|  |_/_/    \_\______|    \_/  \___(_)____|
                                                                     
                                                                                 */

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	vector3.x = 3;
	vector3.y = 3;
	vector3.z = 3;

	printCounter = 0;

	fTimer = 0;
	fOrbitTimer = 0;
	fGameTimer = 0;
	fWinTimer = 10;
	iTrailCount = 0;
	iTrailAmount = 120;
	fPastLength = 0;

	fGravMultiplier = 1.0f;
	srand(time(NULL));
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	iBallCount = 2;
	blueCircle = new Texture("./Images/256blue.png");
	rocket = new Texture("./Images/Rocket.png");
	rocketFire = new Texture("./Images/RocketFire.png");
	purpleCircle = new Texture("./Images/PurpleCircle.png");
	deepRedCircle = new Texture("./Images/DeepRedCircle.png");
	deepGreenCircle = new Texture("./Images/DeepGreenCircle.png");
	redRing = new Texture("./Images/RedRing.png");
	yellowRing = new Texture("./Images/YellowRing.png");
	greenRing = new Texture("./Images/GreenRing.png");

	
	ring.sprite = redRing;

	for (int i = 0; i < iTrailAmount; i++)
	{
		trail[i].sprite = purpleCircle;
		trail[i].fSpriteSize = 3;
	}
	trail[0].sprite = deepGreenCircle;
	trail[1].sprite = deepRedCircle;
	trail[0].fSpriteSize = 8;
	trail[1].fSpriteSize = 8;

	player.sprite = rocket;
	

	player.rotation.mm[0][0] = cos(player.fRotation - 2.595);
	player.rotation.mm[1][0] = sin(player.fRotation - 2.595);
	player.rotation.mm[0][1] = cos((player.fRotation - 2.595) + 90);
	player.rotation.mm[1][1] = sin((player.fRotation - 2.595) + 90);
	player.newDirection = player.rotation * player.direction;

	bWon = false;
	bStart = false;
	for (int i = 0; i < iBallCount; i++)
	{
		//int spriteNum = rand() % 3;
		//
		//if (spriteNum == 0)
		//{
		//	follower[i].sprite = new Texture("./Images/Pascall.png");
		//}
		//else if (spriteNum == 1)
		//{
		//	follower[i].sprite = new Texture("./Images/Lachie.png");
		//}
		//else if (spriteNum == 2)
		//{
		//	follower[i].sprite = new Texture("./Images/Bryce.png");
		//}
		//else
		//{
		//	follower[i].sprite = blueCircle;
		//}

		follower[i].coords.x = rand() % 1650;
		follower[i].coords.y = rand() % 1050;
		
		//follower[i].coords.x = rand() % 400 + 500;
		//follower[i].coords.y = rand() % 400 + 500;
		
		
		follower[i].sprite = blueCircle;
		
	}
	
	follower[0].fSpriteSize = 200;
	follower[0].coords.x = 840;
	follower[0].coords.y = 525;
	
	//follower[0].fSpriteSize = 300;

	//Scenario 1
	follower[0].fSpriteSize = 80;
	follower[0].coords.x = 840;
	follower[0].coords.y = 525;
	follower[0].momentum.y = -0.015;
	follower[0].bCheckGravity = false;
	follower[1].fSpriteSize = 40;
	follower[1].coords.x = 1240;
	follower[1].coords.y = 525;
	follower[1].momentum.y = 0.322;
	player.coords.x = 440;
	player.coords.y = 525;
	player.fObjectSpeed = 20;
	player.momentum.y = 0.322;
	player.fFuel = 1000;
	ring.fSpriteSize = 150;

	//Sun, planet and moon
	//follower[0].fSpriteSize = 200;
	//follower[0].coords.x = 840;
	//follower[0].coords.y = 525;
	//follower[0].momentum.y = -0.02;
	//follower[1].fSpriteSize = 30;
	//follower[1].coords.x = 1340;
	//follower[1].coords.y = 525;
	//follower[1].momentum.y = 0.7;
	//follower[2].fSpriteSize = 10;
	//follower[2].coords.x = 1300;
	//follower[2].coords.y = 525;
	//follower[2].momentum.y = 0.40;

	//Sun, planet and 2 moons
	//follower[0].fSpriteSize = 200;
	//follower[0].coords.x = 840;
	//follower[0].coords.y = 525;
	//follower[1].fSpriteSize = 30;
	//follower[1].coords.x = 1340;
	//follower[1].coords.y = 525;
	//follower[1].momentum.y = 1.0;
	//follower[2].fSpriteSize = 5;
	//follower[2].coords.x = 1300;
	//follower[2].coords.y = 525;
	//follower[2].momentum.y = 0.50;
	//follower[3].fSpriteSize = 5;
	//follower[3].coords.x = 1380;
	//follower[3].coords.y = 525;
	//follower[3].momentum.y = 1.50;

	//Sun and 2 planets with moons
	//follower[0].fSpriteSize = 200;
	//follower[0].coords.x = 840;
	//follower[0].coords.y = 525;
	//follower[1].fSpriteSize = 30;
	//follower[1].coords.x = 1340;
	//follower[1].coords.y = 525;
	//follower[1].momentum.y = 1.0;
	//follower[2].fSpriteSize = 5;
	//follower[2].coords.x = 1300;
	//follower[2].coords.y = 525;
	//follower[2].momentum.y = 0.50;
	//follower[3].fSpriteSize = 30;
	//follower[3].coords.x = 340;
	//follower[3].coords.y = 525;
	//follower[3].momentum.y = -1;
	//follower[4].fSpriteSize = 5;
	//follower[4].coords.x = 300;
	//follower[4].coords.y = 525;
	//follower[4].momentum.y = -0.5;

	//Binary star system
	//follower[0].fSpriteSize = 100;
	//follower[0].coords.x = 640;
	//follower[0].coords.y = 525;
	//follower[0].momentum.y = -0.28;
	//follower[1].fSpriteSize = 100;
	//follower[1].coords.x = 1040;
	//follower[1].coords.y = 525;
	//follower[1].momentum.y = 0.28;
	//player.coords.x = 440;
	//player.momentum.y = 0.445;

	//Planet formation


	
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		std::cout << derp.mm[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	//
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		std::cout << herp.mm[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	//
	//blerp = derp + herp;
	//
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		std::cout << blerp.mm[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;
	//
	//blerp = derp * herp; 
	//
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		std::cout << blerp.mm[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	
	//other = derp * vector3;
	//
	//std::cout << other.x << std::endl;
	//std::cout << other.y << std::endl;
	//std::cout << other.z << std::endl;

	
	for (int i = 0; i < iBallCount; i++)
	{
		follower[i].fObjectSpeed = (((follower[i].fSpriteSize / 2) * (follower[i].fSpriteSize / 2)) * 3.1415926);
		follower[i].fObjectSpeed = (follower[i].fObjectSpeed * fGravMultiplier);
	}
	
}



Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}



void Game1::Gravity(float deltaTime)
{
	float Length = 0.0;
	for (int i = 0; i < iBallCount; i++)
	{
		Vector2 distance;
		distance.x = (player.coords.x - follower[i].coords.x);
		distance.y = (player.coords.y - follower[i].coords.y);
		Length = distance.Length();
	
		
		Vector2 Normalised = distance.Normalise();
	
		player.momentum.x -= ((Normalised.x * (follower[i].fObjectSpeed) * deltaTime) / ((Length * Length) + 64));
		player.momentum.y -= ((Normalised.y * (follower[i].fObjectSpeed) * deltaTime) / ((Length * Length) + 64));
	}
	player.coords.x += player.momentum.x * deltaTime * 121;
	player.coords.y += player.momentum.y * deltaTime * 121;
	
	for (int i = 0; i < iBallCount; i++)
	{
		if (follower[i].bCheckGravity == true)
		{
			follower[i].sprite = blueCircle;
			for (int j = 0; j < iBallCount; j++)
			{
				if (i != j)
				{
					Vector2 distance;
					distance.x = (follower[i].coords.x - follower[j].coords.x);
					distance.y = (follower[i].coords.y - follower[j].coords.y);
					Length = distance.Length();
					//if (Length <= (follower[i].fSpriteSize / 2) + (follower[j].fSpriteSize / 2))
					//{
					//	follower[i].sprite = redCircle;
					//	//if (follower[i].momentum.x > 0 && follower[i].momentum.y > 0)
					//	//{
					//	//	follower[i].momentum.x -= 0.03 * deltaTime;
					//	//	follower[i].momentum.y -= 0.03 * deltaTime;
					//	//}
					//	//if (follower[i].momentum.x < 0 && follower[i].momentum.y > 0)
					//	//{
					//	//	follower[i].momentum.x += 0.03 * deltaTime;
					//	//	follower[i].momentum.y -= 0.03 * deltaTime;
					//	//}
					//	//if (follower[i].momentum.x > 0 && follower[i].momentum.y < 0)
					//	//{
					//	//	follower[i].momentum.x -= 0.03 * deltaTime;
					//	//	follower[i].momentum.y += 0.03 * deltaTime;
					//	//}
					//	//if (follower[i].momentum.x < 0 && follower[i].momentum.y < 0)
					//	//{
					//	//	follower[i].momentum.x += 0.03 * deltaTime;
					//	//	follower[i].momentum.y += 0.03 * deltaTime;
					//	//}
					//}
					if (Length >= 0.0001)
					{
						Vector2 Normalised = distance.Normalise();

						follower[i].momentum.x += ((Normalised.x * (follower[j].fObjectSpeed) * deltaTime) / ((Length * Length) + 32));
						follower[i].momentum.y += ((Normalised.y * (follower[j].fObjectSpeed) * deltaTime) / ((Length * Length) + 32));

					}
				}
			}
			follower[i].coords.x -= follower[i].momentum.x * deltaTime * 121;
			follower[i].coords.y -= follower[i].momentum.y * deltaTime * 121;
		}
	}
}

void Game1::Reset()
{
	follower[0].fSpriteSize = 80;
	follower[0].coords.x = 840;
	follower[0].coords.y = 525;
	follower[0].momentum.y = -0.015;
	follower[0].bCheckGravity = false;
	follower[1].fSpriteSize = 40;
	follower[1].coords.x = 1240;
	follower[1].coords.y = 525;
	follower[1].momentum.x = 0;
	follower[1].momentum.y = 0.322;
	player.coords.x = 440;
	player.coords.y = 525;
	player.fObjectSpeed = 20;
	player.momentum.x = 0;
	player.momentum.y = 0.322;
	ring.fSpriteSize = 150;
	for (int i = 0; i < iTrailAmount; i++)
	{
		trail[i].coords.x = -20;
		trail[i].coords.y = -20;
	}
	trail[0].coords.x = player.coords.x;
	trail[0].coords.y = player.coords.y;
	iTrailAmount = 120;
	player.fFuel = 1000;
	player.fRotation = 0;
	player.rotation.mm[0][0] = cos(player.fRotation - 2.595);
	player.rotation.mm[1][0] = sin(player.fRotation - 2.595);
	player.rotation.mm[0][1] = cos((player.fRotation - 2.595) + 90);
	player.rotation.mm[1][1] = sin((player.fRotation - 2.595) + 90);
	player.newDirection = player.rotation * player.direction;
	fGameTimer = 0;
	fWinTimer = 10;
	bWon = false;
}

void Game1::Update(float deltaTime)
{
	if (GetInput()->IsKeyDown(GLFW_KEY_ESCAPE))
	{
		Quit();
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_ENTER))
	{
		Reset();
		bStart = true;
	}
	if (bStart == true)
	{
		Vector2 playerDistance;
		float Length;
		if (GetInput()->IsKeyDown(GLFW_KEY_LEFT_SHIFT))
		{
			fTimer += deltaTime * 6;
		}
		else
		{
			fTimer += deltaTime;
		}
		if (fTimer > 0.01)
		{
			playerDistance.x = (player.coords.x - follower[0].coords.x);
			playerDistance.y = (player.coords.y - follower[0].coords.y);
			Length = playerDistance.Length();
			if (Length > fPastLength)
			{
				trail[0].coords.x = player.coords.x;
				trail[0].coords.y = player.coords.y;
			}
			if (Length < fPastLength)
			{
				trail[1].coords.x = player.coords.x;
				trail[1].coords.y = player.coords.y;
			}
			fPastLength = Length;
		}
		
		if (fTimer > 0.25)
		{
			trail[iTrailCount].coords.x = player.coords.x;
			trail[iTrailCount].coords.y = player.coords.y;
			iTrailCount++;
			if (iTrailCount > iTrailAmount - 1)
			{
				iTrailCount = 2;
			}

			fTimer = 0;
		}
		
		player.sprite = rocket;
		if (GetInput()->IsKeyDown(GLFW_KEY_W))
		{
			if (player.fFuel > 0)
			{
				if (GetInput()->IsKeyDown(GLFW_KEY_U))
				{
					player.momentum.x += (player.newDirection.x * deltaTime) * 5;
					player.momentum.y += (player.newDirection.y * deltaTime) * 5;
					player.sprite = rocketFire;
				}
				else  if (GetInput()->IsKeyDown(GLFW_KEY_LEFT_SHIFT))
				{
					player.momentum.x += (player.newDirection.x * deltaTime) * 5;
					player.momentum.y += (player.newDirection.y * deltaTime) * 5;
					player.fFuel -= (500 * deltaTime);
					player.sprite = rocketFire;
				}
				else
				{
					player.momentum.x += (player.newDirection.x * deltaTime);
					player.momentum.y += (player.newDirection.y * deltaTime);
					player.fFuel -= (100 * deltaTime);
					player.sprite = rocketFire;
				}
				if (player.fFuel < 0)
				{
					player.fFuel = 0;
				}
			}
		}
		if (GetInput()->IsKeyDown(GLFW_KEY_A))
		{
			player.fRotation -= (4 * deltaTime);
			if (player.fRotation > 6.28318531)
			{
				player.fRotation = 0;
			}
			if (player.fRotation < 0)
			{
				player.fRotation = 6.28318531;
			}
			player.rotation.mm[0][0] = cos(player.fRotation - 2.595);
			player.rotation.mm[1][0] = sin(player.fRotation - 2.595);
			player.rotation.mm[0][1] = cos((player.fRotation - 2.595) + 90);
			player.rotation.mm[1][1] = sin((player.fRotation - 2.595) + 90);
			player.newDirection = player.rotation * player.direction;
		}
		if (GetInput()->IsKeyDown(GLFW_KEY_S))
		{

		}
		if (GetInput()->IsKeyDown(GLFW_KEY_D))
		{
			player.fRotation += (4 * deltaTime);
			if (player.fRotation > 6.28318531)
			{
				player.fRotation = 0;
			}
			if (player.fRotation < 0)
			{
				player.fRotation = 6.28318531;
			}
			player.rotation.mm[0][0] = cos(player.fRotation - 2.595);
			player.rotation.mm[1][0] = sin(player.fRotation - 2.595);
			player.rotation.mm[0][1] = cos((player.fRotation - 2.595) + 90);
			player.rotation.mm[1][1] = sin((player.fRotation - 2.595) + 90);
			player.newDirection = player.rotation * player.direction;
		}

		playerDistance.x = (player.coords.x - follower[1].coords.x);
		playerDistance.y = (player.coords.y - follower[1].coords.y);
		Length = playerDistance.Length();
		if (Length > ring.fSpriteSize / 2)
		{
			ring.sprite = redRing;
			fOrbitTimer = 0;
			if (fGameTimer <= 120)
			{
				if (GetInput()->IsKeyDown(GLFW_KEY_LEFT_SHIFT))
				{
					fGameTimer += deltaTime * 5;
				}
				else
				{
					fGameTimer += deltaTime;
				}

			}
			else
			{
				Reset();
			}
		}
		else if (Length <= ring.fSpriteSize / 2)
		{
			ring.sprite = yellowRing;
			if (GetInput()->IsKeyDown(GLFW_KEY_LEFT_SHIFT))
			{
				fOrbitTimer += deltaTime * 5;
			}
			else
			{
				fOrbitTimer += deltaTime;
			}
			if (fOrbitTimer > 10)
			{
				ring.sprite = greenRing;
				if (fOrbitTimer > 60)
				{
					bWon = true;
				}
			}
		}
		if (bWon == true)
		{
			fWinTimer -= deltaTime;
			if (fWinTimer < 0)
			{
				Reset();
			}
		}

		
		if (bWon == false && (player.coords.x < -100 || player.coords.x > 1750 || player.coords.y > 1150 || player.coords.y < -100))
		{
			Reset();
		}
		
		

		playerDistance.x = (player.coords.x - follower[0].coords.x);
		playerDistance.y = (player.coords.y - follower[0].coords.y);
		Length = playerDistance.Length();

		if (Length < (follower[0].fSpriteSize / 2) + 15)
		{
			Reset();
		}

		//follower.Follow(player, deltaTime);

		if (GetInput()->IsKeyDown(GLFW_KEY_LEFT_SHIFT))
		{
			for (int i = 0; i < 4; i++)
			{
				Gravity(deltaTime);
			}
		}
		Gravity(deltaTime);
	}
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();


	for (int i = 0; i < iBallCount; i++)
	{
		m_spritebatch->DrawSprite(follower[i].sprite, follower[i].coords.x, follower[i].coords.y, follower[i].fSpriteSize, follower[i].fSpriteSize);
	}
	for (int i = 2; i < iTrailAmount; i++)
	{
		m_spritebatch->DrawSprite(trail[i].sprite, trail[i].coords.x, trail[i].coords.y, trail[i].fSpriteSize, trail[i].fSpriteSize);
	}
	m_spritebatch->DrawSprite(trail[0].sprite, trail[0].coords.x, trail[0].coords.y, trail[0].fSpriteSize, trail[0].fSpriteSize);
	m_spritebatch->DrawSprite(trail[1].sprite, trail[1].coords.x, trail[1].coords.y, trail[1].fSpriteSize, trail[1].fSpriteSize);

	m_spritebatch->DrawSprite(ring.sprite, follower[1].coords.x, follower[1].coords.y, ring.fSpriteSize, ring.fSpriteSize);

	m_spritebatch->DrawSprite(player.sprite, player.coords.x, player.coords.y, player.fSpriteWidth / 20, player.fSpriteHeight / 20, player.fRotation);
	
	player.sFuel = std::to_string((int) player.fFuel);
	sOrbitTimer = std::to_string((int) fOrbitTimer);
	sGameTimer = std::to_string((int) fGameTimer);
	sWinTimer = std::to_string((int) fWinTimer);

	m_spritebatch->DrawString(player.fuel, player.sFuel.c_str(), 1580, 10);
	m_spritebatch->DrawString(player.fuel, sOrbitTimer.c_str(), 1580, 30);
	m_spritebatch->DrawString(player.fuel, sGameTimer.c_str(), 1580, 50);

	if (bWon == true)
	{
		m_spritebatch->DrawString(player.fuel, "YOU WIN! :D", 797, 515);
		m_spritebatch->DrawString(player.fuel, "Game wil reset in:", 767, 580);
		m_spritebatch->DrawString(player.fuel, sWinTimer.c_str(), 897, 580);


	}

	m_spritebatch->DrawSprite(player.sprite, player.coords.x + player.direction.x, player.coords.y + player.direction.y, player.fSpriteWidth / 20, player.fSpriteHeight / 20, player.fRotation);

	// TODO: draw stuff.

	m_spritebatch->End();

}