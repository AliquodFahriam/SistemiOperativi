#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int stato_figlio1;
	int stato_figlio2;
	pid_t pid1;
	pid_t pid2;

	printf("--start process %d\n", (int)getpid());

	pid1 = fork();

	if (pid1 == 0) {
		//primo figio
		printf("F1: PRIMO FIGLIO\n");
		printf("F1: id primo figlio %d\n", (int) getpid());
	} else {
		
		pid2 = fork();

		if (pid2 == 0) {
			printf("F2: SECONDO FIGLIO\n");
			printf("F2: id secondo figlio %d\n", (int)getpid());
		} else {
			printf("P: PROCESSO PADRE\n");
			printf("P: id padre %d\n", (int) getpid());
			printf("P: id processo primo figlio %d\n", pid1);
			printf("P: id processo secondo figlio %d\n", pid2);
		}
		
		wait(&stato_figlio2);
	}
	
	wait(&stato_figlio1);

	return 0;
}