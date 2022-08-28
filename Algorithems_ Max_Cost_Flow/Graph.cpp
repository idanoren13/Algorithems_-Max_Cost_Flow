#include "Graph.h"

void Graph::MakeEmptyGraph(int _n) {
	n = _n;
	if (n < 0)
		return;

	else if (n == 0)
		adjListArr = nullptr;

	else
		adjListArr = new list<item>[n + 1];
}

bool Graph::is_adjacent(int u, int v) {
	if (u > 0 && u <= n) {
		Node<item>* current = adjListArr[u].head->next;
		while (current != nullptr) {
			if (current->data.vertex == v)
				return true;
			current = current->next;
		}
	}
	return false;
}

LinkedList<item>* Graph::GetAdjList(int u) {
	LinkedList<item>* res = nullptr;
	if (u > 0 && u <= n)
		res = &adjListArr[u];

	return res;
}

void Graph::AddEdge(int u, int v, int c) {
	if (u <= 0 || u > n || v <= 0 || v > n)
		return;
	item new_item = item(v, c);
	adjListArr[u].insert_to_end(new_item);
}
 
void Graph::RemoveEdge(int u, int v) {
	if (u <= 0 || u > n || v <= 0 || v > n)
		return;

	Node<item>* temp = adjListArr[u].head;
	while (temp->next->data.vertex != v || temp->next == nullptr)
		temp = temp->next;

	if (temp->next->data.vertex == v)
		adjListArr[u].delete_after(temp);
	m -= 1;
}