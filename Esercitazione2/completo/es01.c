#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct arraystore{ 
	int array[10];
	int sumeven; 
	int sumUneven; 
}; 

void* sumeven(void* args){

	struct arraystore* array = (struct arraystore*) args;  

	for (int i = 0; i<10; i++){

		if( (i%2) == 0 ){ 
			(array->sumeven) += (array->array[i]); 
		}

	}

	return (void*) &(array->sumeven);



}

void* sumUneven(void* args){ 

	struct arraystore* array = (struct arraystore*) args; 
	

	for (int i = 0; i < 10; i++){ 

		if ((i%2) != 0){ 
			(array->sumUneven)+= (array->array[i]); 
		}

	} 

	return (void*) &(array->sumUneven); 
}

int main(){ 

	pthread_t thread1; 
	pthread_t thread2; 

	int* threadreturn1; 
	int* threadreturn2; 

	struct arraystore threadargs; 
	threadargs.sumeven = 0; 
	threadargs.sumUneven = 0; 


	//Array initializing 
	for (int i=0; i < 10; i++){ 
		threadargs.array[i] = i; 
	}
				//Thread ID, NULL, funzione, argomenti funzione
	pthread_create(&thread1, NULL, &sumeven, &threadargs); 
	pthread_create(&thread2, NULL, &sumUneven, &threadargs); 

	pthread_join(thread1, (void**) &threadreturn1); 
	pthread_join(thread2, (void**) &threadreturn2);

	printf("La somma dei numeri in posizione pari è %d\n", threadargs.sumeven);
	printf("La somma dei numeri in posizione dispari è %d\n", *threadreturn2);


}