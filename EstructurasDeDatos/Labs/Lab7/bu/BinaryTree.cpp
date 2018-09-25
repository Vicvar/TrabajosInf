#include <iostream>
#include <stdlib.h>
#include "BinaryTree.h"

BinaryTree::BinaryTree(){
	_size=0;
	root=new node();
}

BinaryTree::~BinaryTree(){
	node *aux=root;
}

void BinaryTree::insert(int n){
	node *aux=root;
	while(!aux->isEmpty()){
		if(n<aux->getData()) aux=aux->getL();
		else if(n>aux->getData()) aux=aux->getR();
	}
	aux->setData(n);
	aux->getL()=new node();
	aux->getR()=new node();
}

node *BinaryTree::search(int n){
	node *aux=root;
	while(!aux->isEmpty()){
		if(aux->getData()==n) return aux;
		else if(n<aux->getData()) aux=aux->getL();
		else if(n>aux->getData()) aux=aux->getR();
	}
	cout<<"No se encontró el elemento"<<endl;
}

int BinaryTree::size(){
	return _size;
}