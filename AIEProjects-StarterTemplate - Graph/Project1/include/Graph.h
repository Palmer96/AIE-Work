#pragma once
#include <Vector> 
#include "MathLib.h"


struct Edge;

class Node
{
public:
	Node();
	Node(Vector2 nodePos);

	Vector2 Pos;

	void AddEdge(Edge * a_edge);
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


	std::vector < Node*> nodes;

	std::vector < Edge*> edges;

	Graph();
	~Graph();

	Node* AddNode(Vector2 data);
	void AddEdge(Node *a_start, Node *a_end, int a_cost);


};

