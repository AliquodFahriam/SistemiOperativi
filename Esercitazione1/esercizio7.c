#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
int main (void){ 

	int fd[2];
	pipe(fd); 
	char buffer; 
	int child_status;

	char stringa[] = "esempio2.c";

	pid_t pid; 

	pid = fork();
 

	if (pid == -1){ 
		printf("Fork fail\n");
	}

	if (pid == 0){ 

		printf("Closing input FD...\n");
		close(fd[1]); 

		printf("Fork Receiving\n");
		read(fd[0], &buffer, strlen(stringa)); 

		printf("Child received %s\n", &buffer);

		execl("/bin/mv","mv", "esempio.c", &buffer,(char*)0);
		//ti permette di eseguire un comando di linux

	}else{ 

		printf("Closing output FD...\n");
		close(fd[0]); 

		write(fd[1],&stringa,strlen(stringa)); 



	}



	wait(&child_status); 





} 