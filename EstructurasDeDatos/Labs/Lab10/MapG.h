#include "MapADT.h"

class MapG : public MapADT{
private:
	int _size;
	int max_s;
	pair<string,int> *Array;
	void hash(string, int);
	void rehash();

public:
	MapG();
	~MapG();
	bool empty();
	int size();
	void insert(pair<string,int>);
	int at(string);
	void erase(string);
};