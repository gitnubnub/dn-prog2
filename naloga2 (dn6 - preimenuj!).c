
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int** ap2pp(int(*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic) {
    int povrsina = izvornoStVrstic * N;
    int stElementov = povrsina / ciljnoStVrstic;
    int** novaTabela = (int**) calloc(ciljnoStVrstic, sizeof(int*));
    for (int i = 0; i < ciljnoStVrstic; i++) {
        novaTabela[i] = (int*) calloc(stElementov + 1, sizeof(int));
    }

    int stevecElementov = 0;
    int stevecVrstic = 0;
    for (int i = 0; i < izvornoStVrstic; i++) {
        for (int j = 0; j < N; j++) {
            novaTabela[stevecVrstic][stevecElementov] = (*kazalec)[j];
            stevecElementov++;
            if (stevecElementov > stElementov - 1) {
                stevecVrstic++;
                stevecElementov = 0;
            }
        }
        kazalec++;
    }

    return novaTabela;
}

int prestejElemente(int** kazalec, int stVrstic) {
    int stevec = 0;
    for (int i = 0; i < stVrstic; i++) {
        int* vrstica = kazalec[i];
        for (int j = 0; vrstica[j] != 0; j++) {
            stevec++;
        }
    }
    return stevec;
}

int (*pp2ap(int** kazalec, int izvornoStVrstic, int* ciljnoStVrstic))[N] {
    int stevec = 0;
    for (int i = 0; i < izvornoStVrstic; i++) {
        int* vrstica = kazalec[i];
        for (int j = 0; vrstica[j] != 0; j++) {
            stevec++;
        }
    }
    
    *ciljnoStVrstic = 1 + ((stevec - 1) / N);
    int (*arr)[N] = calloc(*ciljnoStVrstic, N * sizeof(int));
    
    int stevecElementov = 0;
    int stevecVrstic = 0;
    for (int i = 0; i < izvornoStVrstic; i++) {
        int* vrstica = kazalec[i];
        for (int j = 0; vrstica[j] != 0; j++) {
            arr[stevecVrstic][stevecElementov] = vrstica[j];
            stevecElementov++;
            if (stevecElementov > N - 1) {
                stevecVrstic++;
                stevecElementov = 0;
            }
        }
    }
    
    return arr;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
