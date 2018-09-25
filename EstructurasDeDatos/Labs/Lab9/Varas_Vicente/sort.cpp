#include <iostream>
#include <vector>
#include "PQHeap.cpp"
#include "PQUnsorted.cpp"

using namespace std;

void heapSort(vector<int> &v);
void selectionSort(vector<int> &v);

int main(int argc, char *argv[]){
	
	if(argc!=2)	cout<<"./sort N"<<endl;

	int N=atoi(argv[1]);
	double theap, tselect;
	clock_t ini, fin;

	vector<int> v1;
	vector<int> v2;

	for(int i=0;i<N;i++){
		v1.push_back(rand());
	}

	v2=v1;

	ini=clock();
	heapSort(v1);
	fin=clock();

	theap=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	ini=clock();
	selectionSort(v2);
	fin=clock();

	tselect=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	cout<<"tiempo heapSort: "<<theap<<"ms"<<endl;
	cout<<"tiempo selectionSort: "<<tselect<<"ms"<<endl;
}

void heapSort(vector<int> &v){
	PriorityQueueADT *pq=new PQHeap();
	
	for(int i=0;i<v.size();i++){
		pq->push(v.at(i));
	}
	
	for(int i=0;i<pq->size();i++){
		v.at(i)=pq->top();
		pq->pop();
	}
}

void selectionSort(vector<int> &v){
	PriorityQueueADT *pq=new PQUnsorted();
	
	for(int i=0;i<v.size();i++){
		pq->push(v.at(i));
	}
	
	for(int i=0;i<pq->size();i++){
		v.at(i)=pq->top();
		pq->pop();
	}	
}