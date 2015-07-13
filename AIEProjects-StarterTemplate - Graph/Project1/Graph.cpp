#include "Graph.h"
#include "MathLib.h"


Graph::Graph()
{
	Vector2 data;
}



Graph::~Graph()
{
	// for loop delete Nodes
}

Node* Graph::AddNode(Vector2 data)
{
	Node* node = new Node(data);
	nodes.push_back(node);

	return node;
}

void Graph::AddEdge(Node *a_start, Node *a_end, int a_cost)
{
	start = a_start;
	end = a_end;
	cost = a_cost;

}

Node::Node(Vector2 VecData)
{

}

Node::Node()
{
	//cost = 0;
}


Edge::Edge()
{

}
Edge::Edge(Node* a_start, Node* a_end, int a_cost)
{
	start = *a_start;
	end = *a_end;
	cost = a_cost;
}
