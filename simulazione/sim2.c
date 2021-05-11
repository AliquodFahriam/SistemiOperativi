#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#include <string.h>

struct arraydigitalpha
{
	int countalpha; 
	int countdigit; 

	char str[10]; 
};

void* digit(void* args){ 

	struct arraydigitalpha* x = (struct arraydigitalpha*) args; 
	//printf("%d\n",(int)strlen(x->str));
	for (int i = 0; i < 10; i++){ 

		if (isdigit(x->str[i])){ 

			(x->countdigit)++; 
			printf("Il carattere numerico trovato è %c\n", x->str[i] );

		}

	}

	return (void*) &(x->countdigit); 

}
void* alpha (void* args){ 

	struct arraydigitalpha* x = (struct arraydigitalpha*) args; 

	for (int i = 0 ; i<10; i++ ){ 

		if (isalpha(x->str[i])){ 

			(x->countalpha)++; 
			printf("Il carattere alfabetico trovato è %c\n",x->str[i] );

		}

	}  

	return (void*) &(x->countalpha); 
}

int main(){ 

	pthread_t thread1; 
	pthread_t thread2; 

	int* returnvalue1;
	int* returnvalue2; 

	struct arraydigitalpha threadargs; 

	threadargs.countalpha = 0; 
	threadargs.countdigit = 0; 

	char stringa[10] = "a1b2c3d4e5"; 

	for(int i = 0; i < 10; i++){ 

		threadargs.str[i] = stringa[i];
		//printf("%c\n",threadargs.str[i]);


	}
	//printf("%d\n",(int) strlen( threadargs.str));

	pthread_create(&thread1, NULL, &digit, &threadargs);
	pthread_create(&thread2, NULL, &alpha, &threadargs); 

	pthread_join(thread1, (void**)&returnvalue1); 
	pthread_join(thread2, (void**)&returnvalue2); 

	printf("Il numero di valori alfabetici è %d\n",*returnvalue2);
	printf("Il numero di valori numerici è %d\n",*returnvalue1);







}