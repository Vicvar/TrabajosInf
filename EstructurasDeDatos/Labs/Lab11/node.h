class node{
	private:
		int height;
		int data;
		bool _empty;
		node *P;
		node *L;
		node *R;

	public:
		node();
		node(node  *);
		~node();
		bool isEmpty();
		bool hasP();
		bool hasL();
		bool hasR();
		int getH();
		void setH(int);
		int getData();
		void setData(int);
		node *getP();
		void setP(node *);
		node *getL();
		void setL(node*);
		node *getR();
		void setR(node*);

};