#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>
#include <signal.h>

int main(){ 

	pid_t pid1; 
	pid_t pid2; 

	int buffer1; 
	int buffer2; 

	int child_status1; 
	int child_status2; 

	int fd1[2]; 
	int fd2[2]; 

	pipe(fd1); 
	pipe(fd2); 

	int n; 

	pid1 = fork(); 

	if (pid1 == -1 ){ 

		printf("Errore FORK\n");
		exit(0); 
	}

	if(pid1 == 0){ 

		printf("f1: Closing output\n");
		close(fd1[0]); 

		

		while (1){ 
			printf("Inserisci un numero valido (0-31)\n");
			scanf("%d", &n); 
			if(n >= 0 && n <=31){ 
				break;
			}
			printf("Hai inserito il numero sbagliato\n");
		}

		write(fd1[1], &n, sizeof(n));


	}else{ 

		pid2 = fork(); 

		if(pid2 == 0){ 

			close(fd2[1]); 
			read(fd2[0], &buffer2, sizeof(buffer2)); 
			printf("f2: Ricevuto numero %d\n",buffer2 );

			pid_t pid_processo; 
			printf("Inserisci il pid del processo a cui vuoi inviare il signal\n");
			scanf("%d", &pid_processo);

			kill(pid_processo, buffer2);
			printf("Sending to PID %d\n",(int)pid_processo );



		}else{ 

			close(fd1[1]); 
			close(fd2[0]); 

			read(fd1[0], &buffer1, sizeof(buffer1)); 
			printf("P:Ricevuto numero %d \n",buffer1);
			write(fd2[1], &buffer1, sizeof(buffer1)); 

		}





	}

	wait(&child_status1); 
	wait(&child_status2);



}