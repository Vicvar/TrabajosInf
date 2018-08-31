#include <vector>
#include <string>
using namespace std;
class Node{
	private:
		string nombre;
		vector<Node*> seguidos;
		int in, seguidores;
		void addSeg();
	public:
		Node(string,int);
		~Node();
		void seguir(Node*);
		string name();
		Node* nodoSeguido(int);
		int get_i();
		int getNseguidos();
		bool sigueA(string);
		int getSeg();
};