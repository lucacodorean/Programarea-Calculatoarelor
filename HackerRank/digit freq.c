//
// Created by Luca Codorean on 10/21/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

_Bool isdigit(char parameter);

int main() {

    char text[1000];
    int ap[10] = {0};
    scanf("%s", text);

    for(size_t i = 0; i<strlen(text); i++) {
        if(isdigit(text[i])==1) {
            ap[text[i]-'0'] ++;
        }
    }

    for(size_t number = 0; number<10; number++) printf("%d ", ap[number]);
    return 0;
}

_Bool isdigit(char parameter) {
    return ((int)parameter >=48 && (int)parameter<=57 ? true : false);
}