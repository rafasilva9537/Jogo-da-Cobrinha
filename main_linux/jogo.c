//usar system("clear") para limpar o cmd toda execução
//urban peguin: site para printar letras com cores no cmd
#include <stdio.h>
#include <string.h>
#include <unistd.h> //mudar biblioteca <dos.h> para <unistd.h> no linux
#include <stdlib.h>
#include <termios.h>

#define LINHAS 10
#define COLUNAS 32+1

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
  sprintf(mapa[6], "|-----*------------------------|");
  sprintf(mapa[7], "|------------------------------|");
  sprintf(mapa[8], "|------------------------------|");
  sprintf(mapa[9], ":==============================:");

  //criando personagem
  char cobra = '@';
  //coordenadas iniciais do personagem
  int x = 5;
  int y = 3;
  mapa[x][y] = cobra;   

  
  //ATIVANDO RAW MODE!
  tcgetattr(STDIN_FILENO, &terminal_original); //pega atributos do terminal e coloca na struct

  struct termios raw = terminal_original; //struct que irá receber os atributos modificados do terminal
  //ECHO é reponsável por printar cada tecla digitada no terminal
  raw.c_lflag &= ~(ECHO | ICANON); //DESLIGANDO ECHO. DESLIGANDO MODO CANONICO. Pesquisar mais, operações binárias e uso do ECHO
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1; //Pula input após 1/10 de segundo (100 milésimos)

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); //Aplica atributos modificados da struct raw no terminal. TCSAFLUSH especifica quando aplicar as mudanças


  do {  
    system("clear"); //mudar comando "cls" para "clear" no linux
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
            mapa[x][y] = '-'; //apagar rastro da cobra
            x--;
            break;
        case 's':
            mapa[x][y] = '-';
            x++;
            break;
        case 'a':
            mapa[x][y] = '-';
            y--;
            break;
        case 'd':
            mapa[x][y] = '-';
            y++;
            break;
        default:
            continue;
    }
    if(mapa[x][y]=='=' || mapa[x][y]=='|'){
        printf("Colidiu com a parede!\n");
        break;
    } 
    mapa[x][y] = '@';

    usleep(100000);
  } while(1);

  //Desativas raw mode. Aplica atributos originais do terminal
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal_original);
  
  printf("Fim de jogo! Tente novamente");

  return 0;
}