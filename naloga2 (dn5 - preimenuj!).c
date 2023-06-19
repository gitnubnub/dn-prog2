
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga2.c
./a.out


*/

#include <stdio.h>

#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

void uredi(int** a, int** b, int** c) {
    if (**a > **b) {
        zamenjaj(a, b);
    }

    if (**a > **c) {
        zamenjaj(a, c);
    }
    
    if (**b > **c){
        zamenjaj(b, c);

    }
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
