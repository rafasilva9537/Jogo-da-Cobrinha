#include <stdio.h>

int main() {
    char palavra_digitada[15];

    printf("Digite uma palavra:\n");
    fgets(palavra_digitada, 15, stdin);

    printf("A palavra digitada foi: %s", palavra_digitada);
    
    return 0;
}