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

	//int a1 = algo.findMaxFlowBFSVariantion(g, s, t).maxFlow;
	int a2 = algo.DijkstraVriation(g, s, t).maxFlow;
	cout << a2;
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