#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int status_child1;
	int status_child2;
	int x;
	int buffer;

	pid_t pid1;
	pid_t pid2;

	int fd1[2];
	int fd2[2];

	pipe(fd1);
	pid1 = fork();

	if (pid1 == 0){
		//primo figlio
		printf("processo figlio 1 scrive....\n");
		close(fd1[0]);

		srand(time(NULL));
		x = (int) (rand() % 101);
		printf("F1: %d\n", x);

		write(fd1[1], &x, sizeof(x));

	} else {
		pipe(fd2);
		pid2 = fork();

		if (pid2 == 0) {
			//secondo figlio
			printf("processo figlio 2 legge...\n");
			close(fd2[1]);

			read(fd2[0], &buffer, sizeof(buffer));

			printf("F2: %d\n", buffer);

		} else {
			//padre
			printf("processo padre legge....\n");
			close(fd1[1]);

			read(fd1[0], &buffer, sizeof(buffer));
			printf("P: %d\n", buffer);

			printf("processo padre scrive....\n");
			close(fd2[0]);

			write(fd2[1], &buffer, sizeof(buffer));

		}
		
		wait(&status_child2);
	}

	wait(&status_child1);

	return 0;
}
