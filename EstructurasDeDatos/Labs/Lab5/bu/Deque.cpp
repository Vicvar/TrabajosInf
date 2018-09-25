#include "Deque.h"

Deque::Deque(){
	_size=0;
	head=new Node;
	tail= new Node;
}

Deque::~Deque(){
	while(head!=tail){
		Node *aux=head;
		head=head->next;
		delete aux;
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
		return head->next->data;
	}
}

int Deque::back(){
	if(_size!=0){
		return tail->next->data;
	}
}

void Deque::push_front(int n){
	if(_size==0){
		head->next=new Node;
		head->next->data=n;
		head->next->prev=head;
		head->next->next=tail;
		tail->prev=head->next;
	}
	else{
		Node *aux=new Node;
		aux->next=head->next;
		aux->prev=head;
		head->next->prev=aux;
		head->next=aux;
	}
	_size++;
}

void Deque::push_back(int n){
	if(_size==0){
		head->next=new Node;
		head->next->prev=head;
		head->next->next=tail;
		tail->prev=head->next;
	}
	else{
		Node *aux=new Node;
		aux->prev=tail->next;
		aux->next=tail;
		tail->next->next=aux;
		tail->prev=aux;
	}
	_size++;
}

void Deque::pop_front(){
	if(_size!=0){
		Node *aux;
		aux=head->next;
		head->next=head->next->next;
		head->next->prev=head;
		delete aux;
		_size--;
	}
}

void Deque::pop_back(){
	if(_size!=0){
		Node *aux;
		aux=tail->prev;
		tail->prev=tail->prev->prev;
		tail->prev->next=tail;
		delete aux;
		_size--;
	}
}
