#include <stdio.h>
#include <unistd.h>
#include <wait.h>
int main (void){

	int child_status; 
	pid_t pid; 
	
	int child_status2; 
	pid_t pid2;


	pid = fork(); 

	if(pid == 0){ 

		printf("Primo Figlio: pid del primo figlio: %d\n", (int)getpid());

	}else{

		printf("Processo Padre: pid del padre %d\n", (int)getpid() );

		
		pid2 = fork();

		if(pid2 == 0){

			printf("Secondo figlio: pid del secondo figlio %d\n", (int)getpid() );
		}

		wait(&child_status2);

	}

	//Il wait non distingue tra figlio 1 e 2 quindi sostanzialmente fa salvare lo stato 
	//prima di un figlio in child status 2 e poi di un figlio in child status 1
	//terminato uno dei due figli il padre continua, finito anche il secondo il padre è libero di terminare
	

	wait(&child_status); 
	 

	return 0; 

}