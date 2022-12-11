//
// Created by Luca Codorean on 12/10/2022.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define CHAR_LIMIT 256

void init(char*, int*, int*);
void strextract(char*, char*, int, int);

int main(void) {
    char* text = (char*)calloc(CHAR_LIMIT, sizeof(char));
    int start, size;
    init(text, &start, &size);

    char* result = (char*)calloc(size, sizeof(char));
    strextract(text, result, 4, size);
    printf("Secventa extrasa: %s\nDupa extragerea secventei, textul sursa este: %s", result, text);

    free(result),   result = NULL;
    free(text),     text = NULL;
    return 0;
}

void init(char* scr, int* start, int* size) {
    puts("Introduceti secventa (max. 256 caractere.)");
    scanf("%[^\n]", scr);
    puts("Introduceti pozitia de start respectiv numarul de elemente ale secventei (start, size):");
    scanf("%d %d", start, size);
}

void strextract(char *scr, char* dest, int start, int size) {
    char* new = (char*)calloc(CHAR_LIMIT, sizeof(char));
    memcpy(dest, scr+start, size);         /// formarea secventei extrase

    strncpy(new, scr, start);        /// formarea noii secventa
    strcat(new,scr+start+size);

    memmove(scr, new, strlen(new));   /// mutarea noii secvente in sursa (echivelent cu strcpy(scr,new))
    scr[strlen(new)] = '\0';
    free(new), new = NULL;
}