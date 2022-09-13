#include "Graph.h"

Graph::Graph(const Graph& g)
{
	this->MakeEmptyGraph()
	n = g.n;
	m = g.m;
	
	adjListArr = new list<item>[n];
	for (int i = 0; i < n; i++)
	{
		adjListArr[i] = g.adjListArr[i];
	}
}

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

	//new_item = item(u, c);
	//adjListArr[v].push_back(new_item);
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

bool Graph::IncreaseFlow(int u, int v, int flowToAdd)
{
	int vertexFlow, vertexCapacity;

	for (item curr : adjListArr[u]) {
		if (curr.vertex == v) {
			
			curr.flow += flowToAdd;
			vertexFlow = curr.flow;
		}
	}

	for (item curr : adjListArr[v]) { //f(v,u) = -f(u,v)
		if (curr.vertex == u) {

			decreaseFlow(v, u, vertexFlow);
		}
	}

}

bool Graph::decreaseFlow(int u, int v, int flowToSubtract)
{
	int vertexFlow, vertexCapacity;

	for (item curr : adjListArr[u]) {
		if (curr.vertex == v) {

			if (curr.flow - flowToSubtract >= 0 )
			{
				curr.flow -= flowToSubtract;
				return true;
			}

			return false;
		}
	}
}

int Graph::getEdgeWeight(int u, int v)
{
	for (item curr : adjListArr[u]) {
		if (curr.vertex == v) {
			
			return curr.capacity;
		}
	}
}

void Graph::decCapacity(int u, int v, int capacity)
{
	for (item it : adjListArr[u]) {
		if (it.vertex == v)
		{
			it.capacity -= capacity;
			if (it.capacity < 0)
			{
				it.capacity = 0;
			}
			break;
		}
	}
}
