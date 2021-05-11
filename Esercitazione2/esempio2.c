#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

struct print_params
{
	char character; 
	int times; 
};

void* print_char(void* parameters){ 

	struct print_params* pp = (struct print_params*) parameters;

	for (int i = 0; i <= pp->times; i++){ 
		printf("%c\n",pp->character);
		fflush(stdout); 
		sleep(1); 
	}

	return NULL; 
}

int main(){ 
	pthread_t thread1_id; 
	pthread_t thread2_id; 

	struct print_params thread1_args; 
	struct print_params thread2_args;

	thread1_args.character = 'X'; 
	thread2_args.character = 'O'; 

	thread1_args.times = 20; 
	thread2_args.times = 30;

	pthread_create(&thread1_id, NULL, &print_char, &thread1_args);
	pthread_create(&thread2_id, NULL, &print_char, &thread2_args); 

	pthread_join(thread1_id, NULL); 
	pthread_join(thread2_id, NULL); 

	return 0; 

}

