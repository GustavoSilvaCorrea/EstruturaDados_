#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um ITEM da lista ENCADEADA

typedef struct Item {
    int Chave;
    struct Item * Proximo;
} Item;

// Bloco principal 

int main(){

    Item * A = (Item *) malloc (sizeof(Item));
    Item * B = (Item *) malloc (sizeof(Item));
    Item * C = (Item *) malloc (sizeof(Item));
    Item * D = (Item *) malloc (sizeof(Item));

    A->Chave = 17;
    A->Proximo = NULL;
    B->Chave = 29;
    B->Proximo = NULL;
    C->Chave = 41;
    C->Proximo = NULL;
    D->Chave = 97;
    D->Proximo = NULL;

    // Alguns testes

    printf("%X\t %d\n", A, A->Chave);
    printf("%X\t %d\n", B, B->Chave);
    printf("%X\t %d\n", C, C->Chave);
    printf("%X\t %d\n", D, D->Chave);

    // Construindo o encadeamento (LISTA) A, C, B, D

    A->Proximo = C;
    B->Proximo = D;
    C->Proximo = B;

    printf("%d\n", A->Chave); // 17
    printf("%d\n", A->Proximo->Chave); // 41
    printf("%d\n", C->Proximo->Proximo->Chave); // 97
}