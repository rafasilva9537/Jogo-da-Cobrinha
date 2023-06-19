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

  int matriz[10][10];
  matriz[0][0] = 52;
  matriz[0][1] = 1;
  matriz[0][2] = 32;
  matriz[0][3] = 69;
  matriz[1][0] = 46;
  matriz[1][1] = 81;
  matriz[1][2] = 51;
  matriz[1][3] = 74;
  matriz[2][0] = 851;
  matriz[2][1] = 8;
  matriz[2][2] = 21;
  matriz[2][3] = 47;
  matriz[3][0] = 647;
  matriz[3][1] = 51;
  matriz[3][2] = 35;
  matriz[3][3] = 3;

  /*printf("A posicao da cabeça é = (%d, %d)\n", cobra[0].x, cobra[0].y);
  printf("A posicao do corpo 1 é = (%d, %d)\n", cobra[0].x, cobra[0].y);
  printf("A posicao do corpo 1 é = (%d, %d)\n", cobra[1].x, cobra[1].y);
  printf("A posicao do corpo 1 é = (%d, %d)\n", cobra[2].x, cobra[2].y);
  printf("A posicao do corpo 1 é = (%d, %d)\n", cobra[3].x, cobra[3].y);*/
  printf("Valor da matriz é: %d\n", matriz[cobra[0].x++][cobra[0].y += 2]);
  
  
  return 0;
}