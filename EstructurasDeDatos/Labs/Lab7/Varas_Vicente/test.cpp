#include <stdlib.h>
#include <iostream>
#include <vector>
#include "BinaryTree.cpp"

using namespace std;

int main(int argc, char *argv[]){
	BinaryTreeADT *A_ord=new BinaryTree();
	BinaryTreeADT *A_des=new BinaryTree();
	vector<int> v1, v2;
	int N, tlf;
	double tord, tdes;
	clock_t ini, fin;

	N=10000;

	for(int i=0;i<N;i++){
		v1.push_back(rand());
	}

	tlf=v1.at(1);
	v2=v1;
	sort(v1.begin(),v1.end());

	for(int i=0;i<N;i++){
		A_ord->insert(v1.at(i));
		A_des->insert(v2.at(i));
	}

	ini=clock();
	A_ord->search(tlf);
	fin=clock();
	tord=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	delete A_ord;

	ini=clock();
	A_des->search(tlf);
	fin=clock();
	tdes=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	delete A_des;

	cout<<"La busqueda en el arbol insertado de forma ordenada toma "<<tord<<"ms"<<endl;
	cout<<"La busqueda en el arbol insertado de forma desordenada toma "<<tdes<<"ms"<<endl;
}