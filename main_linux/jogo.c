//usar system("clear") para limpar o cmd toda execução
//urban peguin: site para printar letras com cores no cmd
#include <stdio.h>
#include <string.h>
#include <unistd.h> //mudar biblioteca <dos.h> para <unistd.h> no linux
#include <stdlib.h>
#include <termios.h>
#include <time.h>

#define G "\x1b[32m"
#define V "\x1b[31m"
#define B "\x1b[34m"
#define E "\x1b[0m"

#define LINHAS 17
#define COLUNAS 48+1
#define TAMANHO 690

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


   strcpy(mapa[0],  "|==============================================|");           
   strcpy(mapa[1],  "|..............................................|");
   strcpy(mapa[2],  "|..............................................|");
   strcpy(mapa[3],  "|..............................................|");
   strcpy(mapa[4],  "|..............................................|");
   strcpy(mapa[5],  "|..............................................|");
   strcpy(mapa[6],  "|..............................................|");
   strcpy(mapa[7],  "|..............................................|");
   strcpy(mapa[8],  "|..............................................|");
   strcpy(mapa[9],  "|..............................................|");
   strcpy(mapa[10], "|..............................................|");
   strcpy(mapa[11], "|..............................................|");
   strcpy(mapa[12], "|..............................................|");
   strcpy(mapa[13], "|..............................................|");
   strcpy(mapa[14], "|..............................................|");
   strcpy(mapa[15], "|..............................................|");
   strcpy(mapa[16], "|==============================================|");           



  
  //fruta
  posicao fruta;
  fruta.x = 6;
  fruta.y = 6;
  mapa[fruta.x][fruta.y] = '*';
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
    printf(" "V"     Clique 'q' para sair "E" \n\n");
    for(int i = 0; i < LINHAS; i++) {
      //apagar linha atual(1), usado no lugar no system("clear") para que o jogo não oscile
      printf("\033[K");
      for(int j = 0; j < COLUNAS; j++) {
        if(mapa[i][j] == '@' || mapa[i][j] == 'X'){
          printf(""G"%c"E"", mapa[i][j]);
        }
        else{
          printf("%c", mapa[i][j]);
        }
      }
      printf("\n");
    }

    char tecla_anterior = tecla;
    read(STDIN_FILENO, &tecla, 1); //assume a função do scanf

    //sair do jogo
    if(tecla == 'q'){
      break;
    }
    //evitar andar para trás e clicar outros botões
    else if(!(tecla == 's' || tecla == 'a'|| tecla == 'd'|| tecla == 'w')){
      tecla = tecla_anterior;
    }
    else if(tecla == 'a' && tecla_anterior == 'd'){
      tecla = 'd';
    }
    else if(tecla == 'd' && tecla_anterior == 'a'){
      tecla = 'a';
    }
    else if(tecla == 'w' && tecla_anterior == 's'){
      tecla = 's';
    }
    else if(tecla == 's' && tecla_anterior == 'w'){
      tecla = 'w';
    }

    //apagar rastro da cobra
    for(int i = tamanho_atual; i > 0; i--){
      mapa[cobra[i].x][cobra[i].y] = '.';
      cobra[i].x = cobra[i-1].x; //...4,3,2,1 = ...3,2,1,0
      cobra[i].y = cobra[i-1].y;
    }
    
    //movimentação
    switch(tecla){
      case 'w':
        cobra[0].x--;
        break;
      case 's':
        cobra[0].x++;
        break;
      case 'a':   
        cobra[0].y--;
        break;
      case 'd':       
        cobra[0].y++;
        break;
    }
    
    //comer fruta
    if(cobra[0].x == fruta.x && cobra[0].y == fruta.y){
      srand(time(0));
      int posicaox_aleatoria = (rand()%8)+1;
      int posicaoy_aleatoria = (rand()%30)+1;
      
      fruta.x = posicaox_aleatoria;
      fruta.y = posicaoy_aleatoria;

      tamanho_atual++;

      //evitar que corpo novo fique com posicao (0,0)
      cobra[tamanho_atual].x = cobra[tamanho_atual-1].x;
      cobra[tamanho_atual].y = cobra[tamanho_atual-1].y;
    }

    //colisão com parede (precisa estar antes de definir corpo)
    if(mapa[cobra[0].x][cobra[0].y]== '=' || mapa[cobra[0].x][cobra[0].y]=='|'){  
      printf(" \n");
      printf(B              "Você colidiu com a parede! "E" \n");
      break;
    } 
    
    mapa[fruta.x][fruta.y] = '*'; //definir fruta no mapa
    mapa[cobra[0].x][cobra[0].y] = '@'; //definir cabeça no mapa
    //definir corpo da cobra no mapa
    for(int i = tamanho_atual; i > 0; i--){
      mapa[cobra[i].x][cobra[i].y] = 'X';
    }

    //colisão com próprio corpo (precisar estar depois de definir corpo)
    if(mapa[cobra[0].x][cobra[0].y]=='X'){
      printf("Você colidiu com o próprio corpo!\n");
      break;
    } 

    usleep(95000); //velocidade do jogo
  } while(1);

  //Desativas raw mode. Aplica atributos originais do terminal
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal_original);
  printf(" \n");
  printf(V"Fim de jogo! Tente novamente "E" \n");
  printf(" \n");
  printf("\033[?25h"); //mostrar cursor do terminal

  return 0;
}
