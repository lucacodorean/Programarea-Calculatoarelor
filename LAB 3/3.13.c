//
// Created by Luca Codorean on 10/18/2022.
//

#include <stdlib.h>
#include <stdio.h>

int main() {
    double varsta, inaltime;
    scanf("%lf %lf", &varsta, &inaltime);
    double masa_barbat = 50+(0.75*(inaltime-150))((varsta-20)/4);
    double masa_femeie = masa_barbat - 10;

    printf("Pentru barbati: %lf\nPentru femei: %lf", masa_barbat, masa_femeie);
    return 0;
}
