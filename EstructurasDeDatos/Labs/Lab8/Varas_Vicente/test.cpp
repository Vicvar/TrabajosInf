#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "Sort.h"

using namespace std;

int main(int argc, char * argv[]){
	int N;
	vector<int> vect;
	double tord, tdes;
	clock_t ini, fin;
	Sort *st_des=new Sort();
	Sort *st_ord=new Sort();
	

	if(argc!=2){
		cout<<"uso: ./test 'n° de elementos'"<<endl;
		return -1;
	}

	N=atoi(argv[1]);

	for(int i=0;i<N;i++){
		vect.push_back(rand());
	}

	ini=clock();
	for(int i=0;i<N;i++){
		st_des->insert(vect.at(i));
	}
	fin=clock();

	tdes=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	sort(vect.begin(),vect.end());

	ini=clock();
	for(int i=0;i<N;i++){
		st_ord->insert(vect.at(i));
	}
	fin=clock();

	tord=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	for(int i=0;i<N;i++){
		cout<<st_ord->min()<<" ";
		st_ord->remove();
	}
	cout<<endl;

	cout<<"La insercion de elementos ordenados toma: "<<tord<<"ms"<<endl;
	cout<<"La insercion de elementos desordenados toma: "<<tdes<<"ms"<<endl;
}