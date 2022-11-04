//
// Created by Luca Codorean on 10/18/2022.
//

#include <stdio.h>

typedef char bool;

void get_binary(unsigned int number) {
    bool result[32] = {'0'};
    unsigned int auxiliary = number;
    int p = 0;
    while(number>0) {
        result[p++] = (bool)(number%2);
        number/=2;
    }

    printf("%d: ", auxiliary);
    for(int i = 31; i>=0; i--) {
        printf("%s%d", ((i+1)%8==0 ? " " : ""),result[i]);
    } printf("\n");
}

int main() {
    unsigned int current_year=2022, birth_year = 2003;
    get_binary(birth_year);
    get_binary(current_year);

    printf("\nPentru %d:\n", birth_year);
    printf("Shiftare la stanga   => ");   get_binary(birth_year<<4);
    printf("Shiftare la dreapta  => ");   get_binary(birth_year>>2);
    printf("Complement fata de 1 => ");   get_binary(-birth_year);

    printf("\nPentru %d:\n", current_year);
    printf("Shiftare la stanga => ");   get_binary(current_year << 4);
    printf("Shiftare la dreapta => ");  get_binary(current_year >> 2);
    printf("Complement fata de 1 => "); get_binary(-current_year);

    printf("\n AND, OR, XOR cu %d si %d:\n", current_year, birth_year);
    printf("&: ");  get_binary(current_year & birth_year);
    printf("|: ");  get_binary(current_year | birth_year);
    printf("^: ");  get_binary(current_year ^ birth_year);

    return 0;
}