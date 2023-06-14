//usar system("clear") para limpar o cmd toda execução
//urban peguin: site para printar letras com cores no cmd
#include <stdio.h>
#include <string.h>
#include <unistd.h> //mudar biblioteca <dos.h> para <unistd.h> no linux
#include <stdlib.h>
#include <termios.h>

#define LINHAS 10
#define COLUNAS 32+1
#define TAMANHO 210

struct posicao {
  int x;
  int y;
};
typedef struct posicao posicao;

struct termios terminal_original;

int main() {
  //criando mapa
  char mapa[LINHAS][COLUNAS];

  sprintf(mapa[0], ":==============================:");
  sprintf(mapa[1], "|------------------------------|");
  sprintf(mapa[2], "|------------------------------|");
  sprintf(mapa[3], "|------------------------------|");
  sprintf(mapa[4], "|------------------------------|");
  sprintf(mapa[5], "|------------------------------|");
  sprintf(mapa[6], "|------------------------------|");
  sprintf(mapa[7], "|------------------------------|");
  sprintf(mapa[8], "|------------------------------|");
  sprintf(mapa[9], ":==============================:");

  //fruta
  posicao fruta;
  fruta.x = 6;
  fruta.y = 6;
  //criando cobra
  posicao cobra[TAMANHO];
  //coordenadas iniciais do personagem
  int tamanho_atual = 2; //serve para criar corpo da cobra em loops de forma automática
  cobra[0].x = 5;
  cobra[0].y = 3;
  cobra[1].x = 5;
  cobra[1].y = 4;
  cobra[2].x = 5;
  cobra[2].y = 5;
  mapa[cobra[0].x][cobra[0].y] = '@';
  mapa[cobra[1].x][cobra[1].y] = 'X';
  mapa[cobra[2].x][cobra[2].y] = 'X';
  
  //ATIVANDO RAW MODE!
  tcgetattr(STDIN_FILENO, &terminal_original); //pega atributos do terminal e coloca na struct

  struct termios raw = terminal_original; //struct que irá receber os atributos modificados do terminal
  //ECHO é reponsável por printar cada tecla digitada no terminal
  raw.c_lflag &= ~(ECHO | ICANON); //DESLIGANDO ECHO. DESLIGANDO MODO CANONICO. Pesquisar mais, operações binárias e uso do ECHO
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1; //Pula input após 1/10 de segundo (100 milésimos)

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); //Aplica atributos modificados da struct raw no terminal. TCSAFLUSH especifica quando aplicar as mudanças


  do {
    system("clear");
    
    //imprimir mapa
    for(int i = 0; i < LINHAS; i++) {
        printf("%s\n", mapa[i]);
    }
    
    //comando de movimento
    char tecla;
    read(STDIN_FILENO, &tecla, 1); //assume a função do scanf

    
    //movimentação
    switch(tecla){
      case 'w':
        for(int i = tamanho_atual; i > 0; i--){
          mapa[cobra[i].x][cobra[i].y] = '-';
          int j = i-1;
          cobra[i].x = cobra[j].x; //i= 5,4,3...
          cobra[i].y = cobra[j].y; //j= 4,3,2...
        }
        
        mapa[cobra[0].x][cobra[0].y] = '-'; //apagar rastro da cobra
        cobra[0].x--;
        break;
      case 's':
        for(int i = tamanho_atual; i > 0; i--){
          mapa[cobra[i].x][cobra[i].y] = '-';
          int j = i-1;
          cobra[i].x = cobra[j].x;
          cobra[i].y = cobra[j].y;
        }
        
        mapa[cobra[0].x][cobra[0].y] = '-';
        cobra[0].x++;
        break;
      case 'a':
        for(int i = tamanho_atual; i > 0; i--){
          mapa[cobra[i].x][cobra[i].y] = '-';
          int j = i-1;
          cobra[i].x = cobra[j].x;
          cobra[i].y = cobra[j].y;
        }
        
        mapa[cobra[0].x][cobra[0].y] = '-';
        cobra[0].y--;
        break;
      case 'd':
        for(int i = tamanho_atual; i > 0; i--){
          mapa[cobra[i].x][cobra[i].y] = '-';
          int j = i-1;
          cobra[i].x = cobra[j].x;
          cobra[i].y = cobra[j].y;
        }
        
        mapa[cobra[0].x][cobra[0].y] = '-';
        cobra[0].y++;
        break;
      default:
        continue;
    }
    //comer fruta
    if(cobra[0].x == fruta.x && cobra[0].y == fruta.y){
      fruta.x = 3;
      fruta.y = 15;
      tamanho_atual++;
    }

    //colisão com parede (precisa estar antes de printar corpo)
    if(mapa[cobra[0].x][cobra[0].y]=='=' || mapa[cobra[0].x][cobra[0].y]=='|'){
      printf("Você colidiu com a parede!\n");
      break;
    } 
    
    mapa[fruta.x][fruta.y] = '*'; //printar fruta no mapa
    mapa[cobra[0].x][cobra[0].y] = '@'; //printar cabeça no mapa
    //printar corpo da cobra no mapa
    for(int i = tamanho_atual; i > 0; i--){
      mapa[cobra[i].x][cobra[i].y] = 'X';
    }

    //colisão com próprio corpo (precisar estar depois de printar corpo)
    if(mapa[cobra[0].x][cobra[0].y]=='X'){
      printf("Você colidiu com o próprio corpo!\n");
      break;
    } 

    usleep(100000); //velocidade do jogo
  } while(1);

  //Desativas raw mode. Aplica atributos originais do terminal
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal_original);
  
  printf("Fim de jogo! Tente novamente\n");
  printf("O tamanho atual é: %d\n", tamanho_atual);

  return 0;
}