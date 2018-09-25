#include <bits/stdc++.h>
#include "ListADT.h"

using namespace std;

template<typename T>
class ArrayList : public ListADT<T>{

	private:
		T *arr;
		int vSize;
		int max;

	public:
		ArrayList();
		ArrayList(int n);
		~ArrayList();
		T at(int n);
		int size();
		void push_back(T n);
};

template<typename T>
ArrayList<T>::ArrayList(){
	max=50;
	arr=(T *)malloc(max*sizeof(T));
	vSize=0;
}

template<typename T>
ArrayList<T>::ArrayList(int n){
	max=n;
	arr=(T *)malloc(max*sizeof(T));
	vSize=0;
}

template<typename T>
ArrayList<T>::~ArrayList(){
	delete arr;
}

template<typename T>
T ArrayList<T>::at(int n){
	if(n<vSize) return arr[n];
	else cout<<"fuera de rango"<<endl;
}

template<typename T>
int ArrayList<T>::size(){
	return vSize;
}

template<typename T>
void ArrayList<T>::push_back(T n){
	if(vSize<max){
		arr[vSize]=n;
		vSize++;
	}
	else{
		arr=(T *)realloc(arr,2*max*sizeof(T));
		max=2*max;
		arr[vSize]=n;
		vSize++;
	}
}
