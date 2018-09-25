#include <bits/stdc++.h>
#include "ListADT.h"
#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[]){
	
	ArrayList lArray=ArrayList();
	LinkedList lEnc=LinkedList();

	lArray.push_back(1);
	lArray.push_back(2);
	lArray.push_back(3);
	lEnc.push_back(1);
	lEnc.push_back(2);
	lEnc.push_back(3);

	cout<<"Tamaño ListArr:"<<lArray.size()<<endl;
	cout<<"Tamaño ListEnc:"<<lEnc.size()<<endl;
	cout<<"ListArr"<<endl;
	for(int i=0;i<lArray.size();i++){
		cout<<lArray.at(i)<<endl;
	}
	cout<<"ListEnc"<<endl;
	for(int i=0;i<lEnc.size();i++){
		cout<<lEnc.at(i)<<endl;
	}
}