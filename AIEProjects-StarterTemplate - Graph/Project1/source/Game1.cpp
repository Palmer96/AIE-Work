#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	Graph * pGraph = new Graph();
	NodeTexture = new Texture("C:/Users/kayne.palmer/Desktop/Work/trunk/AIEProjects - StarterTemplate - Graph/Project1/Resources/Images/nodeTexture ");

}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{
	
	Node *a = pGraph->AddNode(Vector2(100.0f, 100.0f));
	Node *b = pGraph->AddNode(Vector2(150.0f, 150.0f));
	Node *c = pGraph->AddNode(Vector2(200.0f, 200.0f));
	//Node *d = pGraph->AddNode(Vector2(250.0f, 250.0f));
	//Node *e = pGraph->AddNode(Vector2(300.0f, 300.0f));
	//Node *f = pGraph->AddNode(Vector2(350.0f, 350.0f));
	//Node *g = pGraph->AddNode(Vector2(400.0f, 400.0f));
	//Node *h = pGraph->AddNode(Vector2(450.0f, 450.0f));
	//Node *i = pGraph->AddNode(Vector2(500.0f, 500.0f));
	//Node *j = pGraph->AddNode(Vector2(550.0f, 550.0f));
	//Node *k = pGraph->AddNode(Vector2(600.0f, 600.0f));
	
	
	pGraph->AddEdge2(a, b, 1);
	pGraph->AddEdge2(b, c, 1);
	//pGraph->AddEdge(c, b, 1);
	//pGraph->AddEdge(d, c, 1);
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


	egg.DrawCircle(*m_spritebatch, Vector2 (100.0f, 100.0f), 20.0f);

	// TODO: draw stuff.

	//std::vector< Node*>::iterator iter = nodeArray.begin();
	//draw    (*iter)->.x
	//m_spritebatch->DrawSprite(NodeTexture, (*iter)->data.x, (*iter)->data.y, 10.0f, 10.0f);

	//pGraph->Draw(m_spritebatch);

	//while (*iter != 0)
	//{
	//	//nodes
	//
	//}


	//m_spritebatch->DrawLine();



	m_spritebatch->End();

}