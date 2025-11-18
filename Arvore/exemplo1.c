#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    char Chave;

    // No caso de árvore com grau 3:
    struct No * F1; // Primeiro Filho
    struct No * F2; // Segundo Filho
    struct No * F3; // Terceiro Filho

    // Outra possibilidade
    struct No * F[3]; // Filhos: F[N]
} No;

No * CriarNo(char Chave){
    No * N = (No *) malloc(sizeof(No));
    if (N == NULL){
        printf("Erro ao alocar memoria");
        return NULL;
    }

    N->Chave = Chave;
    N->F1 = NULL;
    N->F2 = NULL;
    N->F3 = NULL;

    for (int i = 0; i < 3; i++) N->F[i] = NULL;

    return N;
}