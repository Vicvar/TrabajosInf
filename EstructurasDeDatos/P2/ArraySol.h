class ArraySol{

	struct Point{
		int x;
		int y;
	};

private:
	Point *Array;
	int _size;
	int max_s;
public:
	ArraySol(char *);
	~ArraySol();
	void addPoint(int x, int y);
	bool search(int x, int y);
};