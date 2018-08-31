#include <iostream>
#include <cstdlib>
#include <vector>
#include "./hpc_helpers.h"

using namespace std;

int main(int argc, char *argv[]){
	int nexp = atoi(argv[1]);
	int lexp = atoi(argv[2]);
	int mexp = atoi(argv[3]);
	int n=1<<nexp;
	int l=1<<lexp;
	int m=1<<mexp;

	vector<float> A(n*l), B(l*m), C(n*m), Bt(m*l);


	TIMERSTART(init);
	for(int i=0; i<n*l; i++){
		A.at(i)=rand()%10;
	}
	for(int i=0; i<l*m; i++){
		B.at(i)=rand()%10;
	}
	for(int i=0; i<n*m; i++){
		C.at(i)=0;
	}
	TIMERSTOP(init);
	

	TIMERSTART(transp);
	for(int k=0; k<m; k++){
		for(int j=0; j<l; j++){
			Bt[k*l+j]=B[j*m+k];
		}
	}
	TIMERSTOP(transp);

	TIMERSTART(mult2);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			float acc=0;
			for(int k=0; k<l; k++){
				acc=A[i*l+k]*Bt[j*m+k];
			}
			C[i*m+j]=acc;
		}
	}
	TIMERSTOP(mult2);

}