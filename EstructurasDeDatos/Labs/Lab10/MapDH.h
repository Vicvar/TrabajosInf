#include "MapADT.h"

class MapDH : public MapADT{
private:
	int _size;
	int max_s;
	pair<string,int> *Array;
	void hash(string, int);
	void rehash();
	int nextPrime(int);
	
public:
	MapDH();
	~MapDH();
	bool empty();
	int size();
	void insert(pair<string,int>);
	int at(string);
	void erase(string);
};