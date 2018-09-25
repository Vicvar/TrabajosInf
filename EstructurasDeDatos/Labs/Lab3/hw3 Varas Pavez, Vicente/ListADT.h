#ifndef LISTADT_H
#define LISTADT_H

class ListADT{

public:
	virtual int at(int n)=0;
	virtual int size()=0;
	virtual void push_back(int n)=0;
};
#endif
