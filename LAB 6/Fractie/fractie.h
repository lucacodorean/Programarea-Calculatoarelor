//
// Created by Luca Codorean on 11/6/2022.
//
//
#ifndef C_FRACTIE_H
#define C_FRACTIE_H

    struct Fractie {
        int numitor, numarator;
    };

    void printF(struct Fractie fractie);
    void reducere(struct Fractie* function);
    struct Fractie aduna(struct Fractie first, struct Fractie second);
    struct Fractie scade(struct Fractie first, struct Fractie second);
    struct Fractie inmultire(struct Fractie first, struct Fractie second);
    struct Fractie impartire(struct Fractie first, struct Fractie second);

    //s#include "fractie.c"
#endif //C_FRACTIE_H
