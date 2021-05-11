#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

struct resistenze{
	float resistenza1;
	float resistenza2; 
	float parallelo; 
	float serie; 
};


void* parallelo(void* args){ 

	struct resistenze* x = (struct resistenze*) args; 
	//calcoliamo il parallelo come

	x->parallelo = (x->resistenza1*x->resistenza2)/(x->resistenza1 + x->resistenza2); 

	return (void*) &(x->parallelo); 


}

void* serie(void* args){ 

	struct resistenze* x = (struct resistenze*) args;
	x->serie = x->resistenza1+x->resistenza2; 

	return (void*) &(x->serie); 

}




int main () { 

	
	pthread_t thread1;
	pthread_t thread2;

	float* returnvalue1; 
	float* returnvalue2; 



	printf("L'utente deve inserire due numeri per le resistenze\n");


	struct resistenze resistenze; 
	resistenze.parallelo = 0; 
	resistenze.serie = 0; 

	printf("Inserisci il valore della prima resistenza: \n");
	scanf("%f", &resistenze.resistenza1); 

	printf("Inserisci il valore della seconda resistenza\n");
	scanf("%f", &resistenze.resistenza2); 

	pthread_create(&thread1, NULL, &parallelo, &resistenze); 
	pthread_create(&thread2, NULL, &serie, &resistenze); 

	pthread_join(thread1, (void**)&returnvalue1); 
	pthread_join(thread2, (void**)&returnvalue2); 

	printf("Il valore del parallelo è %f\n",*returnvalue1 );
	printf("Il valore della serie è %f\n",*returnvalue2 );




}