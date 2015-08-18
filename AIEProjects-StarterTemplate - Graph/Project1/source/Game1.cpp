#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"
//#include "Player.h"
#include "MathLib.h"
#include "Agents.h"
#include "iostream"
#include "Blood.h"



Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{//-------------------------------------------------------------------------------------------------------------------------------------------//
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	m_spritebatch->SetColumnMajor(true);
	pGraph = new Graph();





	//-----------------------< Create Nodes >-------------------------//
	for (int i = 20; i <= 780; i += 20)//39
	{
		for (int j = 20; j <= 1180; j += 20)//59
		{
			pGraph->AddNode(Vector2(j, i));
		}
	}
	//-----------------------< Create Edges >-------------------------//
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
	//-----------------------< Set Untraversable Nodes >-------------------------//
	int count = 0;
	int count2 = 0;

	for (int j = 241; j < 2300; j += 9)
	{
		count++;
		for (int i = j; i < j + 4; i++)
		{
			pGraph->nodes[i]->traversable = false;
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
	for (int i = 0; i < 59; i++)
	{
		pGraph->nodes[i]->traversable = false;
	}

	for (int i = 58; i < 2300; i += 59)
	{
		pGraph->nodes[i]->traversable = false;
		pGraph->nodes[i + 1]->traversable = false;
	}

	for (int i = 2243; i < 2301; i++)
	{
		pGraph->nodes[i]->traversable = false;
	}

	//-----------------------< Set Variables >-------------------------//

	pGraph->ActivateDijkstras = false;

	playerTex = new Texture("./Images/Limo.png");
	personTex = new Texture("./Images/nodeTexture.png");
	policeTex = new Texture("./Images/Police.png");
	roadTex = new Texture("./Images/Road.png");
	roofTex = new Texture("./Images/Roof.png");
	bloodTex = new Texture("./Images/Blood.png");

	playerPos = Vector3(600.0f, 400.0f, 1.0f);

	playerMat = Matrix3(playerPos.x, 0.0f, 0.0f,
		0.0f, playerPos.y, 0.0f,
		0.0f, 0.0f, 1.0f);

	policePos = Vector2(30.0f, 30.0f);
	agentPos = Vector2(100.0f, 100.0f);
	rotate = 0.0f;


	scale = Vector3(1.0f, 1.0f, 1.0f);

	k = 0;


	//Alpha = 255;


	fTimer = 0.0f;



	for (int i = 0; i <= 10; i++)
	{
		blood.push_back(new Blood);
	}

	counter = 0;
	counter2 = 0;

	////////////----------------------------< Create random Pedestrians >----------------------////////////
	for (int i = 0; i <= 100; i++)
	{
		agent.push_back(new Agents);
		agent[i]->m_position = pGraph->SafeRandPos();
	}
	bBloodTrail = false;
	////////////----------------------------< Make First Path >----------------------////////////
	Path = pGraph->Dijkstras(pGraph->ClosestNode(policePos), pGraph->ClosestNode(playerPos));
}

Game1::~Game1()//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)//-------------------------------------------------------------------------------------------------------------------------------------------//
{

	Input * InputManager = GetInput();



	system("cls");

	if (InputManager->WasKeyPressed(GLFW_KEY_R))
	{
		for (int i = 0; i < agent.size(); i++)
		{
			agent[i]->m_position = pGraph->SafeRandPos();
		}
	}

	for (int i = 0; i < agent.size() - 1; i++)
	{

		//if (counter == 10)
		//agent[i]->m_velocity = pGraph->SafeRandPos();

		agent[i]->Update(deltaTime);
	}

	//agent[0]->m_position += (agent[0]->m_velocity - agent[0]->m_position).Normalised() * 10 * deltaTime;


	////////////-----------------------< Check if at Final Node >-----------------------////////////
	if (pGraph->ClosestNode(policePos) == pGraph->ClosestNode(Path[Path.size() - 1]))
	{
		k = 0;
		Path = pGraph->Dijkstras(pGraph->ClosestNode(policePos), pGraph->ClosestNode(playerPos));
	}
	////////////----------------------< Move to next Node in Path >----------------------////////////
	policePos += (Path[k] - policePos).Normalised() * 100 * deltaTime;

	if (pGraph->ClosestNode(Path[k]) == pGraph->ClosestNode(policePos))
	{
		k++;
	}

	////////////----------------------------< Re-Path >----------------------////////////

	if (k == 5)
	{
		Path = pGraph->Dijkstras(pGraph->ClosestNode(policePos), pGraph->ClosestNode(playerPos));
		k = 0;
	}
	////////////-------------------------< Steering >------------------------////////////

	Vector3 upVec = Vector3(playerMat.a12, playerMat.a11, 1.0);
	Vector3 normVec = upVec.Normalised();

	if (InputManager->IsKeyDown(GLFW_KEY_UP))
	{
		//--------Move Foward
		if (pGraph->ClosestNode(playerPos)->traversable == true)
		{
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


	////////////-----------------------< Blood Trail >-----------------------////////////

	if (InputManager->WasKeyPressed(GLFW_KEY_SPACE))
	{
		bBloodTrail = true;
	}

	if (bBloodTrail)
	{
		if (fTimer > 0.01)
		{
			
			if (counter > 10)
			{
				{
					blood[counter2]->Pos = Vector2(-10.0f, -10.0f);
					counter2++;

				}
				if (counter2 > 10)
				{
					counter = 0;
					counter2 = 0;
					bBloodTrail = false;
				}

			}
			else
			{
				blood[counter]->Pos.x = playerPos.x;
				blood[counter]->Pos.y = playerPos.y;
				counter++;
			}

			fTimer = 0;
		}
		else
		{
			fTimer += deltaTime;
		}
	}

}

void Game1::Draw()//-------------------------------------------------------------------------------------------------------------------------------------------//
{
	// clear the back buffer
	ClearScreen();

	// TODO: draw stuff.	

	m_spritebatch->Begin();


	////////////-------------------------< Draw Nodes >---------------------------////////////
	for (int i = 0; i < pGraph->nodes.size(); i++)
	{
		if (pGraph->nodes[i]->traversable == false)
		{
			m_spritebatch->DrawSprite(roofTex, pGraph->nodes[i]->data.x, pGraph->nodes[i]->data.y, 20.0f, 20.0f);
		}
		else
		{
			m_spritebatch->DrawSprite(roadTex, pGraph->nodes[i]->data.x, pGraph->nodes[i]->data.y, 20.0f, 20.0f);
		}
	}

	////////////-----------------------< Draw Dijkstras >-------------------------////////////

	m_spritebatch->SetRenderColor(0, 0, 0, 100);
	for (int i = 0; i < Path.size() - 1; i++)
	{
		m_spritebatch->DrawLine(Path[i].x, Path[i].y, Path[i + 1].x, Path[i + 1].y, 5.0f);
	}

	////////////-----------------------< Draw Blood Trail >-----------------------////////////
	m_spritebatch->SetRenderColor(200, 0, 0, 255);
	for (int i = 0; i < blood.size(); i++)
	{
		m_spritebatch->DrawSprite(bloodTex, blood[i]->Pos.x, blood[i]->Pos.y, 20.0f, 20.0f);
	}

	////////////-----------------------< Draw Pedestrians >-----------------------////////////
	m_spritebatch->SetRenderColor(255, 255, 255, 255);

	for (int i = 0; i < agent.size(); i++)
	{
		m_spritebatch->DrawSprite(personTex, agent[i]->m_position.x, agent[i]->m_position.y, 10.0f, 10.0f);
	}
	////////////--------------------------< Draw Player >-------------------------////////////
	m_spritebatch->DrawSpriteTransformed3x3(playerTex, playerMat.GetMatrix(), 25.0f, 75.0f);
	////////////--------------------------< Draw Police >-------------------------////2////////
	m_spritebatch->DrawSprite(policeTex, policePos.x, policePos.y, 10.0f, 10.0f);



	m_spritebatch->End();

}