
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga1.h"

int neurejeno(VO** tabela, int velikost) {
    for (int i = 0; i < velikost - 1; i++) {
        if (tabela[i] -> ocena < tabela[i + 1] -> ocena) {
            return 1;
        } else if (tabela[i] -> ocena == tabela[i + 1] -> ocena) {
            if (tabela[i] -> vpisna > tabela[i + 1] -> vpisna) {
                return 1;
            }
        }
    }

    return 0;
}

VO** uredi(VO** opravljeni, int velikost) {
    while (neurejeno(opravljeni, velikost)) {
        for (int i = 0; i < velikost - 1; i++) {
            if (opravljeni[i] -> ocena < opravljeni[i + 1] -> ocena) {
                int vpisnaTemp = opravljeni[i] -> vpisna;
                int ocenaTemp = opravljeni[i] -> ocena;
                opravljeni[i] -> vpisna = opravljeni[i + 1] -> vpisna;
                opravljeni[i] -> ocena = opravljeni[i + 1] -> ocena;
                opravljeni[i + 1] -> vpisna = vpisnaTemp;
                opravljeni[i + 1] -> ocena = ocenaTemp; 
            }
        }

        for (int i = 0; i < velikost - 1; i++) {
            if (opravljeni[i] -> ocena == opravljeni[i + 1] -> ocena) {
                if (opravljeni[i] -> vpisna > opravljeni[i + 1] -> vpisna) {
                    int vpisnaTemp = opravljeni[i] -> vpisna;
                    int ocenaTemp = opravljeni[i] -> ocena;
                    opravljeni[i] -> vpisna = opravljeni[i + 1] -> vpisna;
                    opravljeni[i] -> ocena = opravljeni[i + 1] -> ocena;
                    opravljeni[i + 1] -> vpisna = vpisnaTemp;
                    opravljeni[i + 1] -> ocena = ocenaTemp; 
                }
            }
        }
    }

    return opravljeni;
}

VO** opravili(Student** studentje, int stStudentov, char* predmet, int* stVO) {
    VO** opravljeni = (VO**) calloc(1000, sizeof(VO*));
    *stVO = 0;
    
    for (int i = 0; i < stStudentov; i++) {
        int stOcen = studentje[i] -> stPO;
        for (int j = 0; j < stOcen; j++) {
            if (strcmp(studentje[i] -> po[j].predmet, predmet) == 0) {
                if (studentje[i] -> po[j].ocena > 5) {
                    opravljeni[*stVO] = (VO*) calloc(1, sizeof(VO));
                    opravljeni[*stVO] -> vpisna = studentje[i] -> vpisna;
                    opravljeni[*stVO] -> ocena = studentje[i] -> po[j].ocena;
                    (*stVO)++;
                }
            }
        }
    }

    return uredi(opravljeni, *stVO);
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
