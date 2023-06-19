#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define G "\x1b[32m" 
#define Y "\x1b[33m"
#define V "\x1b[31m"
#define B "\x1b[34m"
#define E "\x1b[0m"


int main() {
  while (1) {
    system("clear");
    printf(V "Ajuste seu terminal deixando o titulo abaixo centralizado aos lados! :) " E "\n");
        printf(G "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"
                 "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄" E "\n");

    usleep(55000);
        printf(G "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"
                 "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄" E "\n");
        usleep(60000);
        printf(G "█                                                                "
                 "               █" E "\n");
        usleep(70000);
        printf(G " █           ▄█▀▀▀█▄█                         ▀███               "
                 "              █" E "\n");
        usleep(80000);
        printf(G "█           ▄██    ▀█                           ██               "
                 "               █" E "\n");
        usleep(90000);
        printf(G " █           ▀███▄     ▀████████▄     ▄█▀██▄    ██  ▄██▀    "
                 "▄▄█▀▀█▄            █" E "\n");
        usleep(80000);
        printf(G "█              ▀█████▄   ██    ██    ██   ██    ██ ▄█      ▄█▀   "
                 "██             █" E "\n");
        usleep(70000);
        printf(G " █           ▄     ▀██   ██    ██     ▄█████    ██▄██      "
                 "██▀▀▀▀▀▀            █" E "\n");
        usleep(60000);
        printf(G "█            ██     ██   ██    ██    ██   ██    ██ ▀██▄    ██▄   "
                 "▄▄             █" E "\n");
        usleep(50000);
        printf(G " █           ▀██████▀  ▄████  ████  ▄████▀██▄  ████▄ ██▄▄  "
                 "▀██████▀            █" E "\n");
        usleep(40000);
        printf(G "█                                                                "
                 "               █" E "\n");
        usleep(30000);
        printf(G "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"
                 "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" E "\n");
        printf(G "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"
                 "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄" E "\n");
    
        printf("                                                                   "
               "          \n");
    
        printf("                                                                   "
               "          \n");

        usleep(155000); 
        printf(Y"                                1 - Novo jogo                "E"    \n");
        usleep(155000);
        printf("                                                                 \n");
        usleep(155000);
        printf(Y"                                2 - Como Jogar               "E"   \n");
        usleep(155000);
        printf("                                                                 \n");     
        usleep(155000);
        printf(Y"                                3 - Creditos                 "E"    \n");
        usleep(155000);
        printf("                                                                 \n");
        usleep(155000);
        printf(V"                                0 - Sair do jogo             "E"    \n");

      
    int opcao = -1;
    scanf("%i", &opcao);
    getchar();
    
    switch (opcao){
      case 1:{
        system("clear");
           // jogo inicia aqui
           getchar();
          break;  
      }    
    }

    
        switch (opcao) {
          case 2: {
          while (1) {
            system("clear");
            printf("                                                                 \n");
            usleep(155000);
            printf(Y"                                   1 - Controles                    "E"  \n");          
            printf("                                                                 \n");
            usleep(155000);
            printf(Y"                                   2 - Regras                       "E"  \n");
            printf("                                                                 \n");
            usleep(155000);
            printf(V"                                   0 - Voltar                       "E"  \n");
            printf("                                                                 \n");
            
            int opcao = -1;
            scanf("%i", &opcao);
            getchar();
            if (opcao == 0) break;
    



            
              switch (opcao) {
              case 1:
                system("clear");
                  printf("\n");
                  printf(Y"                               Controles                     "E"   \n");
                  printf("\n");
                  printf("\n");
                  usleep(55000);
                  printf(B"                             W - Para cima                   "E"   \n");
                  printf("\n");
                  usleep(55000);
                  printf(B"                             S - Para baixo                  "E"   \n");
                  printf("\n");
                  usleep(55000);
                  printf(B"                             D - Para a direita              "E"   \n");
                  printf("\n");
                  usleep(55000);
                  printf(B"                             A - Para a esquerda             "E"   \n");
                  printf("\n");
                  usleep(55000);
                  printf("\n");
                  printf(V"                             0 - Para voltar                 "E"     \n");
                  getchar();
              break;



                
              case 2:
                system("clear");
                  printf(Y"                              Regras                        "E"    \n");
                  printf("\n");
    printf(B"1º para começar, basta movimentar em uma das teclas para a cobrinha se movimentar."E"\n");
                printf("\n");
    printf(B"2º evite bater nas bordas do mapa e no próprio corpo."E"\n");
                printf("\n");
    printf(B"3º Lembre-se, o movimento da cobra é constante, ela nunca irá parar!"E"\n");
                printf("\n");
    printf(B"4º A sua pontuação aumenta ao longo em que voce vai comendo as frutinhas, ao mesmo tempo o seu corpo aumenta."E"\n");
                  printf("\n");
                  printf(V"                         0 - para voltar                   "E"     \n");
                  printf("\n");
                  getchar();
              break;
              }
            }     
          } //esse é o fim do menu 2
            
          break; //break do case 2
          case 0: system("clear");
          break;
        }


    

        switch (opcao) {
          case 3:  
          while (1) {
          system("clear");
          printf("\n");
          printf(G "Jogo Snake - versão 1.0 early "E"\n");
          printf(Y "Language C edition! "E"\n");
          printf("\n");
          printf(B "Feito por Davi e Rafael "E"\n");
          printf("\n");
          printf(V"0 - para voltar "E"\n");
          int opcao = -1;
          scanf("%i", &opcao);
          getchar();
          if (opcao == 0) break;
          }
          break;
    }

    
  
    if (opcao == 0) break;
  
  } 

  
}