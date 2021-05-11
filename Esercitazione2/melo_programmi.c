//Si scriva un programma, sia in C che in Java, che sfrutti 2
//diversi thread per la generazione casuale di una stringa di 10 caratteri:
// il thread A fornisce in output 6 valori numerici nel range [0,9];
// in thread B fornisce in output 4 caratteri alfabetici minuscoli (a...z);
//La stringa finale sarà ottenuta concatenando a coppie i risultati dei 
//thread A e B, ad esempio 15ad36gt78
//#include <grep.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/timeb.h>

struct stampa_parametri_thread{
	
	char grep[10];
	
	 	
};

void *casualeNumeri (void* parameters) 
{
	srand(time(NULL));
	
	struct stampa_parametri_thread* pp = (struct stampa_parametri_thread*) parameters;
	
	for(int i=0;i<=9;i++){
		
		if(i!=2 && i!=3 && i!=6 && i!=7){
			pp->grep[i]=48+rand()%10;
		}
		
		
		
		
	}
	
	
	return NULL;
	
}

void *casualeCaratteri (void* parameters) 
{
	srand(time(NULL));
	
	struct stampa_parametri_thread* pp = (struct stampa_parametri_thread*) parameters;
	
	//sleep(1);
	for(int i=0;i<=9;i++){
		
		if(i==2 || i==3 || i==6 || i==7){
			pp->grep[i]=97+rand()%26;

		}
		
		//printf("%c", pp->grep[i]);
		
		
	}
	
	
	return NULL;
	
}


int main(){
	pthread_t thread1_id;
	pthread_t thread2_id;
	
	int* thread1_ritornoValore;
	int* thread2_ritornoValore;
	
	
	struct stampa_parametri_thread thread_argomento;
	
	pthread_create(&thread1_id, NULL, &casualeNumeri, &thread_argomento);
	pthread_create(&thread2_id, NULL, &casualeCaratteri, &thread_argomento);
	
	
	pthread_join(thread1_id, NULL);
	pthread_join(thread2_id, NULL);
	
	for (int k = 0; k <= 9; k++){
		printf("%c",thread_argomento.grep[k]);
	}

	printf("\n");
	return 0;


}
