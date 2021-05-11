#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int status;
	pid_t pid;

	printf("--start process %d\n", (int)getpid());

	pid = fork();

	if (pid == 0){
		//sono nel processo figlio
		printf("F: Processo figlio\n");
		printf("F: id figlio %d\n", (int) 	getpid());
	} else {
		//sono nel processo padre
		printf("P: Processo padre\n");
		printf("P: id padre %d\n", (int) getpid());
		printf("P: id figlio %d\n", pid);
	}

	wait(&status);

	return 0;
}
