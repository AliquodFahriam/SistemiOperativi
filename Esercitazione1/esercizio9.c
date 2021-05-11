#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
//potrebbe anche essere implementato automaticamente con 
//la soluzione di srand(time(NULL))
int main (){ 

	pid_t pid1; 
	pid_t pid2; 

	int child_status1; 
	int child_status2; 
	int buffer1; 
	int buffer2; 

	int fd1[2]; 
	int fd2[2]; 

	int count_v1; 
	int count_v2; 
	 

	pipe(fd1); 
	pipe(fd2); 

	
while (1){

	pid1 = fork(); 

	if(pid1 == -1){ 

		printf("ERRORE di FORK \n");
		return 1; 
	}

	if (pid1 == 0){ 
		int scelta1;
		printf("f1:Seleziona una delle seguenti possibilità\n");
		printf("1. Carta\n2. Forbici\n3. Pietra\n");
		
		while(1){
			
			scanf("%d", &scelta1);
			printf("\n");
			if (scelta1 <= 3 && scelta1 >= 1){ 

				break; 
			}

			printf("Hai sbagliato, inserisci un numero da 1 a 3 per continuare...\n");

		} 
		close(fd1[0]); 

		write(fd1[1], &scelta1, sizeof(scelta1)); 
		break;  



	}else{ 
		wait(&child_status1);
		
		
		pid2 = fork();
	
 		
 		if (pid2 == 0){ 
 			int scelta2;
 			
 			printf("f2:Seleziona una delle seguenti possibilità\n");
			printf("1. Carta\n2. Forbici\n3. Pietra\n");
			
			while(1){
			
				scanf("%d", &scelta2);
				printf("\n");
				if (scelta2 <= 3 && scelta2 >= 1){ 

					break; 
				}

				printf("Hai sbagliato, inserisci un numero da 1 a 3 per continuare...\n");

			} 

			printf("via\n");
			close(fd2[0]); 
			write(fd2[1], &scelta2, sizeof(scelta2));
			break; 



 		}else{ 
 			
 			wait(&child_status2);

 			
 			printf("P:controllo il vincitore...\n...\n");
 			close(fd1[1]); 
 			close(fd2[1]); 
 			read(fd1[0], &buffer1, sizeof(buffer1));
 			read(fd2[0], &buffer2, sizeof(buffer2)); 

 			if(buffer1 == buffer2){

 				printf("PARI\n");

 			} 

 			if ((buffer1 == 1 && buffer2 == 3) || (buffer1 == 2 && buffer2 == 1) || (buffer1 == 3 && buffer2 == 2) ){ 
 				printf("F1 ha  vinto!\n\n");
 				count_v1++; 
 				if (count_v1 == 2){ 
 					printf("F1 Ha vinto il match.\n");
 					break; 
 				}
 				
 			}

 			if ((buffer2 == 1 && buffer1 == 3) || (buffer2 == 2 && buffer1 == 1) || (buffer2 == 3 && buffer1 == 2)){ 
 			
 				printf("F2 ha vinto!\n\n");
 				count_v2++; 
 				if (count_v2 == 2){ 
 					printf("F2 ha vinto il match.\n");
 					break; 
 				}

 			}

 				
 			

 		}




	}
}
	
	 
	


}