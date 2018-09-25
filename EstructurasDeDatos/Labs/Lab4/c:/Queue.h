#include "QueueADT.h"
#include <stack>

using namespace std;

class Queue : public QueueADT{

	private:
		stack<int> s1,s2;
		int _size;

	public:
		Queue();
		~Queue();
		bool empty();
		int size();
		int front();
		int back();
		void push(int n);
		void pop();
};