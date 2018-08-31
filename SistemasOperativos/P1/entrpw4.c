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
	pid_t pid;
	while(1){
		int p[20];
		for(int i=0;i<10;i++){
			pipe(&p[2*i]);
		}
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
		printf("pcount: %d\n", pcount);
		//fork exec dup
		if(pcount>1){
			for(int i=0;i<pcount;i++){
				pid=fork();
				if(pid==0){
					printf("comando:%s, i=%d, in:p[%d], out:p[%d]\n",pipes[i],i,2*(i-1),i*2+1);
					if(i==0){
						dup2(p[1],STDOUT_FILENO);
					}
					else if(i==pcount-1){
						dup2(p[2*(i-1)],STDIN_FILENO);
					}
					else{
						dup2(p[2*(i-1)],STDIN_FILENO);
						dup2(p[i*2+1],STDOUT_FILENO);
					}
					for(int j=0;j<20;j++){
						close(p[j]);
					}
					execvp(command[i][0],command[i]);
				}
				else if(pid>0){
					//waitpid(-1,&st,0);
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

		pcount=0;
		ccount=0;
	}
}
