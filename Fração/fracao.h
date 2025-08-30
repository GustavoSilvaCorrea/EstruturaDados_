#ifndef FRACAO_H
#define FRACAO_H
// Def. do TAD Fração
typedef struct 
{
    int num; // Int 4B
    int den;

} Fracao; // Determina a estrutura de algo, essa por exemplo determina a estrutura de uma fração: Numerador e Denominador;

// Prototipo das Funções 

Fracao criarFracao(int n, int d);
void exibirFracao(Fracao F);
int calcularMDC(int a, int b);
Fracao simplificarFracao(Fracao F);
Fracao somarFracoes(Fracao F, Fracao G);
Fracao subtrairFracoes(Fracao F, Fracao G);
Fracao multiplicarFracoes(Fracao F, Fracao G);
Fracao dividirFracoes(Fracao F, Fracao G);
void escrever(Fracao F1, Fracao F2);
void escreverFracao(FILE *fp, Fracao f);
#endif