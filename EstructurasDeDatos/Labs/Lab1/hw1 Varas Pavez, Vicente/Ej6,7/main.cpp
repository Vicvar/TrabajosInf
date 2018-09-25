#include <iostream>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]){
	if(argc != 2){
		std::cout<<"Error de argumentos"<<std::endl;
		return 0;
	}
	int n = atoi(argv[1]);
	int A[n],sum[n];
	for(int i=0;i<n;i++){
		A[i]=rand();
	}

	clock_t ini = clock();
	for(int i = 0;i < n; i++){
		int aux=0;
		for(int j = 0;j <= i;j++){
			aux+=A[j];
		}
		sum[i]=aux;
	}
	clock_t fin = clock();
	double t1=(double) (fin-ini)/CLOCKS_PER_SEC*1000.0;

	ini=clock();
	sum[0]=A[0];
	for(int i = 1;i < n; i++){
		sum[i]=sum[i-1]+A[i];
	}
	fin=clock();
	double t2=(double) (fin-ini)/CLOCKS_PER_SEC*1000.0;

	std::cout << "El algoritmo 1 demoro:" << t1 << "ms" << std::endl;
	std::cout << "El algoritmo 2 demoro:" << t2 << "ms" << std::endl;
}

