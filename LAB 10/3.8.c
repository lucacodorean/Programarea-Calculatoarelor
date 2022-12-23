//
// Created by Luca Codorean on 12/18/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHAR_LIMIT 256

typedef struct {
    char character;
    unsigned int ap;
} FREQUENCY;

void printf_list(FREQUENCY*);

int main(void) {

    char* string = (char*)calloc(CHAR_LIMIT, sizeof(char));
    FREQUENCY* list = (FREQUENCY*)calloc(CHAR_LIMIT, sizeof(FREQUENCY));
    scanf("%[^\n]", string);

    for(size_t i = 0; i<strlen(string); i++) {
        list[(int)string[i]].character = string[i];
        list[(int)string[i]].ap++;
    }

    printf_list(list);

    free(string);
    free(list);
    return 0;
}

void printf_list(FREQUENCY * arr) {
    puts("FREQUENCY TABLE: ");
    puts("CHARACTER | FREQUENCY");
    puts("----------|----------");

    for(size_t i = '0'; i<='z'; i++) {
        if((arr+i)->ap != 0) printf("Ch: %c\t  | Freq: %u\n", (arr+i)->character, (arr+i)->ap);
    }
}