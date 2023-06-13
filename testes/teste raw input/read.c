#include <stdio.h>
#include <unistd.h>

int main() {
  int letra;

  read(STDIN_FILENO, &letra, 1);
  printf("Letra: %c", letra);
  
  return 0;
}