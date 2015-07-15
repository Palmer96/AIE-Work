#pragma once
#include <Vector> 
#include "MathLib.h"
#include "SpriteBatch.h"



class Edge;
class Graph;

class Node
{
public:
	Node();
	Node(Vector2 nodePos);

	Vector2 data;

	void AddEdge(Node *a_start, Node *a_end, int a_cost);
};

class Edge
{
public:
	Edge();
	Edge(Node *a_start, Node *a_end, int a_cost);
	Node start;
	Node end;
	int cost;

};
class Graph
{
public:


	std::vector < Node*> nodeArray;

	std::vector < Edge*> edgeArray;

	Graph();
	//Graph(Texture* tex);
	~Graph();

	Node* AddNode(Vector2 data);
	void AddEdge(Edge * a_edge);
	void AddEdge2(Node *a_start, Node *a_end, int a_cost);

	//void Draw(SpriteBatch& m_spritebatch);

	void DrawCircle(SpriteBatch& a_spriteBatch, Vector2 pos, float radius);

	//GraphNodeTex


};

