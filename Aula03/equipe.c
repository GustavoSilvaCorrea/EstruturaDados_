// Implementar todas as funções do TAD Equipe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equipe.h"

Time *LerDados(char *Arquivo)
{

    Time *X = malloc(20 * sizeof(Time)); // malloc (memory allocation) é uma função aloca dinamicamente um bloco de um número específico de bytes na memória (heap)
    if (X == NULL)
    {
        printf("ERRO: memoria insuficiente \n");
        exit(1);
    }

    FILE *fp = fopen(Arquivo, "r");
    if (fp == NULL)
    {
        printf("ERRO: Arquivo nao pode ser aberto.");
        exit(1);
    }

    int i = 0;
    char cabecalho[100];
    fscanf(fp, "%s", cabecalho);
    while (fscanf(fp,
                  "%d; %[^;]; %[^;]; %d; %d; %d; %d; %d; %d; %d; %d\n",
                  &X[i].posicao, X[i].estado, X[i].equipe, &X[i].pts,
                  &X[i].j, &X[i].v, &X[i].e, &X[i].d, &X[i].gp, &X[i].gc, &X[i].sg) == 11)
    {
        X[i].aproveitamento = 100 * (float) X[i].pts / (3 * X[i].j );
        i++;
    }

    fclose(fp);
    return X;
}

int getPontos(Time* T, int posicao){
    int i;
    for (i = 0; i < 20; i++)
        if(T[i].posicao == posicao)
            return T[i].pts;
    
    return ERRO;
}

float getAproveitamento(Time* T, char* equipe){
    int i;
    for (i = 0; i < 20; i++)
        if(strcmp(T[i].equipe, equipe) == 0)
        return T[i].aproveitamento;

    return ERRO;
}

void InsertionSort(Time  *V, int N){
    Time Chave; // Elemento que será inserido na parte ordenada
    int i; // Posição (ou coordenada) do elemento chave
    int j; // Posição de elemento da "parte ordenada" que será comparada com a Chave

    for (i = 1; i < N; i++)
    {
        Chave = V[i];
        j = i - 1;


        while (j >= 0 && strcmp(V[j].equipe, Chave.equipe) > 0)
        {
            V[j + 1] = V[j];
            j--;   
        }
        V[j + 1] = Chave; // Copiando o Chave no ultimo logar modificado 
    } 
}