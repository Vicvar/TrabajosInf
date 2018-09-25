#include <iostream>
#include <stdlib.h>
#include "ListADT.h"
#include "LinkedList.hpp"
#include "ArrayList.hpp"

using namespace std;


void il_test(ListADT<int> * list, int n){
	for(int i=0;i<n;i++){
		list->push_back(rand());
	}
}

void il_disp(ListADT<int> * list){
	for (int i=0;i<list->size();++i){
		cout<<list->at(i)<<" ";
	}
	cout<<endl;
}

void cl_test(ListADT<char> * list, int n){
	for(int i=0;i<n;i++){
		list->push_back('a');
	}
}

void cl_disp(ListADT<char> * list){
	for (int i = 0; i < list->size(); ++i){
		cout<<list->at(i)<<" ";
	}
	cout<<endl;
}

int main(int argc, char *argv[]){
	ListADT<int> *int_lList=new LinkedList<int>();
	ListADT<int> *int_aList=new ArrayList<int>();
	ListADT<char> *char_lList=new LinkedList<char>();
	ListADT<char> *char_aList=new ArrayList<char>();

	il_test(int_aList,10);
	il_test(int_lList,5);
	cout<<"rand int array list size 10:"<<endl;
	il_disp(int_aList);
	cout<<"rand int linked list size 5:"<<endl;
	il_disp(int_lList);

	cl_test(char_aList,10);
	cl_test(char_lList,5);
	cout<<"a's char array list size 10:"<<endl;
	cl_disp(char_aList);
	cout<<"a's char linked list size 5:"<<endl;
	cl_disp(char_lList);
}