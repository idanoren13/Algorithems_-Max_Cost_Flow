#include "console.h"

void console::run() {
	int n, m, s, t;
	Edge edge;
	console cons;
	cin >> n >> m >> s >> t;

	Graph g;
	g.MakeEmptyGraph(n);

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
}