//
// Created by Luca Codorean on 12/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ULL unsigned long long

char* number_to_string(double);
void swap(char*, char*);

int main(void) {
    number_to_string(531.1256);
    printf("\n");
    number_to_string(612542.124654123);
    return 0;
}

void swap(char* first, char* second) {
    *first =    *first ^ *second;
    *second =   *first ^ *second;
    *first =    *second ^ *first;
}


char* number_to_string(double number) {
    ULL number_but_integer = (ULL)number; int decimals = 0;
    char* result = (char*)calloc(50, sizeof(char));
    while (fabs(number - number_but_integer) != 0 && decimals < 16) {
        number*=10;
        number_but_integer = number;
        decimals++;
    }

    ULL aux = number; int l = 0;
    while(aux>0) {
        char character = (aux%10 + '0');
        result[l++] = character;
        aux/=10;
    }

    if(decimals > 0) {
        l++;
        for(int i = l-1; i>=decimals; i--) {
            result[i] = result[i-1];
        }
        result[decimals] = '.';
    }

    for(int i = 0; i<(strlen(result)/2); i++) swap(&result[i], &result[strlen(result)-i-1]);
    printf("%s", result);
}