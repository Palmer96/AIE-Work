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
			pGraph->AddEdge(pGraph->nodeArray[i], pGraph->nodeArray[i + 1], 1);
		}
	}

	for (int j = 0; j < 49; j += 1)
	{
		for (int i = j; i < 10 + j; i += 5)
		{
			pGraph->AddEdge(pGraph->nodeArray[i], pGraph->nodeArray[i + 6], 1);
		}
	}
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{
	// --------// change color of selected node to green/red \\--------
	/*
	Input * InputManager = GetInput();


	if (InputManager->WasMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
	{
	//if (MouseClickInRange(InputManager->GetMouseX, InputManager->GetMouseY))
	{
	green = true;
	}
	}
	if (InputManager->WasMouseButtonPressed(GLFW_MOUSE_BUTTON_2))
	{
	//	if (MouseClickInRange())
	{
	red = true;
	}
	}
	*/

}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	// TODO: draw stuff.	

	m_spritebatch->Begin();


	for (int i = 0; i < 10; i++)
	{
		m_spritebatch->SetRenderColor(0, 255, 0, 255);
		pGraph->DrawCircle(*m_spritebatch, pGraph->nodeArray[0]->data, i);

		m_spritebatch->SetRenderColor(255, 0, 0, 255);
		pGraph->DrawCircle(*m_spritebatch, pGraph->nodeArray[59]->data, i);
	}

	m_spritebatch->SetRenderColor(255, 255, 255, 255);
	//		loop through all nodes
	for (int i = 0; i < pGraph->nodeArray.size(); i++)
	{	// show nodes




		//pGraph->nodeArray[i]->traveled = true;

		if (pGraph->nodeArray[i]->traveled == true)
		{	// change color to show that this path has been taken
			m_spritebatch->SetRenderColor(0, 0, 255, 200);
		}
		else
		{
			// 
			m_spritebatch->SetRenderColor(255, 255, 255, 255);
		}

		pGraph->DrawCircle(*m_spritebatch, pGraph->nodeArray[i]->data, 10.0f);

		m_spritebatch->SetRenderColor(0, 0, 255, 25);
		for (int j = 0; j < pGraph->nodeArray[i]->edgeArray.size(); j++)
		{
			//		show edges
			Node* startNode = pGraph->nodeArray[i]->edgeArray[j]->start;
			Node* endNode = pGraph->nodeArray[i]->edgeArray[j]->end;


			
			m_spritebatch->DrawLine(startNode->data.x,
				startNode->data.y,
				endNode->data.x,
				endNode->data.y, 3.0f);
			//m_spritebatch->SetRenderColor(255, 255, 255, 255);
		}
	}

	


	//	----// color for end path \\----
	//m_spritebatch->SetRenderColor(255, 0, 0, 255);
	//m_spritebatch->DrawLine(100.0f, 100.0f, 150.0f, 150.0f, 3.0f);

	m_spritebatch->End();

}