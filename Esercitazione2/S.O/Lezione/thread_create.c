#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* print_x(void* unused);

int main(int argc, char const *argv[])
{
	pthread_t thread_id;
	
	pthread_create (&thread_id, NULL, &print_x, NULL);

	while (1)
	{
		printf(("*\n"));
		fflush(stdout);
		sleep(1);
	}

	return 0;
}

void *print_x(void *unused){
	while (1)
	{
		printf(("-\n"));
		fflush(stdout);
		sleep(3);
	}
	
}
