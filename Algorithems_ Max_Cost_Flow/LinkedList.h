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
	LinkedList(const LinkedList& list) {
		make_empty();
		if (list.head != nullptr)
		{
			head = new Node<T>(list.head->data, nullptr);
			Node<T>* thisTemp = head;
			for (Node<T>* temp = list.head->next; temp != nullptr; temp = temp->next) {
				thisTemp->next = new Node<T>(temp->data);
				tail = thisTemp->next;
			}
		}
		
	}

	LinkedList copy() {
		return LinkedList(this);
	}
	void make_empty() {
		//Node<T>* dummy_head = new Node<T>();
		tail = head = nullptr;
	}

	bool is_empty() {
		return head == nullptr;
	}

	void push_back(T& item) {
		Node<T>* node = new Node<T>(item);
		if (is_empty()) {
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}

	~LinkedList() {
		Node<T>* next, * curr = head;
		while (curr != nullptr) {
			next = curr->next;
			delete curr;
			curr = next;
		}
	}

	
	class Iterator {
		friend class LinkedList;
	private:
		Node<T>* nodePtr;
		// The constructor is private, so only our friends
		// can create instances of iterators.
		Iterator(Node<T>* newPtr) : nodePtr(newPtr) {}
	public:
		Iterator() : nodePtr(nullptr) {}

		T getData() { return nodePtr->data; }

		// Overload for the comparison operator !=
		bool operator!=(const Iterator& itr) const {
			return nodePtr != itr.nodePtr;
		}

		bool operator==(const Iterator& itr) const {
			return nodePtr == itr.nodePtr;
		}

		// Overload for the dereference operator *
		T& operator*() const {
			return nodePtr->data;
		}

		// Overload for the postincrement operator ++
		Iterator operator++(int) {
			Iterator temp = *this;
			nodePtr = nodePtr->next;
			return temp;
		}

		Iterator operator++() {
			Iterator temp = *this;
			nodePtr = nodePtr->next;
			return temp;
		}
	};

	Iterator begin() const {
		return Iterator(head);
	}

	Iterator end() const {
		return Iterator(nullptr);
	}

	Iterator insert(Iterator position, const T& value) {
		Node<T>* newNode = new Node<T>(value, position.nodePtr->next);
		if (position.nodePtr == tail) tail = newNode;
		position.nodePtr->next = newNode;
		return position;
	}

	Iterator erase(Iterator position) {
		Node<T>* toDelete = position.nodePtr->next;
		position.nodePtr->next = position.nodePtr->next->next;
		if (toDelete == tail) tail = position.nodePtr;
		delete toDelete;
		return position;
	}
};