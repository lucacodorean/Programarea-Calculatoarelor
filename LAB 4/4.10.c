/*
// Created by Luca Codorean on 10/26/2022.
Determinati solutiile a n ecuatii cu n necunosute. Pentru aceasta, vom folosi metoda matriceala a lui Gauss care presupune scaderea succesiva de linii si coloane.

Se citesc coeficientii celor n necunoscute, urmat de rezultatul fiecarei ecuatii. Matricea de lucru este data de matricea extinsa.
In pasul urmator formam solutiile in partea de sus a diagonalei principale, sub forma unui triunghi.

 */


#include <stdio.h>

#define MAX_NEC 100

struct Ecuation {
    double solution;
    double coef[MAX_NEC];
};

void GaussMethod(struct Ecuation system[], int size) {
    for(int i = 1; i<=size-1; i++) {
        if(system[i].coef[i]==0.0) {
            puts("Error: Impartirea cu 0.0 nu returneaza o valoare reala.\n");
            return;
        }

        for(int j = i+1; j<=size; j++) {
            double ratie = system[j].coef[i] / system[i].coef[i];
            for(int k = 1; k<=size+1; k++) {
                system[j].coef[k] = system[j].coef[k] - ratie * system[i].coef[k];
            }
        }
    }
}

void Substitution(struct Ecuation system[], int size) {
    system[size].solution = system[size].coef[size+1] / system[size].coef[size];
    for(int i=size-1; i>=1; i--) {
        system[i].solution = system[i].coef[size+1];
        for(int j = i+1; j<=size; j++) {
            system[i].solution = system[i].solution - system[i].coef[j] * system[j].solution;
        }
        system[i].solution = system[i].solution/system[i].coef[i];
    }
}

void printSolution(struct Ecuation system[], int size) {
    puts("Solutiile ecuatiei sunt:\n");
    for(int i = 1; i<=size; i++) {
        printf("\tSolutia %i: %lf\n", i, system[i].solution);
    }
}


int main(void) {
    puts("Introdu numarul de ecuatii liniare: n = ");
    int n; scanf("%d", &n);
    printf("\nFiecare ecuatie va avea exact %d necunoscute.\n", n);

    struct Ecuation system[n+1];

    for(int i = 1; i<=n; i++) {
        printf("Introdu coeficientii pentru ecuatia nr. %d: ", i);
        for(int j = 1; j<=n+1; j++) {
            scanf("%lf", &system[i].coef[j]);
        }
    }

    GaussMethod(system, n);
    Substitution(system,n);
    printSolution(system,n);
    return 0;
}
