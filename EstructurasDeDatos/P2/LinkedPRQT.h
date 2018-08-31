#include "PRQuadTreeADT.h"

struct Node{
	int state;
	int tl[2];
	int br[2];
	int point[2];
	Node *prev_cuad;
	Node *NW;
	Node *SW;
	Node *NE;
	Node *SE;
};

class LinkedPRQT: public PRQuadTreeADT{


private:
	Node *root;
	int *childCount(Node *);
	void subdivide(Node *);
	void collapse(Node *);
	int belongsTo(int, int, int *, int *);
	void passPoint(int, int, Node *);
	void asPointLoc(int, int, Node *);
	void destroyNode(Node *);
	double minDist(Node *,double,int,int);
	int pdm[2];

public:
	LinkedPRQT(char *);
	LinkedPRQT(int, int);
	~LinkedPRQT();
	void addPoint(int, int);
	void remPoint(int, int);
	bool search(int, int);
	void closest(int,int);
};