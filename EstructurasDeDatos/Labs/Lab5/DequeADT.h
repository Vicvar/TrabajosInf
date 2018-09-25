class DequeADT{
public:
	virtual bool empty()=0;
	virtual int size()=0;
	virtual int front()=0;
	virtual int back()=0;
	virtual void push_front(int n)=0;
	virtual void push_back(int n)=0;
	virtual void pop_front()=0;
	virtual void pop_back()=0;
};