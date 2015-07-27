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
	nodes.push_back(node);
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
	bIsStart = false;
	bIsEnd = false;
	//node->data = data;
}

Node::Node(Vector2 VecData)
{
	data = VecData;
}

void Node::AddEdge(Edge* a_edge)
{
	edges.push_back(a_edge);
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




void Graph::Dijkstras()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i]->bIsStart = true)
		{
			startNode = nodes[i];
		}
		if (nodes[i]->bIsEnd = true)
		{
			endNode = nodes[i];
		}
	}
	nodeQueue.push_back(startNode);

	Vector2 distance;

	Node* currentNode = nodeQueue[0];
	Node* shortest;
	Node* smallest;

	bool bSorted = false;
	int count = 0;

	while (true)
	{
		count = 0;
		smallest = nodeQueue[0];
		for (int j = 0; j < nodeQueue.size(); j++)
		{
			if (nodeQueue[j]->travelCost < smallest->travelCost)
			{
				smallest = nodeQueue[j];
				count = j;
			}
		}

		currentNode = smallest;

		if (currentNode == endNode)
		{
			break;
		}

		for (int i = 0; i < currentNode->edges.size(); i++)
		{
			distance.x = currentNode->edges[i]->end->data.x - currentNode->data.x;
			distance.y = currentNode->edges[i]->end->data.y - currentNode->data.y;

			if ((distance.Magnitude() + currentNode->travelCost) < currentNode->edges[i]->end->travelCost)
			{
				currentNode->edges[i]->end->travelCost = (distance.Magnitude() + currentNode->travelCost);
				currentNode->edges[i]->end->previous = currentNode;
			}
			if (currentNode->edges[i]->end->traveled == false)
			{
				nodeQueue.push_back(currentNode->edges[i]->end);
				currentNode->edges[i]->end->traveled = true;
			}
			currentNode->edges[i]->color.x = 0;
			currentNode->edges[i]->color.y = 0;
			currentNode->edges[i]->color.z = 255;
		}
		nodeQueue.erase(nodeQueue.begin() + count);
	}

	while (currentNode != startNode)
	{
		currentNode->color.x = 255;
		currentNode->color.y = 0;
		currentNode->color.z = 0;
		for (int i = 0; i < currentNode->edges.size(); i++)
		{
			if (currentNode->edges[i]->end = currentNode->previous)
			{
				currentNode->color.x = 0;
				currentNode->color.y = 255;
				currentNode->color.z = 0;
			}
		}
		currentNode = currentNode->previous;
	}




}










//		void Graph::CalculatePath()
//		{
//			for (int i = 0; i < nodeArray.size(); i++)
//			{
//				nodes[i]->N = nullptr;
//				nodes[i]->G = std::numeric_limits<float>::max();
//		
//				nodeQueue.push_back(nodeArray[0]);
//		
//				nodes[0]->N = 0.0f;
//				nodes[0]->G = nodeArray[0];
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