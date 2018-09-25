#include <iostream>
#include <stdlib.h>
#include "Deque.h"
#include <deque>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
	int N;
	clock_t ini, fin;
	double t1,t2;
	Deque dq_imp=Deque();
	deque<int> dq_stl;
	vector<int> v;

	if(argc!=2){
		cout<<"Error de argumentos. Ingresar el número de elementos"<<endl;
		return -1;
	}

	N=atoi(argv[1]);

	for(int i=0;i<N;i++){
		v.push_back(rand());
	}

	ini=clock();
	for(int i=0;i<N;i++){
		if(i%2==0){
			dq_imp.push_back(v.at(i));
		}
		else{
			dq_imp.push_front(v.at(i));
		}
		dq_imp.front();
		dq_imp.back();
		dq_imp.empty();
	}
	for(int i=0;i<N;i++){
		if(i%2==0){
			dq_imp.pop_back();
		}
		else{
			dq_imp.pop_front();
		}
	}
	fin=clock();
	t1=(double) (fin-ini)/CLOCKS_PER_SEC*1000.0;

	cout<<"La Deque implementada tomo "<<t1<<" ms en llevar acabo las operaciones"<<endl;

	ini=clock();
	for(int i=0;i<N;i++){
		if(i%2==0){
			dq_stl.push_back(v.at(i));
		}
		else{
			dq_stl.push_front(v.at(i));
		}
		dq_stl.front();
		dq_stl.back();
		dq_stl.empty();
	}
	for(int i=0;i<N;i++){
		if(i%2==0){
			dq_stl.pop_back();
		}
		else{
			dq_stl.pop_front();
		}
	}
	fin=clock();
	t2=(double) (fin-ini)/CLOCKS_PER_SEC*1000.0;

	cout<<"La Deque de la STL tomo "<<t2<<"ms en llevar a cabo las operaciones"<<endl;
}