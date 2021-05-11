#include<stdio.h>
#include<unistd.h>

int main(void){

    printf("Il mio PID è: %d\n", (int)getpid());
    printf("Il PID del mio genitore è %d\n", (int)getppid());


}