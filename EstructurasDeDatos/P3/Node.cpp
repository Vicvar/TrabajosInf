#include "Node.h"
#include <bits/stdc++.h>
using namespace std;
Node::Node(string n, int i){
	nombre = n;
	in = i;
	seguidores=0;
}
Node::~Node(){

}

void Node::seguir(Node* n){
	seguidos.push_back(n);
	n->addSeg();
}
void Node::addSeg(){
	seguidores++;
}
int Node::getSeg(){
	return seguidores;
}

string Node::name(){
	return nombre;
}

Node* Node::nodoSeguido(int i){
	return seguidos[i];
}

int Node::get_i(){
	return in;
}

int Node::getNseguidos(){
	return seguidos.size();
}

bool Node::sigueA(string u){
	for(int i=0; i<seguidos.size(); i++){
		if(u==seguidos[i]->name())return true;
	}
	return false;
}