#include <bits/stdc++.h>
#include "ListADT.h"

using namespace std;

template<typename T>
class LinkedList : public ListADT<T>{
	
	struct Node{
		T data;
		Node *next;
	};
	
	private:
		Node *head;
		Node *tail;
		int vSize;

	public:
		LinkedList();
		~LinkedList();
		T at(int n);
		int size();
		void push_back(T n);
};

template<typename T>
LinkedList<T>::LinkedList(){
	head=new Node;
	tail=head;
	vSize=0;
}

template<typename T>
LinkedList<T>::~LinkedList(){
	while(head!=NULL){
		Node *aux=head;
		head=head->next;
		delete aux;
	}
}

template<typename T>
T LinkedList<T>::at(int n){
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

template<typename T>
int LinkedList<T>::size(){
	return vSize;
}

template<typename T>
void LinkedList<T>::push_back(T n){
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