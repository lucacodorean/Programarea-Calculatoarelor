#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_LIMIT 255

void sort_string(char**, int);
void swap(void*, void*,  int);
void display(char**, int);

int main(void) {

    puts("Introduceti numarul de propozitii.");
    int size; scanf("%d", &size);
    char** text = (char**) calloc(size, sizeof(char*));

    for(int i = 0; i<size; i++) {
        text[i] = (char*) calloc(CHAR_LIMIT, sizeof(char));
        scanf("%s", text[i]);
    }

    sort_string(text, size);
    puts("Dupa sortarea lexicografica, propozitiile textului sunt:");
    display(text, size);

    free(text), text = NULL;
    return 0;
}

void swap(void* first_ptr, void* second_ptr, int size) {
    void* aux = malloc(size);

    memcpy(aux, first_ptr, size);               /// turnam in auxiliar din first_ptr
    memcpy(first_ptr, second_ptr, size);        /// turnam in first_ptr din second_ptr
    memcpy(second_ptr, aux, size);              /// turnam in second_otr din aux

    free(aux), aux = NULL;
}

void sort_string(char** text, int text_size) {
    for(int i = 0; i<text_size; i++) {
        for(int j = i+1; j<text_size; j++) {
            if(strcmp(*(text+i), *(text+j))>0) swap((char*)(text+i), (char*)(text+j), text_size);
        }
    }
}

void display(char** text, int size) {
    for(int i = 0; i<size; i++) {
        for(int j = 0; j<strlen(text[i]); j++) printf("%c", text[i][j]);
        printf("\n");
    }
}