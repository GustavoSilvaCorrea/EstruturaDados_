#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void TrocarElemento(int* A, int* B);
int Particao(int* V, int Inf, int Sup); // Descobre a localização do pivot, *V é um vetor e não um ponteiro.    
void Quicksort(int* V, int Inf, int Sup);
void ExibirVetor(int *V, int N);

int main(){
    int Vetor[] = {3, 6, 4, 5, 1, 7, 2};
    int Tamanho = sizeof(Vetor) / sizeof(int);

    Quicksort(Vetor, 0, Tamanho - 1);
    ExibirVetor(Vetor, Tamanho);
    return 0;
}

void TrocarElemento(int* A, int* B){
    // Obs: A e B são ponteiros
    // * -> Valor apontado pelo ponteiro, Sem * -> Endereço de memória

    int temp = *A;
    *A = *B;
    *B = temp;
}

int Particao(int* V, int Inf, int Sup){
    int Pivot = V[(Inf + Sup) / 2];
    int i = Inf;
    int j = Sup;

    while (i <= j)
    {
        while (V[i] < Pivot){
            i++;
        }
        while (V[j] > Pivot){
            j--;
        } 
        if (i <= j)
        {
            TrocarElemento(&V[i], &V[j]);
            i++;
            j--;
        }   
    }
    // for (int p = 0; p < i; p++) printf("%d\t", V[p]);
    // printf("\n[%d]\n", V[i]);
    // for (int q = i + 1; q <= Sup; q++) printf("%d\t", V[q]);
    return i;
}

void Quicksort(int* V, int Inf, int Sup){
    if (Inf < Sup)
    {
        int P = Particao(V, Inf, Sup);
        Quicksort(V, Inf, P - 1);
        Quicksort(V, P, Sup);
    }
}

void ExibirVetor(int *V, int N){
    for (int i = 0; i < N; i++) printf("%d\t", V[i]);
    printf("\n");
}