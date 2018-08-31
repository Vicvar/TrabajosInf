#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct mblock memblock;

struct mblock {
  size_t size;
  memblock *next;
  memblock *prev;
  void *mip;
  int free;
  int magic; 
};

#define B_SIZE sizeof(memblock)

memblock * block;

void dispList(){
	memblock * aux=block;
	printf("\n");
	while(aux!=NULL){
		printf("mip=%p size=%d free=%d\n",aux->mip,(int)aux->size,aux->free);
		aux=aux->next;
	}
}

void * myMalloc(int nbytes){
	memblock * aux=block;
	while(!(aux->free && aux->size>=nbytes)){
		aux=aux->next;
		if(aux==NULL){
			printf("\nno hay memoria!\n");
			return (void *) -1;
		}
	}

	if(aux->size>=nbytes + B_SIZE){
		memblock * newb=aux + B_SIZE + nbytes;
		newb->size=aux->size - nbytes - B_SIZE;
		newb->next=aux->next;
		newb->prev=aux;
		newb->mip=newb;
		newb->free=1;
		newb->magic=0x12345678;

		aux->size=nbytes;
		aux->next=newb;
		aux->free=0;
		aux->magic=0x77777777;
	}
	else{
		aux->free=0;
		aux->magic=0x77777777;
	}

}

void myFree(void * mip){
	memblock * aux=block;
	while(aux->mip != mip){
		aux=aux->next;
		if(aux==NULL){
			printf("\nbloque no encontrado!\n");
			return;
		}
	}
	aux->free=1;
	aux->magic=0x12345678;

	if(aux->prev!=NULL && aux->next!=NULL){
		if(aux->prev->free==1 && aux->next->free==1){
			aux->prev->size=aux->prev->size + 2*B_SIZE + aux->size + aux->next->size;
			aux->prev->next=aux->next->next;
			if(aux->next->next!=NULL) aux->next->next->prev=aux->prev;
		}
		else if(aux->prev->free==1){
			aux->prev->size=aux->prev->size + B_SIZE + aux->size;
			aux->prev->next=aux->next;
			aux->next->prev=aux->prev;
		}
		else if(aux->next->free==1){
			aux->size=aux->size + B_SIZE + aux->next->size;
			if(aux->next->next!=NULL) aux->next->next->prev=aux;
			aux->next=aux->next->next;
		}
	}

	else if(aux->prev!=NULL){
		if(aux->prev->free==1){
			aux->prev->size=aux->prev->size + B_SIZE + aux->size;
			aux->prev->next=aux->next;
		}
	}

	else if(aux->next!=NULL){
		if(aux->next->free==1){
			aux->size=aux->size + B_SIZE + aux->next->size;
			if(aux->next->next!=NULL) aux->next->next->prev=aux;
			aux->next=aux->next->next;
		}
	}
}

int main(int argc, char * argv[]){
	
	block=sbrk(0);
	
	if(argc!=2){
		printf("uso ./tarea nbytes\n");
		return 1;
	}

	int nbytes = atoi(argv[1]);
	
	void *request = sbrk(nbytes + B_SIZE);
	if (request == (void*) -1) return 1;
	
	block->size = nbytes;
	block->next = NULL;
	block->prev = NULL;
	block->free = 1;
	block->mip = block;
	block->magic = 0x12345678;

	printf("\n1.- asignar memoria\n");
	printf("2.- liberar memoria\n");
	printf("3.- ver lista\n");
	printf("4.- salir\n\n");

	int op=0;
	void * mip;
	int newalloc;
	scanf("%d",&op);
	while(op!=4){
	
	
		switch(op){
			case 1:{
				printf("\ncantidad de memoria a asignar:\n\n");
				scanf("%d",&newalloc);
				myMalloc(newalloc);
				break;
			}
			case 2:{
				printf("\ningresar mip:\n\n");
				scanf("%p",&mip);
				myFree((void *)mip);
				break;
			}
			case 3:{
				dispList();
				break;
			}
		}

		printf("\n1.- asignar memoria\n");
		printf("2.- liberar memoria\n");
		printf("3.- ver lista\n");
		printf("4.- salir\n\n");
		scanf("%d",&op);
	}
}
