#ifndef LISTADT_H
#define LISTADT_H

template<typename T>
class ListADT{

public:
	virtual T at(int n)=0;
	virtual int size()=0;
	virtual void push_back(T n)=0;
};
#endif
