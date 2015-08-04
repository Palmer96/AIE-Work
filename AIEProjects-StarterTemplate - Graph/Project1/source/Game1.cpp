#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"
#include "Player.h"
#include "MathLib.h"
#include "Agents.h"
#include "iostream"


Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	m_spritebatch->SetColumnMajor(true);
	pGraph = new Graph();





	//---------------------------------------------------------------//

	//				COMBINE THE TWO

	// so that only add Nodes when they would be transversable







	int count = 0;
	int count2 = 0;
	for (int i = 20; i <= 780; i += 20)//39
	{
		for (int j = 20; j <= 1180; j += 20)//59
		{
			pGraph->AddNode(Vector2(j, i));
		}
	}


	for (int j = 0; j < 2264; j += 59)
	{
		for (int i = 0; i < 58; i++)
		{
			pGraph->AddEdge(pGraph->nodes[i + j], pGraph->nodes[i + j + 1], 1);
			pGraph->AddEdge(pGraph->nodes[i + j + 1], pGraph->nodes[i + j], 1);
		}
	}


	for (int j = 0; j < 2205; j += 59)
	{
		for (int i = 0; i < 59; i++)
		{
			pGraph->AddEdge(pGraph->nodes[i + j], pGraph->nodes[i + j + 59], 1);
			pGraph->AddEdge(pGraph->nodes[i + j + 59], pGraph->nodes[i + j], 1);
		}
	}



	for (int j = 241; j < 2300; j += 9)
	{
		count++;
		for (int i = j; i < j + 4; i++)
		{
			pGraph->nodes[i]->transversable = false;
		}
		if (count == 6)
		{
			count = 0;
			count2++;
			j += 5;
		}
		if (count2 == 4)
		{
			count2 = 0;
			j += 295;
		}
	}

	//---------------------------------------------------------------//




















	pGraph->nodes[0]->bIsStart = true;
	pGraph->nodes[1300]->bIsEnd = true;

	pGraph->ActivateDijkstras = false;

	playerTex = new Texture("./Images/Limo.png");
	personTex = new Texture("./Images/nodeTexture.png");
	roadTex = new Texture("./Images/Road.png");
	roofTex = new Texture("./Images/Roof.png");
	bloodTex = new Texture("./Images/Blood.png");



	playerPos = Vector3(600.0f, 400.0f, 1.0f);


	playerMat = Matrix3(playerPos.x, 0.0f, 0.0f,
		0.0f, playerPos.y, 0.0f,
		0.0f, 0.0f, 1.0f);


	agentPos = Vector2(100.0f, 100.0f);
	//agentPos = Vector2(pGraph->nodes[5]->data.x, pGraph->nodes[5]->data.y);
	rotate = 0.0f;
	//person = Agents(agentPos);

	scale = Vector3(1.0f, 1.0f, 1.0f);

	k = 5;
	std::cout << pGraph->nodes[1150]->data.x << ", " << pGraph->nodes[1150]->data.y << std::endl;


	counter1 = 0;
	counter2 = 2;
	counter3 = 4;
	counter4 = 6;
	counter5 = 8;
	counter6 = 10;
	counter7 = 12;
	counter8 = 14;
	counter9 = 16;
	counter10 = 18;
	counter11 = 20;
	counter12 = 22;
	counter13 = 24;
	counter14 = 26;
	counter15 = 28;
	counter16 = 30;
	counter17 = 32;
	counter18 = 34;
	counter19 = 36;
	counter20 = 38;
	counter21 = 40;

	Blood1 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood2 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood3 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood4 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood5 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood6 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood7 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood8 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood9 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood10 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood11 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood12 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood13 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood14 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood15 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood16 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood17 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood18 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood19 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood20 = Vector3(playerPos.x, playerPos.y, 1.0f);
	Blood21 = Vector3(playerPos.x, playerPos.y, 1.0f);



	Alpha= 255;
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{
	Input * InputManager = GetInput();
	//-----------------// Dijkstras //-----------------//
	/*
pGraph->Dijkstras();
if (InputManager->WasKeyPressed(GLFW_KEY_SPACE))
{
pGraph->ActivateDijkstras = true;
}
*/

	//-----------------// Steering //-----------------//

	Vector3 upVec = Vector3(playerMat.a12, playerMat.a11, 1.0);
	Vector3 normVec = upVec.Normalised();

	if (InputManager->IsKeyDown(GLFW_KEY_UP))
	{
		//--------Move Foward
		playerPos -= upVec * 300.0f * deltaTime;

		if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
		{
			//--------Rotate Limo Left
			rotate -= 4 * deltaTime;
		}
		if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
		{
			//--------Rotate Limo Right
			rotate += 4 * deltaTime;
		}
	}
	if (InputManager->IsKeyDown(GLFW_KEY_DOWN))
	{
		//--------Move Back
		playerPos += upVec * 150.0f * deltaTime;

		if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
		{
			//--------Rotate Limo Left
			rotate += 2 * deltaTime;
		}
		if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
		{
			//--------Rotate Limo Right
			rotate -= 2 * deltaTime;
		}
	}

	playerMat = playerMat.Translation(playerPos) *  playerMat.Rotation(rotate) * playerMat.Scale(scale);
	//------------------------------------------------//



	counter1  ++;
	counter2  ++;
	counter3  ++;
	counter4  ++;
	counter5  ++;
	counter6  ++;
	counter7  ++;
	counter8  ++;
	counter9  ++;
	counter10 ++;
	counter11 ++;
	counter12 ++;
	counter13 ++;
	counter14 ++;
	counter15 ++;
	counter16 ++;
	counter17 ++;
	counter18 ++;
	counter19 ++;
	counter20 ++;
	counter21 ++;


	int amount = 40;

	if (counter1 == amount)
	{
		counter1 = 0;
		Blood1 = playerPos;
	}
	if (counter2 == amount)
	{
		counter2 = 0;
		Blood2 = playerPos;
	}
	if (counter3 == amount)
	{
		counter3 = 0;
		Blood3 = playerPos;
	}
	if (counter4 == amount)
	{
		counter4 = 0;
		Blood4 = playerPos;
	}
	if (counter5 == amount)
	{
		counter5 = 0;
		Blood5 = playerPos;
	}
	if (counter6 == amount)
	{
		counter6 = 0;
		Blood6 = playerPos;
	}
	if (counter7 == amount)
	{
		counter7 = 0;
		Blood7 = playerPos;
	}
	if (counter8 == amount)
	{
		counter8 = 0;
		Blood8 = playerPos;
	}
	if (counter9 == amount)
	{
		counter9 = 0;
		Blood9 = playerPos;
	}
	if (counter10 == amount)
	{
		counter10 = 0;
		Blood10 = playerPos;
	}
	if (counter11 == amount)
	{
		counter11 = 0;
		Blood11 = playerPos;
	}
	if (counter12 == amount)
	{
		counter12 = 0;
		Blood12 = playerPos;
	}
	if (counter13 == amount)
	{
		counter13 = 0;
		Blood13 = playerPos;
	}
	if (counter14 == amount)
	{
		counter14 = 0;
		Blood14 = playerPos;
	}
	if (counter15 == amount)
	{
		counter15 = 0;
		Blood15 = playerPos;
	}
	if (counter16 == amount)
	{
		counter16 = 0;
		Blood16 = playerPos;
	}
	if (counter17 == amount)
	{
		counter17 = 0;
		Blood17 = playerPos;
	}
	if (counter18 == amount)
	{
		counter18 = 0;
		Blood18 = playerPos;
	}
	if (counter19 == amount)
	{
		counter19 = 0;
		Blood19 = playerPos;
	}
	if (counter20 == amount)
	{
		counter20 = 0;
		Blood20 = playerPos;
	}
	if (counter21 == amount)
	{
		counter21 = 0;
		Blood21 = playerPos;
	}










	//												person.Update(deltaTime);
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	// TODO: draw stuff.	

	m_spritebatch->Begin();


	//												person.Draw(personTex);// personTex);


	//-----------------// Grid //-----------------//

	for (int i = 0; i < 10; i++)
	{
		m_spritebatch->SetRenderColor(0, 255, 0, 255);
		pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[0]->data, i);

		m_spritebatch->SetRenderColor(255, 0, 0, 255);
		pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[2300]->data, i);
	}

	m_spritebatch->SetRenderColor(255, 255, 255, 255);
	//		loop through all nodes
	for (int i = 0; i < pGraph->nodes.size(); i++)
	{	// show nodes



		if (pGraph->nodes[i]->transversable == false)
		{
			m_spritebatch->DrawSprite(roofTex, pGraph->nodes[i]->data.x, pGraph->nodes[i]->data.y, 20.0f, 20.0f);
		}
		else
		{
			m_spritebatch->DrawSprite(roadTex, pGraph->nodes[i]->data.x, pGraph->nodes[i]->data.y, 20.0f, 20.0f);
		}

		//pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[i]->data, 10.0f);


		/*
		m_spritebatch->SetRenderColor(255, 255, 255, 255);

		if (pGraph->nodes[i]->travelable == false)
		{
		m_spritebatch->SetRenderColor(255, 0, 0, 255);
		}
		else
		{
		m_spritebatch->SetRenderColor(255, 255, 255, 255);
		pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[i]->data, 10.0f);
		}

		m_spritebatch->SetRenderColor(255, 0, 0, 255);
		pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[1150]->data, 10.0f);
		//pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[i]->data, 10.0f);
		m_spritebatch->SetRenderColor(255, 255, 255, 255);

		//	m_spritebatch->DrawSprite(personTex, pGraph->nodes[i]->data.x, pGraph->nodes[i]->data.y, 10.0f, 10.0f);

		//m_spritebatch->SetRenderColor(0, 0, 255, 25);

		*/
		//										for (int j = 0; j < pGraph->nodes[i]->edges.size(); j++)
		//										{
		//									
		//											//		show edges
		//											Node* startNode = pGraph->nodes[i]->edges[j]->start;
		//											Node* endNode = pGraph->nodes[i]->edges[j]->end;
		//									
		//											m_spritebatch->SetRenderColor(255, 0, 0, 100);
		//									
		//											m_spritebatch->DrawLine(startNode->data.x,
		//												startNode->data.y,
		//												endNode->data.x,
		//												endNode->data.y, 2.0f);
		//											//m_spritebatch->SetRenderColor(255, 255, 255, 255);
		//										}


	}
	if (pGraph->ActivateDijkstras == true)
	{
		for (int i = 0; i < pGraph->nodes.size() - 1; i++)
		{
			for (int j = 0; j < pGraph->nodes[i]->edges.size() - 1; j++)
			{
				//		show edges

				m_spritebatch->SetRenderColor(255, i * 20, j * 20, 255);
				//	m_spritebatch->SetRenderColor(pGraph->nodeQueue[i]->edges[j]->color.x, pGraph->nodeQueue[i]->edges[j]->color.y, pGraph->nodeQueue[i]->edges[j]->color.z, 255);



				//pGraph->nodeQueue[i]->color.x


				Node* startNode = pGraph->nodes[i]->edges[j]->start;
				Node* endNode = pGraph->nodes[i]->edges[j]->end;
				m_spritebatch->DrawLine(startNode->data.x,
					startNode->data.y,
					endNode->data.x,
					endNode->data.y, 3.0f);


				//m_spritebatch->SetRenderColor(255, 255, 255, 255);
			}
		}
	}
	//	----// color for end path \\----
	//m_spritebatch->SetRenderColor(255, 0, 0, 255);
	//m_spritebatch->DrawLine(100.0f, 100.0f, 150.0f, 150.0f, 3.0f);

	//--------------------------------------------//


	m_spritebatch->SetRenderColor(255, 255, 255, 255);


	m_spritebatch->DrawSprite(personTex, agentPos.x, agentPos.x, 10.0f, 10.0f);
	m_spritebatch->SetRenderColor(255, 0, 0, 255);
	m_spritebatch->DrawSprite(bloodTex, Blood1.x, Blood1.y, 20.0f, 20.0f);
	m_spritebatch->SetRenderColor(255, 0, 0, 245);
	m_spritebatch->DrawSprite(bloodTex, Blood2.x, Blood2.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 235);
	m_spritebatch->DrawSprite(bloodTex, Blood3.x, Blood3.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 225);
	m_spritebatch->DrawSprite(bloodTex, Blood4.x, Blood4.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 215);
	m_spritebatch->DrawSprite(bloodTex, Blood5.x, Blood5.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 205);
	m_spritebatch->DrawSprite(bloodTex, Blood6.x, Blood6.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 195);
	m_spritebatch->DrawSprite(bloodTex, Blood7.x, Blood7.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 185);
	m_spritebatch->DrawSprite(bloodTex, Blood8.x, Blood8.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 175);
	m_spritebatch->DrawSprite(bloodTex, Blood9.x, Blood9.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 165);
	m_spritebatch->DrawSprite(bloodTex, Blood10.x, Blood10.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 155);
	m_spritebatch->DrawSprite(bloodTex, Blood11.x, Blood11.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 145);
	m_spritebatch->DrawSprite(bloodTex, Blood12.x, Blood12.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 135);
	m_spritebatch->DrawSprite(bloodTex, Blood13.x, Blood13.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 125);
	m_spritebatch->DrawSprite(bloodTex, Blood14.x, Blood14.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 115);
	m_spritebatch->DrawSprite(bloodTex, Blood15.x, Blood15.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 105);
	m_spritebatch->DrawSprite(bloodTex, Blood16.x, Blood16.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 95);
	m_spritebatch->DrawSprite(bloodTex, Blood17.x, Blood17.y, 20.0f, 20.0f);
	m_spritebatch->SetRenderColor(255, 0, 0, 85);
	m_spritebatch->DrawSprite(bloodTex, Blood18.x, Blood18.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 75);
	m_spritebatch->DrawSprite(bloodTex, Blood19.x, Blood19.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 65);
	m_spritebatch->DrawSprite(bloodTex, Blood20.x, Blood20.y, 20.0f, 20.0f); 
	m_spritebatch->SetRenderColor(255, 0, 0, 55);
	m_spritebatch->DrawSprite(bloodTex, Blood21.x, Blood21.y, 20.0f, 20.0f);

	m_spritebatch->SetRenderColor(255, 255, 255, 255);
	m_spritebatch->DrawSpriteTransformed3x3(playerTex, playerMat.GetMatrix(), 25.0f, 75.0f);

	m_spritebatch->End();

}