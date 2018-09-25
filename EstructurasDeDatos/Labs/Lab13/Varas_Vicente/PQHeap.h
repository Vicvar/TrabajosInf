#include "PriorityQueueADT.h"

class PQHeap:public PriorityQueueADT{
private:
	int *A;
	int max_s;
	int _size;		

public:
	PQHeap();
	~PQHeap();
	bool empty();
	int size();
	int top();
	void push(int n);
	void pop();
};