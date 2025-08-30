#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp; // É um ponteiro para um arquivo.
    fp = fopen("teste.txt", "a"); // a = abre o txt pra escrita embaixo da existente
    if (fp == NULL)
    {
        printf("ERRO: Arquivo nao foi aberto!\n");
        exit('1');
    }
        fprintf(fp, "Nah i'd win");
    
    fclose(fp);
    return 0;
}