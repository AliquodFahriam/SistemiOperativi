#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct circafacile
{
	int numeri[6]; 
	char caratteri[4];  
};

void* numeriInit(void* args){ 

	struct circafacile* x = (struct circafacile*) args; 
	srand(time(NULL));

	for (int i = 0; i<6 ; i++){ 

		x->numeri[i]= (rand()%10); 

	}

	return (void*) &(x->numeri); 

}
void* charInit(void* args){ 

	struct circafacile* x = (struct circafacile*) args; 
	srand(time(NULL)); 

	for(int i = 0; i < 4; i++){ 

		x->caratteri[i] = 97+(rand()%26); 	//Nella tabella ASCII sappiamo che l'alfabeto
		//varia dal numero 97 a 122...

	}

	return (void*) &(x->caratteri);

}



int main(){ 

	pthread_t pid1; 
	pthread_t pid2; 

	struct circafacile threadargs;

	int* valorediritorno1;
	char* valorediritorno2; 

	pthread_create(&pid1,NULL, &numeriInit, &threadargs); 
	pthread_create(&pid2,NULL, &charInit, &threadargs);

	pthread_join(pid1, (void**)&valorediritorno1); 
	pthread_join(pid2, (void**)&valorediritorno2);

	char arraysperiamo[10]; 
	int k = 0;
	int j = 0;

	for (int i = 0; i < 10; i++){ 

		if(i == 2 ||i == 3 || i == 7|| i == 6){ 
		 	arraysperiamo[i] = valorediritorno2[k];
		 	k++; 
		}else{
			//48 è zero in ascii
			arraysperiamo[i] = 48+valorediritorno1[j]; 
			j++; 

		}

	}

	printf("%s\n",arraysperiamo);
	//printf("%s\n",threadargs.caratteri);





}