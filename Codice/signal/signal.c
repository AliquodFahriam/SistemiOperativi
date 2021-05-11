#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void sigint(); 
void sigterm(); 
void sigcont();
int main (){
	
	//Sigint produce un interrupt simile a quello prodotto dalla tastiera quando premiamo ctrl+c 
	//sigstop consente di interrompere l'esecuzione di un processo con la possibilità di poterlo riprendere quando si vuole 
	//sigstop aspetta sigcont per far riprendere il processo
	//SIGSTOP NON PUÒ ESSERE INTERCETTATO O IGNORATO, in sostanza non può essere gestito. 
	//sigterm richiede la terminazione di un processo (può quindi essere ignorato a differenza di sigstop)
	//sigkill non può essere gestito o ignorato, il processo termina e basta, non può nemmeno effettuare operazioni di cleanup

	printf("---Test is rugging\n");

	while (1){

		//signal has two params 
		//-sig to be handled
		//-handler function
		signal(SIGINT, sigint); 
		signal(SIGTERM, sigterm); 
		signal(SIGCONT, sigcont); 


	}
	
	return 0;
} 


void sigint(){

	printf("---received SIGINT\n");
	exit(0); 

}

void sigterm(){

	printf("---received SIGTERM\n");
	exit(0); //provare con e senza 

}
void sigcont(){

	printf("---received SIGCONT\n");

}

