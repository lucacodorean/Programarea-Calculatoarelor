//
// Created by codor on 10/10/2022.
//
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    /// parsare
    /// cand citesti si pui * in fata unui element din format, el este ignorat
    char text[100];
    start: printf("Zi fra un text:\n");
    gets(text);

    for(int i = 0; text[i] != '\0'; i++) {
       text[i] -= (text[i] >= 'a' && text[i] <= 'z' ? ' ' : 'a'-'A');
    }

    for(int i = 0, j =0; text[i] != '\0'; i++) {
        if(text[i]>='a' && text[i]<='z') {
            if(j%2==0) text[i]-= 'a'-'A';
        }
        j++;
    }
    puts(text);

    printf("Mai este un om?");
    int raspuns= getch();
    if (raspuns == 'y') goto start;

    return 0;
}