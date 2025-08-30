#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "fracao.h"

int main()
{
    system("cls");

    srand(time(NULL));
    int a = rand() % 101;
    int b = rand() % 101;
    int c = rand() % 101;
    int d = rand() % 101;

    Fracao F1 = criarFracao(a, b);
    Fracao F2 = criarFracao(c, d);
    printf("Fracoes: \n");
    exibirFracao(F1);
    printf(" - ");
    exibirFracao(F2);

    printf("\n");

    printf("Simplificacao: \n");
    exibirFracao(simplificarFracao(F1));
    printf(" - ");
    exibirFracao(simplificarFracao(F2));

    printf("\n");

    printf("Soma de Fracoes: \n");
    exibirFracao(somarFracoes(F1, F2));

    printf("\n");

    printf("Subtracao de Fracoes: \n");
    exibirFracao(subtrairFracoes(F1, F2));

    printf("\n");

    printf("Multiplicacao de Fracoes: \n");
    exibirFracao(multiplicarFracoes(F1, F2));

    printf("\n");

    printf("Divisao de Fracoes: \n");
    exibirFracao(dividirFracoes(F1, F2));

    escrever(F1, F2);
    return 0;
}