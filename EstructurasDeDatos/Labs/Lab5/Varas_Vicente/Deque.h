#include "DequeADT.h"

class Deque : public DequeADT{

	struct Node{
		int data;
		Node *prev;
		Node *next;
	};

	private:
		int _size;
		Node *head;
		Node *tail;

	public:
		Deque();
		~Deque();
		bool empty();
		int size();
		int front();
		int back();
		void push_front(int n);
		void push_back(int n);
		void pop_front();
		void pop_back();
};