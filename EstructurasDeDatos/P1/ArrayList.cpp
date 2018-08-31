#include <bits/stdc++.h>
#include "ArrayList.h"

using namespace std;

ArrayList::ArrayList(){
	max=50;
	arr=(int *)malloc(max*sizeof(int));
	vSize=0;
}

ArrayList::ArrayList(int n){
	max=n;
	arr=(int *)malloc(max*sizeof(int));
	vSize=0;
}

ArrayList::~ArrayList(){
	delete arr;
}

int ArrayList::at(int n){
	if(n<vSize) return arr[n];
	else cout<<"fuera de rango"<<endl;
}

int ArrayList::size(){
	return vSize;
}

void ArrayList::push_back(int n){
	if(vSize<max){
		arr[vSize]=n;
		vSize++;
	}
	else{
		arr=(int*)realloc(arr,2*max*sizeof(int));
		max=2*max;
		arr[vSize]=n;
		vSize++;
	}
}
