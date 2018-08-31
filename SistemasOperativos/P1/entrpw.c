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
	int npipe=0;
	pid_t pid;
	while(1){
		int p[4];
		pipe(p);
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
			for(int i=0;i<pcount;i++){
				pid=fork();
				if(pid==0){
					if(i==0){
						close(p[0]);
						dup2(p[1],1);
					}
					else if(i==1){
						if(i!=pcount-1){
							close(p[1]);
							close(p[2]);
							dup2(p[0],0);
							dup2(p[3],1);
						}
						else{	
							close(p[1]);
							close(p[2]);
							close(p[3]);
							dup2(p[0],0);
						}
					}
					else{
						if(i!=pcount-1){
							if(npipe){
								dup2(p[2],p[0]);
								dup2(p[1],p[3]);
								npipe=0;
							}else{
								dup2(p[0],p[2]);
								dup2(p[3],p[1]);
								npipe=1;
							}
						}
						else{
							if(npipe){
								dup2(1,p[1]);
							}
							else{
								dup2(1,p[3]);
							}
						}
					}
					execvp(command[i][0],command[i]);
				}
				else if(pid>0){}
				else{
					printf("error en fork\n");
				}
			}
			for(int i=0;i<pcount-1;i++){
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
		printf("%d %s %s\n",pcount,pipes[0],command[0][0]);
		//for next loop
		for(int i=0;i<=pcount;i++){
			free(pipes[i]);
			pipes[i]=NULL;
		}
		for(int i=0;i<=pcount;i++){
			for(int j=0;command[i][j]!=NULL;j++){
				free(command[i][j]);
				command[i][j]=NULL;
			}
		}

		pcount=0;
		ccount=0;
		npipe=0;
	}
}
