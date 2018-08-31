#include "Busqueda.h"
#include <bits/stdc++.h>
using namespace std;

Busqueda::Busqueda(){

}

bool Busqueda::lineal(ListADT* list, int num){

	int i=0;
	while(i<list->size()){
		if(num==list->at(i)){
			cout << "Se ha encontrado el elemento " << num << " en la posición número " << i << endl;
			return true;//break;
		}
		i++;
	}
	cout << "No se ha encontrado el elemento " << num << endl;
	return false;
}


bool Busqueda::binaria(ListADT* list, int num, int min, int max){
	int l=min, r=max;
	while(l<=r){
		int m=(l+r)/2;
		if(list->at(m)<num) l=m+1;
		else if(list->at(m)>num) r=m-1;
		else if(list->at(m)==num) {
			//cout << "Se ha encontrado el elemento " << num << " en la posición número " << m << endl; 
			return true;
		}
	}
	//cout << "No se ha encontrado el elemento " << num << endl;
	return false;
}


bool Busqueda::exponencial(ListADT* list, int num){
    if (list->size() == 0) {
    	cout << "No se ha encontrado el elemento " << num << endl;
        return false;
    }

    int bound = 1;
    while (bound < list->size() && list->at(bound) < num) {
        bound *= 2;
    }

    return binaria(list, num, bound/2, min(bound, list->size()));
}