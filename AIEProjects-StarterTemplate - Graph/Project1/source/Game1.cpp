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
	/*
	Node *a0 = pGraph->AddNode(Vector2(100.0f, 100.0f));
	Node *a1 = pGraph->AddNode(Vector2(150.0f, 100.0f));
	Node *a2 = pGraph->AddNode(Vector2(200.0f, 100.0f));
	Node *a3 = pGraph->AddNode(Vector2(250.0f, 100.0f));
	Node *a4 = pGraph->AddNode(Vector2(300.0f, 100.0f));
	Node *a5 = pGraph->AddNode(Vector2(350.0f, 100.0f));
	Node *a6 = pGraph->AddNode(Vector2(400.0f, 100.0f));
	Node *a7 = pGraph->AddNode(Vector2(450.0f, 100.0f));
	Node *a8 = pGraph->AddNode(Vector2(500.0f, 100.0f));
	Node *a9 = pGraph->AddNode(Vector2(550.0f, 100.0f));

	Node *b0 = pGraph->AddNode(Vector2(100.0f, 150.0f));
	Node *b1 = pGraph->AddNode(Vector2(150.0f, 150.0f));
	Node *b2 = pGraph->AddNode(Vector2(200.0f, 150.0f));
	Node *b3 = pGraph->AddNode(Vector2(250.0f, 150.0f));
	Node *b4 = pGraph->AddNode(Vector2(300.0f, 150.0f));
	Node *b5 = pGraph->AddNode(Vector2(350.0f, 150.0f));
	Node *b6 = pGraph->AddNode(Vector2(400.0f, 150.0f));
	Node *b7 = pGraph->AddNode(Vector2(450.0f, 150.0f));
	Node *b8 = pGraph->AddNode(Vector2(500.0f, 150.0f));
	Node *b9 = pGraph->AddNode(Vector2(550.0f, 150.0f));

	Node *c0 = pGraph->AddNode(Vector2(100.0f, 200.0f));
	Node *c1 = pGraph->AddNode(Vector2(150.0f, 200.0f));
	Node *c2 = pGraph->AddNode(Vector2(200.0f, 200.0f));
	Node *c3 = pGraph->AddNode(Vector2(250.0f, 200.0f));
	Node *c4 = pGraph->AddNode(Vector2(300.0f, 200.0f));
	Node *c5 = pGraph->AddNode(Vector2(350.0f, 200.0f));
	Node *c6 = pGraph->AddNode(Vector2(400.0f, 200.0f));
	Node *c7 = pGraph->AddNode(Vector2(450.0f, 200.0f));
	Node *c8 = pGraph->AddNode(Vector2(500.0f, 200.0f));
	Node *c9 = pGraph->AddNode(Vector2(550.0f, 200.0f));

	Node *d0 = pGraph->AddNode(Vector2(100.0f, 250.0f));
	Node *d1 = pGraph->AddNode(Vector2(150.0f, 250.0f));
	Node *d2 = pGraph->AddNode(Vector2(200.0f, 250.0f));
	Node *d3 = pGraph->AddNode(Vector2(250.0f, 250.0f));
	Node *d4 = pGraph->AddNode(Vector2(300.0f, 250.0f));
	Node *d5 = pGraph->AddNode(Vector2(350.0f, 250.0f));
	Node *d6 = pGraph->AddNode(Vector2(400.0f, 250.0f));
	Node *d7 = pGraph->AddNode(Vector2(450.0f, 250.0f));
	Node *d8 = pGraph->AddNode(Vector2(500.0f, 250.0f));
	Node *d9 = pGraph->AddNode(Vector2(550.0f, 250.0f));

	Node *e0 = pGraph->AddNode(Vector2(100.0f, 300.0f));
	Node *e1 = pGraph->AddNode(Vector2(150.0f, 300.0f));
	Node *e2 = pGraph->AddNode(Vector2(200.0f, 300.0f));
	Node *e3 = pGraph->AddNode(Vector2(250.0f, 300.0f));
	Node *e4 = pGraph->AddNode(Vector2(300.0f, 300.0f));
	Node *e5 = pGraph->AddNode(Vector2(350.0f, 300.0f));
	Node *e6 = pGraph->AddNode(Vector2(400.0f, 300.0f));
	Node *e7 = pGraph->AddNode(Vector2(450.0f, 300.0f));
	Node *e8 = pGraph->AddNode(Vector2(500.0f, 300.0f));
	Node *e9 = pGraph->AddNode(Vector2(550.0f, 300.0f));

	Node *f0 = pGraph->AddNode(Vector2(100.0f, 350.0f));
	Node *f1 = pGraph->AddNode(Vector2(150.0f, 350.0f));
	Node *f2 = pGraph->AddNode(Vector2(200.0f, 350.0f));
	Node *f3 = pGraph->AddNode(Vector2(250.0f, 350.0f));
	Node *f4 = pGraph->AddNode(Vector2(300.0f, 350.0f));
	Node *f5 = pGraph->AddNode(Vector2(350.0f, 350.0f));
	Node *f6 = pGraph->AddNode(Vector2(400.0f, 350.0f));
	Node *f7 = pGraph->AddNode(Vector2(450.0f, 350.0f));
	Node *f8 = pGraph->AddNode(Vector2(500.0f, 350.0f));
	Node *f9 = pGraph->AddNode(Vector2(550.0f, 350.0f));
	*/
	int k = 0;
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



	//for (int j = 0; j < 60; j += 6)
	//{
	//	for (int i = j; i < 5; i++)
	//	{
	//		pGraph->AddEdge(pGraph->nodeArray[i], pGraph->nodeArray[i + 1], 1);
	//	}
	//
	//	for (int i = 6; i < 11; i++)
	//	{
	//		pGraph->AddEdge(pGraph->nodeArray[i], pGraph->nodeArray[i + 1], 1);
	//	}
	//	for (int i = 12; i < 17; i++)
	//	{
	//		pGraph->AddEdge(pGraph->nodeArray[i], pGraph->nodeArray[i + 1], 1);
	//	}
	//	for (int i = 18; i < 23; i++)
	//	{
	//		pGraph->AddEdge(pGraph->nodeArray[i], pGraph->nodeArray[i + 1], 1);
	//	}
	//	for (int i = 24; i < 29; i++)
	//	{
	//		pGraph->AddEdge(pGraph->nodeArray[i], pGraph->nodeArray[i + 1], 1);
	//	}
	//	for (int i = 30; i < 35; i++)
	//	{
	//		pGraph->AddEdge(pGraph->nodeArray[i], pGraph->nodeArray[i + 1], 1);
	//	}
	//	for (int i = 36; i < 11; i++)
	//	{
	//		pGraph->AddEdge(pGraph->nodeArray[i], pGraph->nodeArray[i + 1], 1);
	//	}
	//
	//}






	/*
pGraph->AddEdge(a0, a1);
pGraph->AddEdge(a1, a2);
pGraph->AddEdge(a2, a3);
pGraph->AddEdge(a3, a4);
pGraph->AddEdge(a4, a5);
pGraph->AddEdge(a5, a6);
pGraph->AddEdge(a6, a7);
pGraph->AddEdge(a7, a8);
pGraph->AddEdge(a8, a9);

pGraph->AddEdge(b0, b1);
pGraph->AddEdge(b1, b2);
pGraph->AddEdge(b2, b3);
pGraph->AddEdge(b3, b4);
pGraph->AddEdge(b4, b5);
pGraph->AddEdge(b5, b6);
pGraph->AddEdge(b6, b7);
pGraph->AddEdge(b7, b8);
pGraph->AddEdge(b8, b9);

pGraph->AddEdge(c0, c1);
pGraph->AddEdge(c1, c2);
pGraph->AddEdge(c2, c3);
pGraph->AddEdge(c3, c4);
pGraph->AddEdge(c4, c5);
pGraph->AddEdge(c5, c6);
pGraph->AddEdge(c6, c7);
pGraph->AddEdge(c7, c8);
pGraph->AddEdge(c8, c9);

pGraph->AddEdge(d0, d1);
pGraph->AddEdge(d1, d2);
pGraph->AddEdge(d2, d3);
pGraph->AddEdge(d3, d4);
pGraph->AddEdge(d4, d5);
pGraph->AddEdge(d5, d6);
pGraph->AddEdge(d6, d7);
pGraph->AddEdge(d7, d8);
pGraph->AddEdge(d8, d9);

pGraph->AddEdge(e0, e1);
pGraph->AddEdge(e1, e2);
pGraph->AddEdge(e2, e3);
pGraph->AddEdge(e3, e4);
pGraph->AddEdge(e4, e5);
pGraph->AddEdge(e5, e6);
pGraph->AddEdge(e6, e7);
pGraph->AddEdge(e7, e8);
pGraph->AddEdge(e8, e9);

pGraph->AddEdge(f0, f1);
pGraph->AddEdge(f1, f2);
pGraph->AddEdge(f2, f3);
pGraph->AddEdge(f3, f4);
pGraph->AddEdge(f4, f5);
pGraph->AddEdge(f5, f6);
pGraph->AddEdge(f6, f7);
pGraph->AddEdge(f7, f8);
pGraph->AddEdge(f8, f9);

pGraph->AddEdge(a0, b0);
pGraph->AddEdge(b0, c0);
pGraph->AddEdge(c0, d0);
pGraph->AddEdge(d0, e0);
pGraph->AddEdge(e0, f0);

pGraph->AddEdge(a2, b2);
pGraph->AddEdge(b2, c2);
pGraph->AddEdge(c2, d2);
pGraph->AddEdge(d2, e2);
pGraph->AddEdge(e2, f2);

pGraph->AddEdge(a3, b3);
pGraph->AddEdge(b3, c3);
pGraph->AddEdge(c3, d3);
pGraph->AddEdge(d3, e3);
pGraph->AddEdge(e3, f3);

pGraph->AddEdge(a4, b4);
pGraph->AddEdge(b4, c4);
pGraph->AddEdge(c4, d4);
pGraph->AddEdge(d4, e4);
pGraph->AddEdge(e4, f4);

pGraph->AddEdge(a5, b5);
pGraph->AddEdge(b5, c5);
pGraph->AddEdge(c5, d5);
pGraph->AddEdge(d5, e5);
pGraph->AddEdge(e5, f5);

pGraph->AddEdge(a6, b6);
pGraph->AddEdge(b6, c6);
pGraph->AddEdge(c6, d6);
pGraph->AddEdge(d6, e6);
pGraph->AddEdge(e6, f6);

pGraph->AddEdge(a7, b7);
pGraph->AddEdge(b7, c7);
pGraph->AddEdge(c7, d7);
pGraph->AddEdge(d7, e7);
pGraph->AddEdge(e7, f7);

pGraph->AddEdge(a8, b8);
pGraph->AddEdge(b8, c8);
pGraph->AddEdge(c8, d8);
pGraph->AddEdge(d8, e8);
pGraph->AddEdge(e8, f8);

pGraph->AddEdge(a9, b9);
pGraph->AddEdge(b9, c9);
pGraph->AddEdge(c9, d9);
pGraph->AddEdge(d9, e9);
pGraph->AddEdge(e9, f9);
*/

}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{

}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	// TODO: draw stuff.	

	m_spritebatch->Begin();


	//for (int i = 0; i < pGraph->nodeArray.size(); i++)
	//{
	//	//show nodes
	//	
	//}

	for (int i = 0; i < pGraph->nodeArray.size(); i++)
	{
		pGraph->DrawCircle(*m_spritebatch, pGraph->nodeArray[i]->data, 5.0f);

		for (int j = 0; j < pGraph->nodeArray[i]->edgeArray.size(); j++)
		{
			Node* startNode = pGraph->nodeArray[i]->edgeArray[j]->start;
			Node* endNode = pGraph->nodeArray[i]->edgeArray[j]->end;
			m_spritebatch->DrawLine(startNode->data.x,
				startNode->data.y,
				endNode->data.x,
				endNode->data.y, 1.5f);
		}
	}

	//for (int i = 0; i < pGraph->nodeArray-[i]->edgeArray.size(); i++)
	//{
	//	show edges
	//	m_spritebatch->DrawLine(pGraph->nodeArray[i]->data.x, pGraph->nodeArray[i]->data.y, pGraph->nodeArray[i + 10]->data.x, pGraph->nodeArray[i + 10]->data.y, 2.0f);
	//	
	//}


	m_spritebatch->End();

}