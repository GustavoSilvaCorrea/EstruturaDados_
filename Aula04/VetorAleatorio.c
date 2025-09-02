#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 200000

int main(){
    int soma = 0;

    srand(time(NULL)); // Entrega o tempo da máquina para geração de numeros aleatorios
    clock_t T0 = clock(); // Inicia o cronometro
    for (int i = 0; i < TAMANHO; i++){
        int temp = rand() % 1000; // Gera um numero de 0 a 1000
        printf("%d\n", temp);
        soma += temp;
    }
    clock_t TF = clock(); // Finalia o cronometro
    double TempoCPU = (double)(TF - T0) / CLOCKS_PER_SEC; // Calculo para segundos (Clocks_Per_sec é do cpu da máquina)

    printf("Tempo de CPU: %.3f segundos \n", TempoCPU);
    printf("Soma: %d", soma);
    
}