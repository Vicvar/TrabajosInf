#include "PQUnsorted.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

PQUnsorted::PQUnsorted(){
	_size=0;
	max_s=10;
	A=new int[max_s+1];
}

PQUnsorted::~PQUnsorted(){
	delete A;
}

bool PQUnsorted::empty(){
	if(_size==0) return true;
	else return false;
}

int PQUnsorted::size(){
	return _size;
}

int PQUnsorted::top(){
	if(_size==0){
		cout<<"intentando encontrar minimo con tamaño 0"<<endl;
		return -404;
	}
	int min=A[0];
	for(int i=0;i<_size;i++){
		if(min>A[i]) min=A[i];
	}
	return min;
}

void PQUnsorted::push(int n){
	if(_size==max_s){
		A=(int*)realloc(A,(2*max_s+1)*sizeof(int));
		max_s=max_s*2;
	}
	A[_size]=n;
	_size++;
}

void PQUnsorted::pop(){
	int min_i=0;
	int min=A[0];
	for(int i=0;i<_size;i++){
		if(min>A[i]){
		min=A[i];
		min_i=i;
		}
	}
	A[min_i]=A[_size-1];
	_size--;
}