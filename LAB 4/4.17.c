//
// Created by Luca Codorean on 10/30/2022.
//

#include <stdio.h>

const int max(int a, int b);
int numberOfDigits(int number);

int main(void) {
    int number; scanf("%d", &number);
    int ap[10] = {0};
    int digits[numberOfDigits(number)];
    int max_ap = 1, size = 0;

    int aux = number;
    while(aux>0) {
        ap[aux%10]++;
        digits[size++] = aux%10;
        aux/=10;
    }

    aux = number;

    for(int digit = 0; digit<=9; digit++) {
        max_ap = max(max_ap, ap[digit]);
    }

    int result = 0, p = 1;
    while(aux>0) {
        int digit = aux%10;
        if(ap[digit]!=max_ap) {
            result = result + (digit *p);
            p*=10;
        }
        aux/=10;
    }

    printf("Numarul obtinut prin eliminarea cifrelor cu frecventa de aparitii maxima este: %d.\n", result);

    printf("Numarul obtinut prin regula interschimbarii este: ");
    for(int i = 0; i<size; i++) printf("%d", digits[i]);

    printf("\nCel mai mare numar ce se poate obtine din cifrele numarului citit este: ");
    for(int digit = 9; digit>=0; digit--) {
        while(ap[digit]>0) {
            printf("%d", digit);
            ap[digit]--;
        }
    }
    printf(".");
    return 0;
}

int numberOfDigits(int number) {
    int result = 0;
    for(; number>0; number/=10) result++;
    return result;
}

const int max(int a, int b) { return a<b ? b : a; }