//si scriva un programma, sia in C che in java, che dato un array A di n interi
//sfrutti due thread distinti per calcolare rispettivamente la somma di tutti i
//numeri di posizione pari e di tutti i numeri di posizione dispari

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

struct stampa_parametri_thread{
	int numero[10];
	int somma;
	int somma1;
	 	
};  

void *sommaPari (void* parameters) 
{
	struct stampa_parametri_thread* pp = (struct stampa_parametri_thread*) parameters;
	
	
	
	
	for(int i=0;i<=9;i++){
		
		if(i%2==0){
			pp->somma+=pp->numero[i];
			
		}
	}
	
	
	
	return (void*) &(pp->somma);
	
}

void *sommaDispari (void* parameters) 
{
	struct stampa_parametri_thread* pp = (struct stampa_parametri_thread*) parameters;
	
	
	
	
	for(int i=0;i<=9;i++){
		
		if(i%2==1){
			pp->somma1+=pp->numero[i];
			
		}
	}
	
	
	
	return (void*) &(pp->somma1);
	
}

int main(){
	
	pthread_t thread1_id;
	pthread_t thread2_id; 
	
	int* thread1_ritornoValore;
	int* thread2_ritornoValore;
	
	struct stampa_parametri_thread thread_argomento;
	
	thread_argomento.somma=0;
	thread_argomento.somma1=0;
	
	
	for(int j=0; j<10; j++){
		if(j%2==0){
			thread_argomento.numero[j]=2;
		}else{
			thread_argomento.numero[j]=1;
		}
	}
		
		
	
	 
	

	pthread_create(&thread1_id, NULL, &sommaPari, &thread_argomento);
	pthread_create(&thread2_id, NULL, &sommaDispari, &thread_argomento);
	
	pthread_join(thread1_id, (void**) &thread1_ritornoValore);
	pthread_join(thread2_id, (void**) &thread2_ritornoValore);
	
	
	printf("\n Value returned by Thread 1 is: %d\n", *thread1_ritornoValore);
	printf("\n Value returned by Thread 2 is: %d\n", *thread2_ritornoValore);
	
	
	return 0;
}
	
