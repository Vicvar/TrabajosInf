#include <iostream>
#include "Deque.h"

using namespace std;

Deque::Deque(){
	_size=0;
	head=new Node;
	tail=head;
}

Deque::~Deque(){
	Node* aux=head->next;
	while(aux!=NULL){
		delete head;
		head=aux;
		aux=head->next;
	}

}

bool Deque::empty(){
	if(_size==0) return true;
	else return false;
}

int Deque::size(){
	return _size;
}

int Deque::front(){
	if(_size!=0){
		return head->data;
	}
	else return -1;
}

int Deque::back(){
	if(_size!=0){
		return tail->data;
	}
	else return -1;
}

void Deque::push_front(int n){
	if(_size==0){
		head->data=n;
	}
	else{
		Node* aux=new Node;
		aux->data=n;
		aux->next=head;
		head->prev=aux;
		head=aux;
	}
	_size++;
}

void Deque::push_back(int n){
	if(_size==0){
		head->data=n;
	}
	else{
		Node* aux=new Node;
		aux->data=n;
		aux->prev=tail;
		tail->next=aux;
		tail=aux;
	}
	_size++;
}

void Deque::pop_front(){
	if(_size==0){
		cout<<"Deque vacio, no pop_front"<<endl;
	}
	else if(_size>1){
		Node* aux=head;
		head=head->next;
		head->prev=NULL;
		delete aux;
	}
	_size--;
}

void Deque::pop_back(){
	if(_size==0){
		cout<<"Deque vacio, no pop_back"<<endl;
	}
	else if(_size>1){
		Node* aux=tail;
		tail=tail->prev;
		tail->next=NULL;
		delete aux;
	}
	_size--;	
}
