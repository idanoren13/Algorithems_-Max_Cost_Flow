#pragma once
#include "LinkedList.h"
#include <iostream>
#include<list>

class item {
public:
	int vertex;
	int weight;
	item(int v, int w) : vertex(v), weight(w) {}
	item() {}
};

class Graph
{
	
	LinkedList<item>* adjListArr;
	int n;
	int m;

public:
	Graph(int _n = 0) : n(_n) { MakeEmptyGraph(n); }
	~Graph() { delete[]  adjListArr; }

	void set_m(int _m) { m = _m; }
	const int get_n() { return n; }
	const int get_m() { return m; }

	void MakeEmptyGraph(int _n);
	void RemoveEdge(int u, int v);
	void AddEdge(int u, int v, int c);
	bool is_adjacent(int u, int v);
	LinkedList<item>* GetAdjList(int u);
};

