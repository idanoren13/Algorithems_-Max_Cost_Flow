#include "Algorithems.h"
#include "MaxHeap.h"

vector<int> Algorithems::BFSPath(Graph& g, int s, int t)
{
	vector<bool> visited;
	vector<int> path;
	vector<int> parents = BFS(g, s, t, visited);
	if (visited[t])
	{
		int curr = t;
		while (curr != -1)
		{
			path.insert(path.begin(), curr);
			curr = parents[curr];
		}
	}

	return path;
}

vector<int> Algorithems::BFS(Graph& g, int s, int t, vector<bool>& _visited)
{
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

	_visited = visited;
	return parents;
}

vector<int> Algorithems::DijkstraPath(Graph& g, int s, int t) {
	vector<bool> visited(g.get_n(), false);
	vector<int> path;
	vector<int> parents = Dijkstra(g, s, t, visited);
	if (visited[t])
	{
		int curr = t;
		while (curr != -1)
		{
			path.insert(path.begin(), curr);
			curr = parents[curr];
		}
	}

	return path;
}

maxFlowAndMinCuts Algorithems::DijkstraVriation(Graph& g, int s, int t)
{
	int n = g.get_n(), flow, maxFlow = 0;
	int parent;
	Graph residualGraph = g;
	vector<int> path;

	do
	{
		path = DijkstraPath(residualGraph, s, t);
		if (path.size() > 0 && path[0] == s && path[path.size() - 1] == t) {
			flow = minCapacity(residualGraph, path);
			maxFlow += flow;

			for (int i = 0; i < path.size() - 1; i++) {
				residualGraph.decCapacity(path[i], path[i + 1], flow);
			}
		}
	} while (path.size() > 0 && path[0] == s && path[path.size() - 1] == t);

	maxFlowAndMinCuts res = minCut(residualGraph, s, t);
	res.maxFlow = maxFlow;

	return res;
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

vector<int> Algorithems::Dijkstra(Graph& g, int s, int t, vector<bool>& visited) // pair = first d[], second: num of vertex
{
	int n = g.get_n();
	vector<int> parent(n, -1);
	vector<int> d(n, INT32_MIN);
	priority_queue< pair <int, int>> priority_Q;
	d[s] = 0;
	pair<int, int> p(d[s], s);

	for (int i = 0; i < n; i++) {
		priority_Q.push(pair<int, int>(d[i], i));
	}

	while (!priority_Q.empty())
	{

		pair <int, int> u = priority_Q.top();
		priority_Q.pop();
		if (!visited[u.second]) {
			for (item& v : g.GetAdjList(u.second))
			{//relax
				if (d[v.vertex] < (v.capacity) && v.capacity > 0)
				{
					d[v.vertex] = (v.capacity);
					parent[v.vertex] = u.second;
					p = pair<int, int>(d[v.vertex], v.vertex);
					priority_Q.push(p);
				}
			}

			visited[u.second] = true;
		}
	}

	return parent;
}

vector<int> Algorithems::init(int vertexS, int size)
{
	vector<int> d(size);
	for (auto var : d)
	{
		if (var == vertexS)
		{
			d[vertexS] = 0;
		}
		else d[var] = INT32_MAX; //=inf
	}

	return d;
}


maxFlowAndMinCuts Algorithems::findMaxFlowBFSVariantion(Graph& g, int s, int t)
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
				//residualGraph.IncreaseFlow(path[i], path[i + 1], flow);
				residualGraph.decCapacity(path[i], path[i + 1], flow);
			}
		}
	} while (path.size() > 0);

	maxFlowAndMinCuts res = minCut(residualGraph, s, t);
	res.maxFlow = maxFlow;

	return res;
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

maxFlowAndMinCuts Algorithems::minCut(Graph& Gf, int s, int t)
{
	vector<int> S, T;
	vector<bool> visited(Gf.get_n(), false);
	vector<int> parents = BFS(Gf, s, t, visited);
	S.push_back(s + 1);
	for (int i = 0; i < Gf.get_n(); i++) {
		if (i != s) {
			parents[i] != -1 ? S.push_back(i + 1) : T.push_back(i + 1);
		}
	}

	sort(S.begin(), S.end());
	sort(T.begin(), T.end());

	return { 0,S,T };
}