//
// Created by Luca Codorean on 11/6/2022.
//

#include "multime.h"
#include <stdio.h>
#include <stdbool.h>

static void swapf(float* first, float* second) {
    float aux = *first;
    *first = *second;
    *second = aux;
}
static _Bool cauta(int element, float arr[CAPACITY]) {
    for(int i = 0; i<CAPACITY; i++) {
        if(element==arr[i]) return true;
    }
    return false;
}

void printm(Multime parameter) {
    if(parameter.cardinal == 0) {
        printf("Multimea vida.\n");
        return;
    }

    printf("\n{ ");
    for(int i = 0; i<parameter.cardinal; i++) printf("%.0f%s ", parameter.elemente[i], i!=parameter.cardinal-1 ? "," : "");
    printf("}\n");
}

void sorteaza_multime(Multime* destinatie, char conditie) {
    switch (conditie) {
        case 'c':
            for(int i = 0; i<destinatie->cardinal; i++) {
                for(int j = i + 1; j<destinatie->cardinal-1; j++) {
                    if(destinatie->elemente[i] < destinatie->elemente[j]) {
                        swapf(&destinatie->elemente[i], &destinatie->elemente[j]);
                    }
                }
            }
            break;
        case 'd':
            for(int i = 0; i<destinatie->cardinal; i++) {
                for(int j = i + 1; j<destinatie->cardinal-1; j++) {
                    if(destinatie->elemente[i] > destinatie->elemente[j]) {
                        swapf(&destinatie->elemente[i], &destinatie->elemente[j]);
                    }
                }
            }
            break;
        default:
            puts("Conditie necunoscuta.");
            break;
    }
    return;
}
void adauga_in_multime(float element, Multime* destinatie) { destinatie->elemente[(destinatie->cardinal)++] = element; }
Multime intersectie(Multime A, Multime B) {
    Multime result;
    result.cardinal = 0;

    for(int i = 0; i<A.cardinal; i++) {
        for(int j = 0; j<B.cardinal; j++) {
            if(A.elemente[i] == B.elemente[j]) {
                result.elemente[result.cardinal++] = A.elemente[i];
            }
        }
    }

    return result;
}

Multime reuniune(Multime A, Multime B) {
    Multime result;
    result.cardinal = 0;

    for(int i = 0; i<A.cardinal; i++) {
        result.elemente[result.cardinal++] = A.elemente[i];
    }

    for(int i = 0; i<B.cardinal; i++) {
        if(cauta(B.elemente[i], result.elemente) == true) continue;
        else result.elemente[result.cardinal++] = B.elemente[i];
    }

    return result;
}
Multime diferenta(Multime A, Multime B) {
    Multime result;
    result.cardinal = 0;

    for(int i = 0; i<A.cardinal; i++) {
        if(cauta(A.elemente[i], B.elemente) == false) {
            result.elemente[result.cardinal++] = A.elemente[i];
        }
    }

    return result;
}
