#include "Graph.cpp"

int main(){
	Graph * g = new Graph();

	g->add("a","c");
	g->add("c","b");	g->add("c","d");	g->add("c","e");
	g->add("d","c");	g->add("d","e");	g->add("d","f");
	g->add("e","c");	g->add("e","d");
	g->add("f","g");	g->add("f","h");	g->add("f","i");	g->add("f","j");
	g->add("g","f");	g->add("g","h");	g->add("g","i");	g->add("g","j");
	g->add("h","f");	g->add("h","g");	g->add("h","i");	g->add("h","j");
	g->add("i","f");	g->add("i","g");	g->add("i","h");	g->add("i","j");	g->add("i","k");	g->add("i","l");
	g->add("j","f");	g->add("j","g");	g->add("j","h");	g->add("j","i");
	g->add("k","i");	g->add("k","l");
	g->add("l","k");	g->add("l","i");

	g->Clique();
	g->Compact();
}