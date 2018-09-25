#include <stdlib.h>
#include <vector>

class MergeSort{

private:
	int * arr;
	int max_size;
	int _size;
	void merge(int *, int, int);

public:
	MergeSort();
	~MergeSort();
	bool empty();
	int size();
	int top();
	void insert(int);
	void copy(std::vector<int> *);
	void sort();
};