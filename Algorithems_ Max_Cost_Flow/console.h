#pragma once
#include"Graph.h"
class console
{
public:
	struct Edge
	{
		int i;
		int j;
		int capacity;
	};

	Edge getNewEdge()
	{
		Edge edge;
		cin >> edge.i >> edge.j >> edge.capacity;
		return edge;
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
	void run();
};


