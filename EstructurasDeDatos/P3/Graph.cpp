#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;
Graph::Graph(){
}

Graph::~Graph(){
}

void Graph::add(string u1, string u2){
	Node *n1;
	Node *n2;
	if(!Find_map(u1)){
		n1=new Node(u1,g.size());
		mop.insert(pair<string,Node*>(n1->name(),n1));
		g.push_back(n1);
	}
	else n1=mop[u1];
	if(!Find_map(u2)){
		n2=new Node(u2,g.size());
		mop.insert(pair<string,Node*>(n2->name(),n2));
		g.push_back(n2);
	}
	else n2=mop[u2];
	n1->seguir(n2);
}

bool Graph::Find_g(string u){
	vector<bool> visited(g.size(),false);
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		if(u==g[q.front()]->name()){
			return true;
		}
		for(int i = 0; i<g[q.front()]->getNseguidos(); i++){
			int n = g[q.front()]->nodoSeguido(i)->get_i();
			if(!visited[n]){
				visited[n] = true;
				q.push(n);
			}
		}
		q.pop();
		if(!q.empty()){
			for(int i=0; i<g.size(); i++){
				if(!visited[i]){
					q.push(i);
					visited[i] = true;
					break;
				}
			}
		}
	}
	return false;
}

bool Graph::Find_map(string u){
	if(mop.count(u)>0) return true;
	return false;
}

void Graph::Clique(){
	//para este metodo se implemento el algoritmo de Bron-Kerbosch
	vector<Node*> R,P,X;
	P=g;
	cliques.clear();
	BK(R,P,X);
	for(int i=0; i<cliques.size(); i++){
		for(int j=0; j<cliques[i].size(); j++){
			cout<< cliques[i][j]->name() << " ";
		}
		cout<<endl;
	}
}

void Graph::BK(vector<Node*> R, vector<Node*> P, vector<Node*> X){
	if(P.size()==0 && X.size()==0 && R.size()>2){ //se añade la condicion de que el clique contega 3 o mas nodos
		cliques.push_back(R);
	}

	while(P.size()!=0){
		vector<Node*> RuV, PyN, XyN;

		RuV=R;
		RuV.push_back(P[0]);
		
		//como el grafo es dirigido, se consideran vecinos los nodos conectados en ambos sentidos
		for(int j=0; j<P.size(); j++){
			if(P[j]->sigueA(P[0]->name()) && P[0]->sigueA(P[j]->name()))
				PyN.push_back(P[j]);
		}
		
		for(int j=0; j<X.size(); j++){
			if(X[j]->sigueA(P[0]->name()) && P[0]->sigueA(X[j]->name()))
				XyN.push_back(X[j]);
		}

		BK(RuV,PyN,XyN);

		X.push_back(P[0]);
		P.erase(P.begin());
	}
}


void Graph::Compact(){
	compact.clear();
	vector<Node*> R, P, X, s;
	vector<vector<Node*> > m;
	P=g;
	BK2(R,P,X);

	//separa componentes comunes en los cliques
	for(int i=0; i<compact.size()-1 ; i++){
		for(int j=0; j<compact[i].size(); j++){
			for(int k=i+1; k<compact.size(); k++){
				for(int l=0; l<compact[k].size(); l++){
					if(compact[i][j]==compact[k][l]){
						if(compact[i].size()>compact[k].size()){
							compact[k].erase(compact[k].begin()+l);
							if(compact[k].size()==0) compact.erase(compact.begin()+k);
						}
						else{ 
							compact[i].erase(compact[i].begin()+j);
							if(compact[i].size()==0) compact.erase(compact.begin()+i);
						}
					}
				}
			}
		}
	}
	
	for(int i=0; i<compact.size() ; i++){
		if(compact[i].size()>1){
			m.push_back(compact[i]);
		}
		else s.push_back(compact[i][0]);
	}

	for(int i=0; i<s.size(); i++){
		for(int j=0; j<s.size(); j++){
			if(s[i]->sigueA(s[j]->name())){
				cout<<"("<<s[i]->name()<<","<<s[j]->name()<<")"<<endl;
			}
		}
	}

	for(int i=0; i<s.size(); i++){
		for(int j=0; j<m.size(); j++){
			for(int k=0; k<m[j].size(); k++){
				if(s[i]->sigueA(m[j][k]->name())){
					cout<<"("<<s[i]->name()<<",C"<<j+1<<")"<<endl;
					break;
				}
			}
		}
	}

	for(int i=0; i<s.size(); i++){
		for(int j=0; j<m.size(); j++){
			for(int k=0; k<m[j].size(); k++){
				if(m[j][k]->sigueA(s[i]->name())){
					cout<<"("<<"C"<<j+1<<","<<s[i]->name()<<")"<<endl;
					break;
				}
			}
		}
	}

	int m_ad[m.size()][m.size()]={0};


	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			for(int k=0; k<m.size(); k++){
				for(int l=0; l<m[k].size(); l++){
					if(m[i][j]->sigueA(m[k][l]->name()) && i!=k){
						m_ad[i][k]=1;
					}
				}
			}
		}
	}

	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m.size(); j++){
			if(m_ad[i][j]==1){
				cout<<"(C"<<i+1<<",C"<<j+1<<")"<<endl;
			}
		}
	}
}

void Graph::BK2(vector<Node*> R, vector<Node*> P, vector<Node*> X){
	if(P.size()==0 && X.size()==0){
		compact.push_back(R);
	}

	while(P.size()!=0){
		vector<Node*> RuV, PyN, XyN;

		RuV=R;
		RuV.push_back(P[0]);
		
		//como el grafo es dirigido, se consideran vecinos los nodos conectados en ambos sentidos
		for(int j=0; j<P.size(); j++){
			if(P[j]->sigueA(P[0]->name()) && P[0]->sigueA(P[j]->name()))
				PyN.push_back(P[j]);
		}
		
		for(int j=0; j<X.size(); j++){
			if(X[j]->sigueA(P[0]->name()) && P[0]->sigueA(X[j]->name()))
				XyN.push_back(X[j]);
		}

		BK2(RuV,PyN,XyN);

		X.push_back(P[0]);
		P.erase(P.begin());
	}
}

class comparaSeg
{
public:
	bool operator()(Node* n1, Node* n2){
		return n1->getSeg() < n2->getSeg();
	}
};

void Graph::Follow(int n){
	priority_queue<Node*, vector<Node*>, comparaSeg> pq;
	for(int i=0; i<g.size(); i++) pq.push(g[i]);
	for(int i=0; i<n; i++){
		cout<< pq.top()->name() <<endl;
		pq.pop();
	}
}