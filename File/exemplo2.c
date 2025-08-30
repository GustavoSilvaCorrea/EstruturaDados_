#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp; // É um ponteiro para um arquivo.
    fp = fopen("abc/teste.txt", "w"); // w = abre o txt pra escrita
    if (fp == NULL)
    {
        printf("ERRO: Arquivo nao foi aberto!\n");
        exit('1');
    }
    printf("Arquivo aberto!\n");

    fclose(fp);
    return 0;
}