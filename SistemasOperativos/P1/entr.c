#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char buffer[50];
char *commands[10];
int ccount=0,i=0;
char *token;

int main(int argc, char *argv[]){
	fgets(buffer,50,stdin);
	token=strtok(buffer," \n");
	while(token!=NULL){
		commands[ccount]=(char *)malloc(sizeof(token));	
		strcpy(commands[ccount],token);
		token = strtok(NULL," \n");
		ccount++;
	}
	for(int i=0;i<ccount;i++){
		printf("%s\n",commands[i]);
	}
}
