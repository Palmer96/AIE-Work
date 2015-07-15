#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	pGraph = new Graph();
	NodeTexture = new Texture("C:/Users/kayne.palmer/Desktop/Work/trunk/AIEProjects - StarterTemplate - Graph/Project1/Resources/Images/nodeTexture ");

}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{

	pGraph->AddNode(Vector2(100.0f, 100.0f));
	pGraph->AddNode(Vector2(150.0f, 150.0f));
	pGraph->AddNode(Vector2(200.0f, 200.0f));
	pGraph->AddNode(Vector2(250.0f, 250.0f));
	pGraph->AddNode(Vector2(300.0f, 300.0f));
	pGraph->AddNode(Vector2(350.0f, 350.0f));
	pGraph->AddNode(Vector2(400.0f, 400.0f));
	pGraph->AddNode(Vector2(450.0f, 450.0f));
	pGraph->AddNode(Vector2(500.0f, 500.0f));
	pGraph->AddNode(Vector2(550.0f, 550.0f));
	pGraph->AddNode(Vector2(600.0f, 600.0f));

		

		if (GetInput()->WasMouseButtonPressed(GLFW_MOUSE_BUTTON_1))
		{
			pGraph->AddNode(Vector2(GetInput()->GetMouseX(), GetInput()->GetMouseY()));
		}

	if (GetInput()->IsMouseButtonDown(GLFW_MOUSE_BUTTON_2))
		{
			// if a node is within range, save the node as oldnode
			// clicked = true
		}

		if (GetInput()->IsMouseButtonUp(GLFW_MOUSE_BUTTON_2))
		{
			// if a node is within range, save the node as new node
			// unclicked = true
		}

		// if clicked and unclicked = true, AddEdge using oldnode and newnode, cost = distance between oldnode and newnode



	//pGraph->AddEdge2(a, b, 1);
	//pGraph->AddEdge2(b, c, 1);
	//pGraph->AddEdge2(c, b, 1);
	//pGraph->AddEdge2(d, c, 1);
	//pGraph->AddEdge(e, d, 1);
	//pGraph->AddEdge(f, e, 1);
	//pGraph->AddEdge(g, f, 1);
	//pGraph->AddEdge(h, g, 1);
	//pGraph->AddEdge(i, h, 1);
	//pGraph->AddEdge(j, i, 1);
	//pGraph->AddEdge(k, j, 1);
}

void Game1::Draw()
{
	Graph egg;
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();


	pGraph->DrawCircle(*m_spritebatch, Vector2(100.0f, 100.0f), 20.0f);

	// TODO: draw stuff.

	//std::vector< Node*>::iterator iter = egg.nodeArray.begin();

	//std::cout << egg.nodeArray.size();


	//m_spritebatch->DrawSprite(NodeTexture, egg.nodeArray[0]->data.x, egg.nodeArray[0]->data.y, 10.0f, 10.0f);

	for (int i = 0; i < pGraph->nodeArray.size(); i++)
	{
		pGraph->DrawCircle(*m_spritebatch, pGraph->nodeArray[i]->data, 20.0f);
	}

	for (int i = 0; i < 2; i++)
	{
		//show edges
	}
	m_spritebatch->DrawLine(pGraph->nodeArray[0]->data.x, pGraph->nodeArray[0]->data.y, pGraph->nodeArray[1]->data.x, pGraph->nodeArray[1]->data.y, 2.0f);
	m_spritebatch->DrawLine(pGraph->nodeArray[1]->data.x, pGraph->nodeArray[1]->data.y, pGraph->nodeArray[2]->data.x, pGraph->nodeArray[2]->data.y, 2.0f);
	m_spritebatch->DrawLine(pGraph->nodeArray[2]->data.x, pGraph->nodeArray[2]->data.y, pGraph->nodeArray[3]->data.x, pGraph->nodeArray[3]->data.y, 2.0f);
//	m_spritebatch->DrawLine(pGraph->nodeArray[3]->data.x, pGraph->nodeArray[3]->data.y, pGraph->nodeArray[4]->data.x, pGraph->nodeArray[4]->data.y, 2.0f);
	m_spritebatch->DrawLine(pGraph->nodeArray[4]->data.x, pGraph->nodeArray[4]->data.y, pGraph->nodeArray[5]->data.x, pGraph->nodeArray[5]->data.y, 2.0f);
//	m_spritebatch->DrawLine(pGraph->nodeArray[5]->data.x, pGraph->nodeArray[5]->data.y, pGraph->nodeArray[6]->data.x, pGraph->nodeArray[6]->data.y, 2.0f);
	m_spritebatch->DrawLine(pGraph->nodeArray[6]->data.x, pGraph->nodeArray[6]->data.y, pGraph->nodeArray[7]->data.x, pGraph->nodeArray[7]->data.y, 2.0f);
	//m_spritebatch->DrawLine(pGraph->edgeArray[0]->start->data.x, pGraph->edgeArray[0]->start->data.y,
	//						pGraph->edgeArray[0]->end->data.x, pGraph->edgeArray[0]->end->data.y, 3.0f)


	//pGraph->Draw(m_spritebatch);

	//while (*iter != 0)
	//{
	//	//nodes
	//
	//}


	//m_spritebatch->DrawLine();



	m_spritebatch->End();

}