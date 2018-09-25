#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree(){
	_size=0;
	root=new node();
}

void postOrderDel(node *n){
	postOrderDel(n->getL());
	postOrderDel(n->getR());
	delete n;
}

BinaryTree::~BinaryTree(){
	postOrderDel(root);
}

void BinaryTree::insert(int n){
	node *aux=root;
	while(!aux->isEmpty()){
		if(n<aux->getData()) aux=aux->getL();
		else if(n>aux->getData()) aux=aux->getR();
	}
	aux->setData(n);
	aux->setL(new node());
	aux->setR(new node());
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