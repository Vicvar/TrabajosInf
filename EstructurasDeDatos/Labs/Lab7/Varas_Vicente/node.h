class node{
	private:
		int data;
		bool _empty;
		node *L;
		node *R;

	public:
		node();
		~node();
		bool isEmpty();
		bool hasL();
		bool hasR();
		int getData();
		void setData(int);
		node *getL();
		void setL(node*);
		node *getR();
		void setR(node*);
};