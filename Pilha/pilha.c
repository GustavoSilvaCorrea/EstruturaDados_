#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

Item * criarItem(int Chave){
    Item * I = (Item *) malloc(sizeof(Item));
    if (I == NULL)
    {
        printf("Não foi possivel alocar memoria.");
        return I;
    }

    I->Chave = Chave;
    I->Anterior = NULL;

    return I;
}

Pilha * criarPilha(){
    Pilha * P = (Pilha *) malloc(sizeof(Pilha));
    if (P == NULL)
    {
        printf("Não foi possivel alocar memoria.");
        return P;
    }

    P->Tamanho = 0;
    P->Topo = NULL;

    return P;
}

void empillhar(Pilha * P, Item * I){
    I->Anterior = P->Topo;
    P->Topo = I;
    P->Tamanho ++;
}

void desempilhar(Pilha * P){
    if (P->Tamanho == 0)
    {
        printf("Erro: a pilha está vazia!");
        return ;
    }
    
    Item * I = P->Topo;

    P->Topo = I->Anterior;
    free(I);
    P->Tamanho --;
}
