#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_COBRA 50

struct posicao{
  int x;
  int y;
};
typedef struct posicao posicao; //nomeia struct para que não seja preciso ficar escrevendo struct posicao toda vez que for utilizar, apenas posicao (ou outro nome que eu queira usar)

int main() {
  posicao cobra[TAMANHO_COBRA];

  cobra[0].x = 0;
  cobra[0].y = 1;
  cobra[1].x = 0;
  cobra[1].y = 2;
  cobra[2].x = 1;
  cobra[2].y = 2;
  cobra[3].x = 1;
  cobra[3].y = 3;
  

  printf("A posicao da cabeça é = (%d, %d)\n", cobra[0].x, cobra[0].y);
  printf("A posicao do corpo 1 é = (%d, %d)\n", cobra[0].x, cobra[0].y);
  printf("A posicao do corpo 1 é = (%d, %d)\n", cobra[1].x, cobra[1].y);
  printf("A posicao do corpo 1 é = (%d, %d)\n", cobra[2].x, cobra[2].y);
  printf("A posicao do corpo 1 é = (%d, %d)\n", cobra[3].x, cobra[3].y);
  
  
  return 0;
}