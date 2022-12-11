//
// Created by Luca Codorean on 12/5/2022.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ULL unsigned long long

void insert(char*, char*, ULL);

int main(void) {
    char text[200] = "Salut ce faci fra";
    char name[50]; scanf("%s", name);

    insert(text,name, 5);

    printf("%s?", text);
    return 0;
}

void insert(char* scr, char* element,  unsigned long long position) {
    char *const aux = (char*)calloc(CHAR_MAX, sizeof(char));
    strncpy(aux, scr, position);
    aux[strlen(aux)] = ' ';
    strcat(aux, element);
    strcpy(aux+strlen(aux), scr+position);
    memcpy(scr, aux, strlen(aux));
    free(aux);
}

