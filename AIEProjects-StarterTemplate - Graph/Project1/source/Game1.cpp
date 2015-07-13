#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"



Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	nodeTexture = new Texture("./Images/nodeTexture.png");

}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{
	Graph * pGraph = new Graph();


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


	pGraph->AddEdge(a, b, 1);
	pGraph->AddEdge(b, c, 1);
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
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	//DrawCircle(Pos, 2);

	// TODO: draw stuff.
	std::vector< Node*>::iterator iter = nodes.begin();
	//draw    (*iter)->.x
	m_spritebatch->DrawSprite(nodeTexture, (*iter)->->a.x, (*iter)->.y, 10.0f, 10.0f);


	//while (*iter != 0)
	//{
	//	//nodes
	//
	//}


	//m_spritebatch->DrawLine();



	m_spritebatch->End();

}



//void Game1::DrawCircle(Vector2 Pos, float radius)
//{
//	m_spritebatch->Begin();
//	for (int ii = 0; ii < radius; ii++)
//	{
//		float theta = 2.0f * 3.1415926f * float(ii) / float(radius);
//
//		float ax = radius * cos(theta);
//		float ay = radius * sin(theta);
//
//		Vector2 newVec(Pos.x + ax, Pos.y + ay);
//
//
//	}
//	m_spritebatch->End();
//}