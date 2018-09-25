class PriorityQueueADT{
private:

public:
	virtual bool empty()=0;
	virtual int size()=0;
	virtual int top()=0;
	virtual void push(int)=0;
	virtual void pop()=0;
};