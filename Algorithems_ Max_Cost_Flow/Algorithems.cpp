#include "Algorithems.h"
#include "MaxHeap.h"

void Algorithems::BFS(Graph g, int vertex_s)
{
	vector<DistanceItem> d(g.getNumberOfVertices());
	queue<int> Q;
	int u;


	Q.push(vertex_s);
	d[vertex_s - 1].setDistance(0);

	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();

		list<item> u_neighbors = *g.GetAdjList(u);
		for (item neighbor : u_neighbors) {
			if (d[neighbor.vertex].isInfinity())
			{
				d[neighbor.vertex].setDistance(d[u].distance + 1);
				Q.push(neighbor.vertex);
			}
		}
	}
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



Graph Algorithems::ResidualGraph(Graph g)
{
	Graph residualGraph;

	for (int i = 0; i < g.get_n(); i++)
	{
		for (item curr : g.get_adjListArr()[i]) {

			if (curr.fullFlow() == false)
			{
				residualGraph.AddEdge(i, curr.vertex, curr.capacity - curr.flow);
			}
		}
	}
}


