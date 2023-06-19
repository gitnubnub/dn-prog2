
/*

Prevajanje in poganjanje:

gcc -o test01 test01.c inverz.c -lm
./test01

*/

#include <stdio.h>
#include <stdbool.h>

#include "inverz.h"

long inverz(long y, long a, long b) {
    long inverzVrednost = 0;
    
    while (a <= b) {
        long i = (a + b) / 2;
        long result = f(i);
        if (result == y) {
            inverzVrednost = i;
            break;
        } else if (result > y) {
            b = i - 1;
        } else if (result < y) {
            a = i + 1;
        }
    }
    
    return inverzVrednost;
}

// Ta datoteka NE SME vsebovati funkcij main in f!
// Funkciji main in f sta definirani v datoteki test01.c.
