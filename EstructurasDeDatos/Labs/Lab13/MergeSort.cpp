#include "MergeSort.h"
#include <stdlib.h>

using namespace std;

MergeSort :: MergeSort(){
	_size=0;
	max_size=10;
	arr=(int*)malloc(sizeof(int)*(max_size+1));
}

MergeSort :: ~MergeSort(){

}

bool MergeSort :: empty(){
	if(_size==0) return true;
	else return false;
}

int MergeSort :: size(){
	return _size;
}

void MergeSort :: insert(int n){
	if(_size==max_size){
		max_size=max_size*2;
		arr=(int *)realloc(arr,sizeof(int)*max_size+1);
	}
	arr[_size+1]=n;
	_size++;
}

void MergeSort :: copy(vector<int> *v){
	for(int i=0; i<_size ; i++){
		v->push_back(arr[i]);
	}
}

void MergeSort :: sort(){
	merge(arr,0,_size-1);
}

/*******private*******/

void MergeSort :: merge(int *array, int l, int r){
	if(l-r){
		int m=(l+r)/2;
		merge(array,l,m);
		merge(array,m+1,r);
		
		//merge
		int L[m-l+1], R[r-m];

		for(int i=0; i<m-l+1; i++){
			L[i]=array[i+l];
		}
		for(int i=0; i<r-m; i++){
			R[i]=array[m+1+i];
		}

		int cont1=0, cont2=0, cont3=0;
		while(cont1<m-l+1 && cont2<r-m){
			if(L[cont1]<=R[cont2]){
				array[cont3]=L[cont1];
				cont1++;
			}
			else{
				array[cont3]=R[cont2];
				cont2++;
			}
			cont3++;
		}
		while(cont1<m-l+1){
			array[cont3]=L[cont1];
			cont1++;
			cont3++;
		}
		while(cont2<r-m){
			array[cont3]=R[cont2];
			cont2++;
			cont3++;
		}
	}
}