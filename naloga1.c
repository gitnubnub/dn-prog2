
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

int dolzinaNiza(char* niz) {
    int stevec = 0;
    for (int i = 0; niz[i] != '\0'; i++) {
        stevec++;
    }
    return stevec;
}

char* kopirajNiz(char* niz, char* kopija) {
    char* kazalec = kopija;
    for (int i = 0; niz[i] != '\0'; i++) {
        *kazalec = niz[i];
        kazalec++;
    }
    return kazalec;
}

char* zdruzi(char** nizi, char* locilo) {
    int dolzinaLocila = dolzinaNiza(locilo);
    int dolzinaZdruzenega = 0;
    for (int i = 0; nizi[i] != NULL; i++) {
        dolzinaZdruzenega += dolzinaNiza(nizi[i]);
        dolzinaZdruzenega += dolzinaLocila;
    }
    dolzinaZdruzenega -= dolzinaLocila;
    dolzinaZdruzenega++;

    char* zdruzen = (char*) calloc(dolzinaZdruzenega, sizeof(char));
    char* zacetek = zdruzen;
    for (int i = 0; nizi[i] != NULL; i++) {
        zacetek = kopirajNiz(nizi[i], zacetek);

        if (nizi[i + 1] == NULL) {
            *zacetek = '\0';
            return zdruzen;
        } else {
            zacetek = kopirajNiz(locilo, zacetek);
        }
    }
    return zdruzen;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje
    return 0;
}

#endif
