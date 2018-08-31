#include "PointGen.h"
#include <iostream>
#include <stdlib.h>
#include <random>
#include <fstream>

using namespace std;	

PointGen::PointGen(int a, int b){
	n=a;
	m=b;
}

PointGen::~PointGen(){

}

void PointGen::nUniPoints(int N, char * filename){
	nop=N;

	ofstream out;
	out.open(filename,ofstream::out);
	
	int array[nop][2];
	default_random_engine generator;
	uniform_int_distribution<int> distribution1(0,n);
	uniform_int_distribution<int> distribution2(0,m);

	generator.seed(clock());

	for(int i=0; i<nop; i++){
		for(int j=0; j<2;j++){
			if(j==0){
				array[i][j]=distribution1(generator);
			}
			else{
				array[i][j]=distribution2(generator);
			}
		}
	}

	out<<n<<" "<<m<<endl;
	out<<nop<<endl;
	for(int i=0; i<nop; i++){
		out<<array[i][0]<<" "<<array[i][1]<<endl;
	}
}

void PointGen::nNorPoints(int N, char * filename){
	nop=N;

	ofstream out;
	out.open(filename,ofstream::out);
	
	int array[nop][2];
	default_random_engine generator;
	normal_distribution<double> distribution1(n/2,n/8);
	normal_distribution<double> distribution2(m/2,m/8);

	generator.seed(clock());

	for(int i=0; i<nop; i++){
		for(int j=0; j<2;j++){
			if(j==0){
				array[i][j]=(int)distribution1(generator);
			}
			else{
				array[i][j]=(int)distribution2(generator);
			}
		}
	}

	out<<n<<" "<<m<<endl;
	out<<nop<<endl;
	for(int i=0; i<nop; i++){
		out<<array[i][0]<<" "<<array[i][1]<<endl;
	}
}

void PointGen::nCenterPoints(int N, char * filename){
	nop=N;

	ofstream out;
	out.open(filename,ofstream::out);
	
	int array[nop][2];
	default_random_engine generator;
	uniform_int_distribution<int> distribution1(n/4,3*n/4);
	uniform_int_distribution<int> distribution2(m/4,3*m/4);

	generator.seed(clock());

	for(int i=0; i<nop; i++){
		for(int j=0; j<2;j++){
			if(j==0){
				array[i][j]=distribution1(generator);
			}
			else{
				array[i][j]=distribution2(generator);
			}
		}
	}

	out<<n<<" "<<m<<endl;
	out<<nop<<endl;
	for(int i=0; i<nop; i++){
		out<<array[i][0]<<" "<<array[i][1]<<endl;
	}
}

void PointGen::allPoints(char * filename){
	nop=n*m;
	
	ofstream out;
	out.open(filename,ofstream::out);

	out<<n<<" "<<m<<endl;
	out<<nop<<endl;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			out<<i<<" "<<j<<endl;
		}
	}
}
