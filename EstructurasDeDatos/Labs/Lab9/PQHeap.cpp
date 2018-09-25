#include "PQHeap.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void swap(int ia, int ib);
int numHijos(int i, int _size);
void downheap(int i, int *A, int _size);
void upheap(int *A, int _size);

PQHeap::PQHeap(){
	_size=0;
	max_s=10;
	A=new int[max_s+1];
}

PQHeap::~PQHeap(){
	delete A;
}

bool PQHeap::empty(){
	if(_size==0) return true;
	else return false;
}

int PQHeap::size(){
	return _size;
}

int PQHeap::top(){
	if(_size==0){
		cout<<"intentando encontrar minimo con tamaño 0"<<endl;
		return -404;
	}
	return A[1];
}


void PQHeap::push(int n){
	if(_size==max_s){
		A=(int*)realloc(A,(2*max_s+1)*sizeof(int));
		max_s=max_s*2;
	}
	A[_size+1]=n;
	_size++;
	upheap(A,_size);
}

void PQHeap::pop(){
	A[1]=A[_size];
	_size--;
	downheap(1, A,_size);
}

void swap(int *A, int ia, int ib){
	int aux=A[ia];
	A[ia]=A[ib];
	A[ib]=aux;
}

int numHijos(int i, int _size){
	if((i*2+1)<=_size) return 2;
	else if(i*2<=_size) return 1;
	else return 0;
}

void upheap(int *A,int _size){
	int actual=_size;
	int padre=actual/2;
	while(A[padre]>A[actual]&&padre!=0){
		swap(A,padre,actual);
		actual=padre;
		padre=actual/2;
	}
}

void downheap(int i, int *A, int _size){
	if(numHijos(i,_size)==1&&A[i*2]<A[i]) swap(A,i,i*2);
	else if(numHijos(i,_size)==2){
		if(A[i*2]<A[i]&&A[i*2]<A[i*2+1]){
			swap(A,i,i*2);
			downheap(i*2, A, _size);
		}
		else if(A[i*2+1]<A[i]){
			swap(A,i,i*2+1);
			downheap(i*2+1, A, _size);
		}
	}
}
