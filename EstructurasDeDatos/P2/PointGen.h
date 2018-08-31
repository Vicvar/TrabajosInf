class PointGen{
private:
	int n, m, nop;
	char * filename;
public:
	PointGen(int n, int m);
	~PointGen();
	void nUniPoints(int, char *);
	void nNorPoints(int, char *);
	void nCenterPoints(int, char *);
	void allPoints(char *);
};