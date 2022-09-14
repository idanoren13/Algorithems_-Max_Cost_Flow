#pragma once
#include "Graph.h"

#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;
struct maxFlowAndMinCuts
{
public:
	int maxFlow;
	vector<int> minCutS, minCutT;
};

class Algorithems
{
public:

	vector<int> BFSPath(Graph& g, int s, int t);
	vector<int> BFS(Graph& g, int s, int t, vector<bool>& visited);
	vector<int> DijkstarPath(Graph& g, int s, int t);
	maxFlowAndMinCuts DijkstraVriation(Graph& g, int s, int t);
	vector<int> Dijkstra(Graph& g, int s, int t, vector<bool>& visited);
	Graph ResidualGraph(Graph g);
	vector<int> init(int vertexS, int size);
	void relax(int vertexS, int vertexV, vector<int> d);
	maxFlowAndMinCuts findMaxFlowBFSVariantion(Graph& g, int s, int t);
	int findMaxFlow(Graph g, vector<int> path, int t);


	int minCapacity(Graph& g, vector<int> path);

	maxFlowAndMinCuts minCut(Graph& Gf, int s, int t);


};

