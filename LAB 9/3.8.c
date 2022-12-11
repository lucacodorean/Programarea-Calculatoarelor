//
// Created by Luca Codorean on 12/10/2022.
//


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define CHAR_LIMIT 256

double getSum(char*, const char*);

int main(void) {
    const char* delim = "abcdefghijklmnopqrstuvwxyz,/;'[]=/*!@#$%^&*() ";
    char* text = (char*)calloc(CHAR_LIMIT, sizeof(char));
    scanf("%[^\n]", text);
    double sum = getSum(text, delim);
    printf("%lf", sum);

    free(text), text = NULL;
    return 0;
}

double getSum(char* scr, const char* delim) {
    double sum = 0;
    char* copy = (char*)calloc(CHAR_LIMIT, sizeof(char));
    memcpy(copy, scr, strlen(scr));
    char* number = strtok(copy, delim);
    while(number != NULL) {
        sum += strtod(number, NULL);
        number = strtok(NULL, delim);
    }
    free(copy), copy = NULL;
    return sum;
}