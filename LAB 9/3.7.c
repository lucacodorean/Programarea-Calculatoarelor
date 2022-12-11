//
// Created by Luca Codorean on 12/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_LIMIT 256

void init(char**, unsigned short);
void longest_string(char**, unsigned short, char*);
void best_alphanumeric_string(char**, unsigned short, char*);
void print_solution(char**, unsigned short, char*, char*, void (*first_function)(char**, unsigned short, char*), void (*second_function)(char**, unsigned short, char*));
static const int max(unsigned short a, unsigned short b) { return (a>b ? a : b); }

int main(void) {
    puts("Introduceti numarul de stringuri pe care doriti sa le cititi.");
    int n; scanf("%d", &n);
    char** text = (char**)calloc(n,sizeof(char*));

    puts("Introduceti stringurile. Odata cu terminarea citirii unui string, apasati tasta ENTER.");
    init(text, n);

    char* longest = (char*)calloc(CHAR_LIMIT, sizeof(char));
    char* alpha = (char*)calloc(CHAR_LIMIT, sizeof(char));
    print_solution(text, n, longest, alpha,
                   (void (*)(char **, unsigned short, char *)) longest_string,
                   (void (*)(char **, unsigned short, char *)) best_alphanumeric_string);

    free(text), text = NULL;
    return 0;
}

void init(char** scr, unsigned short size) {
    for(int i = 0; i<size; i++) {
        scr[i] = (char*)calloc(CHAR_LIMIT, sizeof(char));
    }

    for(int i = 0; i<size; i++) {
        scanf("\n%[^\n]", scr[i]);
    }
}
void print_solution(char** scr, unsigned short size, char* first_function_buffer, char* second_function_buffer, void (first_function)(char**, unsigned short, char*), void (*second_function)(char**, unsigned short, char*)) {

    (*first_function)(scr,size, first_function_buffer);
    printf("Cel mai lung string din cele %d este: ''%s''.", size, first_function_buffer);

    (*second_function)(scr, size, second_function_buffer);
    printf("\nCel mai bun sir dpdv. alfanumeric din cele %d este: ''%s''.", size, second_function_buffer);

    free(first_function_buffer), first_function_buffer = NULL;
    free(second_function_buffer), second_function_buffer = NULL;
}
void longest_string(char** scr, unsigned short size, char* dest) {
    int max_value = 0;
    for(unsigned short i = 0; i<size; i++) {
       max_value = max(max_value, strlen(scr[i]));
       if(max_value == strlen(scr[i])) {
           strcpy(dest, scr[i]);
       }
    }
}
void best_alphanumeric_string(char** scr, unsigned short size, char* dest) {
    strcpy(dest, scr[0]);
    for(unsigned short i = 1; i<size; i++) {
        if(strcmp(scr[i], dest)<0) strcpy(dest,scr[i]);
    }
}