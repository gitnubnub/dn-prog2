
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

Vozlisce* zdesetkaj(Vozlisce* zacetek, int k) {
    if (k == 1) {
        return zacetek;
    }

    Vozlisce* trenutno = zacetek;
    Vozlisce* ohranimo = NULL;
    int iteracija = 1;
    while (trenutno != NULL) {
        if (iteracija % k == 0) {
            if (iteracija == k) {
                zacetek = trenutno;
                ohranimo = zacetek;
            } else {
                ohranimo -> naslednje = trenutno;
                ohranimo = trenutno;
            }
        }
        iteracija++;
        trenutno = trenutno -> naslednje;
    }
    
    ohranimo -> naslednje = NULL;
    return zacetek;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
