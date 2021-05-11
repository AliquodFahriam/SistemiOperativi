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
		printf("processo figlio\n");
		execl("/bin/ls", "ls", "-l", (char *)0);
	}
	else
	{
		//sono nel processo padre
		printf("processo padre\n");
	}

	wait(&chile_status);

	return 0;
}