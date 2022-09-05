#include "MaxHeap.h"
#include <vector>

void MaxHeap::deepCopy(vector<Vertex> vector)
{
	Vertex vertex;
	for (Vertex vp : vector )
	{
		data.push_back(vertex);
	}
}

MaxHeap::MaxHeap(int size)
{
	data = vector<Vertex>();
	maxSize = size;
	heapSize = 0;
}

void MaxHeap::Insert(Vertex newVertex)
{
	if (heapSize == maxSize)
	{ 
		//
	}
	
	int i = heapSize;
	heapSize++;

	while ((i>0) && data[Parent(i)].shortestPathWeight > newVertex.shortestPathWeight)
	{
		data[i] = data[Parent(i)];
		i = Parent(i);
	}

	data[i] = newVertex;
}

Vertex MaxHeap::Max()
{
	return data[0];
}

Vertex MaxHeap::DeleteMax()
{
	if (heapSize < 1)
	{
		exit(1);
	}

	Vertex max = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);

	return max;
}

void MaxHeap::BuildHeap(vector<Vertex>const &personArray, int size)
{
	heapSize = maxSize = size;

	//data = personArray;
	deepCopy(personArray);

	for (int i = size / 2 - 1; i >= 0; i--)
	{
		FixHeap(i);
	}
}

bool MaxHeap::IsEmpty()
{
	bool isEmpty = false;

	if (heapSize == 0)
	{
		isEmpty = true;
	}

	return isEmpty;
}

int MaxHeap::Parent(int node)
{
	return (node - 1) / 2;
}

int MaxHeap::Left(int node)
{
	return (2 * node + 1);
}

int MaxHeap::Right(int node)
{
	return (2 * node + 2);
}

void MaxHeap::FixHeap(int index)//fixes heap that has node as a root
{
	int max;
	int left = Left(index);
	int right = Right(index);

	// find minimum among node left and right
	if (left < heapSize && (data[left].shortestPathWeight > data[index].shortestPathWeight))
	{
		max = left;
	}
	else
	{
		max = index;
	}
		
	if (right < heapSize && data[right].shortestPathWeight > data[max].shortestPathWeight)
	{
		max = right;
	}
		
	if (max != index)
	{
		Swap(data[index], data[max]);
		FixHeap(max);
	}
}

void MaxHeap::Swap(Vertex& vertex1, Vertex& vertex2)
{
	Vertex temp;

	temp = vertex1;
	vertex1.shortestPathWeight = vertex2.shortestPathWeight;
	vertex1.vertexNum = vertex2.vertexNum;
	vertex2.shortestPathWeight = temp.shortestPathWeight;
	vertex2.vertexNum = temp.vertexNum;
}