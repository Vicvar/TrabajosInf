#include "ArrayList.h"
#include "LinkedList.h"
#include "Busqueda.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void listCompV1(ListADT *l1,ListADT *l2, ListADT *lr){
	int l1_cr=0,l2_cr=0;

	while(l1_cr<l1->size()&&l2_cr<l2->size()){
		if(l1->at(l1_cr)==l2->at(l2_cr)){
			lr->push_back(l1->at(l1_cr));
			l1_cr++;
			l2_cr++;
		}
		else{
			if(l1->at(l1_cr)<l2->at(l2_cr)) l1_cr++;
			else l2_cr++;
		}
	}
}

void listCompV2(ListADT *l1,ListADT *l2, ListADT *lr){
	for(int i=0;i<l1->size();i++){
		if(Busqueda::binaria(l2,l1->at(i),0,l2->size()-1)) lr->push_back(l1->at(i));
	}
}

void listDisp(ListADT *list){
	for(int i=0;i<list->size();i++){
		cout<<list->at(i)<<" ";
	}
	cout<<endl;
}

int main(int argc, char* argv[]){
	ListADT *l1=new ArrayList();
	ListADT *l2=new ArrayList();
	ListADT *lr_v1=new ArrayList();
	ListADT *lr_v2=new ArrayList();
	vector<int> v1,v2;
	int n,r,r_int;
	double tv1,tv2;
	clock_t ini, fin;

	if(argc!=3){
		 cout<<"Uso: ./main 'n' 'm/n'"<<endl;
		 return -1;	
	}

	n=atoi(argv[1]);
	r=atoi(argv[2]);

	for(int i=0;i<n;i++){
		v1.push_back(rand()%(10*n));
	}
	for(int i=0;i<n*r;i++){
		v2.push_back(rand()%(10*n*r));
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	for(int i=0;i<n;i++){
		l1->push_back(v1.at(i));
	}
	for(int i=0;i<n*r;i++){
		l2->push_back(v2.at(i));
	}

	cout<<"Elementos en n:"<<n<<endl;
	cout<<"Elementos en m:"<<n*r<<endl;
	ini=clock();
	listCompV1(l1,l2,lr_v1);
	fin=clock();
	tv1=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	cout<<"La version 1 demoro:"<<tv1<<" ms"<<endl;

	ini=clock();
	listCompV2(l1,l2,lr_v2);
	fin=clock();
	tv2=(double)(fin-ini)/CLOCKS_PER_SEC*1000.0;

	cout<<"La version 2 demoro:"<<tv2<<" ms"<<endl;
}