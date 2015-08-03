#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"
#include "Player.h"
#include "MathLib.h"
#include "Agents.h"


Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	m_spritebatch->SetColumnMajor(true);
	pGraph = new Graph();

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
			pGraph->AddEdge(pGraph->nodes[i + j +1], pGraph->nodes[i + j], 1);
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




	//for (int j = 0; j < 58; j += 1)
	//{
	//	for (int i = j; i < 20 + j; i++)
	//	{
	//		pGraph->AddEdge(pGraph->nodes[i], pGraph->nodes[i + 59], 1);
	//	}
	//}

	pGraph->nodes[0]->bIsStart = true;
	pGraph->nodes[1300]->bIsEnd = true;

	pGraph->ActivateDijkstras = false;

	playerTex = new Texture("./Images/player.png");
	personTex = new Texture("./Images/nodeTexture.png");




	playerPos = Vector3(300.0f, 300.0f, 1.0f);

	playerMat = Matrix3(playerPos.x, 0.0f, 0.0f,
		0.0f, playerPos.y, 0.0f,
		0.0f, 0.0f, 1.0f);


	agentPos = Vector2(100.0f, 100.0f);
	//agentPos = Vector2(pGraph->nodes[5]->data.x, pGraph->nodes[5]->data.y);
	rotate = 0.0f;
	//person = Agents(agentPos);

	scale = Vector3(1.0f, 1.0f, 1.0f);

	k = 5;
	

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

	if (InputManager->IsKeyDown(GLFW_KEY_W))
	{
		//--------Move Foward
		playerPos -= upVec * 300.0f * deltaTime;

		if (InputManager->IsKeyDown(GLFW_KEY_A))
		{
			//--------Rotate Limo Left
			rotate -= 3 * deltaTime;
		}
		if (InputManager->IsKeyDown(GLFW_KEY_D))
		{
			//--------Rotate Limo Right
			rotate += 3 * deltaTime;
		}
	}
	if (InputManager->IsKeyDown(GLFW_KEY_S))
	{
		//--------Move Back
		playerPos += upVec * 150.0f * deltaTime;

		if (InputManager->IsKeyDown(GLFW_KEY_A))
		{
			//--------Rotate Limo Left
			rotate -= 2 * deltaTime;
		}
		if (InputManager->IsKeyDown(GLFW_KEY_D))
		{
			//--------Rotate Limo Right
			rotate += 2 * deltaTime;
		}
	}

	playerMat = playerMat.Translation(playerPos) *  playerMat.Rotation(rotate) * playerMat.Scale(scale);
	//------------------------------------------------//


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
	/*
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
		//m_spritebatch->SetRenderColor(255, 255, 255, 255);
			pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[i]->data, 10.0f);
	//	m_spritebatch->DrawSprite(personTex, pGraph->nodes[i]->data.x, pGraph->nodes[i]->data.y, 10.0f, 10.0f);

		//m_spritebatch->SetRenderColor(0, 0, 255, 25);

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

		m_spritebatch->SetRenderColor(255, 255, 255, 255);
		//	pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[i]->data, 10.0f);
		//m_spritebatch->DrawSprite(personTex, pGraph->nodes[i]->data.x, pGraph->nodes[i]->data.y, 10.0f, 10.0f);

		
	}
	if (pGraph->ActivateDijkstras == true)
	{
		for (int i = 0; i < pGraph->nodes.size()-1; i++)
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
	*/
	//--------------------------------------------//


	m_spritebatch->SetRenderColor(255, 255, 255, 255);
	m_spritebatch->DrawSpriteTransformed3x3(playerTex, playerMat.GetMatrix(), 25.0f, 50.0f);

	m_spritebatch->DrawSprite(personTex, agentPos.x, agentPos.x, 10.0f, 10.0f);


	m_spritebatch->End();

}