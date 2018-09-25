#include "Sort.h"

Sort::Sort(){

}

Sort::~Sort(){

}

void Sort::insert(int e){
	pq.push(-1*e);
}

void Sort::remove(){
	pq.pop();
}

int Sort::min(){
	return -1*pq.top();
}

int Sort::size(){
	return pq.size();
}