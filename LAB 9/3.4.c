//
// Created by Luca Codorean on 12/5/2022.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ULL unsigned long long

void insert(char*, char*, ULL);
void delete(char*, char*);

int main(void) {
    char text[200] = "Salut ce faci fra?";
    char name[50]; scanf("%s", name);

    delete(text, "ce");

    printf("%s", text);
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

void delete(char* scr, char* parameter) {
    char *const scr_copy = (char*)calloc(strlen(scr), sizeof(char));
    char *const aux = (char*)calloc(strlen(scr), sizeof(char));
    char* delim = " ";
    strcpy(scr_copy, scr);
    char* word = strtok(scr_copy, delim);
    while(word != NULL) {
        if(strcmp(word, parameter) != 0) {
            strcat(aux, word);
            strcat(aux, " ");
        }
        word = strtok(NULL, delim);
    }
    aux[strlen(aux)-1]='\0';
    strcpy(scr, aux);
    free(aux), free(scr_copy);
}