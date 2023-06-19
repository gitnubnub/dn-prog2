
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c tranzitivnost.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "tranzitivnost.h"

int tranzitivnost(int a, int b) {
    int trans = 1;
    int anti = 1;
    int ne = 0;

    for (int x = a; x <= b; x++) {
        for (int y = a; y <= b; y++) {
            for (int z = a; z <= b; z++) {
                if (f(x,y) && f(y,z) && !f(x,z)) {
                    trans = 0;
                    ne = 1;
                }

                if (f(x,y) && f(y,z) && f(x,z)) {
                    anti = 0;
                }
            }
        }
    }

    if (trans && anti) {
        return 1;
    } else if (trans) {
        return 2;
    } else if (anti) {
        return 3;
    } else if (ne) {
        return 4;
    } else {
        return -1;
    }
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
