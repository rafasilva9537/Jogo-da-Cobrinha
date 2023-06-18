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
  system("clear");
  
  //criando mapa
  char mapa[LINHAS][COLUNAS];

  strcpy(mapa[0], ":==============================:");
  strcpy(mapa[1], "|------------------------------|");
  strcpy(mapa[2], "|------------------------------|");
  strcpy(mapa[3], "|------------------------------|");
  strcpy(mapa[4], "|------------------------------|");
  strcpy(mapa[5], "|------------------------------|");
  strcpy(mapa[6], "|------------------------------|");
  strcpy(mapa[7], "|------------------------------|");
  strcpy(mapa[8], "|------------------------------|");
  strcpy(mapa[9], ":==============================:");

  //fruta
  posicao fruta;
  fruta.x = 6;
  fruta.y = 6;
  //criando cobra
  posicao cobra[TAMANHO];
  //coordenadas iniciais do personagem
  int tamanho_atual = 2; //serve para criar corpo da cobra em loops de forma automática
  cobra[0].x = 5;
  cobra[0].y = 5;
  cobra[1].x = 5;
  cobra[1].y = 4;
  cobra[2].x = 5;
  cobra[2].y = 3;
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

  //comando de movimento
  char tecla = 'd';
  do {
    printf("\033[1;1H"); //move o cursor do terminal para linha 1, coluna 1
    printf("\033[?25l"); //esconder cursor do terminal

    //imprimir mapa
    for(int i = 0; i < LINHAS; i++) {
      //apagar linha atual(1), usado no lugar no system("clear") para que o jogo não oscile
      printf("\033[K");
      for(int j = 0; j < COLUNAS; j++) {
        printf("%c", mapa[i][j]);
      }
      printf("\n");
    }

    char tecla_anterior = tecla;
    read(STDIN_FILENO, &tecla, 1); //assume a função do scanf

    //evitar andar para trás/colidir com próprio corpo
    if(tecla == 'a' && tecla_anterior == 'd'){
      tecla = 'd';
    }
    if(tecla == 'd' && tecla_anterior == 'a'){
      tecla = 'a';
    }
    if(tecla == 'w' && tecla_anterior == 's'){
      tecla = 's';
    }
    if(tecla == 's' && tecla_anterior == 'w'){
      tecla = 'w';
    }
    
    //movimentação
    switch(tecla){
      case 'w':
        //apagar rastro da cobra
        for(int i = tamanho_atual; i > 0; i--){
          mapa[cobra[i].x][cobra[i].y] = '-';
          cobra[i].x = cobra[i-1].x; //...4,3,2,1 = ...3,2,1,0
          cobra[i].y = cobra[i-1].y;
        }
        
        cobra[0].x--;
        break;
      case 's':
        for(int i = tamanho_atual; i > 0; i--){
          mapa[cobra[i].x][cobra[i].y] = '-';
          cobra[i].x = cobra[i-1].x;
          cobra[i].y = cobra[i-1].y;
        }
        
        cobra[0].x++;
        break;
      case 'a':   
        for(int i = tamanho_atual; i > 0; i--){
          mapa[cobra[i].x][cobra[i].y] = '-';
          cobra[i].x = cobra[i-1].x;
          cobra[i].y = cobra[i-1].y;
        }
        
        cobra[0].y--;
        break;
      case 'd':       
        for(int i = tamanho_atual; i > 0; i--){
          mapa[cobra[i].x][cobra[i].y] = '-';
          cobra[i].x = cobra[i-1].x;
          cobra[i].y = cobra[i-1].y;
        }
        
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

      //evitar que corpo novo fique com posicao (0,0)
      cobra[tamanho_atual].x = cobra[tamanho_atual-1].x;
      cobra[tamanho_atual].y = cobra[tamanho_atual-1].y;
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

    usleep(90000); //velocidade do jogo
  } while(1);

  //Desativas raw mode. Aplica atributos originais do terminal
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal_original);
  
  printf("Fim de jogo! Tente novamente\n");
  printf("O tamanho atual é: %d\n", tamanho_atual);
  printf("\033[?25h"); //mostrar cursor do terminal

  return 0;
}