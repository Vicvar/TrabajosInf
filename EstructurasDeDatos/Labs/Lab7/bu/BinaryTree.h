#include "BinaryTreeADT.h"

class BinaryTree : public BinaryTreeADT{
	
	private:
		int _size;
		node *root;

	public:
		BinaryTree();
		~BinaryTree();
		void insert(int);
		node *search(int);
		int size();
};