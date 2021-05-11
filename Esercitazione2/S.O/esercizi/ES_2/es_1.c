#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct array_dim
{
	int* array;
	int dim;
	int sum_p;
	int sum_d;
};


void* sum_p(void* parametri);
void* sum_d(void* parametri);

int main(int argc, char const *argv[])
{
	pthread_t thread1_id;
	pthread_t thread2_id;

	int* thread1_return;
	int* thread2_return;

	int a[9] = {1, 2, 1, 2, 1, 2, 1, 2, 1};

	struct array_dim thread_args;
	
	thread_args.array = a;
	thread_args.dim = 9;

	pthread_create(&thread1_id, NULL, &sum_p, &thread_args);
	pthread_create(&thread2_id, NULL, &sum_d, &thread_args);

	pthread_join(thread1_id, (void**) &thread1_return);
	pthread_join(thread2_id, (void**) &thread2_return);

	printf("Somma primo thread: %d\n", *thread1_return);
	printf("Somma secondo thread: %d\n", *thread2_return);
	printf("Somma tot: %d\n", *thread1_return + *thread2_return);

	return 0;
}

void * sum_p(void* parametri){
	struct array_dim * p = (struct array_dim *) parametri;
	
	p->sum_p=0;

	for (size_t i = 0; i < p->dim; i++)
	{	
		if (i % 2 == 0)
			p->sum_p += p->array[i];
	}

	return (void *) &(p->sum_p);
	
}

void *sum_d(void *parametri)
{
	struct array_dim *p = (struct array_dim *)parametri;

	p->sum_d = 0;

	for (size_t i = 0; i < p->dim; i++)
	{
		if (i % 2 != 0)
			p->sum_d += p->array[i];
	}

	return (void *) &(p->sum_d);
}