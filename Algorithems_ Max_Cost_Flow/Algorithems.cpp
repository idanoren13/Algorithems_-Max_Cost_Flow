#include "Algorithems.h"
#include "MaxHeap.h"

vector<int> Algorithems::BFSPath(Graph& g, int s, int t)
{
	//return a list of vertices that represent the shortest path from s to t
	//return an empty list if no such path exists
	//BFS
	int n = g.get_n();
	vector<bool> visited(n, false);
	vector<int> parents(n, -1);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		LinkedList<item> adjList = g.GetAdjList(u);
		for (const item& v : adjList)
		{
			if (!visited[v.vertex] && v.capacity > 0)
			{
				visited[v.vertex] = true;
				parents[v.vertex] = u;
				q.push(v.vertex);

			}
		}
	}

	vector<int> path;
	if (visited[t])
	{
		int curr = t;
		while (curr != -1)
		{
			path.insert(path.begin(), curr);
			//path.push_back(curr);
			curr = parents[curr];
		}
	}

	return path;
}

int Algorithems::DijkstraVriation(Graph g, int s, int t, vector<bool>& minCut)
{
	int n = g.get_n(), flow, maxFlow = 0;
	int i = t - 1;
	int parent;
	Graph residualGraph = g;
	vector<int> p(n);


	while (Dijkstra(residualGraph, s, t, p))
	{
		flow = findMaxFlow(residualGraph, p, t);
		maxFlow += flow;

		while (p[i] != -1)
		{
			parent = p[i];
			residualGraph.IncreaseFlow(parent, p[i], flow);
			residualGraph.decreaseFlow(p[i], parent, residualGraph.getEdgeWeight(parent, p[i]));

			i = parent;
		}
	}
	//minCut = findMinCutBFS(Gf, s, t, parent);
	return maxFlow;
}

int Algorithems::findMaxFlow(Graph g, vector<int> path, int t)
{
	int findMaxFlow = INT8_MAX, i = t - 1, parent, weight;

	while (path[i] != -1)
	{
		parent = path[i];
		weight = g.getEdgeWeight(parent, i);
		if (findMaxFlow > weight)
		{
			findMaxFlow = weight;
		}
		i = parent;
	}

	return findMaxFlow;
}

bool Algorithems::Dijkstra(Graph g, int s, int t, vector<int>& parent) // pair = first d[], second: num of vertex
{
	int n = g.get_n();
	int i = s - 1;
	vector<int> d;

	priority_queue< pair <int, int>> Q;
	d = init(s, n);

	pair<int, int> p;
	p.first = d[i];
	p.second = i;

	Q.push(p);

	while (!Q.empty())
	{
		pair <int, int> u = Q.top();
		Q.pop();

		for (item v : g.get_adjListArr()[u.second])
		{//relax
			if (d[v.vertex] < d[u.second] + v.capacity)
			{
				d[v.vertex] = d[u.second] + (v.capacity);
				parent[v.vertex] = u.second;
				p.first = d[v.vertex];
				p.second = v.vertex;
				Q.push(p);
			}
		}
	}

	//if (d[t] != -1)
	//{
	//	return true;
	//}
	//return false;

	return d[t] != -1;


}

vector<int> Algorithems::init(int vertexS, int size)
{
	vector<int> d(size);
	for (int var : d)
	{
		if (var == vertexS)
		{
			d[vertexS] = 0;
		}
		else d[var] = -1; //=null
	}

	return d;
}


int Algorithems::findMaxFlowBFSVariantion(Graph& g, int s, int t)
{
	int n = g.get_n(), flow, maxFlow = 0;
	int i = t - 1;
	int parent;
	Graph residualGraph = g;
	vector<int> path;

	do
	{
		path = BFSPath(residualGraph, s, t);
		if (path.size() > 0) {
			flow = minCapacity(residualGraph, path);
			maxFlow += flow;

			for (int i = 0; i < path.size() - 1; i++) {
				residualGraph.decCapacity(path[i], path[i + 1], flow);
			}
		}
	} while (path.size() > 0);
	//minCut = findMinCutBFS(Gf, s, t, parent);
	return maxFlow;
}

int Algorithems::minCapacity(Graph& g, vector<int> path)
{
	int t = path[path.size() - 1];
	int minCap = 0;
	if (path.size() > 0)
	{
		minCap = g.getEdgeWeight(path[0], path[1]);
	}
	for (int i = 0; i < path.size() - 1; i++)
	{
		if (minCap > g.getEdgeWeight(path[i], path[i + 1]))
		{
			minCap = g.getEdgeWeight(path[i], path[i + 1]);
		}
	}

	return minCap;
}

//void Algorithems::minCut(Graph Gf, LinkedList<int> path, LinkedList<int>& S, LinkedList<int>& T) {
//}

