#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos 
void InsertionSort(int *V, int N);
void ExibirVetor(int *V, int N);

// Função principal
int main(){
    system("cls");
    int Conjunto[] = {1, 9, 7, 8, 5, 2};
    int Tamanho = sizeof(Conjunto) / sizeof(int);
    InsertionSort(Conjunto, Tamanho);
    ExibirVetor(Conjunto, Tamanho);
}

// Implementação das Funções
void InsertionSort(int *V, int N){
    int Chave; // Elemento que será inserido na parte ordenada
    int i; // Posição (ou coordenada) do elemento chave
    int j; // Posição de elemento da "parte ordenada" que será comparada com a Chave

    for (i = 1; i < N; i++)
    {
        Chave = V[i];
        j = i - 1;

        while (j >= 0 && V[j] > Chave)
        {
            V[j + 1] = V[j];
            j--;   
        }
        V[j + 1] = Chave; // Copiando o Chave no ultimo logar modificado 
        ExibirVetor(V, N);
    } 
}

void ExibirVetor(int *V, int N){
    int i;
    for(i = 0; i < N; i++){
        printf("%d\t", V[i]);
    }
    printf("\n");
}