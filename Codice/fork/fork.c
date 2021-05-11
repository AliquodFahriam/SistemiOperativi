#include <stdio.h>
#include <unistd.h> 
int main (void){

	pid_t pid; 
	printf("main program id is %d\n", (int) getpid());
	
	pid = fork();
	
	if (pid == 0) {
		printf("Child process\n");
		printf("C: Child process ID is %d\n", (int)getpid());
	
	}
	else{
		printf("Parent process\n");
		printf("P; parent ID is %d\n", (int)getpid());
		printf("P: child id is: %d\n", (int)pid); 


	} 

	//sleep(1); //non si usa mai e non bisogna utilizzarlo mai, lo usiamo soltanto perché  ci permette di tornare alla bash. 
	//Questa cosa però rallenta il sistema operativo perché costringe il sistema operativo ad aspettare il tempo indicato prima di uccidere il processo
	//Viene eseguito sia dal padre che dal figlio e prima di fare il return entrambi attendono per un certo periodo
	//
	return 0; 





}
