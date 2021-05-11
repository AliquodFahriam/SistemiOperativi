#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <time.h>
int main(void){ 

	pid_t pid;
	int child_status;
	int child_status2;
	pid_t pid2; 

	int buffer; 
	int fd1[2]; 
	int fd2[2];
	int buffer2;

	pipe(fd1); 
	pipe(fd2);
	int num;
	pid = fork(); 

	if(pid == 0){ 
		close(fd1[0]);
		srand(time(NULL));
		num = (rand()%101);
		printf("%d\n",num );
		write(fd1[1],&num, sizeof(int));

	}
	if (pid > 0) { 

		
		pid2 = fork(); 
		if(pid2 == 0){

			close(fd2[1]);
			read(fd2[0], &buffer2, sizeof(int));
			printf("Il contenuto del buffer è %d\n", buffer2);

		}else{
			close(fd1[1]); 
			close(fd2[0]);
			read(fd1[0], &buffer, sizeof(int)); 
			printf("Il numero passato al padre è %d\n",buffer ); 
			write(fd2[1], &buffer, sizeof(int)); 

		
		}
		
		

		

	}



	wait(&child_status);
	wait(&child_status2);

}