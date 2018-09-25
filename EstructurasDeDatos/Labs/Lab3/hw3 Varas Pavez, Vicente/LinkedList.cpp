#include <bits/stdc++.h>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){
	head=new Node;
	tail=head;
	vSize=0;
}

LinkedList::~LinkedList(){
	while(head!=NULL){
		Node *aux=head;
		head=head->next;
		delete aux;
	}
}

int LinkedList::at(int n){
	if(n<vSize){
		Node *aux;
		aux=head;
		for(int i=0;i<n;i++){
			aux=aux->next;
		}
		return aux->data;
	}
	else cout<<"fuera de rango"<<endl;
}

int LinkedList::size(){
	return vSize;
}

void LinkedList::push_back(int n){
	if(vSize==0){
		head->data=n;
		vSize++;
	}
	else{
		Node *aux;
		aux=tail;
		tail=new Node;
		tail->data=n;
		aux->next=tail;
		vSize++;
	}	
}