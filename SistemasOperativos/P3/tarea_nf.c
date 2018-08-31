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

memblock * block;//"head"
memblock * nextfp;//puntero para iniciar la busqueda del nodo con el espacio pedido

void dispList(){
	//despliega la lista
	memblock * aux=block;
	printf("\n");
	while(aux!=NULL){
		printf("H=%p mip=%p size=%d free=%d next=%p prev=%p\n",aux,aux->mip,(int)aux->size,aux->free,aux->next,aux->prev);
		aux=aux->next;
	}
}

void * myMalloc(int nbytes){
	//busca el siguiente nodo vacio con suficiente espacio, partiendo de nextfp que es una variable global.
	memblock * aux=nextfp;

	//!!no sale del cilclo si hay un solo nodo y se pide mas memoria de la que hay
	while(!(aux->free && aux->size>=nbytes)){
		aux=aux->next;
		if(aux==NULL){
			aux=block;
			if(block->next==NULL){
				printf("\nno hay memoria!\n");
				return (void *) -1;
			}
		}
		else if(aux==nextfp){
			printf("\nno hay memoria!\n");
			return (void *) -1;
		}
		printf("%p\n", nextfp);
	}

	//si el nodo encontrado tiene mas espacio del pedido, se crea otro nodo vacio. Si tiene mas espacio pero no
	//el suficiente para crear otro encabezado, o justo el espacio pedido, solo cambia el nodo ya existente
	if(aux->size >= nbytes + B_SIZE){
		memblock * newb=aux + B_SIZE + nbytes;
		newb->size=aux->size - nbytes - B_SIZE;
		newb->next=aux->next;
		newb->prev=aux;
		newb->mip=newb + B_SIZE;
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

	//modifica la variable global para partir desde aqui la proxima vez
	nextfp=aux;

	//correccion
	return aux->mip;
}

void myFree(void * mip){
	//busca?? el nodo con la direccion dada y lo libera.(quizas se podria haber hecho aux=mip)
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

	//merge y se asegura que no se pierda el nextfp
	if(aux->prev!=NULL && aux->next!=NULL){
		if(aux->prev->free==1 && aux->next->free==1){
			if(nextfp==aux || nextfp==aux->next) nextfp=aux->prev;
			aux->prev->size=aux->prev->size + 2*B_SIZE + aux->size + aux->next->size;
			aux->prev->next=aux->next->next;
			if(aux->next->next!=NULL) aux->next->next->prev=aux->prev;
		}
		else if(aux->prev->free==1){
			if(nextfp==aux) nextfp=aux->prev;
			aux->prev->size=aux->prev->size + B_SIZE + aux->size;
			aux->prev->next=aux->next;
			aux->next->prev=aux->prev;
		}
		else if(aux->next->free==1){
			if(nextfp==aux->next) nextfp=aux;
			aux->size=aux->size + B_SIZE + aux->next->size;
			if(aux->next->next!=NULL) aux->next->next->prev=aux;
			aux->next=aux->next->next;
		}
	}

	else if(aux->prev!=NULL){
		if(aux->prev->free==1){
			if(nextfp==aux) nextfp=aux->prev;
			aux->prev->size=aux->prev->size + B_SIZE + aux->size;
			aux->prev->next=aux->next;
		}
	}

	else if(aux->next!=NULL){
		if(aux->next->free==1){
			if(nextfp==aux->next) nextfp=aux;
			aux->size=aux->size + B_SIZE + aux->next->size;
			if(aux->next->next!=NULL) aux->next->next->prev=aux;
			aux->next=aux->next->next;
		}
	}
}

int main(int argc, char * argv[]){
	//se pide memoria y se inicializa el primer nodo vacio, que tiene toda la memoria. se inicializa el nextfp.
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
	block->mip = block + B_SIZE;
	block->magic = 0x12345678;

	nextfp=block;

	//menu
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
		//printf("%p\n", nextfp);
		scanf("%d",&op);
	}
}
