#include <bits/stdc++.h>
#include "Busqueda.h"

int main(int argc, char *argv[]){
	if(argc!=2){
		std::cout<<"error, ingresar argumento(n° de elementos)"<<std::endl;
		return 0;
	}
	int n=atoi(argv[1]);
	Busqueda busq(n);
	busq.impVec();

	int aux;
	while(1){
		std::cin >> aux;
		busq.lineal(aux);
		busq.binariaRecursiva(aux,0,n-1);
		busq.binariaIterativa(aux);
	}
}
