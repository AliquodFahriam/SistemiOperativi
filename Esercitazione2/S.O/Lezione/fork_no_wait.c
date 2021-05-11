#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  printf("l'ID del processo main è: %d\n", (int) getpid());
  pid_t pid;
  pid = fork();

  if (pid == 0){
    //sono nel processo figlio
    //sleep(1);
    printf("processo figlio\n");
    printf("F: ID figlo: %d\n", (int) getpid());
  } else{
    //sono nel processo padre
    printf("processo padre\n");
    printf("P: ID padre: %d\n", (int) getpid());
    printf("P: ID figlo: %d\n", pid);
  }
  return 0;
}
