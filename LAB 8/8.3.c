//
// Created by Luca Codorean on 11/29/2022.
//

#include <stdlib.h>
#include <stdio.h>

void Hanoi(int, char, char, char);


int main(void) {
    Hanoi(3,'a','b','c');
    return 0;
}

void Hanoi(int size, char a, char b, char c) {
    if(size==1) printf("%c %c", a, b);
    else {
        Hanoi(size-1, a,c,b);
        printf(" %c %c ", a, b);
        Hanoi(size-1,c, b,a);
    }
}