#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(void){
//Bisogna passare l'indirizzo di child status al wait per far terminare correttamente il programma
	int child_status; 
	

	pid_t pid; 
	pid = fork();

	if(pid == -1 ){
		printf("errore"); 
		return 1; 
	}


	if (pid == 0){
		printf("Processo figlio: l'id del processo figlio è %d\n", (int)getpid());

	}else{

		printf("Processo padre: l'id del processo padre è %d\n", (int)getpid());

	}




	wait(&child_status);
	return 0;





}