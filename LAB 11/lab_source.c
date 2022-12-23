//
// Created by Luca Codorean on 12/19/2022.
//

#include <stdio.h>
#include <stdlib.h>

#define ERR_FILE_NOT_FOUND 1
#define ERR_PATH_NOT_SPECIFIED 2

int main(int argc, char* argv[]) {


    if(argc<2) {
        printf("Error - no file name specified.");
        return ERR_PATH_NOT_SPECIFIED;
    }

    FILE* file = fopen(argv[1], argv[2]);
    if(file==NULL) {
        printf("Error - file not found.");
        return ERR_FILE_NOT_FOUND;
    }

    char chr; // read the first character
    while((chr = fgetc(file))!=EOF) {
        printf("%c", chr);
    }

    fclose(file);
    free(argv);
    return 0;
}