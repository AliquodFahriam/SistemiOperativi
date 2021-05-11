#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* print_X(void* unused){ 
while(1){
	printf("-\n");
	fflush(stdout);
	sleep(1);  
} 
return NULL; 

} 

int main(){
	pthread_t thread_id; 
	
	pthread_create(&thread_id, NULL, &print_X,NULL);
	
	while(1){ 
		printf("o\n"); 
		fflush(stdout); 
		sleep(1);
	
	} 
	
return 0; 

} 

