#include "Algorithems.h"

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

void Algorithems::Dijkstra(Graph g, int wwight, int vertex)
{

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


