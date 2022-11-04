//
// Created by Luca Codorean on 10/27/2022.
/*
 Se dau 2 şiruri de n si respectiv m elemente de tip întreg. Să se calculeze:
        a) şirul ce conţine elementele comune ale celor două şiruri;
        b) şirul ce conţine toate elementele celor două şiruri luate o singura dată;
        c) şirul ce conţine elementele primului şir din care au fost eliminate elementele comune.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 101

struct Array {
    int size;
    int elements[MAX];
};

int max(int a, int b) {return a > b ? a : b; }

int function (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

struct Array intersection(struct Array first, struct Array second) {
    struct Array aux;
    aux.size = 0;

    for(int i = 0; i<aux.size; i++) aux.elements[i] = 0;

    for(int i = 0,el; i<first.size; i++) {
        el = first.elements[i];
        for(int j = 0; j<second.size; j++) {
            if(el == second.elements[j])
                aux.elements[aux.size++] = el;
        }
    }
    return aux;
}
struct Array unique_reunion(struct Array first, struct  Array second) {
    struct Array aux;
    int ap[MAX] = {0};

    for(int i = 0; i<first.size; i++) {
        aux.elements[aux.size++] = first.elements[i];
        ap[first.elements[i]]=1;
    }

    for(int i = 0; i<second.size; i++) {
        if(ap[second.elements[i]]==1) {
            continue;
        } else {
            aux.elements[aux.size++] = second.elements[i];
            ap[second.elements[i]]=1;
        }
    }

    qsort(aux.elements,aux.size,sizeof(int),function);
    return aux;
}
struct Array difference(struct Array first, struct Array second) {

    for (int i = 0; i < first.size; i++) {
        for (int j = 0; j < second.size; j++) {
            if (first.elements[i] == second.elements[j]) {
                for(int k = i ; k < first.size - 1; k ++) first.elements[k] = first.elements[k+1];
                first.size--;
            } else continue;
        }
    }
    return first;
}


int main(void) {
     int size_of_a=0, size_of_b=0;
     scanf("%d %d", &size_of_a, &size_of_b);

     struct Array a,b;
     a.size = size_of_a; b.size = size_of_b;
     for(int i = 0; i<size_of_a; i++) scanf("%d", &a.elements[i]);
     for(int i = 0; i<size_of_b; i++) scanf("%d", &b.elements[i]);

     struct Array arraysIntersection = intersection(a,b);
     struct Array arraysUniqueReunion = unique_reunion(a,b);
     struct Array firstLessIntersection = difference(a, intersection(a,b));

     printf("\nIntersectia celor doua multimi este: { ");
     if(arraysIntersection.size==0) puts("multimea vida");
     else for(int i = 0; i<arraysIntersection.size; i++) printf("%d ", arraysIntersection.elements[i]);
    printf("}\nReuniunea unica a celor doua multimi este:\n{ ");
     for(int i = 0; i<arraysUniqueReunion.size; i++) printf("%d ", arraysUniqueReunion.elements[i]);
    printf("}\nA - (A n B) = { ");
    for(int i = 0; i<firstLessIntersection.size; i++) printf("%d ", firstLessIntersection.elements[i]);
    printf("}");
     return 0;
}