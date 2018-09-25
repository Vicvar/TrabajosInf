#include <queue>

class Sort{
private:
	std::priority_queue<int> pq;
public:
	Sort();
	~Sort();
	void insert(int);
	void remove();
	int min();
	int size();
};