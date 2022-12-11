#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHAR_LIMIT 256

int substring(char*, char*);

int main(void) {

    char* text = (char*)calloc(CHAR_LIMIT, sizeof(char));
    char* string = (char*)calloc(CHAR_LIMIT, sizeof(char));

    puts("Introduceti textul suport."); scanf("%[^\n]", text);
    puts("Introduceti stringul de cautat."); scanf("\n%[^\n]", string);

    printf("Secventa %s%s in sirul %s", string, (substring(text, string)!=-1 ? " se afla" : " nu se afla"), text);
    free(text), text = NULL;
    free(string), string = NULL;
    return 0;
}

int substring(char* scr, char* string) {
    int pos = -1;
    for(int i = 0; i<strlen(scr); i++) {
        if(scr[i]==string[0]) {
            int start = 0;
            int ok = 1;
            for(int j = i; ok == 1 && string[start] != '\0'; j++) {
                if(scr[j]==string[start]) {
                    start++;
                } else ok = 0;
            }

            if(ok == 1) {
                pos = i;
                break;
            }
        }
    }

    return pos;
}