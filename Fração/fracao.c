#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fracao.h"

// Funções em si
Fracao criarFracao(int n, int d)
{
    Fracao F;
    F.num = n;
    F.den = d;
    return F;
}

void exibirFracao(Fracao F)
{
    printf("%d / %d", F.num, F.den);
}

int calcularMDC(int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    while (a % b != 0)
    {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return (b);
}

Fracao simplificarFracao(Fracao F)
{
    int mdc = calcularMDC(F.num, F.den);
    F.num /= mdc;
    F.den /= mdc;
    return F;
}

Fracao somarFracoes(Fracao F, Fracao G)
{
    Fracao resposta;
    resposta.den = F.den * G.den;
    resposta.num = (F.num * G.den) + (G.num * F.den);
    resposta = simplificarFracao(resposta);
    return resposta;
}

Fracao subtrairFracoes(Fracao F, Fracao G)
{
    Fracao resposta;
    resposta.den = F.den * G.den;
    resposta.num = (F.num * G.den) - (G.num * F.den);
    resposta = simplificarFracao(resposta);
    return resposta;
}

Fracao multiplicarFracoes(Fracao F, Fracao G)
{
    Fracao resposta;
    resposta.den = F.den * G.den;
    resposta.num = F.num * G.num;
    resposta = simplificarFracao(resposta);
    return resposta;
}

Fracao dividirFracoes(Fracao F, Fracao G)
{
    Fracao resposta;

    if (F.den != 0 && G.den != 0)
    {
        resposta.den = F.den * G.num;
        resposta.num = F.num * G.den;
        resposta = simplificarFracao(resposta);
        return resposta;
    }
    else
    {
        printf("Denominador = 0");
    }
}

void escreverFracao(FILE *fp, Fracao f) {
    fprintf(fp, "%d / %d", f.num, f.den);
}

void escrever(Fracao F1, Fracao F2)
{
    FILE *fp = fopen("tabela.txt", "w");
    if (fp == NULL)
    {
        printf("ERRO: Arquivo nao foi aberto!\n");
        exit(1);
    }

    fprintf(fp, "Fracoes: \n");
    escreverFracao(fp, F1);
    fprintf(fp, " - ");
    escreverFracao(fp, F2);
    fprintf(fp, "\n");

    fprintf(fp, "Simplificacao: \n");
    escreverFracao(fp, simplificarFracao(F1));
    fprintf(fp, " - ");
    escreverFracao(fp, simplificarFracao(F2));
    fprintf(fp, "\n");

    fprintf(fp, "Soma de Fracoes: \n");
    escreverFracao(fp, somarFracoes(F1, F2));
    fprintf(fp, "\n");

    fprintf(fp, "Subtracao de Fracoes: \n");
    escreverFracao(fp, subtrairFracoes(F1, F2));
    fprintf(fp, "\n");

    fprintf(fp, "Multiplicacao de Fracoes: \n");
    escreverFracao(fp, multiplicarFracoes(F1, F2));
    fprintf(fp, "\n");

    fprintf(fp, "Divisao de Fracoes: \n");
    escreverFracao(fp, dividirFracoes(F1, F2));
    fprintf(fp, "\n\n");

    fclose(fp);
}
