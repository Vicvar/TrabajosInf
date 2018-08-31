#include <vector>
#include <string>
#include "Node.cpp"

using namespace std;

class Graph{
	private:
		vector<vector<Node*> > cliques;
		vector<vector<Node*> > compact;
		vector<Node*> g;
		map<string,Node*> mop;
		void BK(vector<Node*>,vector<Node*>,vector<Node*>);
		void BK2(vector<Node*>,vector<Node*>,vector<Node*>);
		
	public:
		Graph();
		~Graph();
		void add(string,string);
		bool Find_g(string);
		bool Find_map(string);
		void Clique();
		void Compact();
		void Follow(int);
};