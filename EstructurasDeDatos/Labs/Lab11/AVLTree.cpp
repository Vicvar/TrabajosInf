#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree(){
	_size=0;
	root=new node();
}

AVLTree::~AVLTree(){
	postOrderDel(root);
}

void AVLTree::insert(int n){
	node *aux=root;
	while(!aux->isEmpty()){
		if(n<aux->getData()) aux=aux->getL();
		else if(n>aux->getData()) aux=aux->getR();
	}
	aux->setData(n);
	aux->setL(new node(aux));
	aux->setR(new node(aux));
	heightUpdate(aux);
	balance(aux);
}

node *AVLTree::search(int n){
	node *aux=root;
	while(!aux->isEmpty()){
		if(aux->getData()==n) return aux;
		else if(n<aux->getData()) aux=aux->getL();
		else if(n>aux->getData()) aux=aux->getR();
	}
	throw "No se encontró el elemento";
}

int AVLTree::size(){
	return _size;
}

/**************************private methods******************************/

void AVLTree::postOrderDel(node *n){
	postOrderDel(n->getL());
	postOrderDel(n->getR());
	delete n;
}

void AVLTree::heightUpdate(node * n){
	if(n->getL()->getH() >= n->getR()->getH()){
		n->setH(n->getL()->getH()+1);
	}
	else{
		n->setH(n->getR()->getH()+1);
	}
	if(n->hasP()) heightUpdate(n->getP());
}

void AVLTree::balance(node * n){
	node * aux = n->getP();
	node * left, * right;
	
	while(aux!=NULL){
		left=aux->getL();
		right=aux->getR();
		
		if(left->getH()>right->getH()+1 || right->getH()>left->getH()+1) break;

		aux=aux->getP();
	}

	if(aux!=NULL){
		if(left->getH()>right->getH()){
			if(left->getL()->getH()>left->getR()->getH()) singleRotR(aux);
			else doubleRotLR(aux);
		}
		else {
			if(right->getR()->getH()>right->getL()->getH()) singleRotL(aux);
			else doubleRotRL(aux);
		}
	}
}

void AVLTree::singleRotL(node * n){
	node * aux1, * aux2;
	
	aux1 = n;
	aux2 = n->getR();

	aux2->setP(aux1->getP());
	aux1->setR(aux2->getL());
	aux2->setL(aux1);
}

void AVLTree::singleRotR(node * n){
	node * aux3, * aux2;

	aux3 = n;
	aux2 = n->getL();

	aux2->setP(aux3->getP());
	aux3->setL(aux2->getL());
	aux2->setR(aux3);
}

void AVLTree::doubleRotLR(node * n){
	node * aux3, * aux1;

	aux3 = n;
	aux1 = n->getL();

	singleRotL(aux1);
	singleRotR(aux3);
}

void AVLTree::doubleRotRL(node * n){
	node * aux1, * aux3;

	aux1 = n;
	aux3 = n->getR();

	singleRotR(aux3);
	singleRotL(aux1);
}