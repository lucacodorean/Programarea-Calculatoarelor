//
// Created by Luca Codorean on 10/18/2022.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int deimpartit_integer, impartitor_integer;
    double deimpartit_double, impartitor_double;

    scanf("%d %d %lf %lf", &deimpartit_integer, &impartitor_integer, &deimpartit_double, &impartitor_double);
    int cat_integer = deimpartit_integer / impartitor_integer;
    double cat_double = deimpartit_double / impartitor_double;

    printf("Catul integer este %d, iar cel double este %lf. Diferenta este ca impartirea integer realizeaza si rotunjire, la partea intreaga. Nu tine cont de partea fractionara.", cat_integer, cat_double);
    return 0;
}