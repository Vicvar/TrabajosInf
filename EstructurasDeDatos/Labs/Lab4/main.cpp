#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"

using namespace std;


void opStackQueue(vector<int> A){
	Queue q= Queue();
	int f,b;
	bool ie;
	for(int i=0;i<A.size()/5;i++){
		q.push(A.at(5*i));
		q.push(A.at(5*i+1));
		q.push(A.at(5*i+2));
		ie=q.empty();
		q.pop();
		f=q.front();
		b=q.back();
		q.push(A.at(5*i+3));
		q.push(A.at(5*i+4));
		q.pop();
		q.pop();
		q.pop();
	}
}

void opSTLQueue(vector<int> A){
	queue<int> q;
	int f,b;
	bool ie;
	for(int i=0;i<A.size()/5;i++){
		ie=q.empty();
		q.push(A.at(5*i));
		q.push(A.at(5*i+1));
		q.push(A.at(5*i+2));
		q.pop();
		f=q.front();
		b=q.back();
		q.push(A.at(5*i+3));
		q.push(A.at(5*i+4));
		q.pop();
		q.pop();
		q.pop();
	}
}

int main(int argc, char * argv[]){

	int N;
	vector<int> A;
	double t1, t2;
	clock_t ini, fin;

	if(argc!=2){
		cout<<"Error de argumentos. Ingresar el número de elementos"<<endl;
		return -1;
	}

	N=atoi(argv[1]);

	for(int i=0;i<N;i++){
		A.push_back(rand());
	}
	ini=clock();
	opSTLQueue(A);
	fin=clock();
	t2=(double) (fin-ini)/CLOCKS_PER_SEC*1000.0;

	cout<<"La Queue de la STL tomo "<<t2<<"ms en llevar a cabo las operaciones"<<endl;

	ini=clock();
	opStackQueue(A);
	fin=clock();
	t1=(double) (fin-ini)/CLOCKS_PER_SEC*1000.0;

	cout<<"La Queue implementada tomo "<<t1<<"ms en llevar acabo las operaciones"<<endl;


	return 0;	
}