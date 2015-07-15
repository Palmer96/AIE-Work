#include "Graph.h"
#include "MathLib.h"

Graph::Graph()
{
	Vector2 data;
	Node* node1 = new Node(Vector2(0.0f, 0.0f));
}



Graph::~Graph()
{
	// for loop delete Nodes
}

Node* Graph::AddNode(Vector2 data)
{
	Node* node = new Node;
	node->data = data;

	nodeArray.push_back(node);
	return node;
}

void Graph::AddEdge(Edge * a_edge)
{
	Edge edge = *a_edge;

}

Node::Node()
{
	//cost = 0;
	Node* node = new Node(Vector2 (0.0f, 0.0f));
	//node->data = data;
}

Node::Node(Vector2 VecData)
{
	data = VecData;
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

void Node::AddEdge(Node *a_start, Node *a_end, int a_cost)
{
	Edge edge(a_start, a_end, a_cost);
}

void Graph::AddEdge2(Node *a_start, Node *a_end, int a_cost)
{
	Edge edge(a_start, a_end, a_cost);
}





void Graph::DrawCircle(SpriteBatch& a_spriteBatch, Vector2 pos, float radius)
{
	Vector2 oldPos = Vector2(pos.x + (cos(0.0f) * radius), pos.y + (sin(0.0f) * radius));

	for (float i = 0; i < 2 * 3.1457f; i += 3.1457f / 10.0f)
	{
		Vector2 newPos;

		newPos.x = pos.x + (cos(i) * radius);
		newPos.y = pos.y + (sin(i) * radius);

		a_spriteBatch.DrawLine(oldPos.x, oldPos.y, newPos.x, newPos.y, 2.0f);

		oldPos = newPos;
	}
}
