#include "LinkedPRQT.cpp"
#include "PointGen.cpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]){
	int n, N, n_2, x, y;
	double tuni, tnor, tcen;
	clock_t ini, fin;
	if(argc!=3){
		cout<<"./compexp2 n N";
		return -1;
	}

	n=atoi(argv[1]);
	N=atoi(argv[2]);

	PointGen *pg=new PointGen(N,N);
	pg->nUniPoints(n,(char *)"uniforme.txt");
	pg->nNorPoints(n,(char *)"normal.txt");
	pg->nCenterPoints(n,(char *)"center.txt");
	pg->allPoints((char *)"search.txt");

	LinkedPRQT *prqt_uni=new LinkedPRQT((char *)"uniforme.txt");
	LinkedPRQT *prqt_nor=new LinkedPRQT((char *)"normal.txt");
	LinkedPRQT *prqt_cen=new LinkedPRQT((char *)"center.txt");


	ifstream sfile;
	sfile.open("search.txt",ifstream::in);

	string durr;
	getline(sfile,durr);
	sfile>>n_2;

	
	ini=clock();
	for(int i=0; i<n_2;i++){
		sfile>>x>>y;
		prqt_cen->search(x,y);
	}
	fin=clock();

	tcen=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;


	sfile.clear();
	sfile.seekg(0,sfile.beg);

	getline(sfile,durr);
	getline(sfile,durr);

	ini=clock();
	for(int i=0; i<n_2;i++){
		sfile>>x>>y;
		prqt_nor->search(x,y);
	}
	fin=clock();

	tnor=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	sfile.clear();
	sfile.seekg(0,sfile.beg);

	getline(sfile,durr);
	getline(sfile,durr);

	ini=clock();
	for(int i=0;i<n_2;i++){
		sfile>>x>>y;
		prqt_uni->search(x,y);
	}
	fin=clock();

	tuni=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	cout<<"Tiempo uniforme: "<<tuni<<"ms"<<endl;
	cout<<"Tiempo normal: "<<tnor<<"ms"<<endl;
	cout<<"Tiempo centro: "<<tcen<<"ms"<<endl;
	
}