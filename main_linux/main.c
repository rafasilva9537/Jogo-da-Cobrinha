#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define G "\x1b[32m"
#define Y "\x1b[33m"
#define R "\x1b[31m"
#define B "\x1b[34m"
#define E "\x1b[0m"

int main() 
{
  
  while (1) {

      system("clear");
        usleep(55000);
        printf(G "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄"
                 "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄" E "\n");
        usleep(55000);
        printf(G "█                                                                "
                 "               █" E "\n");
        usleep(55000);
        printf(G " █           ▄█▀▀▀█▄█                         ▀███               "
                 "              █" E "\n");
        usleep(55000);
        printf(G "█           ▄██    ▀█                           ██               "
                 "               █" E "\n");
        usleep(55000);
        printf(G " █           ▀███▄     ▀████████▄     ▄█▀██▄    ██  ▄██▀    "
                 "▄▄█▀▀█▄            █" E "\n");
        usleep(55000);
        printf(G "█              ▀█████▄   ██    ██    ██   ██    ██ ▄█      ▄█▀   "
                 "██             █" E "\n");
        usleep(55000);
        printf(G " █           ▄     ▀██   ██    ██     ▄█████    ██▄██      "
                 "██▀▀▀▀▀▀            █" E "\n");
        usleep(55000);
        printf(G "█            ██     ██   ██    ██    ██   ██    ██ ▀██▄    ██▄   "
                 "▄▄             █" E "\n");
        usleep(55000);
        printf(G " █           ▀██████▀  ▄████  ████  ▄████▀██▄  ████▄ ██▄▄  "
                 "▀██████▀            █" E "\n");
        usleep(55000);
        printf(G "█                                                                "
                 "               █" E "\n");
        usleep(55000);
        printf(G "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀"
                 "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" E "\n");
    
        printf("                                                                   "
               "          \n");
    
        printf("                                                                   "
               "          \n");
        usleep(56000);
        printf(Y "                                1 - Novo jogo                    "
                 "            " E "\n");
        printf("                                                                   "
               "          \n");
        printf(Y "                                2 - Como Jogar                   "
                 "            " E "\n");
        printf("                                                                   "
               "          \n");
        printf(Y "                                3 - Creditos                     "
                 "            " E "\n");
        printf("                                                                   "
               "          \n");
    
        // consertar as cores que estão dando erro de compilação.
    
        printf(                                                                /*R*/
               "                           0 - Sair do jogo                  " /*E*/
               "\n");
        
        int opcao = -1 ;
        scanf("%i", &opcao);
        getchar();
        
        
    
        
        switch (opcao) {
        case 1:{
           system("clear");
           // jogo inicia aqui
           getchar();
          break; 
          }
          
          case 2: {
          while (1) {
            system("clear");
            
            printf("1 - Controles\n");
            printf("2 - Regras\n");
            printf("0 - Voltar\n");
            
            int opcao = -1;
            scanf("%i", &opcao);
            getchar();
            if (opcao == 0) break;
    
            
              switch (opcao) {
              case 1:
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
                  usleep(55000);
                  printf("\n");
                  printf("0 - para voltar\n");
                  getchar();
              break;
                
              case 2:
                  printf("regras\n");
                  printf("0 - para voltar\n");
                  getchar();
              break;
              }
            }     
          }  
          break; //break do case 2
          case 0: system("clear");
          
        }
  
  if (opcao == 0) break;
  
  } 
}  
  
      
        /*case 3:          //outro submenu (nada haver com a opçao 2)
          while(1) {
          system("clear");
          printf("\n");
          printf(G "Jogo Snake - versão 1.0 early" E "\n");
          printf(Y "Language C edition!" E "\n");
          printf("\n");
          printf(B "Feito por Davi e Rafael" E "\n");
          printf("\n");
          printf("0 - para voltar\n");
            
          int pcao = -1;
          scanf("%i", &opcao);
          getchar(); 
          break;
          
     
         }*/
   
  
  // 1º while          // if (opcao == 0) break;     
  
  
    

    


