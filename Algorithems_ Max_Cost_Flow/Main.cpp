#include "Graph.h"
#include <iostream>
using namespace std;

struct Edge
{
	int i;
	int j;
	int capacity;
}

void Main()
{
	int n, m, s, t;
	Edge edge;

	cin << n << m << s << t;

	Graph g;
	g.MakeEmptyGraph(n);

	for (int k = 0; k < m; k++)
	{
		edge = getNewEdge();

		if (checkEdgeValiation(edge, n))
		{
			g.AddEdge(edge.i, edge.j, edge.capacity);
		}

		else
		{
			cout >> "input invalid";
			exit(1);
		}
	}
}

Edge getNewEdge()
{
	Edge edge;
	cin << edge.i << edge.j << edge.capacity;
}

bool checkEdgeValiation(Edge edge, int n)
{
	bool valid = true;

	if ((edge.i < 0) || (edge.i > n) || (edge.j < 0) || (edge.j > n) || edge.capacity < 0)
	{
		valid = false;
	}

	return valid;
}