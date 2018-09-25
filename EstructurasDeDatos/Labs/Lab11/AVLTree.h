#include "BinaryTreeADT.h"

class AVLTree : public BinaryTreeADT{
private:
	int _size;
	node *root;
	void postOrderDel(node *);
	void heightUpdate(node *);
	void balance(node *);
	void singleRotL(node *);
	void singleRotR(node *);
	void doubleRotLR(node *);
	void doubleRotRL(node *);

public:
	AVLTree();
	~AVLTree();
	void insert(int);
	node *search(int);
	int size();
};