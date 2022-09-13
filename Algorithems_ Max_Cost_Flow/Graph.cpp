#include "Graph.h"

Graph::Graph(const Graph& g)
{
	//for (int i = 0; i < n; i++)
	//{
	//	adjListArr[i].clear();
	//}
	n = g.n;
	m = g.m;

	//adjListArr = vector<LinkedList<item>>();
	for (int i = 0; i < n; i++)
	{
		adjListArr.push_back(g.adjListArr[i]);
	}
}

void Graph::MakeEmptyGraph(int _n) {
	n = _n;
	if (n < 0)
		return;
	else
		adjListArr = vector<LinkedList<item>>(n);

}

bool Graph::is_adjacent(int u, int v) {
	if (u > 0 && u <= n) {
		for (item& curr : adjListArr[u]) {
			if (curr.vertex == v)
				return true;
		}
	}

	return false;
}

LinkedList<item> Graph::GetAdjList(int u) {
	
		return adjListArr[u];

}

void Graph::AddEdge(int u, int v, int c) {
	//if (u < 0 || u > n || v < 0 || v > n)
	//	return;
	item new_item = item(v, c);
	adjListArr[u].push_back(new_item);
	m++;
	//new_item = item(u, c);
	//adjListArr[v].push_back(new_item);
}

void Graph::RemoveEdge(int u, int v) {
	if (u <= 0 || u > n || v <= 0 || v > n)
		return;

	for (LinkedList<item>::Iterator it = adjListArr[u].begin(); it != adjListArr[u].end(); ++it) {
		item temp = it.getData();
		if (temp.vertex == v)
		{
			adjListArr[u].erase(it);
			m -= 1;
			return;
		}
	}
}

bool Graph::IncreaseFlow(int u, int v, int flowToAdd)
{
	int vertexFlow, vertexCapacity;

	for (item curr : adjListArr[u]) {
		if (curr.vertex == v) {

			curr.flow += flowToAdd;
			vertexFlow = curr.flow;
			vertexCapacity = curr.capacity;
			break;
		}
	}

	bool found = false;
	for (item& curr : adjListArr[v]) { //f(v,u) = -f(u,v)
		if (curr.vertex == u) {	
			found = true;
			break;
		}
	}

	if (!found)
	{
		AddEdge(v, u, vertexCapacity);
	}

	decreaseFlow(v, u, vertexFlow);

	return true;
}

bool Graph::decreaseFlow(int u, int v, int flowToSubtract)
{
	//int vertexFlow, vertexCapacity;

	for (item curr : adjListArr[u]) {
		if (curr.vertex == v) {

			if (curr.flow - flowToSubtract >= 0)
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
	for (item &curr : adjListArr[u]) {
		if (curr.vertex == v) {

			return curr.capacity;
		}
	}
}

void Graph::decCapacity(int u, int v, int capacity)
{
	for (item& it : adjListArr[u]) {
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
