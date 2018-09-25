#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int N, M;

void BFS(vector<vector<int> > graph, int start){
	vector<bool> visited(N,false);
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		cout <<"Visita los vecinos de: " << q.front() << endl;
		for(int i=0; i<graph[q.front()].size();i++){
			int node = graph[q.front()][i];
			if(!visited[node]){
				visited[node] = true;
				q.push(node);
				cout <<" visitando a " << node << endl;
			}
		}
		q.pop();
	}
}

void DFS(vector<vector<int> > graph, int start){
	vector<bool> visited(N,false);
	stack<int> st;
	st.push(start);
	visited[start] = true;
	while(!st.empty()){
		cout << "Visita los vecinos de: " << st.top() << endl;
		int i;
		for(i=0;i<graph[st.top()].size();i++){
			int node= graph[st.top()][i];
			if(!visited[node]){
				st.push(node);
				visited[node] = true;
				cout << " visitando a: " << node << endl;
				break;
			}
		}
		if(i==graph[st.top()].size()) st.pop();
	}
}

int main(){
	cin>>N>>M;
	vector<vector<int> > g;
	g.resize(N+1);
	for(int i=0; i<M;i++){
		int X, Y;
		cin>>X>>Y;
		g[X].push_back(Y);
		g[Y].push_back(X);
	}
	for(int i=0;i<g.size();i++) sort(g[i].begin(),g[i].end());
	int inicio;
	cout<<"ingrese el nodo de inicio"<<endl;
	cin>>inicio;
	BFS(g,inicio);
	DFS(g,inicio);
}