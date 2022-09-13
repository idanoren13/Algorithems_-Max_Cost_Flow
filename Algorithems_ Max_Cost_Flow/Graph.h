#pragma once
#include <iostream>
#include <list>


using namespace std;

class item {
public:
	int vertex;
	int capacity;
	int flow = 0;
	item(int v, int w) : vertex(v), capacity(w) {}
	item() {}
	bool fullFlow() { return capacity == flow; }
};

class Graph
{
	list<item>* adjListArr;
	int n;
	int m;

public:
	Graph(int _n = 0) : n(_n) { MakeEmptyGraph(n); }
	//~Graph() { delete[]  adjListArr; }
	Graph(const Graph &g);

	void set_m(int _m) { m = _m; }
	int get_n() { return n; }
	list<item>* get_adjListArr() { return adjListArr; }
	int getEdgeWeight(int u, int v);

	void decCapacity(int u, int v, int capacity);

	const int getNumberOfVertices() { return n; }
	const int getNumberOfEdges() { return m; }

	void MakeEmptyGraph(int _n);
	void RemoveEdge(int u, int v);
	void AddEdge(int u, int v, int c);
	bool is_adjacent(int u, int v);
	list<item>* GetAdjList(int u);
	bool IncreaseFlow(int u, int v, int flowToAdd);
	bool decreaseFlow(int u, int v, int flowToSubtract);


};


