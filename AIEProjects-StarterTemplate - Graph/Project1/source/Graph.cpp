#include "Graph.h"
#include "MathLib.h"

Graph::Graph()
{
	//Vector2 data;
	//Node* node1 = new Node(Vector2(0.0f, 0.0f));

}



Graph::~Graph()
{
	// for loop delete Nodes
}

Node* Graph::AddNode(Vector2 data)
{
	Node* node = new Node(data);
	nodeArray.push_back(node);
	return node;
}

void Graph::AddEdge(Node* a_start, Node* a_end, int data)
{
	Edge* edge = new Edge(a_start, a_end, data);
	a_start->AddEdge(edge);// start;
	a_end->AddEdge(edge);

	//node1->edgeArray.push_back(&edge);
	//edge.start->edgeArray.push_back(&edge);
}

Node::Node()
{
	//cost = 0;
	Node* node = new Node(Vector2(0.0f, 0.0f));
	//node->data = data;
}

Node::Node(Vector2 VecData)
{
	data = VecData;
}

void Node::AddEdge(Edge* a_edge)
{
	edgeArray.push_back(a_edge);
}

Edge::Edge()
{

}

Edge::Edge(Node* a_start, Node* a_end, int a_cost)
{
	start = a_start;
	end = a_end;
	cost = a_cost;

	//traveled = false;
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


//		void Graph::CalculatePath()
//		{
//			for (int i = 0; i < nodeArray.size(); i++)
//			{
//				nodeArray[i]->N = nullptr;
//				nodeArray[i]->G = std::numeric_limits<float>::max();
//		
//				nodeQueue.push_back(nodeArray[0]);
//		
//				nodeArray[0]->N = 0.0f;
//				nodeArray[0]->G = nodeArray[0];
//			}
//		
//			while (nodeQueue.size() != 0)
//			{
//				int index = CheapestNode();
//			
//			Node* currentNode = nodeQueue[index];
//			nodeQueue.erase(nodeQueue.begin() + index);
//		
//			currentNode->traveled = true;
//		}
//		}
//		
//		int Graph::CheapestNode()
//		{
//		
//		}