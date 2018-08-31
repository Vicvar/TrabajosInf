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
	int st, pipe2=0;
	pid_t pid;
	while(1){
		int p1[2],p2[2];
		pipe(p1);
		pipe(p2);
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
					/*close(p1[1]);
					close(p1[0]);
					close(p2[1]);
					close(p2[0]);
					*/
					if(i==0){
						dup2(p1[1],STDOUT_FILENO);
					}
					else if(i==pcount-1){
						if(!pipe2){
							dup2(p1[0],STDIN_FILENO);
						}
						else{
							dup2(p2[0],STDIN_FILENO);
						}
					}
					else{
						if(!pipe2){
							pipe(p2);
							dup2(p1[0],STDIN_FILENO);
							dup2(p2[1],STDOUT_FILENO);
							close(p1[0]);
							close(p1[1]);
							close(p2[0]);
							close(p2[1]);
							pipe2=1;
						}
						else{
							pipe(p1);
							dup2(p2[0],STDIN_FILENO);
							dup2(p1[1],STDOUT_FILENO);
							close(p1[0]);
							close(p1[1]);
							close(p2[0]);
							close(p2[1]);
							pipe2=0;
						}
					}
					execvp(command[i][0],command[i]);
				}
				else if(pid>0){
					waitpid(-1,&st,0);
				}
				else{
					printf("error en fork\n");
				}
			}
			/*for(int i=0;i<pcount;i++){
				waitpid(-1,&st,0);
			}*/
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
		pipe2=0;
		pcount=0;
		ccount=0;
	}
}
