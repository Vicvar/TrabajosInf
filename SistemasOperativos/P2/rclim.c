#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <assert.h>
#include <unistd.h>

void *car();
void *passenger();

int pInCar=0;
int C;
int stop=0;
int runc;
int runmax;

sem_t rcmut;
sem_t stopm;
sem_t mut;
sem_t boarding;
sem_t unboarding;
sem_t full_car;
sem_t empty_car;

int main(int argc, char *argv[]){
	int N;

	if(argc!=4){
		printf("./rcfast N C runmax\n");
		return -1;
	}

	N=atoi(argv[1]);
	C=atoi(argv[2]);
	runmax=atoi(argv[3]);

	assert(N>0&&N<500&&C<N);

	sem_init(&rcmut,0,1);
	sem_init(&stopm,0,1);
	sem_init(&mut,0,1);
	sem_init(&boarding,0,0);
	sem_init(&unboarding,0,0);
	sem_init(&full_car,0,0);
	sem_init(&empty_car,0,1);

	pthread_t passengers_t[N];
	pthread_t car_t;

	pthread_create(&car_t,NULL,car,NULL);

	int id[N];
	for (int i = 0; i < N; ++i)
	{
		id[i]=i;
		pthread_create(&passengers_t[i],NULL,passenger,(void *)(id+i));
	}

	sem_wait(&stopm);
	while(!stop){
	sem_post(&stopm);
	sem_wait(&rcmut);
		if(runc>=runmax){
			stop=1;
		}
	sem_post(&rcmut);
	sem_wait(&stopm);
	}
	sem_post(&stopm);
	
	pthread_join(car_t, NULL);

	for(int i=0; i<N;i++){
		pthread_cancel(passengers_t[i]);
	}

}

void load(){
	sem_wait(&empty_car);
	printf("\nNext %d get in\n",C);
	for(int i=0;i<C;i++){
		sem_post(&boarding);
	}
}

void run(){
	sem_wait(&full_car);
	printf("Here we go! :D\n");
	printf(".\n");
	printf("..\n");
	printf("...\n");
	printf("wow... such fun :D\n");
}

void unload(){
	printf("Now, everyone out...\n");
		for(int i=0;i<C;i++){
		sem_post(&unboarding);
	}
}

void *car(){
	sem_wait(&stopm);
	while(!stop){
		sem_post(&stopm);
		sem_wait(&rcmut);
		runc++;
		sem_post(&rcmut);
		load();
		run();
		unload();
		sem_wait(&stopm);
	}
	sem_post(&stopm);
}

void board(int id){
	sem_wait(&mut);
	pInCar++;
	printf("passenger %d boarding...\n", id);
	if(pInCar==C)	sem_post(&full_car);
	sem_post(&mut);
}

void unboard(int id){
	sem_wait(&mut);
	pInCar--;
	printf("passenger %d unboarding...\n", id);
	if(pInCar==0) sem_post(&empty_car);
	sem_post(&mut);
}

void *passenger(int *id){
	while(1){
		sem_wait(&boarding);
		board(*id);
		sem_wait(&unboarding);
		unboard(*id);
	}
}