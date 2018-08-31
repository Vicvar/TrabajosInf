#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;
int main (int argc, char *argv[]) {

	Graph* gg = new Graph();

	ifstream ifs;
	ifs.open(argv[1],ifstream::in);
	string st;
	ifs>>st;

	while(!ifs.eof()){
		if(st=="Add"){
			string u1, u2;
			ifs>>u1;
			ifs>>u2;
			gg->add(u1, u2);
		}
		else if(st=="Find"){
			string u;
			ifs>>u;
			if(gg->Find_map(u))cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else if(st=="Clique"){
			gg->Clique();
		}
		else if(st=="Compact"){
			gg->Compact();
		}
		else if(st=="Follow"){
			string c;
			ifs>>c;
			int n = atoi(c.c_str());
			gg->Follow(n);
		}
		
		ifs>>st;
	}	
}