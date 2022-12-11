//
// Created by Luca Codorean on 11/14/2022.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int x = 2000;
    int* p = &x;

    printf("La adresa %p, se afla valoarea %d.\n", p, *p);
    *p = 200;
    printf("La adresa %p, se afla valoarea %d.\n", p, *p);

    int y = 201;

//    *p = y;
//    printf("x%s egal cu y\n", x==y ? "" : " nu este");
//    printf("%d", x);

    p = &y;
    x = *p;

    return 0;
}