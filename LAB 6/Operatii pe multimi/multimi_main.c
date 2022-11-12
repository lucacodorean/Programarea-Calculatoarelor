//
// Created by Luca Codorean on 11/6/2022.
//

#include <stdio.h>
#include "multime.h"

int main(void) {
    struct Multime A, B;
    puts("Introduceti cardinalul multimii A, urmat de cele |n| elemente ale sale."); scanf("%d", &A.cardinal);
    for(int i = 0; i<A.cardinal; i++) scanf("%f", &A.elemente[i]);
    puts("Introduceti cardinalul multimii B, urmat de cele |m| elemente ale sale."); scanf("%d", &B.cardinal);
    for(int i = 0; i<B.cardinal; i++) scanf("%f", &B.elemente[i]);

    puts("Intersectia celor doua multimi este:"); printm(intersectie(A,B));
    puts("Reuniunea   celor doua multimi este:"); printm(reuniune(A,B));
    puts("Diferenta A\\B a celor doua multimi este:"); printm(diferenta(A,B));
    puts("Diferenta B\\A a celor doua multimi este:"); printm(diferenta(B,A));
    return 0;
}