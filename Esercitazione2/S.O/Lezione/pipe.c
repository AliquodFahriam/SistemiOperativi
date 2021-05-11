#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int fd[2];
	char buffer[5];

	if (pipe(fd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	char* message = "ciao\0";

	write(fd[1], message, 5);

	read(fd[0], buffer, 5);
	
	printf("%s\n", buffer);

	return 0;
}
