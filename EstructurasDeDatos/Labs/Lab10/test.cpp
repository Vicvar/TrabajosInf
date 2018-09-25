#include "MapB.cpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

string randString();

int main(int argc, char * argv[]){
	int n = atoi(argv[1]);

	MapB *mb=new MapB();
	pair<string, int> aux;

	vector<pair<string,int> > v;

	for(int i=0 ; i<n ; i++){
		aux.first=randString();
		cout<<aux.first<<endl;
		aux.second=rand();
		v.push_back(aux);
		mb->insert(aux);
	}
	cout<<mb->size()<<endl;
	for(int i=0 ; i<n ; i++){
		mb->erase(v[i].first);
	}
	cout<<mb->size()<<endl;
	for(int i=0 ; i<n ; i++){
		mb->insert(v[i]);
	}
	cout<<mb->size()<<endl;
}


string randString(){
	srand(clock());
	int n = rand()%7+3;
	string res;
	for(int i=0 ; i<n ; i++){
		res=res+(char)(rand()%94+32);
	}
	return res;
}