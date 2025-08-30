#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp; // É um ponteiro para um arquivo.
    fp = fopen("database.txt", "r"); // r = abre o txt pra leitura
    if (fp == NULL)
    {
        printf("ERRO: Arquivo nao foi aberto!\n");
        exit('1');
    }

    int conta;
    float saldo;
    char nome[50];

    for (int i = 0; i < 4; i++)
    {
        fscanf(fp,"%d %f %[^\n]\n", &conta, &saldo, nome); // %s[^\Caracter], lê até um caracter
        printf("%d\t %.2f \t%s\n", conta, saldo, nome);
    }
    
    
    

    fclose(fp);
    return 0;
}