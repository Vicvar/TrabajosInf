#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

char buffer[50];
char *command[15];
int ccount=0;
char *token;

int main(int argc, char *argv[]){
	int st;
	pid_t pid;
	while(1){
		printf("shellG4>");
		fgets(buffer,50,stdin);
		token=strtok(buffer," \n");
		while(token!=NULL){
			command[ccount]=(char *)malloc(sizeof(token));
			strcpy(command[ccount],token);
			token = strtok(NULL," \n");
			ccount++;
		}
		ccount=0;
		pid=fork();
		if(pid==0){
			execvp(command[0],command);
		}
		else if(pid>0){
			waitpid(-1,&st,0);
		}
		else{
			printf("error en fork\n");
		}
		for(int i=0;command[i]!=NULL;++i){
			free(command[i]);
			command[i]=NULL;
		}
	}
}
