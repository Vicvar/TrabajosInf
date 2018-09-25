class node{
	private:
		int data;
		bool isEmpty;
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
		node *getR();
};