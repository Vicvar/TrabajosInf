#include <stdlib.h>
#include <iostream>

using namespace std;

class MapADT{
public:
	virtual bool empty()=0;
	virtual int size()=0;
	virtual void insert(pair<string,int>)=0;
	virtual int at(string)=0;
	virtual void erase(string)=0;
};