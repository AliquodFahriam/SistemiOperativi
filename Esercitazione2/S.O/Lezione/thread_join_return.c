#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct print_params
{
	char character;
	int times;
};

void *print_char(void *unused);

int main(int argc, char const *argv[])
{
	pthread_t thread1_id;
	pthread_t thread2_id;

	int* thread1_retirnValue;
	int* thread2_retirnValue;

	struct print_params thread1_args;
	struct print_params thread2_args;

	thread1_args.character = 'X';
	thread1_args.times = 20;

	thread2_args.character = 'O';
	thread2_args.times = 30;

	pthread_create(&thread1_id, NULL, &print_char, &thread1_args);
	pthread_create(&thread2_id, NULL, &print_char, &thread2_args);

	pthread_join(thread1_id, (void **) &thread1_retirnValue);
	pthread_join(thread2_id, (void **) &thread2_retirnValue);

	puts("");

	printf("thread1: %d\n", *thread1_retirnValue);
	printf("thread2: %d\n", *thread2_retirnValue);

	return 0;
}

void *print_char(void *parameters)
{
	struct print_params *pp = (struct print_params *)parameters;

	for (int i = 0; i <= pp->times; i++)
	{
		printf("%c", pp->character);
		fflush(stdout);
		sleep(1);
	}
	return (void *) &(pp->times);
}