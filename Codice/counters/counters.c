#include <stdio.h> 
#include <unistd.h> 
#include<stdlib.h> 
int main (void){

	printf("--beginning program\n");

	int counter= 0; 
	int N = 20; 
	
	pid_t pid = fork(); 
	
	if (pid == 0){ 

	//child 
	for (int i = 0; i < N; i++){
			printf("C process: counter = %d\t(%d)\n",++counter,(int)getpid());
			fflush(stdout); //clean buffer
			sleep((double)rand()/(double)RAND_MAX); //RANDOM IN 0->1


		}


	}else if(pid > 0){//Parent 

		for (int j = 0; j < N; j++){
			printf("P process: counter = %d\t(%d)\n",++counter,(int)getpid()); 
			fflush(stdout);
			//sleep((double)rand()/(double)RAND_MAX); //RANDOM IN 0->1

		}  



	
	}
	else{

		printf("fork error\n");
		return 1;

	}
	
	printf("--end of program\n"); 
	//sleep(1); 
	
	return 0;






}
