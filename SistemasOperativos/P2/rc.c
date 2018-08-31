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


sem_t mut;
sem_t boarding;
sem_t unboarding;
sem_t full_car;
sem_t empty_car;

int main(int argc, char *argv[]){
	int N;

	if(argc!=3){
		printf("./rc N C\n");
		return -1;
	}

	N=atoi(argv[1]);
	C=atoi(argv[2]);

	assert(N>0&&N<100&&C<N);

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

	for(int i=0; i<N;i++){
		pthread_join(passengers_t[i],NULL);
	}
	pthread_join(car_t,NULL);

}

void load(){
	sem_wait(&empty_car);
	printf("Next %d get in\n",C);
	sleep(2);
	for(int i=0;i<C;i++){
		sem_post(&boarding);
	}
}

void run(){
	sem_wait(&full_car);
	printf("Here we go! :D\n");
	printf(".\n");
	sleep(1);
	printf("..\n");
	sleep(1);
	printf("...\n");
	sleep(1);
	printf("wow... such fun :D\n");
	sleep(1);
}

void unload(){
	printf("Now, everyone out...\n");
	sleep(1);
	for(int i=0;i<C;i++){
		sem_post(&unboarding);
	}
}

void *car(){
	while(1){
		load();
		run();
		unload();
	}
}

void board(int id){
	sem_wait(&mut);
	pInCar++;
	printf("passenger %d boarding...\n", id);
	if(pInCar==C) sem_post(&full_car);
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