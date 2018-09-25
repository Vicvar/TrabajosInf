#include <stdlib.h>
#include "node.h"

node::node(){
	isEmpty=true;
	L=NULL;
	R=NULL;
}

node::~node(){

}

bool node::isEmpty(){
	return isEmpty;
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
	isEmpty=false;
}

node *node::getL(){
	return L;
}

node *node::getR(){
	return R;
}
