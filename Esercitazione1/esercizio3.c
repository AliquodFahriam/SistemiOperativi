#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main (void){ 

	int son_status; 
	int fd[2];
	int readBuffer;
	pid_t pid;
	pipe(fd);

	pid = fork(); 

	if (pid == 0){ 

		close(fd[0]);
		printf("Closing pipe output\n");
		int pidson = (int)getpid();
		write(fd[1],&pidson,sizeof(int));

	}else{ 

		printf("P: PID = %d\n", (int)getpid() );
		close(fd[1]);
		printf("Closing pipe input\n");
		read(fd[0],&readBuffer, sizeof(int)); 
		printf("Il PID ricevuto dal figlio è: %d\n",readBuffer);
	}

	wait(&son_status);

}