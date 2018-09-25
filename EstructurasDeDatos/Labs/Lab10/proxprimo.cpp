#include "iostream"
#include <stdlib.h>

using namespace std;

int main(int argc, char * argv[]){
	int nop=0,N;
	N=atoi(argv[1]);

	for(int i=N; ; i++){
		for (int j=2;j<=i/2;j++){
			if(i%j==0){
				nop=1;
				break;
			}
		}
		if(!nop){
			return i;
		}
		nop=0;
	}
}