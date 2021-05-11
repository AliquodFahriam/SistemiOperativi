#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
  pid_t pid;
  printf("id del programma principale: %d\n", (int) getpid());
  pid=fork();

  if (pid==0){
    sleep(5);
    printf("processo figlio\n");
    printf("F: id = %d\n", (int)getpid());
  } else{
    printf("processo padre\n");
    printf("P: id p= %d\n", (int) getpid());
    printf("P: id f= %d\n", (int) pid);
    //sleep(2);
  }

  return 0;
}
