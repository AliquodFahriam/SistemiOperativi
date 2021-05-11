#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

struct element
{
	char* number;
	char* letter;
};

void * create_num(void* parameter);
void * create_let(void* parameter);
char * concat(char* first, char* second);

int main(int argc, char const *argv[])
{
	pthread_t thread1;
	pthread_t thread2;

	char* thread1_return;
	char* thread2_return;

	struct element thread_args;

	pthread_create(&thread1, NULL, &create_let, &thread_args);
	pthread_create(&thread2, NULL, &create_num, &thread_args);

	pthread_join(thread1, (void **) &thread1_return);
	pthread_join(thread2, (void **) &thread2_return);

	printf("string1: %s\n", thread1_return);
	printf("string2: %s\n", thread2_return);

	char* result = concat(thread2_return, thread1_return);

	printf("result = %s\n", result);


	return 0;
}

void * create_let(void * parameter){
	srand(time(NULL));

	char alfabet[21] ={'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'};
	struct element * el = (struct element *) parameter;

	el->letter = (char *)malloc(sizeof(char) * 4);

	for(int i=0; i<4; i++){
		int r = rand() % 21;
		el->letter[i] = alfabet[r];
	}

	return (void *) (el->letter); 
}

void * create_num(void * parameter){
	srand(time(NULL));

	struct element * el = (struct element *) parameter;

	el->number = (char *)malloc(sizeof(char) * 6);

	for (int i = 0; i < 6; i++){
		int r = rand() % 10;
		char c = r + '0';
		el->number[i] = c;
	}

	return (void *) (el->number);
}

char * concat(char * first, char * second){
	char * result;

	result = (char *)malloc(sizeof(char) * 10);
	
	result[0] = first[0];
	result[1] = first[1];
	result[2] = second[0];
	result[3] = second[1];
	result[4] = first[2];
	result[5] = first[3];
	result[6] = second[2];
	result[7] = second[3];
	result[8] = first[4];
	result[9] = first[5];

	return result;
}
