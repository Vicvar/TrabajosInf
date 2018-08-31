#include "LinkedPRQT.cpp"
#include "ArraySol.cpp"
#include "PointGen.cpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]){
	int n, alpha, n_2, x, y;//alpha mayor significa menos puntos
	double tarray, tprqt;
	clock_t ini, fin;
	if(argc!=3){
		cout<<"./compexp n alpha";
		return -1;
	}

	n=atoi(argv[1]);
	alpha=atoi(argv[2]);

	PointGen *pg=new PointGen(n,n);
	pg->nUniPoints((n*n)/alpha,(char *)"input.txt");
	pg->allPoints((char *)"search.txt");
	ArraySol *as=new ArraySol((char *)"input.txt");
	LinkedPRQT *prqt=new LinkedPRQT((char *)"input.txt");

	ifstream sfile;
	sfile.open("search.txt",ifstream::in);

	string durr;
	getline(sfile,durr);
	sfile>>n_2;
	ini=clock();
	for(int i=0;i<n_2;i++){
		sfile>>x>>y;
		prqt->search(x,y);
	}
	fin=clock();

	tprqt=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;


	sfile.clear();
	sfile.seekg(0,sfile.beg);

	getline(sfile,durr);
	getline(sfile,durr);

	ini=clock();
	for(int i=0; i<n_2;i++){
		sfile>>x>>y;
		as->search(x,y);
	}
	fin=clock();

	tarray=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	cout<<"Tiempo LPRQT: "<<tprqt<<"ms"<<endl;
	cout<<"Tiempo Array: "<<tarray<<"ms"<<endl;
	
}