#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main (void){ 

	pid_t pid1; 
	int child_status1;
	int child_status2; 
	//Creiamo la pipe 
	int buffer;

	int fd[2]; 
	pipe(fd); 

	pid_t pid2; 
	int buffer2; 
	int fd2[2]; 
	pipe(fd2); 

	pid1 = fork(); 

	if (pid1 == -1) { 
		printf("fork error\n");
	}

	if (pid1 == 0 ){ 
		printf("f1:Closing pipe input\n");
		close(fd[1]);

		printf("f1:Receiving\n");
		read(fd[0],&buffer, sizeof(buffer));
		printf("F1: received pid_padre %d\n",buffer);

		//f1 to f2 
		printf("F1: Closing pipe2 output\n");
		close(fd2[0]); 
		write(fd2[1], &buffer, sizeof(buffer));



	}else{ 
		
		pid2 = fork(); 

		if (pid2 == 0){ 
			printf("f2:Closing pipe input\n");
			close(fd2[1]);

			printf("f2:Receiving\n");
			read(fd2[0],&buffer2, sizeof(buffer2));
			printf("f2: received pid_padre %d\n",buffer2);

			
		

		}else{ 



			printf("P: Closing pipe output\n");
			close(fd[0]); 

			int pidpadre = (int) getpid();

			printf("P: Sending PID to child \n");
			write(fd[1], &pidpadre, sizeof(pidpadre));
			printf("PID PADRE : %d\n", pidpadre );

			
		}
		
	}
	wait(&child_status1);

	wait(&child_status2);
}