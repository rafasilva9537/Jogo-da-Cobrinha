#include <stdio.h>
#include <string.h>
#include <dos.h>

int main() {
    //abrindo arquivo
    FILE* arquivo_mapa;
    arquivo_mapa = fopen("mapa.txt", "r");

    //testando se arquivo foi aberto
    if(arquivo_mapa) {
        printf("Arquivo aberto com sucesso!\n");
    }
    else {
        printf("Falha em tentar acessar arquivo!\n");
    }

    char mapa[6][14+1];
    for(int i = 0; i < 6; i++) {
        fscanf(arquivo_mapa, "%s", mapa[i]); //caso fosse uma variável, seria colocado &linha1_do_mapa, assim como em scanf(), que representa o endereço de memória, entretando, arrays já são a representação de um endereço, logo o & não é necessário
    }

    //criando personagem
    char cobra = '@';
    //coordenadas iniciais do personagem
    int x = 3;
    int y = 5;
    mapa[x][y] = cobra;   


    do {          
        //imprimir mapa
        for(int i = 0; i < 6; i++) {
            printf("%s\n", mapa[i]);
        }
        
        //comando de movimento
        char tecla = 'd';
        //scanf(" %c", &tecla);
        
        //movimentação
        switch(tecla){
            case 'w':
                mapa[x][y] = '-';
                x--;
                mapa[x][y] = '@';
                break;
            case 's':
                mapa[x][y] = '-';
                x++;
                mapa[x][y] = '@';
                break;
            case 'a':
                mapa[x][y] = '-';
                y--;
                mapa[x][y] = '@';
                break;
            case 'd':
                mapa[x][y] = '-';
                y++;
                mapa[x][y] = '@';
                break;
        }
        usleep(1000000);
    } while(1);


    fclose(arquivo_mapa);

    return 0;
}