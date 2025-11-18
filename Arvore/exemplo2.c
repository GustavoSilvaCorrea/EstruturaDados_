#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int Chave;

    // No caso de árvore Binária (Máximo 2 filhos).
    struct No * Esquerda; // Primeiro Filho
    struct No * Direita; // Segundo Filho

} No;

No * CriarNo(int Chave){
    No * N = (No *) malloc(sizeof(No));
    if (N == NULL){
        printf("Erro ao alocar memoria");
        return NULL;
    }

    N->Chave = Chave;
    N->Esquerda = NULL;
    N->Direita = NULL;

    return N;
}

int ContarNos(No * N){
    if (N == NULL) return 0;
    return 1 + ContarNos(N->Direita) + ContarNos(N->Esquerda);
}

int main(){
    // Nó de Nível 1
    No * Raiz = CriarNo(10);

    // Nós de Nível 2
    Raiz->Esquerda = CriarNo(12);
    Raiz->Direita = CriarNo(15);

    // Nós de Nível 3
    Raiz->Esquerda->Esquerda = CriarNo(16); 
    Raiz->Esquerda->Direita = CriarNo(18);
    Raiz->Direita->Direita = CriarNo(20);

    // Nós de Nível 4
    Raiz->Direita->Direita->Esquerda = CriarNo(17);
    Raiz->Direita->Direita->Direita = CriarNo(19);

}