

class QueueADT{

	public:
		virtual bool empty()=0;
		virtual int size()=0;
		virtual int front()=0;
		virtual int back()=0;
		virtual void push(int n)=0;
		virtual void pop()=0;

};
