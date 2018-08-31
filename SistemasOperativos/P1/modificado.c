#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>

char buffer[50];
char *command[20][20],*pipes[20];
int ccount=0,pcount=0;
char *token;


int main(int argc, char *argv[]){

	while(1){
		int st;
		pid_t pid;
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
			/* pipea todos los elementos excepto el ultimo */
  			int i = 0, in = STDIN_FILENO; 	/* primer comando lee de stdin */
  			for ( ; i < pcount - 1; ++i) {
    			int fd[2];
    			pipe(fd);
    			pid=fork();

    			if (pid == 0) {  			//hijo
      				close(fd[0]); 
      				if (in != STDIN_FILENO) {
    					dup2(in, STDIN_FILENO);
    					close(in);
    				}
  					if (fd[1] != STDOUT_FILENO) {
    					dup2(fd[1], STDOUT_FILENO);
      					close(fd[1]); /* successfully redirected */
  					}
					execvp(command[i][0], command[i]);
    			}

    			else if(pid > 0) { 			//padre
      				assert (pid > 0);
      				close(fd[1]); 
      				close(in);
      				in = fd[0]; /* the next command reads from here */
    			}	
    		
    			else printf("error en fork\n");
  			}

  			if (in != STDIN_FILENO) {
    			dup2(in, STDIN_FILENO);
 			}
 			execvp(command[i][0], command[i]);
 			printf("imprime porfa\n");
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
