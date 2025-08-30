#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp; // É um ponteiro para um arquivo.
    fp = fopen("tabuada.txt", "w"); // abre o txt pra escrita
    if (fp == NULL)
    {
        printf("ERRO: Arquivo nao foi aberto!\n");
        exit('1');
    }
    for (int i = 1; i < 11; i++)
    {
        fprintf(fp, "\nTabuada do %d\n\n", i);
        for (int j = 1; j < 11; j++)
        {
            fprintf(fp,"%d x %d = %d\n", i, j, i*j);
        }
        
    }

    fclose(fp);
    return 0;
}