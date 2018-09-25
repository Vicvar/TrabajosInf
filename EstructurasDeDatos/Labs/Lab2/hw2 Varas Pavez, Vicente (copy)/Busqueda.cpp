#include <bits/stdc++.h>
#include "Busqueda.h"

using namespace std;

Busqueda::Busqueda(int n){
	for(int i=0;i<n;i++){
		vect.push_back(random()%(3*n));
	}
	sort(vect.begin(),vect.end());
}

void Busqueda::lineal(int x){
	cout<<"Busqueda lineal:"<<endl;
	for(int i=0;i<vect.size();i++){
		if(vect[i]==x){
			cout<<"Se ha encontrado el elemento "<<x<<" en la posicion numero "<<i<<endl;
			return;
		}
	}
	cout<<"No se ha encontrado el elemento "<<x<<endl;
}

void Busqueda::binariaIterativa(int x){
	int l,h,m;
	cout<<"Busqueda binaria iterativa"<<endl;
	l=0;
	h=vect.size()-1;
	m=(l+h)/2;
	while(l<=h){
		if(vect[m]==x){
			cout<<"Se ha encontrado el elemento "<<x<<" en la posicion numero "<<m<<endl;
			return;
		}
		else if(x<vect[m]){
			h=m-1;
			m=(l+h)/2;
		}
		else if(x>vect[m]){
			l=m+1;
			m=(l+h)/2;
		}
	}
	cout<<"No se ha encontrado el elemento "<<x<<endl;
}

void Busqueda::binariaRecursiva(int N,int l,int r){
	int m=(l+r)/2;
	if(vect[m]==N&&l<=r){
		cout<<"Busqueda binaria recursiva:"<<endl;
		cout<<"Se ha encontrado el elemento "<<N<<" en la posicion numero "<<m<<endl;
	}
	else if(vect[m]>N&&l<=r) return binariaRecursiva(N,l,m-1);
	else if(vect[m]<N&&l<=r) return binariaRecursiva(N,m+1,r);
	else{
		cout<<"Busqueda binaria recursiva:"<<endl;
		cout<<"No se ha encontrado el elemento "<<N<<endl;
	}
}

void Busqueda::impVec(){
	for(int i=0;i<vect.size();i++){
		cout<<vect[i]<<" ";
	}
	cout<<endl;
}
