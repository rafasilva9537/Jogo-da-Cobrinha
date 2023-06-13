#include <stdio.h>

#define TAMANHO_COBRA 50

struct posicao{
  int x;
  int y;
};
typedef struct posicao posicao; //nomeia struct para que não seja preciso ficar escrevendo struct posicao toda vez que for utilizar, apenas posicao (ou outro nome que eu queira usar)

int main() {
  posicao cobra; //usando struct
  cobra.x = 0;
  cobra.y = 5;
  
  posicao corpo1;
  corpo1.x = 1;
  corpo1.y = 6;
  
  printf("Coordenadas da cobra = (%d, %d)\n", cobra.x, cobra.y);
  printf("Coordenadas do corpo 1 (%d, %d)\n", corpo1.x, corpo1.y);
  
  return 0;
}