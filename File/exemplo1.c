#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp; // É um ponteiro para um arquivo.
    printf("%d %x\n", fp, fp); // Endereço da memória que está guardado no ponteiro, x = hexadecimal
    return 0;
}