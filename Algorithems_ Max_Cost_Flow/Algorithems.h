#pragma once
#include "Graph.h"
#include "LinkedList.h"
#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Algorithems
{
	struct DistanceItem
	{
		bool infinity;
		int distance;
	public:
		DistanceItem() { infinity = true; distance = 0; }
		void setDistance(int dist) {
			infinity = false;
			distance = dist;
		}
		bool isInfinity() { return infinity; }
	};

public:
	void BFS(Graph g, int vertex);
	void DijkstraVriation(Graph g, int s, int t);
	void Dijkstra(Graph g, int wwight, int vertex);
	Graph ResidualGraph(Graph g);

};

