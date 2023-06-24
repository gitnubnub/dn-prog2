//timeout pri 10. testnem primeru, ročno pognano da pravi rezultat
//verjetno bi bilo treba optimizirat krajšanje ulomkov

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Ulomek uredi(Ulomek u) {
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
}

#ifndef test

int main() {
    return 0;
}

#endif
