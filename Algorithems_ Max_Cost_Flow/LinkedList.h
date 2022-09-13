#pragma once
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node* next;
	Node() { next = nullptr; }
	Node(T& item, Node* ptr = nullptr) { data = item; next = ptr; }
};

template<class T>
class LinkedList {
public:

	Node<T>* head, * tail;

	LinkedList() { make_empty(); }
	void make_empty() {
		Node<T>* dummy_head = new Node<T>();
		tail = head = dummy_head;
	}

	bool is_empty() {
		return head == tail;
	}

	void push_back(T& item) {
		Node<T>* node = new Node<T>(item);
		if (is_empty())
			head->next = node;
		tail->next = node;
		tail = node;
	}

	void remove(<T> data) {
		Node<T>* temp = head;
		Node<T>* prev;
		while (head->data != data)
		{
			prev = head;
			head = head->next;
		}

		prev->next = temp->next;
		delete temp;
	}

	~LinkedList() {
		Node<T>* next, * curr = head;
		while (curr != nullptr) {
			next = curr->next;
			delete curr;
			curr = next;
		}
	}

	
};