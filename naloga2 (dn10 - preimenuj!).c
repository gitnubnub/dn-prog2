//timeout pri 10. testnem primeru, ročno pognano da pravi rezultat
//verjetno bi bilo treba optimizirat krajšanje ulomkov

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

/*Ulomek uredi(Ulomek u) {
    if (u.im < 0) {
        u.st *= (-1);
        u.im *= (-1);
    }

    for (int i = u.im; i >= 2; i--) {
        if (u.st == 1 || u.st == -1 || u.im == 1) {
            break;
        }
        if (u.st % i == 0 && u.im % i == 0) {
            u.st /= i;
            u.im /= i;
        }
    }

    return u;
}

Ulomek zmnozi(Ulomek prvi, Ulomek drugi) {
    Ulomek* zmnozek = (Ulomek*) calloc(1, sizeof(Ulomek));
    zmnozek -> st = prvi.st * drugi.st;
    zmnozek -> im = prvi.im * drugi.im;
    return *zmnozek;
}

Ulomek sestej(Ulomek prvi, Ulomek drugi) {
    Ulomek* vsota = (Ulomek*) calloc(1, sizeof(Ulomek));

    if (prvi.im == drugi.im) {
        vsota -> im = prvi.im;
        vsota -> st = prvi.st + drugi.st;
    } else {
        vsota -> st = prvi.st * drugi.im + prvi.im * drugi.st;
        vsota -> im = prvi.im * drugi.im;
    }

    return *vsota;
}

Ulomek deli(Ulomek prvi, Ulomek drugi) {
    Ulomek* kolicnik = (Ulomek*) calloc(1, sizeof(Ulomek));

    int stTemp = drugi.st;
    int imTemp = drugi.im;
    drugi.st = imTemp;
    drugi.im = stTemp;
    *kolicnik = zmnozi(prvi, drugi);

    return *kolicnik;
}

Tocka projekcija(Tocka t, Premica p) {
    Tocka* presecisce = (Tocka*) calloc(1, sizeof(Tocka));
    
    if (p.navpicna) {
        presecisce -> x = p.n;
        presecisce -> y = t.y;
    } else if (p.k.st == 0) {
        presecisce -> x = t.x;
        presecisce -> y = p.n;
    } else {
        Ulomek* minus = (Ulomek*) calloc(1, sizeof(Ulomek));
        minus -> st = -1;
        minus -> im = 1;

        Ulomek* koefPravokotnice = (Ulomek*) calloc(1, sizeof(Ulomek));
        koefPravokotnice -> st = -1 * p.k.im;
        koefPravokotnice -> im = p.k.st;

        Ulomek* nPravokotnice = (Ulomek*) calloc(1, sizeof(Ulomek));
        *nPravokotnice = sestej(t.y, zmnozi(*minus, zmnozi(*koefPravokotnice, t.x)));

        presecisce -> x = deli(sestej(*nPravokotnice, zmnozi(*minus, p.n)), sestej(p.k, zmnozi(*minus, *koefPravokotnice)));
        presecisce -> y = sestej(zmnozi(p.k, presecisce -> x), p.n);

        presecisce -> x = uredi(presecisce -> x);
        presecisce -> y = uredi(presecisce -> y);
    }

    return *presecisce;
}*/

//optimizirana rešitev (delajo vsi testni primeri):

Ulomek sestej(Ulomek prvi, Ulomek drugi) {
    Ulomek* rezultat = (Ulomek*) calloc(1, sizeof(Ulomek));

    if (prvi.im == drugi.im) {
        rezultat -> im = prvi.im;
        rezultat -> st = prvi.st + drugi.st;
    } else {
        rezultat -> im = prvi.im * drugi.im;
        rezultat -> st = prvi.st * drugi.im + drugi.st * prvi.im;
    }

    return *rezultat;
}

Ulomek odstej(Ulomek prvi, Ulomek drugi) {
    drugi.st = - drugi.st;
    return sestej(prvi, drugi);
}

Ulomek zmnozi(Ulomek prvi, Ulomek drugi) {
    Ulomek* rezultat = (Ulomek*) calloc(1, sizeof(Ulomek));

    rezultat -> st = prvi.st * drugi.st;
    rezultat -> im = prvi.im * drugi.im;

    return *rezultat;
}

Ulomek deli(Ulomek prvi, Ulomek drugi) {
    int temp = drugi.st;
    drugi.st = drugi.im;
    drugi.im = temp;
    return zmnozi(prvi, drugi);
}

Ulomek okrajsaj(Ulomek ulomek) {
    if (ulomek.im < 0) {
        ulomek.st = - ulomek.st;
        ulomek.im = - ulomek.im;
    }

    for (int i = (abs(ulomek.st) > abs(ulomek.im) ? abs(ulomek.im) : abs(ulomek.st)); i > 1; i--) {
        if (ulomek.st % i == 0 && ulomek.im % i == 0) {
            ulomek.st /= i;
            ulomek.im /= i;
            i = (abs(ulomek.st) > abs(ulomek.im) ? abs(ulomek.im) : abs(ulomek.st)) + 1;
        }
    }

    return ulomek;
}

Tocka projekcija(Tocka t, Premica p) {
    Tocka* A = (Tocka*) calloc(1, sizeof(Tocka));

    if (p.navpicna) {
        A -> x = p.n;
        A -> y = t.y;
    } else if (p.k.st == 0) {
        A -> x = t.x;
        A -> y = p.n;
    } else {
        Ulomek nPrav = sestej(t.y, deli(t.x, p.k));
        Ulomek* ena = (Ulomek*) calloc(1, sizeof(Ulomek));
        ena -> st = 1;
        ena -> im = 1;

        A -> x = okrajsaj(deli(odstej(nPrav, p.n), sestej(p.k, deli(*ena, p.k))));
        A -> y = okrajsaj(sestej(zmnozi(p.k, A -> x), p.n));
    }

    return *A;
}

#ifndef test

int main() {
    return 0;
}

#endif
