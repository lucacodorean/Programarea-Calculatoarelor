//
// Created by Luca Codorean on 11/6/2022.
//

#include <stdio.h>
#include "fractie.h"

int main(void) {
    struct Fractie A,B;

    puts("Introduceti valori pentru cele doua fractii:");
    scanf("%d/%d", &A.numarator, &A.numitor);
    scanf("%d/%d", &B.numarator, &B.numitor);

    puts("A+B"); printF(aduna(A,B));
    puts("A-B"); printF(scade(A,B));
    puts("A*B"); printF(inmultire(A,B));
    puts("A/B"); printF(impartire(A,B));
    return 0;
}