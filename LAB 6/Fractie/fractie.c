//
// Created by Luca Codorean on 11/6/2022.
//

#include "fractie.h"
#include <stdio.h>

int cmmdc(int first, int second) {
    while(second!=0) {
        int result = first%second;
        first = second;
        second = result;
    }

    return first;
}

void printF(struct Fractie fractie) { printf("%d/%d\n", fractie.numarator, fractie.numitor); }

void reducere(struct Fractie* function) {
    int factor = cmmdc(function->numarator, function->numitor);
    if (factor == 1) return;
    else {
        while(factor>1) {
            function->numitor /= factor;
            function->numarator /= factor;
            factor = cmmdc(function->numarator, function->numitor);
        }
    }
}

struct Fractie aduna(struct Fractie first, struct Fractie second) {
    /// a/d + c/b exista <=> d = b

    struct Fractie result;
    if(first.numitor == second.numitor) {
        result.numitor = first.numitor;
        result.numarator = first.numarator + second.numarator;
    } else {
        int aux = first.numitor;
        first.numitor *= second.numitor;
        first.numarator *= second.numarator;

        second.numitor *= aux;
        second.numarator *= aux;


        result.numarator = first.numarator + second.numarator;
        result.numitor = first.numitor;
    }

    reducere(&result);
    return result;
}
struct Fractie scade(struct Fractie first, struct Fractie second) {
    /// a/d + c/b exista <=> d = b

    struct Fractie result;
    if(first.numitor == second.numitor) {
        result.numitor = first.numitor;
        result.numarator = first.numarator - second.numarator;
    } else {
        int aux = first.numitor;
        first.numitor *= second.numitor;
        first.numarator *= second.numarator;

        second.numitor *= aux;
        second.numarator *= aux;


        result.numarator = first.numarator - second.numarator;
        result.numitor = first.numitor;
    }

    reducere(&result);
    return result;
}
struct Fractie inmultire(struct Fractie first, struct Fractie second) {
    struct Fractie result;
    result.numitor = first.numitor*second.numitor;
    result.numarator = first.numarator * second.numarator;
    reducere(&result);
    return result;
}
struct Fractie impartire(struct Fractie first, struct Fractie second) {
    struct Fractie result;
    /// a/b : c/d = a/b * d/c = ad/bc
    result.numitor   = first.numitor * second.numarator;
    result.numarator = first.numarator * second.numitor;
    reducere(&result);
    return result;
}