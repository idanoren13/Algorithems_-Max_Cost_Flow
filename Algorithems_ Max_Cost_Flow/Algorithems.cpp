#include "Algorithems.h"
#include "MaxHeap.h"

list<int> Algorithems::BFSPath(Graph &g, int s, int t)
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
		list<item> adjList = *g.GetAdjList(u);
		for (const item &v : adjList)
		{
			if (!visited[v.vertex] )
			{
				visited[v.vertex] = true;
				parents[v.vertex] = u;
				q.push(v.vertex);
			}
		}
	}

	list<int> path;
	if (visited[t])
	{
		int curr = t;
		while (curr != -1)
		{
			path.push_front(curr);
			curr = parents[curr];
		}
	}

	return path;
}


void Algorithems::DijkstraVriation(Graph g, int s, int t)
{
	Graph residualGraph = g;


	//make graph siuri
	//Dijkstra
	//increase flow
	//update siuri graph
}

void Algorithems::Dijkstra(Graph g, int wight, int vertexS)
{
	int n = g.get_n();
	vector<int> d;

	MaxHeap q(n);
	d=init(vertexS,n);

	while (!q.IsEmpty())
	{
		Vertex u = q.DeleteMax();

		for (item v : g.get_adjListArr()[u.vertexNum])
		{//relax
			if (d[v.vertex] > d[u.vertexNum] + v.capacity)
			{
				d[v.vertex] = d[u.vertexNum] + v.capacity;
				//q.??????????
			}
		}
		
	}
	

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


int Algorithems::findMaxFlowBFSVariantion(Graph g, int s, int t)
{
	
}

int Algorithems::minCapacity(Graph g, list<int> path)
{
	

}

