#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Musica.h"

Item *criarItem(char *Titulo, char *Autor, int Ano)
{
    Item *X = (Item *)malloc(sizeof(Item)); // malloc aloca, (Item *) especfica a memoria alocada
    if (X == NULL)
    {
        printf("Não foi possivél a alocação de memória.\n");
        return NULL;
    } // Boa Prática

    strcpy(X->Titulo, Titulo);
    strcpy(X->Autor, Autor);
    X->Ano = Ano;
    X->Anterior = NULL;
    X->Posterior = NULL;
}

void exibirInicio(Lista *L)
{
    Item *Atual = L->Inicio;
    for (int i = 0; i < L->Tamanho; i++)
    {
        printf("%d\t %s \n", i + 1, Atual->Titulo);
        Atual = Atual->Posterior;
    }
    printf("\n");
}

void exibirFinal(Lista *L)
{
    Item *Atual = L->Fim;
    for (int i = 0; i < L->Tamanho; i++)
    {
        printf("%d\t %s \n", i + 1, Atual->Titulo);
        Atual = Atual->Anterior;
    }
    printf("\n");
}

void exibirAno(Lista *L, int Ano)
{
    Item *Atual = L->Inicio;
    for (int i = 0; i < L->Tamanho; i++)
    {
        if (Atual->Ano == Ano)
        {
            printf("%d\t %s \n", i + 1, Atual->Titulo);
        }
        Atual = Atual->Posterior;
    }
}