#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 500000

void TrocarElemento(int* A, int* B);
int Particao(int* V, int Inf, int Sup); // Descobre a localização do pivot, *V é um vetor e não um ponteiro.    
void Quicksort(int* V, int Inf, int Sup);
void ExibirVetor(int *V, int N);

int main(){
    system("cls");

    int Vetor[TAMANHO];
    for (int i = 0; i < TAMANHO; i++) Vetor[i] = rand() % 1000;

    clock_t T0 = clock();
    Quicksort(Vetor, 0, TAMANHO - 1);
    clock_t TF = clock();

    printf("Tempo de CPU: %f\n", (double)(TF - T0)/CLOCKS_PER_SEC);
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