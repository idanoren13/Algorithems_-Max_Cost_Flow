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
	list<int> BFSPath(Graph &g, int s, int t);
	void BFS(Graph g, int vertex);
	void DijkstraVriation(Graph g, int s, int t);
	void Dijkstra(Graph g, int wight, int vertex);
	Graph ResidualGraph(Graph g);
	vector<int> init(int vertexS, int size);
	void relax(int vertexS, int vertexV, vector<int> d);
	Graph BFSVariation(Graph);
	int findMaxFlowBFSVariantion(Graph g, int s, int t);

	int minCapacity(Graph g, list<int> path);


};

