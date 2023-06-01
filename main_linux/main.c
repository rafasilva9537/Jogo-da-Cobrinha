#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Cores
#define G "\x1b[32m"
#define Y "\x1b[33m"
#define R "\x1b[31m"
#define B "\x1b[34m"
#define E "\x1b[0m"

int main() {
  
int opcao = 0;
  while(1) {
    system("clear");
    usleep(55000);
printf(G "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"E"\n");
    usleep(55000);
printf(G "█                                                                               █"E"\n");
    usleep(55000);
printf(G " █           ▄█▀▀▀█▄█                         ▀███                             █"E"\n");
    usleep(55000);
printf(G "█           ▄██    ▀█                           ██                              █"E"\n"); 
    usleep(55000);
printf(G " █           ▀███▄     ▀████████▄     ▄█▀██▄    ██  ▄██▀    ▄▄█▀▀█▄            █"E"\n");
    usleep(55000);
printf(G "█              ▀█████▄   ██    ██    ██   ██    ██ ▄█      ▄█▀   ██             █"E"\n");
    usleep(55000);
printf(G " █           ▄     ▀██   ██    ██     ▄█████    ██▄██      ██▀▀▀▀▀▀            █"E"\n");
    usleep(55000);
printf(G "█            ██     ██   ██    ██    ██   ██    ██ ▀██▄    ██▄   ▄▄             █"E"\n");
    usleep(55000);
printf(G " █           ▀██████▀  ▄████  ████  ▄████▀██▄  ████▄ ██▄▄  ▀██████▀            █"E"\n");
    usleep(55000);
printf(G "█                                                                               █"E"\n"); 
    usleep(55000);
printf(G "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"E"\n");
    
    printf("                                                                             \n");
    usleep(356000);
    printf(Y"                                1 - Novo jogo                                "E"\n");
    printf("                                                                             \n");
    printf(Y"                                2 - Como Jogar                               "E"\n");
    printf("                                                                             \n");
    printf(Y"                                3 - Creditos                                 "E"\n");
    printf("                                                                             \n");
    printf(R"                                0 - Sair do jogo                             "E"\n");
    scanf("%i", &opcao);
    getchar();

   switch(opcao){
     case 1: {
     //jogo inicia aqui
       break; }
     
     case 2: {
       
       printf("1 - controles");
       case 4: {
         
       printf("\n");
       printf("Controles\n");
       printf("\n");
       usleep(55000);
       printf("W - Para cima\n");
       usleep(55000);
       printf("S - Para baixo\n");
       usleep(55000);
       printf("D - Para a direita\n");
       usleep(55000);
       printf("A - Para a esquerda\n"); 
       printf("\n");
       break; }
         
       break; }


     case 3: {
       printf("\n");
       printf(G"Jogo Snake - versão 1.0 early"E"\n");
       printf(Y"Language C edition!"E"\n");
       printf("\n");
       printf(B"Feito por Davi e Rafael"E"\n");
       printf("\n"); 
    break; }
     
     case 0:
     break;
     default: printf(R"Opção inválida!!"E"\n");
   } 

    printf(G"Precione enter para continuar.." E "\n");
    getchar();

    if (opcao == 0) {
      break;
    } 
  }
  return 0;
}