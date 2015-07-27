#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"
#include <iostream>

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	pGraph = new Graph();

	for (int i = 100; i <= 550; i += 50)
	{
		for (int j = 100; j <= 350; j += 50)
		{
			pGraph->AddNode(Vector2(i, j));
		}
	}

	for (int j = 0; j < 60; j += 6)
	{
		for (int i = j; i < 5 + j; i++)
		{
			pGraph->AddEdge(pGraph->nodes[i], pGraph->nodes[i + 1], 1);
		}
	}

	for (int j = 0; j < 49; j += 1)
	{
		for (int i = j; i < 10 + j; i += 5)
		{
			pGraph->AddEdge(pGraph->nodes[i], pGraph->nodes[i + 6], 1);
		}
	}

	pGraph->nodes[0]->bIsStart = true;
	pGraph->nodes[59]->bIsEnd = true;

	pGraph->ActivateDijkstras = false;
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{
	Input * InputManager = GetInput();

	if (InputManager->WasKeyPressed(GLFW_KEY_SPACE))
	{
		pGraph->Dijkstras();
		pGraph->ActivateDijkstras = true;
	}
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	// TODO: draw stuff.	

	m_spritebatch->Begin();
	//-----------------// Grid //-----------------//

	for (int i = 0; i < 10; i++)
	{
		m_spritebatch->SetRenderColor(0, 255, 0, 255);
		pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[0]->data, i);

		m_spritebatch->SetRenderColor(255, 0, 0, 255);
		pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[59]->data, i);
	}

	m_spritebatch->SetRenderColor(255, 255, 255, 255);
	pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[0]->data, 20.0f);
	pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[59]->data, 20.0f);

	//		loop through all nodes
	for (int i = 0; i < pGraph->nodes.size(); i++)
	{	// show nodes

		pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[i]->data, 10.0f);

		//m_spritebatch->SetRenderColor(0, 0, 255, 25);
	
		for (int j = 0; j < pGraph->nodes[i]->edges.size(); j++)
		{
			//		show edges
			Node* startNode = pGraph->nodes[i]->edges[j]->start;
			Node* endNode = pGraph->nodes[i]->edges[j]->end;

			m_spritebatch->SetRenderColor(255,255,255, 255);

			m_spritebatch->DrawLine(startNode->data.x,
				startNode->data.y,
				endNode->data.x,
				endNode->data.y, 2.0f);
			//m_spritebatch->SetRenderColor(255, 255, 255, 255);
		}

	}
	if (pGraph->ActivateDijkstras == true)
	{
		for (int i = 0; i < pGraph->nodes.size(); i++)
		{
			for (int j = 0; j < pGraph->nodes[i]->edges.size(); j++)
			{
				//		show edges
				

				m_spritebatch->SetRenderColor(pGraph->nodes[i]->edges[j]->color.x, pGraph->nodes[i]->edges[j]->color.y, 255, 255);


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



	m_spritebatch->End();

}