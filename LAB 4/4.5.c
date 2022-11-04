//
// Created by Luca Codorean on 10/29/2022.
//

#include <stdio.h>
#include <math.h>

int generatePrimeNumber(int limit);
int generateSquareNumber(int limit);

int main(void) {
    puts("Introduceti valoarea lui n: ");
    int n; scanf("%d", &n);

    printf("Cel mai mare numar prim mai mic decat %d este: %d, iar cel mai mic numar patrat perfect mai mic decat %d este: %d.", n,
           generatePrimeNumber(n), n, generateSquareNumber(n));

    return 0;
}

int generatePrimeNumber(int limit) {
    for(int number = limit; number>=2; number--) {
        int ok = 1;
        for(int divisor = 2; divisor*divisor<=number; divisor++) {
            if(number%divisor==0) {
                ok = 0;
                break;
            }
        }
        if(ok == 1) return number;
        else continue;
    }

    return 2;
}

int generateSquareNumber(int limit) {
    for(int number = limit; number>=2; number--) {
        double radical = sqrt(number);
        if((int)radical * (int)radical == number) return number;
        else continue;
    }

    return 1;
}