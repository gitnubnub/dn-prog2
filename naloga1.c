
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga1.c
./a.out

*/

#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int* poisci(int* t, int* dolzina, int** konec) {
    int* element = t;
    int* zacetek = NULL;
    int length = 0;
    
    while (*element != 0) {
        length++;
        element--;
    }

    zacetek = element + 1;
    element = t + 1;

    while (*element != 0) {
        length++;
        element++;
    }

    *konec = element - 1;
    *dolzina = length;
    return zacetek;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
