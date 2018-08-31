#include "ArraySol.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

ArraySol::ArraySol(char * filename){
	_size=0;
	max_s=10;
	Array=new Point[10];
	ifstream inf;
	inf.open(filename,ifstream::in);
	int x,y,n;
	inf>>x;
	inf>>y;
	inf>>n;
	for(int i=0;i<n;i++){
		inf>>x>>y;
		addPoint(x,y);
	}
}
ArraySol::~ArraySol(){
	delete Array;
}

void ArraySol::addPoint(int w, int z){
	if(_size==max_s){
		Array=(Point *)realloc(Array,2*max_s*sizeof(Point));
		max_s=2*max_s;
	}
	Array[_size].x=w;
	Array[_size].y=z;
	_size++;
}

bool ArraySol::search(int w, int z){
	for(int i=0;i<_size;i++){
		if(Array[i].x==w && Array[i].y==z){
			return true;
		}
	}
	return false;
}