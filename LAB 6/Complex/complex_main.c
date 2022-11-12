//
// Created by Luca Codorean on 11/5/2022.
//

#include <stdio.h>
#include "complex.h"


int main(void) {
    struct Complex number_1;
    struct Complex number_2;

    puts("NUMBER_1:\nIntroduceti doua valori float pentru partea reala si pentru partea imaginara, in aceasta ordine.");
    scanf("%f %f", &number_1.real, &number_1.imaginar);

    set_module(&number_1);
    set_PHI(&number_1);
    display(number_1); printf("\n");

    display_forma_trigonometrica(number_1);

    puts("NUMBER_2:\nIntroduceti doua valori float pentru partea reala si pentru partea imaginara, in aceasta ordine.");
    scanf("%f %f", &number_2.real, &number_2.imaginar);

    struct Complex number_3 = aduna(number_1, number_2);
    struct Complex number_4 = scade(number_1, number_2);
    struct Complex number_5 = inmulteste(number_1, number_2);
    struct Complex number_6 = imparte(number_1, number_2);

    printf("NUMBER_3 (+) este: ");   display(number_3);    printf("\n");
    printf("NUMBER_4 (-) este: ");   display(number_4);    printf("\n");
    printf("NUMBER_5 (*) este: ");   display(number_5);    printf("\n");
    printf("NUMBER_6 (/) este: ");   display(number_6);    printf("\n");
    return 0;
}