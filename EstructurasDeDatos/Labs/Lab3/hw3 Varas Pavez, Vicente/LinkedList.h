#include "ListADT.h"

class LinkedList : public ListADT{
	
	struct Node{
		int data;
		Node *next;
	};
	
	private:
		Node *head;
		Node *tail;
		int vSize;

	public:
		LinkedList();
		~LinkedList();
		int at(int n);
		int size();
		void push_back(int n);

};
