#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int chile_status;
	int fd[2];
	pid_t pid;
	
	char string[] = "ciao\n";
	char buffer[80];

	printf("l'ID del processo main è: %d\n", (int)getpid());

	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		//sono nel processo figlio
		printf("processo figlio\n");
		
		close(fd[0]);

		write(fd[1], string, (strlen(string)+1));

		exit(0);
	}
	else
	{
		//sono nel processo padre
		printf("processo padre\n");

		close(fd[1]);

		read(fd[0], buffer, sizeof(buffer));

		printf("%s", buffer);

	}

	wait(&chile_status);

	return 0;
}