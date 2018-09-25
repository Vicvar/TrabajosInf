#include "MapADT.h"


class MapB : public MapADT{
private:
	int _size;
	int max_s;
	pair<string,int> *Array;
	int hash(string);
	void rehash();
	int nextPrime(int);

public:
	MapB();
	~MapB();
	bool empty();
	int size();
	void insert(pair<string,int>);
	int at(string);
	void erase(string);
};