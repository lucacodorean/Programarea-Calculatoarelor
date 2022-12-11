//
// Created by Luca Codorean on 11/29/2022.
//

#include <stdlib.h>
#include <stdio.h>

#define CHAR_LIMIT 256

char** init(int);
void display(char**, int);

int main(void) {
    puts("Introduceti numarul de cuvinte.");
    int size; scanf("%d", &size);

    char** text = init(size);
    display(text, size-1);

    free(text), text=NULL;
    return 0;
}

char** init(int size) {
    char** text = (char**) calloc(size, sizeof(char*));

    for(int i = 0; i<size; i++) {
        text[i] = (char*) calloc(CHAR_LIMIT, sizeof(char));
        scanf("%s", text[i]);
    }
    return text;
}

void display(char** array, int  size) {
    if(size>=0) {
        printf("%s\n", array[size]);
        display(array, size-1);
    } else return;
}