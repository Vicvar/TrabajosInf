#include <stdlib.h>
#include <iostream>
#include <stack>
#include "Queue.h"

using namespace std;

Queue::Queue(){
	_size=0;
}

Queue::~Queue(){
}

bool Queue::empty(){
	if(_size==0) return true;
	else return false;
}

int Queue::size(){
	return _size;
}

int Queue::front(){
	if(_size==0){
		cout<<"La cola esta vacia"<< endl;
	}
	else{
		if(!s1.empty() && s2.empty()){
			for(int i=0;i<s1.size();i++){
				s2.push(s1.top());
				s1.pop();
			}
		}
		return s2.top();
	}
}

int Queue::back(){
	if(_size==0){
		cout<<"La cola esta vacia"<< endl;
	}
	else{
		if(!s2.empty() && s1.empty()){
			for(int i=0;i<s2.size();i++){
				s1.push(s2.top());
				s2.pop();
			}
		}
		return s1.top();
	}
}

void Queue::push(int n){
	s1.push(n);
	_size++;
}

void Queue::pop(){
	if(s2.empty()&&!s1.empty()){
		for(int i=0;i<s1.size();i++){
			s2.push(s1.top());
			s1.pop();
		}
	}
	s2.pop();
	_size--;

}