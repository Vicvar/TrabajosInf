class PRQuadTreeADT{
private:

public:
	virtual void addPoint(int,int)=0;
	virtual void remPoint(int,int)=0;
	virtual bool search(int,int)=0;
	virtual void closest(int,int)=0;
};