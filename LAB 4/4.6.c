//
// Created by Luca Codorean on 10/30/2022.
//

#include <stdlib.h>
#include <stdio.h>

void digitsNumber(char** array, int* array_len, int number) {
    char *aux = malloc(14*sizeof(char));
    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int result = 0;
    while(number>0) {
        aux[result++] = digits[(number%10)];
        number/=10;
    }
    *array = aux;
    *array_len = result;
}

int main(void) {
    puts("Introduceti numarul de verificat: ");
    int len, number; scanf("%d", &number);
    char* digits;
    digitsNumber(&digits,&len, number);

    if(len>1) {
        int ok = 1;
        for(int i = 0; i<len/2; i++) {
            if(digits[i]!=digits[len-i-1]) {
                ok = 0;
                break;
            } else continue;
        }
        printf("Numarul%s este palindrom.", ok==0 ? " nu" : "");
    } else puts("Numarul este mai mic decat 10, deci este palindrom.");

    free(digits);
    return 0;
}