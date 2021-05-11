#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[])
{	
	int chile_status;

	pid_t pid;
	printf("l'ID del processo main è: %d\n", (int)getpid());

	pid = fork();

	if (pid == 0)
	{
		//sono nel processo figlio
		sleep(5);
		printf("processo figlio\n");
		printf("F: ID figlo: %d\n", (int)getpid());
	}
	else
	{
		//sono nel processo padre
		printf("processo padre\n");
		printf("P: ID padre: %d\n", (int)getpid());
		printf("P: ID figlo: %d\n", pid);
	}

	wait(&chile_status);

	return 0;
}