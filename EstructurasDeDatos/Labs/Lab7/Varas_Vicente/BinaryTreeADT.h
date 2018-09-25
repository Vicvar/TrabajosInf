#include "node.cpp"

class BinaryTreeADT{
	public:
		virtual void insert(int)=0;
		virtual node *search(int)=0;
		virtual int size()=0;
};