#include <stdlib.h>
#include "node.h"


node::node(){
	_empty=true;
	P=NULL;
	L=NULL;
	R=NULL;
	height=0;
}

node::node(node * n){
	_empty=true;
	P=n;
	L=NULL;
	R=NULL;
	height=1;
}

node::~node(){

}

bool node::isEmpty(){
	return _empty;
}

bool node::hasP(){
	if(P==NULL) return false;
	else return true;
}
bool node::hasL(){
	if(L==NULL) return false;
	else return true;
}

bool node::hasR(){
	if(R==NULL) return false;
	else return true;
}

int node::getH(){
	return height;
}

void node::setH(int h){
	height=h;
}

int node::getData(){
	return data;
}

void node::setData(int n){
	data=n;
	_empty=false;
}

node *node::getP(){
	return P;
}

void node::setP(node * n){
	P=n;
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