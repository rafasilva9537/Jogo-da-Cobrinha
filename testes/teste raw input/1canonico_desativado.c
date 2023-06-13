#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //função read()
#include <termios.h> //terminal configurações

struct termios terminal_original;

void desativarRawMode(){
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &terminal_original); //Desativas raw mode. Aplica atributos originais do terminal
}

void ativarRawMode() {
  tcgetattr(STDIN_FILENO, &terminal_original); //pega atributos do terminal e coloca na struct
  atexit(desativarRawMode); //executa função na saída do programa (PRECISA SE MUDADO, SEM USO DE FUNÇÕES!!!)

  struct termios raw = terminal_original; //struct que irá receber os atributos modificados do terminal
  //ECHO é reponsável por printar cada tecla digitada no terminal
  raw.c_lflag &= ~(ECHO | ICANON); //DESLIGANDO ECHO. DESLIGANDO MODO CANONICO. Pesquisar mais, operações binárias e uso do ECHO

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); //Aplica atributos modificados da struct raw no terminal. TCSAFLUSH especifica quando aplicar as mudanças
}

int main() {
  ativarRawMode();
  
  char c;
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
    printf("Sua letra é: %c\n", c); //loop para ler caracteres de 1 byte que não sejam a letra "q"
  }
  
  return 0;
}