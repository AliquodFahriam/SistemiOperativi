#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sigint();
void sigterm();
void sigcont();

int main(int argc, char const *argv[])
{
	printf("--test is runnung\n");

	while (1)
	{
	signal(SIGINT, sigint);
	signal(SIGTERM, sigterm);
	signal(SIGCONT, sigcont);
	}
	
	
	return 0;
}

void sigint(){
	printf("--recived SIGINT\n");
	exit(0);
}

void sigterm(){
	printf("--recived SIGTERM\n");
	exit(0);
}

void sigcont()
{
	printf("--recived SIGCONT\n");
}