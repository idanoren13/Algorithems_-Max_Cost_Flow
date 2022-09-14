#pragma once
#include <iostream>
#include <vector>
using namespace std;

static struct Vertex
{
	int vertexNum;
	int Weight;
};

class MaxHeap
{
private:
	vector<Vertex> data;
	int maxSize;
	int heapSize;

	void deepCopy(vector<Vertex> vector);

public:
	MaxHeap(int size);
	void Insert(Vertex newVertex);
	Vertex Max();
	Vertex DeleteMax();
	void BuildHeap(vector<Vertex>const &Array, int size);

	void MakeEmpty();
	bool IsEmpty();

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void FixHeap(int node);
	void Swap(Vertex& vertez1, Vertex& vertex2);
	void DecreaseKey(int v, int dv);


};

