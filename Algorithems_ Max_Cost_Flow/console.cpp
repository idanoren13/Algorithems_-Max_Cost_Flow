#include "console.h"

void console::run() {
	int n, m, s, t;
	Edge edge;
	console cons;
	cin >> n >> m >> s >> t;
	s--; t--;
	Graph g(n);
	//g.MakeEmptyGraph(n);
	if (n < 0 || m < 0 || s < 0 || t < 0) {
		cout << "invalid input";
		exit(1);
	}

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
			cout << i << ", ";
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
			cout << i << ", ";
		}
	}
}

/*
7
11
6
2
6 4 3
6 1 10
4 5 7
7 4 14
1 7 8
1 3 3
3 5 2
4 3 6
7 5 9
5 2 5
3 2 6


Bug with dijkstra it returns to 7 and not 2
*/


/*
* 9
16
4
1
4 7 6
4 2 2
4 5 10
7 2 9
7 6 14
6 2 7
5 7 15
5 3 3
5 8 7
8 2 20
8 9 2
2 1 5
8 1 2
9 3 4
3 9 6
3 1 6

with BFS wrong max flow, it returns 7 instead of 12
with Dijkstra no output at all
*/