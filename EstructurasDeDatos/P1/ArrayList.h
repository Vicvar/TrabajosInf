#include "ListADT.h"

class ArrayList : public ListADT{

	private:
		int *arr;
		int vSize;
		int max;

	public:
		ArrayList();
		ArrayList(int n);
		~ArrayList();
		int at(int n);
		int size();
		void push_back(int n);
};

