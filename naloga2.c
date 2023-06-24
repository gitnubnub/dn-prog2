
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int izpisiB(B* b, char* cilj) {
    if (b == NULL) {
        return sprintf(cilj, "NULL");
    }

    int len = sprintf(cilj, "{%s, ", b -> q);
        
    if (b -> c == NULL) {
        len += sprintf(cilj + len, "NULL");
    } else {
        len += sprintf(cilj + len, "{%s, ", b -> c -> r ? "true" : "false");
        len += izpisiA(b -> c -> a, cilj + len);
        len += sprintf(cilj + len, ", ");
        len += izpisiB(b -> c -> b, cilj + len);
        len += sprintf(cilj + len, "}");
    }

    len += sprintf(cilj + len, "}");
    return len;
}

int izpisiA(A* a, char* cilj) {
    if (a == NULL) {
        return sprintf(cilj, "NULL");
    }
    
    int len = sprintf(cilj, "{%d, ", a -> p);
    
    len += izpisiB(a -> b, cilj + len);
    
    len += sprintf(cilj + len, "}");
    return len;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
