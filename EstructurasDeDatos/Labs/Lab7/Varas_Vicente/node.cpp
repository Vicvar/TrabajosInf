#include <stdlib.h>
#include "node.h"

node::node(){
	_empty=true;
	L=NULL;
	R=NULL;
}

node::~node(){

}

bool node::isEmpty(){
	return _empty;
}

bool node::hasL(){
	if(L==NULL) return false;
	else return true;
}

bool node::hasR(){
	if(R==NULL) return false;
	else return true;
}

int node::getData(){
	return data;
}

void node::setData(int n){
	data=n;
	_empty=false;
}

node *node::getL(){
	return L;
}

void node::setL(node *n){
	L=n;
}

node *node::getR(){
	return R;
}

void node::setR(node *n){
	R=n;
}