#include <iostream>
#include "Deque.cpp"
#include <stack>

using namespace std;

void dequeDisp(Deque dq){
	stack<int> s;
	while(!dq.empty()){
		cout<<dq.front();
		s.push(dq.front());
		dq.pop_front();
	}
	cout<<endl;
	while(!s.empty()){
		dq.push_front(s.top());
		s.pop();
	}
}

int main(int argc, char *arcgv[]){
	Deque dq=Deque();
	dq.push_front(1);
	dq.push_back(2);
	dq.push_front(2);
	dequeDisp(dq);
}