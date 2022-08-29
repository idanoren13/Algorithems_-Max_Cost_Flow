#include "Graph.h"

void Graph::MakeEmptyGraph(int _n) {
	n = _n;
	if (n < 0)
		return;

	else if (n == 0)
		adjListArr = nullptr;

	else
		adjListArr = new list<item>[n + 1];
}

bool Graph::is_adjacent(int u, int v) {
	if (u > 0 && u <= n) {
		for (item curr : adjListArr[u]) {
			if (curr.vertex == v)
				return true;
		}
	}

	return false;
}

list<item>* Graph::GetAdjList(int u) {
	list<item>* res = nullptr;
	if (u > 0 && u <= n)
		res = &adjListArr[u];

	return res;
}

void Graph::AddEdge(int u, int v, int c) {
	if (u <= 0 || u > n || v <= 0 || v > n)
		return;
	item new_item = item(v, c);
	adjListArr[u].push_back(new_item);
}

void Graph::RemoveEdge(int u, int v) {
	if (u <= 0 || u > n || v <= 0 || v > n)
		return;

	for (item curr : adjListArr[u]) {
		if (curr.vertex == v) {
			adjListArr[u].remove(curr);
			return;
		}
	}

	m -= 1;
}