/*
Se citeşte de la tastatură un text care se scrie într-un fişier "poveste.txt". Să se afişeze apoi conţinutul fişierului, fiecare linie fiind precedată de numărul de ordine al ei.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_PATH_NOT_SPECIFIED      1
#define ERR_EXTENSION_NOT_SPECIFIED 2
#define CORRECT_PATH                0
#define TEXT_LIMIT                  256
#define TRUE                        1
#define NO_ERR_AT_COMPILE_TIME      0

int correct_path(int, char*[]);
void free_pointers(FILE*, char*[], char**, int, int);

int main(int argc, char* argv[]) {
    if(correct_path(argc,argv)==0) {
        int line_count = 0;
        FILE* file = fopen(argv[1], "w");
        char** text = (char**)calloc(TEXT_LIMIT, sizeof(char*));

        for(int i = 0; i<TEXT_LIMIT; i++) text[i] = (char*)calloc(TEXT_LIMIT, sizeof(char));

        while(TRUE) {
            if(fgets(text[line_count], TEXT_LIMIT, stdin) == NULL) break;
            fprintf(file, "%d | %s", line_count, text[line_count]);
            line_count++;
        } fclose(file);
    }
    return NO_ERR_AT_COMPILE_TIME;
}

int correct_path(int argc, char* argv[]) {
    if(argc==1) {
        printf("ERROR: Path not specified!\n");
        return ERR_PATH_NOT_SPECIFIED;
    } else {
        if(!stricmp(argv[1], ".txt") || !stricmp(argv[1], ".in")) {
            printf("File extension not specified or file unreadable!\n");
            return ERR_EXTENSION_NOT_SPECIFIED;
        }
    }

    return CORRECT_PATH;
}

void free_pointers(FILE* file, char* argv[], char** text, int argc, int line_count) {
    for(size_t i = 0; i<line_count; i++) { free(text[i]); text[i] = NULL; }
    for(size_t i = 0; i<argc; i++)       { free(argv[i]); argv[i] = NULL; }
    free(argv); argv = NULL;
    free(text); text = NULL;
    free(file); file = NULL;
}