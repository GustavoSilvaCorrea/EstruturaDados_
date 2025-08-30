// Algoritimo de pesquisa sequencial

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO -1

int PesquisaSequencial(int *v, int n, int chave);
// char *PesquisaSequencial_2(int *v, int n, int chave);

int main()
{
    int numero[] = {14, 29, 37, 11, 43, 25, 19, 32, 16, 22,
                    40, 13, 28, 35, 10, 45, 20, 38, 17, 24,
                    30, 41, 15, 27, 33, 18, 26, 39, 12, 21};
    int tamanho = sizeof(numero) / sizeof(int);
    int elemento = 22;
    int posicao = PesquisaSequencial(numero, tamanho, elemento);
    printf("Posicao: %d \n", posicao);
    // printf("%s \n", PesquisaSequencial_2(numero, tamanho, elemento));
}

// Implementação das funções

int PesquisaSequencial(int *v, int n, int chave)
{
    int i;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == chave)
        {
            return i; // O elemento foi encontrado no vetor.
        }
    }
    return ERRO;
}

/* char *PesquisaSequencial_2(int *v, int n, int chave)
{
    int i;
    char resposta[100];
    for (int i = 0; i < n; i++)
    {
        if (v[i] == chave)
        {
            sprintf(resposta, "O elemento %d está na posição %d \n", chave, i);
            return resposta; // O elemento foi encontrado no vetor.
        }
    }
    strcpy(resposta, "Erro:");
    return resposta;
} */