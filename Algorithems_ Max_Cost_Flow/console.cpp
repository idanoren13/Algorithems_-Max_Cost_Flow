#include "console.h"

void console::run() {
	int n, m, s, t;
	Edge edge;
	console cons;
	cin >> n >> m >> s >> t;
	s--; t--;
	Graph g(n);
	//g.MakeEmptyGraph(n);

	for (int k = 0; k < m; k++)
	{
		edge = cons.getNewEdge();

		if (cons.checkEdgeValiation(edge, n))
		{
			g.AddEdge(edge.i, edge.j, edge.capacity);
		}
		else
		{
			cout << "input invalid";
			exit(1);
		}
	}

	Algorithems algo;

	maxFlowAndMinCuts bfs = algo.findMaxFlowBFSVariantion(g, s, t);
	cout << "BFS Method:\n" << "MaxFlow = " << bfs.maxFlow;
	cout << "\nMin Cut: S = ";
	for (auto i : bfs.minCutS) {
		if (i == bfs.minCutS.back())
		{
			cout << i << ". ";
		}
		else
		{
			cout << i << ", ";
		}
	}
	cout << "T = ";
	for (auto i : bfs.minCutT) {
		if (i == bfs.minCutT.back())
		{
			cout << i;
		}
		else
		{
			cout << i << ",";
		}
	}
	maxFlowAndMinCuts greedy = algo.DijkstraVriation(g, s, t);
	cout << "\nGreedy Method:\n" << "MaxFlow = " << bfs.maxFlow;
	cout << "\nMin Cut: S = ";
	for (auto i : greedy.minCutS) {
		if (i == greedy.minCutS.back())
		{
			cout << i << ". ";
		}
		else
		{
			cout << i << ", ";
		}
	}
	cout << "T = ";
	for (auto i : greedy.minCutT) {
		if (i == greedy.minCutT.back())
		{
			cout << i;
		}
		else
		{
			cout << i << ",";
		}
	}
	//cout << a2;
}

/*
6
10
1
6
1 2 16
1 3 13
2 3 10
3 2 4
2 4 12
4 3 9
3 5 14
5 4 7
5 6 4
4 6 20
*/