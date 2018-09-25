#include "PriorityQueueADT.h"

class PQUnsorted : public PriorityQueueADT{
private:
	int *A;
	int _size;
	int max_s;
	
public:
	PQUnsorted();
	~PQUnsorted();
	bool empty();
	int size();
	int top();
	void push(int n);
	void pop();
};