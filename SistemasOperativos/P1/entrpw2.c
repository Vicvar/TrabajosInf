#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

char buffer[50];
char *command[20][20],*pipes[20];
int ccount=0,pcount=0;
char *token;


int main(int argc, char *argv[]){
	int st;
	int p[20];
	int npipe=0;
	pipe(p);
	pid_t pid;
	while(1){
		//read n parse
		printf("shellG4>");
		fgets(buffer,50,stdin);
		token=strtok(buffer,"|\n");
		while(token!=NULL){
			pipes[pcount]=(char *)malloc(sizeof(token));
			strcpy(pipes[pcount],token);
			token=strtok(NULL,"|\n");
			pcount++;
		}
		for(int i=0;i<pcount;i++){
			token=strtok(pipes[i]," \n");
			while(token!=NULL){
				command[i][ccount]=(char *)malloc(sizeof(token));
				strcpy(command[i][ccount],token);
				token = strtok(NULL," \n");
				ccount++;
			}
		ccount=0;
		}
		//fork exec dup
		if(pcount>1){
			for(int i=0;i<=pcount;i++){
				pid=fork();
				if(pid==0){
					if(i==0){
						dup2(p[2],1);
					}
					else if(i==pcount-1){
						if(i%2==0){
							dup2(p[i+1],
					execvp(command[i][0],command[i]);
				}
				else if(pid>0){
				}
				else{
					printf("error en fork\n");
				}
			}
			for(int i=0;i<pcount;i++){
				waitpid(-1,&st,0);
			}
		}
		else{
			//fork n exec 
			pid=fork();
			if(pid==0){
				execvp(command[0][0],command[0]);
			}
			else if(pid>0){
				waitpid(-1,&st,0);
			}
			else{
				printf("error en fork\n");
			}
		}
		//for next loop
		for(int i=0;i<pcount;i++){
			free(pipes[i]);
			pipes[i]=NULL;
		}
		for(int i=0;i<pcount;i++){
			for(int j=0;command[i][j]!=NULL;++j){
				free(command[i][j]);
				command[i][j]=NULL;
			}
		}

		pcount=0;
		ccount=0;
		npipe=0;
	}
}
