#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "directory.h"

#define TRUE                 1
#define MULTIPLE_PATHS_ERROR 400
#define NO_PATH_SPECIFIED    405
#define SUCCESS              100


void create_directory(DIRECTORY*);
void print_solutions(FILE*, DIRECTORY*);

int main(int argc, char* argv[]) {

    if(argc > 2) {
        printf("400: Bad request. \nShell command: { gcc main.c directory.c -o directory } ; if ($?) { .\\directory <file_destination_name>}\n");
        return MULTIPLE_PATHS_ERROR;
    } else if(argc==1) {
        printf("405: Method not allowed. \nShell command: { gcc main.c directory.c -o directory } ; if ($?) { .\\directory <file_destination_name>}\n");
        return NO_PATH_SPECIFIED;
    }

    DIRECTORY* director = (DIRECTORY*)calloc(1, sizeof(DIRECTORY));
    FILE* dest = fopen(argv[1], "w");

    init_directory(director);
    create_directory(director);
    print_solutions(dest, director);

    free_directory(director);
    free(dest), dest = NULL;
    free(argv), argv = NULL;
    return SUCCESS;
}

void create_directory(DIRECTORY* director) {
    puts("Introduceti un nume pentru noul director:");
    scanf("%s", director->directory_name);

    while(TRUE) {
        printf("\tIntroduceti numele fisierului %lld: ", director->file_count);
        fflush(stdin); 
        if(fgets(director->file_name[director->file_count], FILE_NAME_LENGTH, stdin) == NULL) break;
        director->file_name[director->file_count][strlen(director->file_name[director->file_count])-1] = '\0';

        printf("\tIntroduceti extensia fisierului %lld: ", director->file_count); 
        fflush(stdin); 
        if(fgets(director->file_extension[director->file_count], EXTENSION_LENGTH, stdin) == NULL) break;
        director->file_extension[director->file_count][strlen(director->file_extension[director->file_count])] = '\0';
        
        director->last_modified[director->file_count] = get_date();
        director->file_count++;
    }

    director->octects += sizeof(DIRECTORY) * (director->file_count-1);
}

void print_solutions(FILE* dest, DIRECTORY* director) {
    print_directory(dest, director, "INITIAL DIRECTORY INFORMATION");

    printf("\n\n");
    sort_directory(director, alphabetical);
    print_directory(dest, director, "ALPHABETICAL SORTED DIRECTORY INFORMATION");

    printf("\n\n");
    sort_directory(director, last_modified);
    print_directory(dest, director, "LAST_MODIFIED SORTED DIRECTORY INFORMATION");
    fclose(dest);
}